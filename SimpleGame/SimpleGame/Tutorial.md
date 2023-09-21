# SFML ���̺귯�� ��ġ 

## ������Ʈ
https://www.sfml-dev.org/download/sfml/2.6.0/

## �ٿ�ε� 
- C++ 17 : 2022 / 32��Ʈ 

## ���� ����

```
- SimpleGame - External - include 
						- lib 
			 - SimpleGame 
			 - SimpleGame.sln (������Ʈ ����)
```

- SFML > include ��ü ����/���� => SimpleGame > External > include �� ���� �ٿ��ֱ� 
- SFML > lib ��ü ����/���� => SimpleGame > External > lib �� ���� �ٿ��ֱ�   
- SFML > bin ��ü ���� => SimpleGame > SimpleGame �� ���� �ٿ��ֱ�   

# VS 2022 ȯ�漳��

- Solution Explorer > Drop Down Menu > Properties 
- ��� ���� ����
	- Configuration > All Configuration 
	- Platform > Win32 
- C/C++ > General > Additional Include Directories
	- SFML���� �����ؿ� ����/������ �ִ� ��ġ�� ���� 
	- $(SolutionDir) : ���� ������Ʈ ���� ��� �� 

- Linker > General > Additional Library Directories
	- SFML ���� �����ؿ� ����/������ �ִ� ��ġ(����)�� ����

- Linker > Input > Additional Dependancies �� �Ʒ� �ټ��� �־���.
	- Configuration > Release �� �Ǿ��־����. 
```
sfml-system.lib
sfml-graphics.lib
sfml-window.lib
sfml-audio.lib
sfml-network.lib
```

- Linker > Input > Additional Dependancies �� �Ʒ� �ټ��� �־���.
	- Configuration > Debug �� �Ǿ��־����. 
```
sfml-system-d.lib
sfml-graphics-d.lib
sfml-window-d.lib
sfml-audio-d.lib
sfml-network-d.lib
```

# Event 

## Event ���� 
- ���
- ��Ȳ�� ��ȭ 
- Interface�� �����ؼ� ����� ��Ȳ�� ��ȭ 
- Ű����, ���콺�� ����� ��Ȳ�� ��ȭ  // ��׵��� �������̽� ��ġ 
	- Ű���� �̺�Ʈ : Ű �Է� 
	- ���콺 �̺�Ʈ : ���콺 Ŭ��( Push / Release (��/��)), �� ��ũ��, ����Ŭ��, ���콺 ������  // Push �� ������ Release �� ���콺 ���  ex. �߸������ٰ� �ٸ����� ��~��������, �Ǽ� ����. Release �� �����ϴ� �ſ��� ������. 
- ��ġ ��ũ�� : ��ġ, ��������, ��ġ(�հ������� Ȯ��)
- �ε�(������ �޸𸮿� �ö󰣴�, �޸𸮿��� ������ ������)

## Event Handling (����, ���� - �̺�Ʈ�� �ٷ�°�)
- Event Delegate : (Delegaate: �����ϴ�)  �̺�Ʈ�� ���ôٹ������� �ɶ� ��Ƴ��Ҵٰ� �Ѳ����� �����ϵ��� �� (�������� �ѹ��� ó���ؼ� �����ϰ� �ϴ°�)
- Event Listening : �̺�Ʈ�� ������� �Ȼ������ ��� ��� ����. �����Ǹ� -> �׶� Event Handling �� ���ִ°�. Event Delegate �� �� �� �ְ�.




