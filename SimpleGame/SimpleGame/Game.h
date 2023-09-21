#pragma once

#include <SFML/Graphics.hpp>  // library include 시킴 -> 왜? -> 이 다섯가지 구현을 편하게 하려고. 여기서는 이 아래 3개 사용할듯. 
#include <SFML/System.hpp>
#include <SFML/Window.hpp>  
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	// Window                    // Render Window: 타입,  Window: 변수 
	sf::RenderWindow* Window;   // 포인터로 선언해주자 -> 창 열었다(메모리 올려졌다가) 닫았다(삭제되었다가) 편하게 하려고. 동적으로 되는게 더 자유로우니까. 런타임, 실행단계
	sf::VideoMode VMode;  // 정적 선언

	// Event      동적 생성 안해도 되서 포인트로 할 필요 없음. 
	sf::Event Event; // 이벤트 만들기     이벤트 타입의 클래스 객체 Event(뒤에꺼) 만듬.

	void InitVariable(); // 변수를 초기화 하는 함수를 하나 만들어서 한꺼번에 초기화 해주기.
	void InitWindow(); 

public: 
	// constructor 디폴트 생성자  얘는 자동으로 실행됨.
	Game(); 

	// descructor 소멸자
	~Game(); 

	// function
	const bool IsCreate(); // const: 얘가 반환하는값은 절대 수정이 안된다고 보장해줌. 

	void ExecEvent();

	void Update();

	void Render();

	// 창이 계속 유지가 되어야함. 애니메이션 개념 넣어서 시간당 몇프레임 띄워놓고 애니메이션 적용하는것과 비슷.
	// 언리얼엔진에서는 Tick : 1초에 (시간당) 몇 프레인 동작하게 할것인가. 

};

