/*  이건 파일 삭제하기 ( 0925 이전에 했던것)  ---> Game1.cpp 보면 됨.
#include "Game.h"

void Game::InitVariable()
{
	// Game.h 의 sf::RenderWindow* Window; 부분을 동적 생성해줌.
	//  nullptr 로 초기화 해줌.  nullptr: 주소값이 없는 상태 -> 아무것도 가리키고 있지 않는 상태. 주소값이 없다. 값을 아무것도 안넣어줬다.
	this->Window = nullptr; //Null 은 값이 있는 애고, nullptr 은 아예 없는 애
}

void Game::InitWindow() // 윈도우 띄워줌.
{
	this->VMode.width = 1024;
	this->VMode.height = 768;
	this->Window = new sf::RenderWindow(this->VMode, "Simple Game", sf::Style::Titlebar | sf::Style::Close); // sf::RenderWindow 얘는 타입인데, 생성자로 만들고 값 넣어줌.
	//this->Window = new sf::RenderWindow(sf::VideoMode(1024, 768), "Simple Game", sf::Style::Titlebar | sf::Style::Close); // sf::RenderWindow 얘는 타입인데, 생성자로 만들고 값 넣어줌.
}



Game::Game()
{
	this->InitVariable(); // this: 이것, 이 클래스 라고 명시하는거라 의미가 명확해지는 장점이 있음 
	this->InitWindow();
}

Game::~Game()
{
}

const bool Game::IsCreate()   // 여기 고쳐야함.
{
	return this->Window->isOpen(); // 동적생성한애는 메소드나 프로퍼티도 -> 로 써주기.
}


void Game::ExecEvent() 
{
	// 이벤트가 발생되는지 조사한다.  이벤트를 떙겨온다.  poll 조사한다.   
	while (this->Window->pollEvent(this->Event))  // 이게 true면, while 문 실행해라 = 이벤트가 발생되는 동안에는 실행해라   method 
	{
		switch (this->Event.type)   // switch case 로 상황 구분을 해줌. 이벤트 발생하면 -> 무슨 이벤트인지 보고 실행 분기를 해줘라. Event.type 어떤 이벤트인지 종류를 파악해보자 
		{
		case sf::Event::Closed: // Close 버튼 클릭했다   sf, Event 모두 namespace      Closed는 변수 그리고 얘는 무슨 값을 가지고 있음. 
			this->Window->close();  // 문 닫아라.  close()는 () 붙었으니 함수. method 
			break;
		case sf::Event::KeyPressed: // 키가 눌리는 이벤트 발생하면 -> 눌린 키가 무엇인지 찾자. 
			// code는 key 객체 안에 들어있는 변수(Property). key는 Event 객체 안에 들어있는 객체. 
			// . 으로 연결됨. Event는 객체, key도 객체, code는 (키워드,명령어는 아님) 그럼 변수 아니면 함수. () 있으면 함수.
			if (Event.key.code == sf::Keyboard::Escape)  // ESC 키 누르면 
			{
				this->Window->close(); // 창 닫아달라. 
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
