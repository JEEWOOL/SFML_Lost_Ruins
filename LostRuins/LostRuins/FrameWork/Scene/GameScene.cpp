#include "GameScene.h"

void GameScene::Init(SceneManager* sceneManager)
{
	this->sceneMgr = sceneManager;

	resolution.x = 1920.f;
	resolution.y = 1080.f;

	zombieWalker = new ZombieWalker();

	player.Init(zombieWalker);
	gameMap = IntRect(0, 0, resolution.x, resolution.y);

	CreateBlock();

	player.Spawn(gameMap, resolution, 0.5f);

	float wpXpos = 500.f;
	float wpYpos = resolution.y * 0.5f;

	// test
	zombieWalker->MonsterInit();

	//Dummy Map
	CreateBackGround();
	texBackground = TextureHolder::GetTexture("maps/Another/SewerWall.png");
	
}

void GameScene::Update(float dt, Time playTime, RenderWindow* window, View* mainView, View* uiView)
{
	if (player.GetPause() == false)
	{
		if (player.GetAlive() == false)
		{
			dt *= 0.25f;
		}
		
		zombieWalker->Update(player, dt, blocks, playTime);

		if (zombieWalker->GetHealth() == 0)
		{
			zombieWalker->SetPosition(9999.f, 9999.f);
		}

		player.Update(dt, blocks, playTime);
	}
}

void GameScene::Draw(RenderWindow* window, View* objectView)
{
	/* View ����*/
	objectView->setCenter(player.GetPosition());

	//���� ����
	if ((objectView->getCenter().x) - (objectView->getSize().x * 0.5f) < gameMap.left)
	{
		objectView->move((objectView->getSize().x * 0.5f) - (objectView->getCenter().x), 0);
	}

	//���� ����
	if ((objectView->getCenter().x) + (objectView->getSize().x * 0.5f) > gameMap.left + gameMap.width)
	{
		objectView->move((gameMap.left + gameMap.width) - ((objectView->getCenter().x) + (objectView->getSize().x * 0.5f)), 0);
	}

	//���� ����
	if ((objectView->getCenter().y) - (objectView->getSize().y * 0.5f) < gameMap.top)
	{
		objectView->move(0, (objectView->getSize().y * 0.5f) - (objectView->getCenter().y));
	}

	//�Ʒ��� ����
	if ((objectView->getCenter().y) + (objectView->getSize().y * 0.5f) > gameMap.top + gameMap.height)
	{
		objectView->move(0, (gameMap.top + gameMap.height) - ((objectView->getCenter().y) + (objectView->getSize().y * 0.5f)));
	}


	window->draw(tileMap, &texBackground);

	for (auto blockShape : blocks)
	{
		window->draw(blockShape->GetBlockShape());
	}

	player.Draw(window, objectView);

	// test
	zombieWalker->Draw(window);
	
	//testUI.Draw(window, mainView);
}

GameScene::~GameScene()
{
	for (auto blockShape : blocks)
	{
		delete blockShape;
	}
	blocks.clear();
}

void GameScene::CreateBlock()
{
	for (auto bk : blocks)
	{
		delete bk;
	}

	blocks.clear();

	Vector2i res = resolution;

	TestBlock* block1 = new TestBlock(res.x * 0.5f, res.y * 0.5f, 800.f, 50.f);
	blocks.push_back(block1);
	TestBlock* block2 = new TestBlock(res.x * 0.5f, res.y - 50.f, res.x, 100.f);
	blocks.push_back(block2);
	TestBlock* block3 = new TestBlock(440.f, res.y * 0.75f - 50.f, 600.f, 50.f);
	blocks.push_back(block3);
	TestBlock* block4 = new TestBlock(1480.f, res.y * 0.75f - 50.f, 600.f, 50.f);
	blocks.push_back(block4);
	TestBlock* block7 = new TestBlock(res.x * 0.5f, res.y - 150.f, 100.f, 100.f);
	blocks.push_back(block7);
}

int GameScene::CreateBackGround()
{
	const int TILE_SIZE = 128;
	const int TILE_TYPES = 0;
	const int VERTS_IN_QUAD = 4;

	int cols = gameMap.width / TILE_SIZE;
	int rows = gameMap.height / TILE_SIZE;

	tileMap.setPrimitiveType(Quads);
	tileMap.resize(cols * rows * VERTS_IN_QUAD);

	for (int r   = 0; r < rows; ++r)
	{
		for (int c = 0; c < cols; ++c)
		{
			int index = r * cols + c;

			float x = c * TILE_SIZE;
			float y = r * TILE_SIZE;
			//std::cout << x << y << std::endl;
			int vertexIndex = index * VERTS_IN_QUAD;

			tileMap[vertexIndex + 0].position = Vector2f(x, y);
			tileMap[vertexIndex + 1].position = Vector2f(x + TILE_SIZE * 2.f, y);
			tileMap[vertexIndex + 2].position = Vector2f(x + TILE_SIZE * 2.f, y + TILE_SIZE * 2.f);
			tileMap[vertexIndex + 3].position = Vector2f(x, y + TILE_SIZE * 2.f);

			int texIndex = 0;

			float offset = texIndex * TILE_SIZE;
			tileMap[vertexIndex + 0].texCoords = Vector2f(0.f, offset);
			tileMap[vertexIndex + 1].texCoords = Vector2f(TILE_SIZE, offset);
			tileMap[vertexIndex + 2].texCoords = Vector2f(TILE_SIZE, offset + TILE_SIZE);
			tileMap[vertexIndex + 3].texCoords = Vector2f(0.f, offset + TILE_SIZE);
		}
	}

	return cols * rows;
}