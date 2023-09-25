#include "Game1.h"



void Game1::InitWindowPointer()
{
	this-> Window = nullptr;  // int a = 0 과 비슷한것. this는 사실 안붙여도 무방함.
}

// Window 초기화 
void Game1::InitWindow()
{
	// int* a = new int(3) 형식과 비슷함. 
	//     타입       변수
	// RenderWindow  Window   
	this->Window = new RenderWindow(VideoMode(1024, 768), "Simple Game", Style::Titlebar | Style::Close);
	// Game1.h 에서 이미 타입 선언 해줬으므로  RenderWindow* Window;  RenderWindow 빼도 됨. 

	// 한번 딱 띄워주고 가만히 있지 말고, 계속 깜빡이며 보여줘 (프레임 촤라락..)
	// ps. 언리얼 같은 경우, Tick() 함수에 60 프레임으로 정해져있음 (게임은 보통 60)
	this->Window->setFramerateLimit(60);

}

void Game1::DeleteWindow()
{
	delete this->Window;
}

void Game1::InitRectEnemy()
{
	// Vector 데이터 : 방향 & 크기를 같이 가지고 있는 데이터,  스칼라: 크기만 가지고 있는 데이터
	// get: 지정된 값 가져다 쓸때   set: 우리가 지정할때 
	// Vector2f 에서 2f 는 2d 를 의미함.  안에 (x 크기, y 크기) 넣어줌. 
	// 오브젝트 '크기' 정하기
	this->RectEnemy.setSize(Vector2f(100.0f, 100.0f));  // 구분은 , 로 함.
	// 오브젝트 '색상' 정하기
	this->RectEnemy.setFillColor(Color::Yellow);
	// 윈도우에서 뜨는 위치는 잡아줘야함.
	this->RectEnemy.setPosition(30.0f, 30.0f); // 여기 좌표가 계속 바뀐다 -> Update() 함수 가서 뭘 해줘야함.
}

void Game1::InitPlayer()
{
	this->Player.setRadius(30.0f);
	this->Player.setFillColor(Color::Red);
	this->Player.setPosition(
		this->Window->getSize().x / 2,  // 윈도우 가로길이의 절반 정도가 됨. 
		this->Window->getSize().y / 2  // 완전히 중앙은 아니게 됨. 
	);
}

// 생성자 정의
Game1::Game1()
{
	this->InitWindowPointer(); // Game1.h 에 있으니까 this 붙이기. 사실 안붙여도 됨. 
	this->InitWindow();

	// Enemy
	this->InitRectEnemy();
	this->SetSpawnValue();

	// Player
	this->InitPlayer();

	
}

// 소멸자 정의
Game1::~Game1()
{
	this->DeleteWindow();
}


void Game1::SetSpawnValue()
{
	this->EnemySpawnTime = 0.0f;
	this->EnemySpawnTImeMax = 10.0f;  // 10초라는 뜻 아니고, 10 밀리세컨이다. 1000밀리세컨 == 1초
	this->EnemyMaxNumber = 5;
}  


const bool Game1::Running() const
{  // Window. 못하는 이유는 동적생성했기 때문에. 동적생성한 변수나 함수사용하려면 . 아니고 -> 사용해야함. 
   // RenderWindow* Window;  Game1.h 에 포인터로 선언되어있음. 
   // this 는 무조건 -> 화살표 써야함. this는 명시적인것. 여기서는 이걸 포함하고 있는 클래스 Game1 을 의미함. 
	return this->Window->isOpen();
}

void Game1::EventHandler()
{
	// close 버튼을 클릭하면 Event를 감지해서, Window 가 Close 되게 해야함.
	// Event 감지. 얘도 실행되고 끝나버림. 그럼 그 이후 이벤트 발생에 감지 못하니까, 얘도 실행되면서 대기하고 있을 필요 있다 -> 무한루프 필요 -> while
	while (this->Window->pollEvent(e))  // Event 의 e    e는 이벤트 객체 
	{
		// Event type 구분  type 은 변수 
		switch (e.type)
		{
		case Event::Closed: // Event::Closed 얘 자체가 '변수' 다. 이 값이 나오면,
			this->Window->close(); // Window 를 닫자.
			break;  // 얘는 명령어, 키워드 
		}
	}
}

void Game1::SpawnEnemy()
{
	// 위에서 아래로 내려가니까 y좌표는 건드릴 필요 없음.
	// x가 랜덤으로 나와야함 -> rand()함수 쓰기 & srand() 도 같이 써줘야함. 
	// RectEnemy.setPosition(0.0f);  //  0 에서 출발, 
	// x 좌표 random 하게 해주기 근데 random 이 마구 랜덤하면 안됨 -> 화면에 안보임. 따라서,
	// 랜덤한 값 < 윈도우 크기   여야함.  rand() % 윈도우 가로 길이  하면 안쪽으로 나옴.
	// static_cast : 형 변환   혹시 int 로 값이 나오면, float 로 데이터 변환시켜라.
	this->RectEnemy.setPosition(static_cast<float>(rand() % 1024), 0.0f);

	// 이제 배열에 하나씩 넣어줘야함. 5개니까 5개 배열 
	this->RectEnemies.push_back(this->RectEnemy); // 뒤에다가 차례로 넣어줘.
}

