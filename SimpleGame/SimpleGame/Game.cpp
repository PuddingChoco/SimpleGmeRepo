/*  �̰� ���� �����ϱ� ( 0925 ������ �ߴ���)  ---> Game1.cpp ���� ��.
#include "Game.h"

void Game::InitVariable()
{
	// Game.h �� sf::RenderWindow* Window; �κ��� ���� ��������.
	//  nullptr �� �ʱ�ȭ ����.  nullptr: �ּҰ��� ���� ���� -> �ƹ��͵� ����Ű�� ���� �ʴ� ����. �ּҰ��� ����. ���� �ƹ��͵� �ȳ־����.
	this->Window = nullptr; //Null �� ���� �ִ� �ְ�, nullptr �� �ƿ� ���� ��
}

void Game::InitWindow() // ������ �����.
{
	this->VMode.width = 1024;
	this->VMode.height = 768;
	this->Window = new sf::RenderWindow(this->VMode, "Simple Game", sf::Style::Titlebar | sf::Style::Close); // sf::RenderWindow ��� Ÿ���ε�, �����ڷ� ����� �� �־���.
	//this->Window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Simple Game", sf::Style::Titlebar | sf::Style::Close); // sf::RenderWindow ��� Ÿ���ε�, �����ڷ� ����� �� �־���.
}



Game::Game()
{
	this->InitVariable(); // this: �̰�, �� Ŭ���� ��� ����ϴ°Ŷ� �ǹ̰� ��Ȯ������ ������ ���� 
	this->InitWindow();
}

Game::~Game()
{
}

const bool Game::IsCreate()   // ���� ���ľ���.
{
	return this->Window->isOpen(); // ���������Ѿִ� �޼ҵ峪 ������Ƽ�� -> �� ���ֱ�.
}


void Game::ExecEvent() 
{
	// �̺�Ʈ�� �߻��Ǵ��� �����Ѵ�.  �̺�Ʈ�� ���ܿ´�.  poll �����Ѵ�.   
	while (this->Window->pollEvent(this->Event))  // �̰� true��, while �� �����ض� = �̺�Ʈ�� �߻��Ǵ� ���ȿ��� �����ض�   method 
	{
		switch (this->Event.type)   // switch case �� ��Ȳ ������ ����. �̺�Ʈ �߻��ϸ� -> ���� �̺�Ʈ���� ���� ���� �б⸦ �����. Event.type � �̺�Ʈ���� ������ �ľ��غ��� 
		{
		case sf::Event::Closed: // Close ��ư Ŭ���ߴ�   sf, Event ��� namespace      Closed�� ���� �׸��� ��� ���� ���� ������ ����. 
			this->Window->close();  // �� �ݾƶ�.  close()�� () �پ����� �Լ�. method 
			break;
		case sf::Event::KeyPressed: // Ű�� ������ �̺�Ʈ �߻��ϸ� -> ���� Ű�� �������� ã��. 
			// code�� key ��ü �ȿ� ����ִ� ����(Property). key�� Event ��ü �ȿ� ����ִ� ��ü. 
			// . ���� �����. Event�� ��ü, key�� ��ü, code�� (Ű����,��ɾ�� �ƴ�) �׷� ���� �ƴϸ� �Լ�. () ������ �Լ�.
			if (Event.key.code == sf::Keyboard::Escape)  // ESC Ű ������ 
			{
				this->Window->close(); // â �ݾƴ޶�. 
			}
			break;
		}
	}
}


void Game::Update()
{
}

void Game::Render()
{
}

*/
