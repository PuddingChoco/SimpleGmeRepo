# Youtube Reference
https://www.youtube.com/watch?v=BySDfVNljG8&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up

# SFML 라이브러리 설치 

## 웹사이트
https://www.sfml-dev.org/download/sfml/2.6.0/

## 다운로드 
- C++ 17 : 2022 / 32비트 

## 폴더 구조

```
- SimpleGame - External - include 
						- lib 
			 - SimpleGame 
			 - SimpleGame.sln (프로젝트 파일)
```

- SFML > include 전체 파일/폴더 => SimpleGame 이름에 우클릭 > External > include 에 복사 붙여넣기 
- SFML > lib 전체 파일/폴더 => SimpleGame > External > lib 에 복사 붙여넣기   
- SFML > bin 전체 파일 => SimpleGame > SimpleGame 에 복사 붙여넣기   

# VS 2022 환경설정

- VS 2022 에디터 상단 툴바 > Solution Platform > x86으로 선택 

- Solution Explorer > SimpleGame 이름에 우클릭 > Drop Down Menu > Properties 
// - Solution Explorer > Drop Down Menu > Properties (위의것으로 수정)
- 상단 공통 영역
	- Configuration > All Configuration 
	- Platform > Win32 
- C/C++ > General > Additional Include Directories
	- SFML에서 복사해온 파일/폴더가 있는 위치를 선택 
	- $(SolutionDir) : 현재 프로젝트 폴더 표시 입력 하라는 뜻.
	- 최종 입력 형태 : $(SolutionDir)\External\include

- Linker > General > Additional Library Directories
	- SFML 에서 복사해온 파일/폴더가 있는 위치(폴더)를 선택
	- 최종 입력 형태 : $(SolutionDir)\External\lib

- Linker > Input > Additional Dependancies 에 아래 다섯개 넣어줌.
	- Configuration > Release 카테고리로 되어있어야함. (아래 5개 입력해주기)
```
sfml-system.lib
sfml-graphics.lib
sfml-window.lib
sfml-audio.lib
sfml-network.lib
```

- Linker > Input > Additional Dependancies 에 아래 다섯개 넣어줌.
	- Configuration > Debug 로 되어있어야함. (아래 5개 입력해주기)
```
sfml-system-d.lib
sfml-graphics-d.lib
sfml-window-d.lib
sfml-audio-d.lib
sfml-network-d.lib
```

# Event 

## Event 종류 
- 사건, 상황의 변화 
- Interface와 연관해서 생기는 상황의 변화 
- 키보드, 마우스로 생기는 상황의 변화  // 얘네들은 인터페이스 장치 
	- 키보드 이벤트 : 키 입력 
	- 마우스 이벤트 : 마우스 클릭( Push / Release (딸/깍)), 휠 스크롤, 더블클릭, 마우스 움직임  // Push 는 누르기 Release 는 마우스 띄기  
	- ex. 잘못눌렀다가 다른데로 직~끌었을때, 실수 안함. Release 에 반응하는 거였기 때문에. 
- 터치 스크린 : 터치, 스와이프, 핀치(손가락으로 확대)
- 로딩(파일이 메모리에 올라간다, 메모리에서 파일이 열린다)

## Event Handling (제어, 조작 - 이벤트를 다루는것)
- Event Delegate : (Delegaate: 위임하다) 여러개의 이벤트에 대응. 이벤트가 동시다발적으로 될때 모아놓았다가 한꺼번에 동작하도록 함 (여러개를 한번에 처리해서 동작하게 하는것)
- Event Listening : 이벤트 감지. 이벤트가 생기는지 안생기는지 계속 듣고 있음. 감지되면 -> 그때 Event Handling 을 해주는것. Event Delegate 도 할 수 있고.
- Event Handling : 감지된 이벤트에 대해서 적절한 동작 하게함.

# Game Loop

# SimpleGame 프로젝트에 구현한 Game 클래스 

- 게임을 전반적으로 Control하는 클래스 (사실, 플레이어 객체, enemy 객체는 이 클래스에 넣기보다는 분리하는것이 좋음)
- Enemy 생성
- Player 생성













