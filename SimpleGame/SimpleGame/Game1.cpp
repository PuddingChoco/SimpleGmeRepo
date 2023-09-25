#include "Game1.h"



void Game1::InitWindowPointer()
{
	this-> Window = nullptr;  // int a = 0 �� ����Ѱ�. this�� ��� �Ⱥٿ��� ������.
}

// Window �ʱ�ȭ 
void Game1::InitWindow()
{
	// int* a = new int(3) ���İ� �����. 
	//     Ÿ��       ����
	// RenderWindow  Window   
	this->Window = new RenderWindow(VideoMode(1024, 768), "Simple Game", Style::Titlebar | Style::Close);
	// Game1.h ���� �̹� Ÿ�� ���� �������Ƿ�  RenderWindow* Window;  RenderWindow ���� ��. 

	// �ѹ� �� ����ְ� ������ ���� ����, ��� �����̸� ������ (������ �Ҷ��..)
	// ps. �𸮾� ���� ���, Tick() �Լ��� 60 ���������� ���������� (������ ���� 60)
	this->Window->setFramerateLimit(60);

}

void Game1::DeleteWindow()
{
	delete this->Window;
}

void Game1::InitRectEnemy()
{
	// Vector ������ : ���� & ũ�⸦ ���� ������ �ִ� ������,  ��Į��: ũ�⸸ ������ �ִ� ������
	// get: ������ �� ������ ����   set: �츮�� �����Ҷ� 
	// Vector2f ���� 2f �� 2d �� �ǹ���.  �ȿ� (x ũ��, y ũ��) �־���. 
	// ������Ʈ 'ũ��' ���ϱ�
	this->RectEnemy.setSize(Vector2f(100.0f, 100.0f));  // ������ , �� ��.
	// ������Ʈ '����' ���ϱ�
	this->RectEnemy.setFillColor(Color::Yellow);
	// �����쿡�� �ߴ� ��ġ�� ��������.
	this->RectEnemy.setPosition(30.0f, 30.0f); // ���� ��ǥ�� ��� �ٲ�� -> Update() �Լ� ���� �� �������.
}

void Game1::InitPlayer()
{
	this->Player.setRadius(30.0f);
	this->Player.setFillColor(Color::Red);
	this->Player.setPosition(
		this->Window->getSize().x / 2,  // ������ ���α����� ���� ������ ��. 
		this->Window->getSize().y / 2  // ������ �߾��� �ƴϰ� ��. 
	);
}

// ������ ����
Game1::Game1()
{
	this->InitWindowPointer(); // Game1.h �� �����ϱ� this ���̱�. ��� �Ⱥٿ��� ��. 
	this->InitWindow();

	// Enemy
	this->InitRectEnemy();
	this->SetSpawnValue();

	// Player
	this->InitPlayer();

	
}

// �Ҹ��� ����
Game1::~Game1()
{
	this->DeleteWindow();
}


void Game1::SetSpawnValue()
{
	this->EnemySpawnTime = 0.0f;
	this->EnemySpawnTImeMax = 10.0f;  // 10�ʶ�� �� �ƴϰ�, 10 �и������̴�. 1000�и����� == 1��
	this->EnemyMaxNumber = 5;
}  


const bool Game1::Running() const
{  // Window. ���ϴ� ������ ���������߱� ������. ���������� ������ �Լ�����Ϸ��� . �ƴϰ� -> ����ؾ���. 
   // RenderWindow* Window;  Game1.h �� �����ͷ� ����Ǿ�����. 
   // this �� ������ -> ȭ��ǥ �����. this�� ������ΰ�. ���⼭�� �̰� �����ϰ� �ִ� Ŭ���� Game1 �� �ǹ���. 
	return this->Window->isOpen();
}

void Game1::EventHandler()
{
	// close ��ư�� Ŭ���ϸ� Event�� �����ؼ�, Window �� Close �ǰ� �ؾ���.
	// Event ����. �굵 ����ǰ� ��������. �׷� �� ���� �̺�Ʈ �߻��� ���� ���ϴϱ�, �굵 ����Ǹ鼭 ����ϰ� ���� �ʿ� �ִ� -> ���ѷ��� �ʿ� -> while
	while (this->Window->pollEvent(e))  // Event �� e    e�� �̺�Ʈ ��ü 
	{
		// Event type ����  type �� ���� 
		switch (e.type)
		{
		case Event::Closed: // Event::Closed �� ��ü�� '����' ��. �� ���� ������,
			this->Window->close(); // Window �� ����.
			break;  // ��� ��ɾ�, Ű���� 
		}
	}
}

void Game1::SpawnEnemy()
{
	// ������ �Ʒ��� �������ϱ� y��ǥ�� �ǵ帱 �ʿ� ����.
	// x�� �������� ���;��� -> rand()�Լ� ���� & srand() �� ���� �������. 
	// RectEnemy.setPosition(0.0f);  //  0 ���� ���, 
	// x ��ǥ random �ϰ� ���ֱ� �ٵ� random �� ���� �����ϸ� �ȵ� -> ȭ�鿡 �Ⱥ���. ����,
	// ������ �� < ������ ũ��   ������.  rand() % ������ ���� ����  �ϸ� �������� ����.
	// static_cast : �� ��ȯ   Ȥ�� int �� ���� ������, float �� ������ ��ȯ���Ѷ�.
	this->RectEnemy.setPosition(static_cast<float>(rand() % 1024), 0.0f);

	// ���� �迭�� �ϳ��� �־������. 5���ϱ� 5�� �迭 
	this->RectEnemies.push_back(this->RectEnemy); // �ڿ��ٰ� ���ʷ� �־���.
}

