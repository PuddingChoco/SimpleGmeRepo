// SimpleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime> // srand() ������ �̰� �ʿ�

// #include "Game.h"
// #include "SimpleGame.h"
#include "Game1.h"

int main()
{
	srand(time(NULL)); // Null : �ƹ��͵� �ȳְڴ�.

	// ������ â ����
	// SimpleWindow(); ���� x 
	Game1 SimpleGame; 

	// Game Loop
	while (SimpleGame.Running())
	{
		SimpleGame.EventHandler(); // --> Q �̰� �´���  Ȯ���ϱ� 

		SimpleGame.Update();

		SimpleGame.Render();

	}




	/* 0925 �� �������� �Ѱ� 
	Game Simple;
	                        // ���� �����̾����� . �� �ƴ� -> �� �Ǿ�����. ���⼭�� ���� ����.
	while (Simple.IsCreate()) // ������ ���ȴ�? ---> �����ڸ��� ���ѷ��� ������. Close �̺�Ʈ �߻��Ǽ� â�� ����������. (�̰� �Ⱦ��� â�� ���ٰ� �ݹ� ����)
	{
		//Window.clear(sf::Color(255, 255, 255, 255));  // ������ â�� � ������ �־��ٸ� �����ϰ� �����޶�. ( ) �ȿ� �ִ� (���) ��������.   
													   // ���� �۾����� ���� ��ο���. 
		//Window.clear(sf::Color::Cyan);
		//Window.display();
	}
	*/
}


