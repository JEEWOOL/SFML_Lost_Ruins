#include "ZombieWalker.h"
#include "../../Mgr/Utils.h"

ZombieWalker::ZombieWalker()
	:Monster()
{

}

void ZombieWalker::Spawn(Vector2f pos)
{
	position = pos;
	sprite.setPosition(position);

	findPlayerBox.setSize(Vector2f(200.f, 40.f));
	findPlayerBox.setOrigin(200, 40);
	findPlayerBox.setScale(scale);
	findPlayerBox.setFillColor(Color(153, 153, 0, 80));
	findPlayerBox.setPosition(position);

	attackRangeBox.setSize(Vector2f(25.f, 30.f));
	attackRangeBox.setOrigin(20, 30);
	attackRangeBox.setScale(scale);
	attackRangeBox.setFillColor(Color(155, 0, 0, 80));
	attackRangeBox.setPosition(position);

	hitBox.setSize(Vector2f(40.f, 30.f));
	hitBox.setOrigin(hitBox.getSize().x * 0.5f, hitBox.getSize().y * 0.99f);
	hitBox.setScale(scale);
	hitBox.setFillColor(Color(155, 0, 255, 80));
	hitBox.setPosition(position);
}

void ZombieWalker::SetPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
}

void ZombieWalker::MonsterInit()
{
	strWalk = ("ZombieWalkerWalk");
	strIdle = ("ZombieWalkerIdle");
	strRun = ("ZombieWalkerWalk");
	strDead = ("ZombieWalkerGiblets");
	strAttack = ("ZombieWalkerAttack");
	strAttackBlocked = ("ZombieWalkerAttackBlocked");
	strDamageTaken = ("ZombieWalkerDamageTaken");
	AnimationInit(&sprite);

	SetHealth(20);
	SetAtk(3);
	SetSpeed(30.f);
	sprite.setPosition(resolution.x * 0.5f, resolution.y * 0.4f);
	sprite.setScale(scale);
	position = sprite.getPosition();

	

	findPlayerBox.setSize(Vector2f(200.f, 40.f));
	findPlayerBox.setOrigin(200, 40);
	findPlayerBox.setScale(scale);
	findPlayerBox.setFillColor(Color(153, 153, 0, 80));
	findPlayerBox.setPosition(sprite.getOrigin());

	attackRangeBox.setSize(Vector2f(30.f, 30.f));
	attackRangeBox.setOrigin(20, 30);
	attackRangeBox.setScale(scale);
	attackRangeBox.setFillColor(Color(155, 0, 0, 80));
	attackRangeBox.setPosition(sprite.getOrigin());

	hitBox.setSize(Vector2f(43.f, 30.f));
	hitBox.setOrigin(hitBox.getSize().x * 0.5f, hitBox.getSize().y*0.99f);
	hitBox.setScale(scale);
	hitBox.setFillColor(Color(155, 0, 255, 80));
	hitBox.setPosition(sprite.getOrigin());

	SoundInit();

	animation.Play(strIdle);
	sprite.setOrigin((sprite.getTextureRect().width) * 0.5f, sprite.getTextureRect().height);

}

void ZombieWalker::SoundInit()
{
	soundFindPlayer.setBuffer(SoundHolder::GetBuffer("sound/monster/Zombie0.wav"));
	soundHitted.setBuffer(SoundHolder::GetBuffer("sound/monster/Zombie1.wav"));
	soundDeath.setBuffer(SoundHolder::GetBuffer("sound/monster/Zombie2.wav"));
}
