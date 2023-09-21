#pragma once

#include <SFML/Graphics.hpp>  // library include ��Ŵ -> ��? -> �� �ټ����� ������ ���ϰ� �Ϸ���. ���⼭�� �� �Ʒ� 3�� ����ҵ�. 
#include <SFML/System.hpp>
#include <SFML/Window.hpp>  
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Game
{
private:
	// Window                    // Render Window: Ÿ��,  Window: ���� 
	sf::RenderWindow* Window;   // �����ͷ� ���������� -> â ������(�޸� �÷����ٰ�) �ݾҴ�(�����Ǿ��ٰ�) ���ϰ� �Ϸ���. �������� �Ǵ°� �� �����ο�ϱ�. ��Ÿ��, ����ܰ�
	sf::VideoMode VMode;  // ���� ����

	// Event      ���� ���� ���ص� �Ǽ� ����Ʈ�� �� �ʿ� ����. 
	sf::Event Event; // �̺�Ʈ �����     �̺�Ʈ Ÿ���� Ŭ���� ��ü Event(�ڿ���) ����.

	void InitVariable(); // ������ �ʱ�ȭ �ϴ� �Լ��� �ϳ� ���� �Ѳ����� �ʱ�ȭ ���ֱ�.
	void InitWindow(); 

public: 
	// constructor ����Ʈ ������  ��� �ڵ����� �����.
	Game(); 

	// descructor �Ҹ���
	~Game(); 

	// function
	const bool IsCreate(); // const: �갡 ��ȯ�ϴ°��� ���� ������ �ȵȴٰ� ��������. 

	void ExecEvent();

	void Update();

	void Render();

	// â�� ��� ������ �Ǿ����. �ִϸ��̼� ���� �־ �ð��� �������� ������� �ִϸ��̼� �����ϴ°Ͱ� ���.
	// �𸮾��������� Tick : 1�ʿ� (�ð���) �� ������ �����ϰ� �Ұ��ΰ�. 

};

