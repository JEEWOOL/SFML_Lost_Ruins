#include "LamiPhaseOne.h"

LamiPhaseOne::LamiPhaseOne()
	:Monster(), attackCount(0)
{
}

void LamiPhaseOne::MonsterInit()
{
	strWalk = ("Lami1Walk");
	strIdle = ("Lami1Idle");
	strRun = ("Lami1Walk");
	strDead = ("Lami1Dead");
	strAttack = ("Lami1Punch");
	strAttackBlocked = ("Lami1AttackBlocked");
	strDamageTaken = ("Lami1DamageTaken");
	strUppercut = ("Lami1Uppercut");

	SetHealth(60);
	SetAtk(3);
	SetSpeed(80.f);

	sprite.setPosition(resolution.x * 0.3f, resolution.y * 0.5f);
	sprite.setScale(scale);
	position = sprite.getPosition();
	AnimationInit(&sprite);

	findPlayerBox.setSize(Vector2f(200.f, 40.f));
	findPlayerBox.setScale(scale);
	findPlayerBox.setFillColor(Color(255, 255, 255, 80));
	findPlayerBox.setOrigin(200, 40);
	findPlayerBox.setPosition(sprite.getOrigin());

	attackRangeBox.setSize(Vector2f(30.f, 30.f));
	attackRangeBox.setScale(scale);
	attackRangeBox.setFillColor(Color(153, 0, 0, 80));
	attackRangeBox.setOrigin(30, 30);
	attackRangeBox.setPosition(sprite.getOrigin());

	hitBox.setSize(Vector2f(50.f, 30.f));
	hitBox.setScale(scale);
	hitBox.setOrigin(hitBox.getSize().x * 0.5f, hitBox.getSize().y * 0.99f);
	hitBox.setFillColor(Color(50, 50, 25, 70));
	hitBox.setPosition(sprite.getOrigin());

	SoundInit();

	animation.Play(strIdle);
	sprite.setOrigin((sprite.getTextureRect().width) * 0.5f, sprite.getTextureRect().height);
}

void LamiPhaseOne::ChasePlayer(Player& player, float dt)
{
	if (isAlive)
	{
		if (isFindPlayer && !isAttackPlayer)
		{
			if (attackRangeBox.getGlobalBounds().intersects(player.GetHitBox().getGlobalBounds()) && attackDelay > 1.5f)
			{
				attackDelay = 0.f;
				isFindPlayer = false;
				isAttackPlayer = true;
			}

			if (!isAttackPlayer && !isHit)
			{
				float h = player.GetPosition().x - sprite.getPosition().x;
				float v = 0.f;
				Vector2f dir(h, v);

				if (h > 0)
				{
					sprite.setScale(-1.f, 1.f);	//�÷��̾ ���� ���ʿ� ������
					attackRangeBox.setOrigin(attackRangeBox.getSize().x * 0.f, attackRangeBox.getSize().y * 0.99f);
					findPlayerBox.setOrigin(0.f, 40.f);
				}
				else
				{
					sprite.setScale(1.f, 1.f);	//�÷��̾ ���� �����ʿ� ������
					attackRangeBox.setOrigin(attackRangeBox.getSize().x, attackRangeBox.getSize().y * 0.99f);
					findPlayerBox.setOrigin(200.f, 40.f);
				}

				if (h * h > 200.f * 200.f || (sprite.getPosition().y - player.GetPosition().y) > 85 || sprite.getPosition().y - player.GetPosition().y < -50)		//�÷��̾��� �Ÿ��� �������� �÷��̾� �����ϴ°� ���
				{
					isFindPlayer = false;
					isIdle = true;
				}
				if ((isCollideHitBox && !isCollideAttackRangeBox) == false)
				{
					position += Utils::Normalize(dir) * speed * dt;
					sprite.setPosition(position);

					findPlayerBox.setPosition(position);
					attackRangeBox.setPosition(position);
					hitBox.setPosition(position);
				}
			}
		}
	}
}

void LamiPhaseOne::Attack(float dt, int atk, Player& player, Time timeHit)
{
	if (isAlive)
	{
		if (isAttackPlayer)
		{
			attackHitDelay += dt;

			sprite.setPosition(position);
			findPlayerBox.setPosition(position);
			attackRangeBox.setPosition(position);
			hitBox.setPosition(position);

			if (attackHitDelay > 0.75f)
			{
				if (attackRangeBox.getGlobalBounds().intersects(player.GetHitBox().getGlobalBounds()))
				{
					if (sprite.getPosition().x > player.GetSprite().getPosition().x)
					{
						monsterSide = true;
					}
					else
					{
						monsterSide = false;
					}
					player.OnHitted(atk, timeHit);
				}

				attackHitDelay = 0.f;
				isAttackPlayer = false;
				isFindPlayer = true;
			}
		}
	}
}

void LamiPhaseOne::SoundInit()
{
	soundFindPlayer.setBuffer(SoundHolder::GetBuffer("sound/monster/Slime2.wav"));
	soundHitted.setBuffer(SoundHolder::GetBuffer("sound/monster/SlimeHitVoice0.wav"));
	soundDeath.setBuffer(SoundHolder::GetBuffer("sound/monster/SlimeDie0.wav"));
}