void Game1::UpdateEnemy()
{
	// �� �����쿡 ǥ�õǴ� �ִ� ���� ���� (EnemyMaxNumber �� �� �Ѿ�� �ȵ�. �׳� 5�� ������ ����)
	if (this->RectEnemies.size() < this->EnemyMaxNumber)
	{
		// EnemySpawnTime ����Ÿ�� 
		// ���� �����Ǵ� �ð��� �ð� ���� (���͹�, ������) ������ֱ� 
		if (this->EnemySpawnTime >= this->EnemySpawnTImeMax)
		{
			this->EnemySpawnTime = 0.0f; //  �ٽ� 0 �ǰ� �ǵ��������. 
			this->SpawnEnemy();
		}
		else
		{
			this->EnemySpawnTime += 1.0f;  // �� �����Ӹ��� ������.  10 ���������� ���͹��� ����.
		}
	}

	// ������ ���� �����Ǵ� ��� ������ 
	// ������ ������Ʈ ������ŭ �Ǿ���� 
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		this->RectEnemies[i].move(0.0f, 3.0f);
	}

	// �ִϸ��̼� �� (�����غ���)
	//this->RectEnemy.move(0.0f, 3.0f); // �ȿ� ���� �������� �ٲ��ֺ���. 

	// ���� ������ �ٱ����� �����, (y��ǥ�� window�� y ũ�⸦ �Ѿ��) ����
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{                          // ������ ã�������� ���� y
		if (this->RectEnemies[i].getPosition().y >= this->Window->getSize().y)
		{                      // RectEnemies �� �迭 
			this->RectEnemies.erase(this->RectEnemies.begin() + i); // �����ּҴ� 0�̴ϱ� i��° �Ϸ��� +i
		}
	}
}

void Game1::UpdatePlayer()
{   // Ű���� �̺�Ʈ �������� ��� �� �Ѱ��� ->
	// Ű ������ �˾Ƽ� �̺�Ʈ ������ 
	// if ���� else if �ϸ� �ΰ� ������ ���ÿ� ���۵Ǵϱ� �׳� if�� ����. 
	if (Keyboard::isKeyPressed(Keyboard::Left))  // ���� Ű���� ������ �̺�Ʈ ������ 
	{
		this->Player.move(-5.0f, 0.0f);  // + �� �������̴ϱ� ���� ������ -
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))  
	{
		this->Player.move(5.0f, 0.0f);  
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))  
	{
		this->Player.move(0.0f, -5.0f);  
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))  
	{
		this->Player.move(0.0f, 5.0f); 
	}
}

void Game1::UpdateCollision()  // Enemy �߿� Ȥ�� ���� �ֵ��� �ִ���. 
{
	for (int i = 0; i < RectEnemies.size(); i++)
	{
		// ��Ҵ��� Ȯ�����ִ� �Լ�   getGlobalBounds  ��� ������ ��Ҵ�?  intersects�� ����
		// player �� ������Ʈ ������ enemy�� ������Ʈ ���� �� ��ġ�°� �ִ�? (���� ������� �� �ʿ� ����)
		if (this->Player.getGlobalBounds().intersects(this->RectEnemies[i].getGlobalBounds()))
		{
			this->GameOver(); // ��Ҵٸ�, ������ -> ������ ����� ��.
		}
	}

}

void Game1::GameOver()
{
	delete this->Window;
}




void Game1::Update()
{   
	this->UpdateEnemy();

	this->UpdatePlayer();

	this->UpdateCollision();
	/*
	// �� �����쿡 ǥ�õǴ� �ִ� ���� ���� (EnemyMaxNumber �� �� �Ѿ�� �ȵ�. �׳� 5�� ������ ����)
	if (this->RectEnemies.size() < this->EnemyMaxNumber)
	{
		// EnemySpawnTime ����Ÿ�� 
		// ���� �����Ǵ� �ð��� �ð� ���� (���͹�, ������) ������ֱ� 
		if (this->EnemySpawnTime >= this->EnemySpawnTImeMax)
		{
			this->EnemySpawnTime = 0.0f; //  �ٽ� 0 �ǰ� �ǵ��������. 
			this->SpawnEnemy();
		}
		else
		{
			this->EnemySpawnTime += 1.0f;  // �� �����Ӹ��� ������.  10 ���������� ���͹��� ����.
		}
	}

	// ������ ���� �����Ǵ� ��� ������ 
	// ������ ������Ʈ ������ŭ �Ǿ���� 
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		this->RectEnemies[i].move(0.0f, 3.0f);
	}

	// �ִϸ��̼� �� (�����غ���)
	//this->RectEnemy.move(0.0f, 3.0f); // �ȿ� ���� �������� �ٲ��ֺ���. 

	// ���� ������ �ٱ����� �����, (y��ǥ�� window�� y ũ�⸦ �Ѿ��) ����
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{                          // ������ ã�������� ���� y
		if (this->RectEnemies[i].getPosition().y >= this->Window->getSize().y)
		{                      // RectEnemies �� �迭 
			this->RectEnemies.erase(this->RectEnemies.begin() + i); // �����ּҴ� 0�̴ϱ� i��° �Ϸ��� +i
		}
	}
	*/
}

void Game1::Render()
{   
	// ���� �����ӿ� �׷��� ������ ����
	this->Window->clear();

	// draw object 
	// �׷��ٶ��� Window ��ü�� �޼ҵ� �� 
	// this �� Game1 Ŭ���� �ִ� �ֵ����� �� ���̰� �ִ���..
	//this->Window->draw(this->RectEnemy);

	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		this->Window->draw(this->RectEnemies[i]);
	}

	// draw player
	this->Window->draw(this->Player);


	// display
	// display �� §~ �ϰ� ������ �����°Ͱ� ���
	this->Window->display();
}

