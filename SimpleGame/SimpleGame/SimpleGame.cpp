// SimpleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Game.h"

int main()
{
	Game Simple;
	                        // ���� �����̾����� . �� �ƴ� -> �� �Ǿ�����. ���⼭�� ���� ����.
	while (Simple.IsCreate()) // ������ ���ȴ�? ---> �����ڸ��� ���ѷ��� ������. Close �̺�Ʈ �߻��Ǽ� â�� ����������. (�̰� �Ⱦ��� â�� ���ٰ� �ݹ� ����)
	{
		//Window.clear(sf::Color(255, 255, 255, 255));  // ������ â�� � ������ �־��ٸ� �����ϰ� �����޶�. ( ) �ȿ� �ִ� (���) ��������.   
													   // ���� �۾����� ���� ��ο���. 
		//Window.clear(sf::Color::Cyan);
		//Window.display();
	}
}


