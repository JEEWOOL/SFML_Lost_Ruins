#include "AttackManager.h"
#include "../Object/Monster/ZombieWalker.h"

void AttackManager::Init(ZombieWalker* zombie, EffectManager* effectMgr)
{
	isFps = 0;
	maxFps = 0;

	this->zombie = zombie;
	this->effectMgr = effectMgr;

	TwohandWeaponInit();
	DaggerWeaponInit();

	soundDagger = SoundHolder::GetBuffer("sound/Woosh_Sword_Dagger_02.wav");
	soundTwoHanded = SoundHolder::GetBuffer("sound/Woosh_Sword_Heavy_03.wav");

	for (int i = 0; i < MAX_SPELL_CACHE_SIZE; i++)
	{
		unuseSpell.push_back(new FireArrow(zombie, effectMgr));
	}
}

void AttackManager::Update(float dt, std::vector <CollisionBlock*> blocks, Time playTime)
{
	auto spell = useSpell.begin();
	while (spell != useSpell.end())
	{
		FireArrow* isSpell = *spell;
		isSpell->Update(dt, blocks, playTime);

		if (!isSpell->IsActive())
		{
			spell = useSpell.erase(spell);
		}
		else
		{
			++spell;
		}
	}
}

void AttackManager::WeaponDraw(RenderWindow* window, View* mainView)
{
	window->setView(*mainView);

	switch (currentAtkType)
	{
	case AttackType::DAGGER:
		this->sprite = daggers.at(isFps)->GetSprite();
		window->draw(sprite);
		break;
	case AttackType::TWO_HANDED:
		this->sprite = twoHanded.at(isFps)->GetSprite();
		window->draw(sprite);
		break;
	default:
		break;
	}
}

void AttackManager::SpellDraw(RenderWindow* window)
{
	for (auto spell : useSpell)
	{
		window->draw(spell->GetSprite());
	}
}

void AttackManager::SetAttackType(AttackType attackType)
{
	switch (attackType)
	{
	case AttackType::DAGGER:
		soundWeapon.setBuffer(soundDagger);
		currentAtkType = AttackType::DAGGER;
		maxFps = MAX_DAGGER_FPS;
		delay = DAGGER_DELAY;
		currentAtkType = AttackType::DAGGER;
		break;
	case AttackType::TWO_HANDED:
		soundWeapon.setBuffer(soundTwoHanded);
		maxFps = MAX_TWO_HANDED_FPS;
		delay = TWO_HANDED_DELAY;
		currentAtkType = AttackType::TWO_HANDED;
		break;
	case AttackType::FIRE_ARROW:
		cost = SPELL_COST_FIRE_ARROW;
		currentAtkType = AttackType::FIRE_ARROW;
		break;
	}
}

void AttackManager::SetAttackPosition(Sprite sprite)
{
	switch (currentAtkType)
	{
	case AttackType::DAGGER:
		for (auto spriteWeapon : daggers)
		{
			spriteWeapon->SetPosition(sprite);
		}
		break;
	case AttackType::TWO_HANDED:
		for (auto spriteWeapon : twoHanded)
		{
			spriteWeapon->SetPosition(sprite);
		}
		break;
	}
}

void AttackManager::CastingSpell(Sprite sprite)
{
	float xpos = sprite.getPosition().x;
	float ypos = sprite.getGlobalBounds().top + sprite.getGlobalBounds().height * 0.5f;
	Vector2f spawnPos = (Vector2f(xpos, ypos));
	if (sprite.getScale().x > 0.f)
	{
		isDirection = true;
	}
	else if (sprite.getScale().x < 0.f)
	{
		isDirection = false;
	}

	if (unuseSpell.empty())
	{
		for (int i = 0; i < MAX_SPELL_CACHE_SIZE; ++i)
		{
			unuseSpell.push_back(new FireArrow(zombie, effectMgr));
		}
	}

	FireArrow* spell = unuseSpell.front();
	unuseSpell.pop_front();
	useSpell.push_back(spell);
	spell->Spell(spawnPos, isDirection);
}

void AttackManager::GetAttackSound()
{
	soundWeapon.play();
}

int AttackManager::GetAttackPoint()
{
	int damage = 0;
	switch (currentAtkType)
	{
	case AttackType::DAGGER:
		damage = 5;
		break;
	case AttackType::TWO_HANDED:
		damage = 10;
		break;
	}

	return damage;
}

int AttackManager::GetHitFrame()
{
	int frame = 0;
	switch (currentAtkType)
	{
	case AttackType::DAGGER:
		frame = DAGGER_HIT_FRAME;
		break;
	case AttackType::TWO_HANDED:
		frame = TWO_HANDED_HIT_FRAME;
		break;
	}

	return frame;
}

float AttackManager::GetAttackFps()
{
	float fps = 0.f;
	switch (currentAtkType)
	{
	case AttackType::DAGGER:
		fps = DAGGER_ATTACK_FPS;
		break;
	case AttackType::TWO_HANDED:
		fps = TWO_HANDED_ATTACK_FPS;
		break;
	case AttackType::FIRE_ARROW:
		fps = FIRE_ARROW_CAST_TIME;
		break;
	}

	return fps;
}

bool AttackManager::CheckFps()
{
	return isFps < maxFps ? true : false;
}

bool AttackManager::CheckDelay()
{
	return isFps < delay ? true : false;
}

int AttackManager::GetFps()
{
	return isFps;
}

void AttackManager::NextFps()
{
	isFps++;
}

void AttackManager::ResetFps()
{
	isFps = 0;
}

Sprite AttackManager::GetSprite()
{
	return sprite;
}

int AttackManager::PaySpellCost()
{
	return cost;
}

