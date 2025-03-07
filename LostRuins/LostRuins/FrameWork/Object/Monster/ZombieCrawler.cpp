#include "ZombieCrawler.h"
#include "../../Mgr/Utils.h"

ZombieCrawler::ZombieCrawler()
	:Monster()
{
}

void ZombieCrawler::MonsterInit()
{
	strWalk = ("ZombieCrawlerWalk");
	strIdle = ("ZombieCrawlerIdle");
	strRun = ("ZombieCrawlerWalk");
	strDead = ("ZombieCrawlerGiblets");
	strAttack = ("ZombieCrawlerAttack");
	strAttackBlocked = ("ZombieCrawlerAttackBlocked");
	strDamageTaken = ("ZombieCrawlerDamageTaken");
	AnimationInit(&sprite);
	SetHealth(20);
	SetAtk(3);
	SetSpeed(30.f);

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
	hitBox.setOrigin(hitBox.getSize().x * 0.5f, hitBox.getSize().y * 0.99f);
	hitBox.setFillColor(Color(50, 50, 25, 70));
	hitBox.setPosition(sprite.getOrigin());

	SoundInit();

	animation.Play(strIdle);
	sprite.setOrigin((sprite.getTextureRect().width) * 0.5f, sprite.getTextureRect().height);
}

void ZombieCrawler::SoundInit()
{
	soundFindPlayer.setBuffer(SoundHolder::GetBuffer("sound/monster/Zombie0.wav"));
	soundHitted.setBuffer(SoundHolder::GetBuffer("sound/monster/Zombie1.wav"));
	soundDeath.setBuffer(SoundHolder::GetBuffer("sound/monster/Zombie2.wav"));
}
