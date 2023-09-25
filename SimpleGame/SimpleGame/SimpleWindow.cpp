#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

void SimpleWindow()
{
	// 윈도우 창 생성  
	// SFML안에 RenderWindow 라는 클래스 타입있음. 그걸로 객체만들어주면 윈도우를 띄우게 되어있음. 윈도우에 정보를 같이 띄우자.
	// VideoMode 도 클래스, 객체 인스턴스 바로 선언하기 parameter -> 크기, 제목, 윈도우 뜨는 스타일
	// | 쓰면 parameter 가 하나라는 뜻     Style::Titlebar 이건 그냥 '변수'로 보면 됨. 값 저장하고 있는 애.
	// VideoMode() 는 함수 -> VideoMode 의 생성자 
	RenderWindow Window(VideoMode(1024, 768), "Simple Game", Style::Titlebar | Style::Close);
		// 이렇게만 하면 창이 금방 사라짐 (프로그램 종료되니까) 

		// 창 유지되게 하기(프로그램 종료 안되게) -> 무한루프 -> 근데 문제 생김
		// 항상 무한루프 돌아가게 하면 X, 윈도우 떴을때부터 무한루프 동작하게 해야함. 
		// Window 클래스에 isOpen() 함수(메소드): Window의 오픈 여부 확인. 열려있으면 true 가 되니까 열려있을때 루프를 돌리자.

Event e;

while(Window.isOpen())
{
	// close 버튼을 클릭하면 Event를 감지해서, Window 가 Close 되게 해야함.
	// Event 감지. 얘도 실행되고 끝나버림. 그럼 그 이후 이벤트 발생에 감지 못하니까, 얘도 실행되면서 대기하고 있을 필요 있다 -> 무한루프 필요 -> while
	while (Window.pollEvent(e))  // Event 의 e    e는 이벤트 객체 
	{
		// Event type 구분  type 은 변수 
		switch (e.type)  
		{
		case Event::Closed: // Event::Closed 얘 자체가 '변수' 다. 이 값이 나오면,
			Window.close(); // Window 를 닫자.
			break;  // 얘는 명령어, 키워드 
		}
	}
		
}

// ------------------ 여기까지는 창 잘 띄워짐 -----------------







}