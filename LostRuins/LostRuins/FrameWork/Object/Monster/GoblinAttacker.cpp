#include "GoblinAttacker.h"

GoblinAttacker::GoblinAttacker()
	:Monster()
{
	Monster::SetHealth(20);
	Monster::SetAtk(3);
	Monster::SetSpeed(50.f);
}

void GoblinAttacker::MonsterInit()
{
	strDemageTaken = ("GoblinAttackerDemageTaken");

	sprite.setOrigin(23.f, 30);		//��� �� �� ��ǥ 23,30
	sprite.setPosition(resolution.x * 0.3f, resolution.y * 0.5f);
	sprite.setScale(scale);
	position = sprite.getPosition();


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

	hitBox.setSize(Vector2f(43.f, 30.f));
	hitBox.setScale(scale);
	hitBox.setOrigin(21.5f, 30.f);
	hitBox.setFillColor(Color(50, 50, 25, 70));
	hitBox.setPosition(sprite.getOrigin());
}

void GoblinAttacker::FindPlayer(Player& player)
{
	if (!isFindPlayer)
	{
		if (findPlayerBox.getGlobalBounds().intersects(player.GetHitBox().getGlobalBounds()))
		{
			isFindPlayer = true;

			sprite.setOrigin(23.f, 47);		//��� �۶� �� ��ǥ�� 23.f, 47��
			animation.Play("GoblinAttackerRun");
		}
	}
}

void GoblinAttacker::ChasePlayer(Player& player, float dt)
{
	if (isFindPlayer && !isAttackPlayer)
	{
		if (attackRangeBox.getGlobalBounds().intersects(player.GetHitBox().getGlobalBounds()))
		{
			sprite.setOrigin(20.f, 38);		//�����Ҷ� ��� �� �� ��ǥ 20,38
			animation.Play("GoblinAttackerAttack");
			isAttackPlayer = true;
		}

		if (!isAttackPlayer)
		{
			float h = player.GetPosition().x - sprite.getPosition().x;
			float v = 0.f;
			Vector2f dir(h, v);

			position += (Utils::Normalize(dir) * speed) * 2.f * dt;
			sprite.setPosition(position);

			findPlayerBox.setPosition(position);
			attackRangeBox.setPosition(position);
			hitBox.setPosition(position);

			if (h > 0)
			{
				sprite.setScale(-3.f, 3.f);	//�÷��̾ ���� ���ʿ� ������
				attackRangeBox.setOrigin(0, 30);
				findPlayerBox.setOrigin(0.f, 40.f);
			}
			else
			{
				sprite.setScale(3.f, 3.f);	//�÷��̾ ���� �����ʿ� ������
				attackRangeBox.setOrigin(30, 30);
				findPlayerBox.setOrigin(200.f, 40.f);
			}

			if (h * h > 500.f * 500.f)		//�÷��̾��� �Ÿ��� �������� �÷��̾� �����ϴ°� ���
			{
				isFindPlayer = false;
			}
		}
	}
}

void GoblinAttacker::Walk(float dt)
{
	if (!isFindPlayer)
	{
		checkTime += dt;
		if (checkTime > 3.f)
		{
			checkTime = 0;
			nextMove = Utils::RandomRange(-1, 2);	//-1�̸� ������ 0�̸� ���� 1�̸� ����
			switch (nextMove)
			{
			case -1:
				sprite.setScale(3.f, 3.f);
				animation.Play("GoblinAttackerWalk");
				sprite.setOrigin(23.f, 30);
				findPlayerBox.setOrigin(200.f, 40.f);
				attackRangeBox.setOrigin(30, 30);
				break;
			case 0:
				animation.Play("GoblinAttackerIdle");
				sprite.setOrigin(23.f, 30);
				break;
			case 1:
				sprite.setScale(-3.f, 3.f);
				animation.Play("GoblinAttackerWalk");
				sprite.setOrigin(23.f, 30);
				findPlayerBox.setOrigin(0.f, 40.f);
				attackRangeBox.setOrigin(0, 30);
				break;
			default:
				break;
			}
		}

		float h = (float)nextMove;
		float v = 0.f;
		Vector2f dir(h, v);

		position += Utils::Normalize(dir) * speed * dt;

		sprite.setPosition(position);
		findPlayerBox.setPosition(position);
		attackRangeBox.setPosition(position);
		hitBox.setPosition(position);
	}
}

void GoblinAttacker::Run(float dt)
{
}

void GoblinAttacker::Attack(float dt, int atk, Player& player)
{
	if (isAttackPlayer)
	{
		attackDelay += dt;
		if (attackDelay > 1.5f)
		{
			//���⿡ �Լ� �߰��ؼ� �÷��̾� Onhitted �� set �Լ� �Ἥ hp ���̸� �� ��.
			attackDelay = 0.f;
			isAttackPlayer = false;
			sprite.setOrigin(21.f, 46.f);	//�� ��  �� �� ��ǥ 21 46
			animation.Play("GoblinAttackerRun");
		}
	}
}

bool GoblinAttacker::OnHitted(int atk)
{
	if (health > 0)
	{
		animation.Play(strDemageTaken);
		health -= atk;
		return true;
	}
}
