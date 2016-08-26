/*

   KMRobot
   Keyboard & Mouse Robot with Arduino/Genuino Micro
   Build by Arduino 1.6.10
   ZhaoChunsheng 2016/08/26

*/

#include "Keyboard.h"
#include "Mouse.h"

# define ParameterMaxIndex 4
# define ComDataBufferMaxIndex 128

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Keyboard.begin();
  Mouse.begin();
}


void loop() {

  if (Serial.available() > 0) {
    char comDataBuffer[ComDataBufferMaxIndex] = "";
    int comDataBufferIndex = 0;
    delay(100);//等待缓冲区
    int numChar = Serial.available();
    Serial.print("numChar: ");
    Serial.println(numChar);
    if ( numChar > ComDataBufferMaxIndex ) {
      numChar = ComDataBufferMaxIndex;
    }

    //仅仅读取ComDataBufferMaxIndex长度的命令串
    while (numChar--) {
      comDataBuffer[comDataBufferIndex++] = Serial.read();
    }
    //如果还有没读取完毕的数据继续读取，作用是把缓冲数据清空
    while (Serial.read() >= 0);

    Serial.print("ComData: ");
    Serial.println(comDataBuffer);

    char parameter[ParameterMaxIndex][ComDataBufferMaxIndex] = {'\0'};
    int parameterIndex = 0;
    char *substr = strtok(comDataBuffer, " ,");

    while (substr != NULL && parameterIndex < ParameterMaxIndex) {
      strcpy(parameter[parameterIndex++], substr);
      substr = strtok(NULL, " ,");
    }

    //输出各个参数
    for (int i = 0; i < parameterIndex; i++) {
      Serial.print("Parameter");
      Serial.print(i); Serial.print(": ");
      Serial.println(parameter[i]);
    }

    //开始分析命令
    if ( strcmp(parameter[0], "Keyboard.write") == 0) {
      int key = atoi(parameter[1]);
      int times = atoi(parameter[2]);
      for (int i = 0; i < times; i++) {
        Keyboard.write(key);
      }
    }
    else if ( strcmp(parameter[0], "Keyboard.print") == 0) {
      Keyboard.print(parameter[1]);
    }
    else if ( strcmp(parameter[0], "Keyboard.println") == 0) {
      Keyboard.println(parameter[1]);
    }
    else if ( strcmp(parameter[0], "Keyboard.press") == 0) {
      int key = atoi(parameter[1]);
      Keyboard.press(key);
    }
    else if ( strcmp(parameter[0], "Keyboard.release") == 0) {
      int key = atoi(parameter[1]);
      Keyboard.release(key);
    }
    else if ( strcmp(parameter[0], "Keyboard.releaseAll") == 0) {
      Keyboard.releaseAll();
    }
    else if ( strcmp(parameter[0], "Mouse.move") == 0) {
      int x = atoi(parameter[1]);
      int y = atoi(parameter[2]);
      int wheel = atoi(parameter[3]);
      Mouse.move(x, y, wheel);
    }
    else if ( strcmp(parameter[0], "Mouse.setPos") == 0) {
      int x = atoi(parameter[1]);
      int y = atoi(parameter[2]);
      double mouseSpeed = atof(parameter[3]);
      if (x < 0) {
        x = abs(x) * mouseSpeed;
        for (int i = 1; i <= x ; i++) {
          Mouse.move(2, 0);
        }
      }
      else if (x > 0) {
        x = x * mouseSpeed;
        for (int i = 1; i <= x ; i++) {
          Mouse.move(-2, 0);
        }
      }
      if (y < 0) {
        y = abs(y) * mouseSpeed;
        for (int j = 1; j <= y; j++) {
          Mouse.move(0, 2);
        }
      }
      else if (y > 0) {
        y = y * mouseSpeed;
        for (int j = 1; j <= y; j++) {
          Mouse.move(0, -2);
        }
      }
    }
    else if ( strcmp(parameter[0], "Mouse.click") == 0) {
      if ( strcmp(parameter[1], "MOUSE_LEFT") == 0) {
        int clickTimes = atoi(parameter[2]);
        while (clickTimes) {
          Mouse.click();
          clickTimes--;
        }
      }
      else if ( strcmp(parameter[1], "MOUSE_RIGHT") == 0) {
        int clickTimes = atoi(parameter[2]);
        while (clickTimes) {
          Mouse.click(MOUSE_RIGHT);
          clickTimes--;
        }
      }
      else if ( strcmp(parameter[1], "MOUSE_MIDDLE") == 0) {
        int clickTimes = atoi(parameter[2]);
        while (clickTimes) {
          Mouse.click(MOUSE_MIDDLE);
          clickTimes--;
        }
      }
    }
    else if ( strcmp(parameter[0], "Mouse.press") == 0) {
      if ( strcmp(parameter[1], "MOUSE_LEFT") == 0) {
        Mouse.press();
      }
      else if ( strcmp(parameter[1], "MOUSE_RIGHT") == 0) {
        Mouse.press(MOUSE_RIGHT);
      }
      else if ( strcmp(parameter[1], "MOUSE_MIDDLE") == 0) {
        Mouse.press(MOUSE_MIDDLE);
      }
    }
    else if ( strcmp(parameter[0], "Mouse.release") == 0) {
      if ( strcmp(parameter[1], "MOUSE_LEFT") == 0) {
        Mouse.release();
      }
      else if ( strcmp(parameter[1], "MOUSE_RIGHT") == 0) {
        Mouse.release(MOUSE_RIGHT);
      }
      else if ( strcmp(parameter[1], "MOUSE_MIDDLE") == 0) {
        Mouse.release(MOUSE_MIDDLE);
      }
    }
    else if ( strcmp(parameter[0], "Mouse.test") == 0) {
      int x = atoi(parameter[1]);
      int y = atoi(parameter[2]);
      int speed = atoi(parameter[3]);
      for (int i = 0; i < 10; i++) {
        Mouse.move(-127, -127);
      }
      for (int i = 0; i < x; i++)
        Mouse.move(speed, 0);
      for (int i = 0; i < y; i++)
        Mouse.move(0, speed);
    }
    else {
      Serial.println("No Matching Commands!");
    }

    //命令分析结束

  }
}


