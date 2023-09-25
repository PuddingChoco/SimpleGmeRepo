#pragma once

#include <iostream>
#include <vector>  // vector 사용하려면 이거 필요 

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

class Game1
{
private: // 외부에서 접근할 필요 없으니 RenderWindow 얘네들 private 으로 하자. 
	// RenderWindow Window(VideoMode(1024, 768), "Simple Game", Style::Titlebar | Style::Close);
	/*
	  Window
	*/

	RenderWindow* Window; // 포인터 변수 쓰는것: 좀 더 창을 열고닫고 하는 동작에 있어서 메모리 부담 덜 주려고. 작은 게임에는 그럴 필요는 없음.

	Event e;

    // Window 포인터 변수 초기화 하기 --> int a = 0; 처럼 초기값 넣어주는거. 쓰레기값 방지하기 위해서.
	void InitWindowPointer();

	// Window 동적 생성
	void InitWindow();

	// 동적 생성된 Window 삭제 
	void DeleteWindow();

	/*
	Emeny (private 영역)
	*/
	// 클래스타입    객체인스턴스
	// 동적 생성 할 수도 있으나 여기서는 정적 생성으로 함.
	RectangleShape RectEnemy;     // RectangleShape 는 SFML 에서 제공하는 API 객체 인스턴스다. 
	vector<RectangleShape> RectEnemies;  // RectangleShape 타입의 객체를 넣을 수 있는 벡터 

	// Spawn Value  
	// 어느정도 시간의 interval을 두고 spawn 을 좌라락 뿌려줄거냐. 
	float EnemySpawnTime;  // 이걸 0으로 두면
	float EnemySpawnTImeMax; // 최대값 얼마나 둘것이냐
	// 위 둘 얘네들 사이 값이 적을 생성하는 시간이 됨. ex. 10초마다 적 생성해라.
	int EnemyMaxNumber; // 한번에 몇 개 만들거냐. 

	// 초기화 : 처음에 생성할때 어떤것으로 셋팅해줄거냐.'
	void InitRectEnemy();

	/*
	Player
	*/
	CircleShape Player;

	// Init Player
	void InitPlayer();



	// 변후 선언 후, 윈도우 창 띄워주는건 생성자에서 하면 됨. 
public:
	/*
	생성자 & 소멸자
	*/

	// 생성자 선언
	Game1();

	// 소멸자 선언
	~Game1();


	/*
	Enemy (public 영역)
	*/
	// spawn: 계속 생성되며 나타나는 애들

	// Set Spawn Value
	void SetSpawnValue();

	//  Spawn Enemy  --> 만들어주긴 하는데 불규칙하게 만들어줘야함. 
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
	// 앞의 const : 반환값(return값)이 변경되지 않음 (반환되는 true/false 가 변하지 않는다 라는것을 보장해줌)
	// 뒤의 const : 매개변수, 함수 내부 값이 변경되지 않음 
	const bool Running() const;  // 자동이용.

	void EventHandler(); // SimpleWindow.cpp 에 있는 28~41 줄과 관련됨.

	void Update();

	void Render();


};