AttackManager::~AttackManager()
{
	for (auto spriteWeapon : twoHanded)
	{
		delete spriteWeapon;
	}
	twoHanded.clear();
}

void AttackManager::TwohandWeaponInit()
{
	for (auto spriteWeapon : twoHanded)
	{
		delete spriteWeapon;
	}
	twoHanded.clear();

	TwohandWeapon* twoHanded_1fps = new TwohandWeapon(75.f / 3.f, 80.f / 3.f, -80.f);
	twoHanded.push_back(twoHanded_1fps);
	TwohandWeapon* twoHanded_2fps = new TwohandWeapon(75.f / 3.f, 65.f / 3.f, -85.f);
	twoHanded.push_back(twoHanded_2fps);
	TwohandWeapon* twoHanded_3fps = new TwohandWeapon(60.f / 3.f, 60.f / 3.f, -100.f);
	twoHanded.push_back(twoHanded_3fps);
	TwohandWeapon* twoHanded_4fps = new TwohandWeapon(55.f / 3.f, 40.f / 3.f, -110.f);
	twoHanded.push_back(twoHanded_4fps);
	TwohandWeapon* twoHanded_5fps = new TwohandWeapon(50.f / 3.f, 30.f / 3.f, -125.f);
	twoHanded.push_back(twoHanded_5fps);
	TwohandWeapon* twoHanded_6fps = new TwohandWeapon(50.f / 3.f, 30.f / 3.f, -125.f);
	twoHanded.push_back(twoHanded_6fps);
	TwohandWeapon* twoHanded_7fps = new TwohandWeapon(55.f / 3.f, 30.f / 3.f, -115.f);
	twoHanded.push_back(twoHanded_7fps);
	TwohandWeapon* twoHanded_8fps = new TwohandWeapon(70.f / 3.f, 30.f / 3.f, -100.f);
	twoHanded.push_back(twoHanded_8fps);
	TwohandWeapon* twoHanded_9fps = new TwohandWeapon(85.f / 3.f, 30.f / 3.f, -80.f);
	twoHanded.push_back(twoHanded_9fps);
	TwohandWeapon* twoHanded_10fps = new TwohandWeapon(85.f / 3.f, 50.f / 3.f, -40.f);
	twoHanded.push_back(twoHanded_10fps);
	TwohandWeapon* twoHanded_11fps = new TwohandWeapon(90.f / 3.f, 90.f / 3.f, 20.f);
	twoHanded.push_back(twoHanded_11fps);
	TwohandWeapon* twoHanded_12fps = new TwohandWeapon(65.f / 3.f, 80.f / 3.f, 60.f);
	twoHanded.push_back(twoHanded_12fps);
	TwohandWeapon* twoHanded_13fps = new TwohandWeapon(65.f / 3.f, 80.f / 3.f, 90.f);
	twoHanded.push_back(twoHanded_13fps);
	TwohandWeapon* twoHanded_14fps = new TwohandWeapon(65.f / 3.f, 80.f / 3.f, 110.f);
	twoHanded.push_back(twoHanded_14fps);
	TwohandWeapon* twoHanded_15fps = new TwohandWeapon(65.f / 3.f, 80.f / 3.f, 120.f);
	twoHanded.push_back(twoHanded_15fps);
	TwohandWeapon* twoHanded_16fps = new TwohandWeapon(65.f / 3.f, 80.f / 3.f, 120.f);
	twoHanded.push_back(twoHanded_16fps);
	TwohandWeapon* twoHanded_17fps = new TwohandWeapon(65.f / 3.f, 80.f / 3.f, 120.f);
	twoHanded.push_back(twoHanded_17fps);
}

void AttackManager::DaggerWeaponInit()
{
	for (auto spriteWeapon : daggers)
	{
		delete spriteWeapon;
	}
	daggers.clear();

	Dagger* dagger_1fps = new Dagger(15.f / 3.f, 88.f / 3.f, 90.f);
	daggers.push_back(dagger_1fps);
	Dagger* dagger_2fps = new Dagger(10.f / 3.f, 83.f / 3.f, 90.f);
	daggers.push_back(dagger_2fps);
	Dagger* dagger_3fps = new Dagger(4.f / 3.f, 70.f / 3.f, 90.f);
	daggers.push_back(dagger_3fps);
	Dagger* dagger_4fps = new Dagger(4.f / 3.f, 62.f / 3.f, 90.f);
	daggers.push_back(dagger_4fps);
	Dagger* dagger_5fps = new Dagger(3.f / 3.f, 52.f / 3.f, 90.f);
	daggers.push_back(dagger_5fps);
	Dagger* dagger_6fps = new Dagger(15.f / 3.f, 52.f / 3.f, 90.f);
	daggers.push_back(dagger_6fps);
	Dagger* dagger_7fps = new Dagger(30.f / 3.f, 65.f / 3.f, 90.f);
	daggers.push_back(dagger_7fps);
	Dagger* dagger_8fps = new Dagger(57.f / 3.f, 70.f / 3.f, 90.f);
	daggers.push_back(dagger_8fps);
	Dagger* dagger_9fps = new Dagger(80.f / 3.f, 77.f / 3.f, 90.f);
	daggers.push_back(dagger_9fps);
	Dagger* dagger_10fps = new Dagger(105.f / 3.f, 83.f / 3.f, 90.f);
	daggers.push_back(dagger_10fps);
	Dagger* dagger_11fps = new Dagger(105.f / 3.f, 83.f / 3.f, 90.f);
	daggers.push_back(dagger_11fps);
	Dagger* dagger_12fps = new Dagger(105.f / 3.f, 83.f / 3.f, 90.f);
	daggers.push_back(dagger_12fps);
}
