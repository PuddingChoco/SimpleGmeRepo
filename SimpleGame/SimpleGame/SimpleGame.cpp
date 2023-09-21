// SimpleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Game.h"

int main()
{
	Game Simple;
	                        // 동적 생성이었으면 . 이 아닌 -> 가 되었을것. 여기서는 정적 생성.
	while (Simple.IsCreate()) // 윈도우 열렸니? ---> 열리자마자 무한루프 돌려줘. Close 이벤트 발생되서 창이 닫힐때까지. (이거 안쓰면 창이 떴다가 금방 꺼짐)
	{
		//Window.clear(sf::Color(255, 255, 255, 255));  // 기존에 창에 어떤 내용이 있었다면 깨끗하게 지워달라. ( ) 안에 있는 (흰색) 색상으로.   
													   // 숫자 작아지면 색은 어두워짐. 
		//Window.clear(sf::Color::Cyan);
		//Window.display();
	}
}


