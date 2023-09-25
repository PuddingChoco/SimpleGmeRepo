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
	// ������ â ����  
	// SFML�ȿ� RenderWindow ��� Ŭ���� Ÿ������. �װɷ� ��ü������ָ� �����츦 ���� �Ǿ�����. �����쿡 ������ ���� �����.
	// VideoMode �� Ŭ����, ��ü �ν��Ͻ� �ٷ� �����ϱ� parameter -> ũ��, ����, ������ �ߴ� ��Ÿ��
	// | ���� parameter �� �ϳ���� ��     Style::Titlebar �̰� �׳� '����'�� ���� ��. �� �����ϰ� �ִ� ��.
	// VideoMode() �� �Լ� -> VideoMode �� ������ 
	RenderWindow Window(VideoMode(1024, 768), "Simple Game", Style::Titlebar | Style::Close);
		// �̷��Ը� �ϸ� â�� �ݹ� ����� (���α׷� ����Ǵϱ�) 

		// â �����ǰ� �ϱ�(���α׷� ���� �ȵǰ�) -> ���ѷ��� -> �ٵ� ���� ����
		// �׻� ���ѷ��� ���ư��� �ϸ� X, ������ ���������� ���ѷ��� �����ϰ� �ؾ���. 
		// Window Ŭ������ isOpen() �Լ�(�޼ҵ�): Window�� ���� ���� Ȯ��. ���������� true �� �Ǵϱ� ���������� ������ ������.

Event e;

while(Window.isOpen())
{
	// close ��ư�� Ŭ���ϸ� Event�� �����ؼ�, Window �� Close �ǰ� �ؾ���.
	// Event ����. �굵 ����ǰ� ��������. �׷� �� ���� �̺�Ʈ �߻��� ���� ���ϴϱ�, �굵 ����Ǹ鼭 ����ϰ� ���� �ʿ� �ִ� -> ���ѷ��� �ʿ� -> while
	while (Window.pollEvent(e))  // Event �� e    e�� �̺�Ʈ ��ü 
	{
		// Event type ����  type �� ���� 
		switch (e.type)  
		{
		case Event::Closed: // Event::Closed �� ��ü�� '����' ��. �� ���� ������,
			Window.close(); // Window �� ����.
			break;  // ��� ��ɾ�, Ű���� 
		}
	}
		
}

// ------------------ ��������� â �� ����� -----------------







}