void Game1::UpdateEnemy()
{
	// 한 윈도우에 표시되는 최대 개수 제한 (EnemyMaxNumber 이 수 넘어가면 안됨. 그냥 5개 까지만 하자)
	if (this->RectEnemies.size() < this->EnemyMaxNumber)
	{
		// EnemySpawnTime 시작타임 
		// 적이 생성되는 시간의 시간 간격 (인터벌, 딜레이) 만들어주기 
		if (this->EnemySpawnTime >= this->EnemySpawnTImeMax)
		{
			this->EnemySpawnTime = 0.0f; //  다시 0 되게 되돌려줘야함. 
			this->SpawnEnemy();
		}
		else
		{
			this->EnemySpawnTime += 1.0f;  // 매 프레임마다 더해줘.  10 프레임정도 인터벌이 생김.
		}
	}

	// 여러개 적을 생성되는 즉시 움직임 
	// 생성된 오브젝트 개수만큼 되어야함 
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		this->RectEnemies[i].move(0.0f, 3.0f);
	}

	// 애니메이션 됨 (실행해보기)
	//this->RectEnemy.move(0.0f, 3.0f); // 안에 숫자 여러개로 바꿔주보기. 

	// 적이 윈도우 바깥으로 벗어나면, (y좌표가 window의 y 크기를 넘어가면) 삭제
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{                          // 포지션 찾은다음에 현재 y
		if (this->RectEnemies[i].getPosition().y >= this->Window->getSize().y)
		{                      // RectEnemies 는 배열 
			this->RectEnemies.erase(this->RectEnemies.begin() + i); // 시작주소는 0이니까 i번째 하려면 +i
		}
	}
}

void Game1::UpdatePlayer()
{   // 키보드 이벤트 가져오는 방식 중 한가지 ->
	// 키 눌리며 알아서 이벤트 가져와 
	// if 쓰고 else if 하면 두개 누르면 동시에 동작되니까 그냥 if로 해줌. 
	if (Keyboard::isKeyPressed(Keyboard::Left))  // 왼쪽 키보드 눌리면 이벤트 가져와 
	{
		this->Player.move(-5.0f, 0.0f);  // + 는 오른쪽이니까 왼쪽 가려면 -
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))  
	{
		this->Player.move(5.0f, 0.0f);  
	}
	if (Keyboard::isKeyPressed(Keyboard::Up))  
	{
		this->Player.move(0.0f, -5.0f);  
	}
	if (Keyboard::isKeyPressed(Keyboard::Down))  
	{
		this->Player.move(0.0f, 5.0f); 
	}
}

void Game1::UpdateCollision()  // Enemy 중에 혹시 닿은 애들이 있는지. 
{
	for (int i = 0; i < RectEnemies.size(); i++)
	{
		// 닿았는지 확인해주는 함수   getGlobalBounds  경계 영역에 닿았니?  intersects는 교차
		// player 의 오브젝트 영역과 enemy의 오브젝트 영역 중 겹치는게 있니? (누가 닿는지는 알 필요 없음)
		if (this->Player.getGlobalBounds().intersects(this->RectEnemies[i].getGlobalBounds()))
		{
			this->GameOver(); // 닿았다면, 끝내라 -> 윈도우 지우면 됨.
		}
	}

}

void Game1::GameOver()
{
	delete this->Window;
}




void Game1::Update()
{   
	this->UpdateEnemy();

	this->UpdatePlayer();

	this->UpdateCollision();
	/*
	// 한 윈도우에 표시되는 최대 개수 제한 (EnemyMaxNumber 이 수 넘어가면 안됨. 그냥 5개 까지만 하자)
	if (this->RectEnemies.size() < this->EnemyMaxNumber)
	{
		// EnemySpawnTime 시작타임 
		// 적이 생성되는 시간의 시간 간격 (인터벌, 딜레이) 만들어주기 
		if (this->EnemySpawnTime >= this->EnemySpawnTImeMax)
		{
			this->EnemySpawnTime = 0.0f; //  다시 0 되게 되돌려줘야함. 
			this->SpawnEnemy();
		}
		else
		{
			this->EnemySpawnTime += 1.0f;  // 매 프레임마다 더해줘.  10 프레임정도 인터벌이 생김.
		}
	}

	// 여러개 적을 생성되는 즉시 움직임 
	// 생성된 오브젝트 개수만큼 되어야함 
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		this->RectEnemies[i].move(0.0f, 3.0f);
	}

	// 애니메이션 됨 (실행해보기)
	//this->RectEnemy.move(0.0f, 3.0f); // 안에 숫자 여러개로 바꿔주보기. 

	// 적이 윈도우 바깥으로 벗어나면, (y좌표가 window의 y 크기를 넘어가면) 삭제
	for (int i = 0; i < this->RectEnemies.size(); i++)
	{                          // 포지션 찾은다음에 현재 y
		if (this->RectEnemies[i].getPosition().y >= this->Window->getSize().y)
		{                      // RectEnemies 는 배열 
			this->RectEnemies.erase(this->RectEnemies.begin() + i); // 시작주소는 0이니까 i번째 하려면 +i
		}
	}
	*/
}

void Game1::Render()
{   
	// 이전 프레임에 그려진 내용을 지움
	this->Window->clear();

	// draw object 
	// 그려줄때는 Window 객체의 메소드 중 
	// this 는 Game1 클래스 있는 애들한테 다 붙이고 있는중..
	//this->Window->draw(this->RectEnemy);

	for (int i = 0; i < this->RectEnemies.size(); i++)
	{
		this->Window->draw(this->RectEnemies[i]);
	}

	// draw player
	this->Window->draw(this->Player);


	// display
	// display 에 짠~ 하고 전원이 들어오는것과 비슷
	this->Window->display();
}

