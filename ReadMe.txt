English��

Keyboard & Mouse Robot with Arduino/Genuino Micro

Receives commands from the serial port, and then complete keyboard and mouse actions.

Example:

// Sends ASCII value 131(KEY_LEFT_GUI) once
Keyboard.write,131,1

// Sends KMRobot!
Keyboard.print,KMRobot!

// Sends KMRobot��'space' and ',' as separator
Keyboard.print,KMRobot without space

// Sends KMRobot! with a newline and carriage return
Keyboard.println,KMRobot!

// Pressed and held on, to end the key press, use Keyboard.release or Keyboard.releaseAll
Keyboard.press,131

// Lets go of the specified key
Keyboard.release,131

// Lets go of all keys currently pressed
Keyboard.releaseAll

// Double left click
Mouse.click,MOUSE_LEFT,2

// Sends a button press(MOUSE_LEFT|MOUSE_RIGHT|MOUSE_MIDDLE), a press is cancelled with Mouse.release
Mouse.press,MOUSE_LEFT

// Sends a message that a previously pressed button (invoked through Mouse.press) is released
Mouse.release,MOUSE_LEFT

// X-axis+1 Y-axis+1, Range(-127~+127)
Mouse.move,1,1,0

// ScrollUp ScrollDown=-1, Range(-127~+127)
Mouse.move,0,0,1

// Move bottom-right 500 distance from the current location of the cursor (error<3)
Mouse.setPos,-500,-500,0.7645
i.e.
Mouse.setPos (SourcePostionX - DestinationPostionX = DistanceX, SourcePostionY - DestinationPostionY = DistanceY, MouseSpeed)

Q: Why the "MouseSpeed" == 0.7645 ?
A: Use this test command : Mouse.test,500,500,2

It sets the coordinate to (0,0), and it moves X and Y 500 times at a rate of 2 units, but actually it moved 654 units, so: 
500/654=0.7645 *** Current Projects are all move at a rate of 2 units ***
  

or:
// 1280/745=1.718
Mouse.test,1280,1024,1

// If your screen resolution is 1280*1024 and the cursor at (1280,1024), the cursor will moveto (0,0)
Mouse.setPos,1280,1024,1.718



���ģ�

Keyboard & Mouse Robot with Arduino/Genuino Micro

���մ���ָ����Ƽ�����ꡣ


ʾ����

// �򿪿�ʼ�˵����ձ��KEY_LEFT_GUI��ʮ����131��
Keyboard.write,131,1

// ��� KMRobot!
Keyboard.print,KMRobot!

// ��� KMRobot����Ϊ�����Կո�Ͷ�����Ϊ�ָ���
Keyboard.print,KMRobot without space

// ��� KMRobot!���� arduino ����յ��س���
Keyboard.println,KMRobot!

// ��ס�ձ���������� Keyboard.release �� Keyboard.releaseAll �ͷ�
Keyboard.press,131

// �ͷŻձ��
Keyboard.release,131

// �ͷ������Ѱ��µİ���
Keyboard.releaseAll

// ����������Σ�˫����
Mouse.click,MOUSE_LEFT,2

// ��ס���(MOUSE_LEFT|MOUSE_RIGHT|MOUSE_MIDDLE)�������� Mouse.release �ͷ�
Mouse.press,MOUSE_LEFT

// �ͷ����
Mouse.release,MOUSE_LEFT

// X�������� 1 ����λ�� Y �������� 1 ����λ, ��Χ(-127~+127)
Mouse.move,1,1,0

// ���Ϲ���������Ϊ -1, ��Χ(-127~+127)
Mouse.move,0,0,1

// ��������굱ǰλ���������ƶ� 500 ��λ���������С�� 3 ����λ
Mouse.setPos,-500,-500,0.7645
�ر�˵����
Mouse.setPos (��ǰ���X���� - Ŀ������X = ��ֵX, ��ǰ���Y���� - Ŀ������Y = ��ֵY, ����ٶ�)

�ʣ�����ٶ�Ϊʲô�� 0.7645 ��
����д��һ���������Mouse.test,500,500,2
���������Ƚ����������㣬Ȼ���� 2 ����λ���ٶ������ X �� Y ������ƶ� 500 �Σ���ʵ�������ҵļ�������ƶ��� 654 ��λ�����ǣ�
500/654=0.7645 *** ��ǰ��Ŀ����궼���� 2 ����λ���ٶȽ����ƶ��� ***
  

��Ŀ����� 1 ����λ���ٶ��ƶ����ƶ��ٶȽ����ʷ�����:
// 1280/745=1.718
Mouse.test,1280,1024,1

// �� 1 ����λ���ٶȽ����ƶ������������ķֱ����� 1280*1024 ������������½ǣ�ִ�к���꽫�ᴦ�ڣ�0,0����λ��
Mouse.setPos,1280,1024,1.718



