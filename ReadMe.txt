English：

Keyboard & Mouse Robot with Arduino/Genuino Micro

Receives commands from the serial port, and then complete keyboard and mouse actions.

Example:

// Sends ASCII value 131(KEY_LEFT_GUI) once
Keyboard.write,131,1

// Sends KMRobot!
Keyboard.print,KMRobot!

// Sends KMRobot，'space' and ',' as separator
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



中文：

Keyboard & Mouse Robot with Arduino/Genuino Micro

接收串口指令控制键盘鼠标。


示例：

// 打开开始菜单（徽标键KEY_LEFT_GUI，十进制131）
Keyboard.write,131,1

// 输出 KMRobot!
Keyboard.print,KMRobot!

// 输出 KMRobot，因为参数以空格和逗号作为分隔符
Keyboard.print,KMRobot without space

// 输出 KMRobot!，但 arduino 会接收到回车符
Keyboard.println,KMRobot!

// 按住徽标键，必须用 Keyboard.release 或 Keyboard.releaseAll 释放
Keyboard.press,131

// 释放徽标键
Keyboard.release,131

// 释放所有已按下的按键
Keyboard.releaseAll

// 左键单击两次（双击）
Mouse.click,MOUSE_LEFT,2

// 按住左键(MOUSE_LEFT|MOUSE_RIGHT|MOUSE_MIDDLE)，必须用 Mouse.release 释放
Mouse.press,MOUSE_LEFT

// 释放左键
Mouse.release,MOUSE_LEFT

// X坐标右移 1 个单位， Y 坐标下移 1 个单位, 范围(-127~+127)
Mouse.move,1,1,0

// 向上滚动，向下为 -1, 范围(-127~+127)
Mouse.move,0,0,1

// 从鼠标坐标当前位置向右下移动 500 单位，坐标误差小于 3 个单位
Mouse.setPos,-500,-500,0.7645
特别说明：
Mouse.setPos (当前鼠标X坐标 - 目标坐标X = 差值X, 当前鼠标Y坐标 - 目标坐标Y = 差值Y, 鼠标速度)

问：鼠标速度为什么是 0.7645 ？
答：我写了一个测试命令：Mouse.test,500,500,2
该命令首先将鼠标坐标归零，然后以 2 个单位的速度让鼠标 X 和 Y 坐标各移动 500 次，但实际上在我的计算机上移动了 654 单位，于是：
500/654=0.7645 *** 当前项目中鼠标都是以 2 个单位的速度进行移动的 ***
  

项目最初以 1 个单位的速度移动（移动速度较慢故放弃）:
// 1280/745=1.718
Mouse.test,1280,1024,1

// 以 1 个单位的速度进行移动，如果计算机的分辨率是 1280*1024 ，鼠标在最右下角，执行后鼠标将会处在（0,0）的位置
Mouse.setPos,1280,1024,1.718



