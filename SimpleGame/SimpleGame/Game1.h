#pragma once

#include <iostream>
#include <vector>  // vector ����Ϸ��� �̰� �ʿ� 

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

class Game1
{
private: // �ܺο��� ������ �ʿ� ������ RenderWindow ��׵� private ���� ����. 
	// RenderWindow Window(VideoMode(1024, 768), "Simple Game", Style::Titlebar | Style::Close);
	/*
	  Window
	*/

	RenderWindow* Window; // ������ ���� ���°�: �� �� â�� ����ݰ� �ϴ� ���ۿ� �־ �޸� �δ� �� �ַ���. ���� ���ӿ��� �׷� �ʿ�� ����.

	Event e;

    // Window ������ ���� �ʱ�ȭ �ϱ� --> int a = 0; ó�� �ʱⰪ �־��ִ°�. �����Ⱚ �����ϱ� ���ؼ�.
	void InitWindowPointer();

	// Window ���� ����
	void InitWindow();

	// ���� ������ Window ���� 
	void DeleteWindow();

	/*
	Emeny (private ����)
	*/
	// Ŭ����Ÿ��    ��ü�ν��Ͻ�
	// ���� ���� �� ���� ������ ���⼭�� ���� �������� ��.
	RectangleShape RectEnemy;     // RectangleShape �� SFML ���� �����ϴ� API ��ü �ν��Ͻ���. 
	vector<RectangleShape> RectEnemies;  // RectangleShape Ÿ���� ��ü�� ���� �� �ִ� ���� 

	// Spawn Value  
	// ������� �ð��� interval�� �ΰ� spawn �� �¶�� �ѷ��ٰų�. 
	float EnemySpawnTime;  // �̰� 0���� �θ�
	float EnemySpawnTImeMax; // �ִ밪 �󸶳� �Ѱ��̳�
	// �� �� ��׵� ���� ���� ���� �����ϴ� �ð��� ��. ex. 10�ʸ��� �� �����ض�.
	int EnemyMaxNumber; // �ѹ��� �� �� ����ų�. 

	// �ʱ�ȭ : ó���� �����Ҷ� ������� �������ٰų�.'
	void InitRectEnemy();

	/*
	Player
	*/
	CircleShape Player;

	// Init Player
	void InitPlayer();



	// ���� ���� ��, ������ â ����ִ°� �����ڿ��� �ϸ� ��. 
public:
	/*
	������ & �Ҹ���
	*/

	// ������ ����
	Game1();

	// �Ҹ��� ����
	~Game1();


	/*
	Enemy (public ����)
	*/
	// spawn: ��� �����Ǹ� ��Ÿ���� �ֵ�

	// Set Spawn Value
	void SetSpawnValue();

	//  Spawn Enemy  --> ������ֱ� �ϴµ� �ұ�Ģ�ϰ� ����������. 
	void SpawnEnemy();

	void UpdateEnemy();


	/*
	Player
	*/
	void UpdatePlayer();

	/*
	Collision
	*/

	void UpdateCollision();

	void GameOver();

	/*
	Game Loop
	*/

	// Game Loop
	// ���� const : ��ȯ��(return��)�� ������� ���� (��ȯ�Ǵ� true/false �� ������ �ʴ´� ��°��� ��������)
	// ���� const : �Ű�����, �Լ� ���� ���� ������� ���� 
	const bool Running() const;  // �ڵ��̿�.

	void EventHandler(); // SimpleWindow.cpp �� �ִ� 28~41 �ٰ� ���õ�.

	void Update();

	void Render();


};

