#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>
#include <easyx.h>

#define MAX  100	
HWND hwnd = NULL;

//关卡
int cas = 1;
int speed = 150;
//1.数据分析
typedef struct Point
{
	int x;
	int y;
}MYPOINT;
struct mySnack
{
	int num;           //蛇的节数
	MYPOINT xy[MAX];   //记录蛇的meiyijie2坐标
	char postion;
}snake;
struct myFood
{
	MYPOINT fdxy;
	int flag;
	int eatgrade;;
}food;
//枚举类型
enum movePostion
{
	right = 72,
	left = 75,
	down = 77,
	up = 80
};
//2.过程分析
//蛇的过程
void initSnake()      //初始化蛇
{
	snake.xy[2].x = 0;
	snake.xy[2].y = 0;

	snake.xy[1].x = 10;
	snake.xy[1].y = 0;

	snake.xy[0].x = 20;
	snake.xy[0].y = 0;

	snake.num = 3;
	snake.postion = right;

	food.flag = 0;
}
void drawSnake()     //画蛇
{
	for (int i = 0; i < snake.num; i++)
	{
		setlinecolor(BLACK);
		setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
		fillrectangle(snake.xy[i].x, snake.xy[i].y, snake.xy[i].x + 10, snake.xy[i].y + 10);
	}

}
void moveSnake()     //移动蛇
{
	for (int i = snake.num - 1; i > 0; i--)
	{
		snake.xy[i].x = snake.xy[i - 1].x;
		snake.xy[i].y = snake.xy[i - 1].y;
	}
	switch (snake.postion)
	{
	case right:
		snake.xy[0].x += 10;
		break;
	case left:
		snake.xy[0].x -= 10;
		break;
	case down:
		snake.xy[0].y += 10;
		break;
	case up:snake.xy[0].y -= 10;
		break;
	default:break;
	}

}
void keyDown()       //控制蛇移动
{
	char ch = '0';
	ch = _getch();
	switch (ch)
	{
	case right:
		if (snake.postion != down)
		{
			snake.postion = up;
		}
		break;

	case left:
		if (snake.postion != right)
		{
			snake.postion = left;
		}
		break;

	case down:
		if (snake.postion != left)
		{
			snake.postion = right;
		}
		break;

	case up:
		if (snake.postion != up)
		{
			snake.postion = down;
		}
		break;
	default:
		break;
	}
}
//食物
void initFood()//初始化食物
{
	food.fdxy.x = rand() % 64 * 10;
	food.fdxy.y = rand() % 47 * 10;
	food.flag = 1;

	//食物不能和蛇在一起
	for (int i = 0; i < snake.num; i++)
	{
		if (food.fdxy.x == snake.xy[i].x && food.fdxy.y == snake.xy[i].y)
		{
			food.fdxy.x = rand() % 64 * 10;
			food.fdxy.y = rand() % 47 * 10;
		}
	}
}
void drawFood()//画食物
{
	setlinecolor(BLACK);
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	fillrectangle(food.fdxy.x, food.fdxy.y, food.fdxy.x + 10, food.fdxy.y + 10);
}
//3.逻辑分析
void eatFood()               //吃食物
{
	if (food.fdxy.x == snake.xy[0].x && food.fdxy.y == snake.xy[0].y)
	{
		snake.num++;
		food.eatgrade += 10;
		food.flag = 0;
		switch (food.eatgrade)
		{
		case 100:
		case 200:
		case 300:
			cas++;
			speed -= 20;//控制时间
			break;
		}
	}
}

/// <summary>
/// 游戏结束
/// </summary>
/// <returns>标记</returns>
int gameOver()
{
	//撞墙
	if (snake.xy[0].x < 0 || snake.xy[0].y < 0 || snake.xy[0].x > 650 || snake.xy[0].y > 480)
	{
		MessageBox(hwnd, "gameover", "撞墙了!", 0);
		return 1;
	}
	//撞自己
	for (int i = 1; i < snake.num; i++)
	{
		if (snake.xy[0].x == snake.xy[i].x && snake.xy[0].y == snake.xy[i].y)
		{

			MessageBox(hwnd, "游戏结束", "你个辣鸡！！！", 0);
			return 1;
		}
	}
	return 0;
}

//4.功能完善
void gamePause()
{
	if (_getch() == 32)
	{
		while (_getch() != 32);
	}
}
/// <summary>
/// 分数
/// </summary>
void showScore()
{
	char grade[100] = { "" };
	sprintf(grade, "socre:%d", food.eatgrade);

	settextcolor(GREEN);
	outtextxy(560, 20, grade);
	char casStr[20] = "";
	sprintf(casStr, "【第%d关】", cas);
	outtextxy(550, 40, casStr);

}

int main()
{
	//随机函数种子
	srand((unsigned int)time(NULL));
	hwnd = initgraph(640, 480);
	setbkcolor(WHITE);
	cleardevice();
	initSnake();
	int flag = 0;
	while (1)
	{
		cleardevice();
		if (food.flag == 0)
		{
			initFood();
		}
		drawFood();
		drawSnake();
		showScore();

		if (gameOver())
		{
			break;
		}

		eatFood();
		moveSnake();

		//有按键才处理
		while (_kbhit())
		{
			gamePause();
			keyDown();
		}

		Sleep(speed);
	}

	getchar();
	closegraph();
	return 0;
}
