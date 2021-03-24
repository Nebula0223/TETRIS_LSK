#include"pch.h"
#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<Mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;
//Shape_1为L型的第一种形状；Shape_2为L型的第二种形状；Shape_3为O形；Shape_4为T型；Shape_5为S型的第一种形状；
//Shape_6为S型的第二种形状；Shape_7为I型；
//颜色依次为deep_blue，light_blue，red，deep_yellow，purple，green，light_yellow；
int board[18][14];
int Shape_1[4][3][3] = { {{1,0,0},{1,1,1},{0,0,0}},{{0,1,1},{0,1,0},{0,1,0}},{{0,0,0},{1,1,1},{0,0,1}},{{0,1,0},{0,1,0},{1,1,0}} };
int Shape_2[4][3][3] = { {{0,0,2},{2,2,2},{0,0,0}},{{0,2,0},{0,2,0},{0,2,2}},{{0,0,0},{2,2,2},{2,0,0}},{{2,2,0},{0,2,0},{0,2,0}} };
int Shape_3[2][2] = { {3,3},{3,3} };
int Shape_4[4][3][3] = { {{0,4,0},{4,4,4},{0,0,0}},{{0,4,0},{0,4,4},{0,4,0}},{{0,0,0},{4,4,4},{0,4,0}},{{0,4,0},{4,4,0},{0,4,0}} };
int Shape_5[4][3][3] = { {{0,5,5},{5,5,0},{0,0,0}},{{0,5,0},{0,5,5},{0,0,5}},{{0,0,0},{0,5,5},{5,5,0}},{{5,0,0},{5,5,0},{0,5,0}} };
int Shape_6[4][3][3] = { {{6,6,0},{0,6,6},{0,0,0}},{{0,0,6},{0,6,6},{0,6,0}},{{0,0,0},{6,6,0},{0,6,6}},{{0,6,0},{6,6,0},{6,0,0}} };
int Shape_7[4][4][4] = { {{0,7,0,0},{0,7,0,0},{0,7,0,0},{0,7,0,0}},{{0,0,0,0},{7,7,7,7},{0,0,0,0},{0,0,0,0}},{{0,0,7,0},{0,0,7,0},{0,0,7,0},{0,0,7,0}},{{0,0,0,0},{0,0,0,0},{7,7,7,7},{0,0,0,0}} };
int main_menu()
{
	setbkmode(TRANSPARENT);
	IMAGE menu, title, titleWhenClicked;
	loadimage(&menu, ".\\相关图片\\menu.jpg", 480, 640);
	loadimage(&title, ".\\相关图片\\title.jpg", 220, 40);
	loadimage(&titleWhenClicked, ".\\相关图片\\titleWhenClicked.jpg", 220, 40);
	putimage(0, 0, &menu);
	putimage(130, 225, &title);
	putimage(130, 275, &title);
	putimage(130, 325, &title);
	settextcolor(BLUE);
	settextstyle(40, 0, "宋体");
	outtextxy(130, 225, "开 始 游 戏");
	outtextxy(130, 275, "   帮 助   ");
	outtextxy(130, 325, "   退 出   ");
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 130 && m.x < 350 && m.y > 225 && m.y < 265)
		{
			settextcolor(RED);
			putimage(130, 225, &titleWhenClicked);
			outtextxy(130, 225, "开 始 游 戏");
			Sleep(100);
			putimage(130, 225, &title);
			outtextxy(130, 225, "开 始 游 戏");
			Sleep(100);
			return 1;
		}
		else if (m.uMsg == WM_LBUTTONDOWN && m.x > 130 && m.x < 350 && m.y > 275 && m.y < 315)
		{
			settextcolor(RED);
			putimage(130, 275, &titleWhenClicked);
			outtextxy(130, 275, "   帮 助   ");
			Sleep(100);
			putimage(130, 275, &title);
			outtextxy(130, 275, "   帮 助   ");
			Sleep(100);
			return 2;
		}
		else if (m.uMsg == WM_LBUTTONDOWN && m.x > 130 && m.x < 350 && m.y > 325 && m.y < 365)
		{
			settextcolor(RED);
			putimage(130, 325, &titleWhenClicked);
			outtextxy(130, 325, "   退 出   ");
			Sleep(100);
			putimage(130, 325, &title);
			outtextxy(130, 325, "   退 出   ");
			Sleep(100);
			return 3;
		}
		else if (m.x > 130 && m.x < 350 && m.y > 225 && m.y < 265)
		{
			settextcolor(RED);
			outtextxy(130, 225, "开 始 游 戏");
		}
		else if (m.x > 130 && m.x < 350 && m.y > 275 && m.y < 315)
		{
			settextcolor(RED);
			outtextxy(130, 275, "   帮 助   ");
		}
		else if (m.x > 130 && m.x < 350 && m.y > 325 && m.y < 365)
		{
			settextcolor(RED);
			outtextxy(130, 325, "   退 出   ");
		}
		else
		{
			settextcolor(BLUE);
			outtextxy(130, 225, "开 始 游 戏");
			outtextxy(130, 275, "   帮 助   ");
			outtextxy(130, 325, "   退 出   ");
		}
	}
}
void help()
{
	setbkmode(TRANSPARENT);
	IMAGE menu, message_box, title, titleWhenClicked;
	loadimage(&menu, ".\\相关图片\\menu.jpg", 480, 640);
	loadimage(&message_box, ".\\相关图片\\message_box.jpg", 380, 500);
	loadimage(&title, ".\\相关图片\\title.jpg", 220, 40);
	loadimage(&titleWhenClicked, ".\\相关图片\\titleWhenClicked.jpg", 220, 40);
	putimage(0, 0, &menu);
	putimage(50, 50, &message_box);
	putimage(130, 490, &title);
	settextcolor(BLUE);
	settextstyle(40, 0, "宋体");
	outtextxy(200, 490, "返回");
	settextstyle(50, 0, "宋体");
	outtextxy(190, 60, "帮助");
	settextcolor(BLACK);
	settextstyle(30, 0, "宋体");
	Sleep(500);
	outtextxy(50, 110, "   使用键盘来操作游戏，按");
	Sleep(500);
	outtextxy(50, 145, " J键向左移动，按L键向右");
	Sleep(500);
	outtextxy(50, 180, " 移动，按I键旋转方块，按");
	Sleep(500);
	outtextxy(50, 215, " K键加速下落，按Q键暂停。");
	Sleep(500);
	outtextxy(50, 250, "   每当排列成完整的一行后");
	Sleep(500);
	outtextxy(50, 285, " ，这行方块将会自动消除，");
	Sleep(500);
	outtextxy(50, 320, " 同时玩家获得一定分数奖励");
	Sleep(500);
	outtextxy(50, 355, " 。而未被消除的方块会堆叠");
	Sleep(500);
	outtextxy(50, 390, " 起来，一旦堆到屏幕顶端，");
	Sleep(500);
	outtextxy(50, 425, " 游戏便会失败。");
	settextstyle(40, 0, "宋体");
	FlushMouseMsgBuffer();
	while (1)
	{
		MOUSEMSG m;
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN && m.x > 130 && m.x < 350 && m.y > 490 && m.y < 530)
		{
			settextcolor(RED);
			putimage(130, 490, &titleWhenClicked);
			outtextxy(200, 490, "返回");
			Sleep(100);
			putimage(130, 490, &title);
			outtextxy(200, 490, "返回");
			Sleep(100);
			return;
		}
		else if (m.x > 130 && m.x < 350 && m.y > 490 && m.y < 530)
		{
			settextcolor(RED);
			outtextxy(200, 490, "返回");
		}
		else
		{
			settextcolor(BLUE);
			outtextxy(200, 490, "返回");
		}
	}
}
void exit()
{
	setbkmode(TRANSPARENT);
	IMAGE menu, title;
	loadimage(&menu, ".\\相关图片\\menu.jpg", 480, 640);
	loadimage(&title, ".\\相关图片\\title.jpg", 220, 40);
	putimage(0, 0, &menu);
	settextcolor(BLUE);
	settextstyle(40, 0, "宋体");
	putimage(130, 300, &title);
	outtextxy(160, 300, "游戏结束");
	Sleep(1000);
}
void board_reprint(int board[18][14])
{
	IMAGE deep_blue, light_blue, red, deep_yellow, purple, green, light_yellow, white;
	loadimage(&deep_blue, ".\\相关图片\\deep_blue.jpg", 30, 30);
	loadimage(&light_blue, ".\\相关图片\\light_blue.jpg", 30, 30);
	loadimage(&red, ".\\相关图片\\red.jpg", 30, 30);
	loadimage(&deep_yellow, ".\\相关图片\\deep_yellow.jpg", 30, 30);
	loadimage(&purple, ".\\相关图片\\purple.jpg", 30, 30);
	loadimage(&green, ".\\相关图片\\green.jpg", 30, 30);
	loadimage(&light_yellow, ".\\相关图片\\light_yellow.jpg", 30, 30);
	loadimage(&white, ".\\相关图片\\white.jpg", 30, 30);
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			int x = 30 + j * 30;
			int y = 95 + i * 30;
			switch (board[i][j])
			{
				case 0: putimage(x, y, &white); break;
				case 1: putimage(x, y, &deep_blue); break;
				case 2: putimage(x, y, &light_blue); break;
				case 3: putimage(x, y, &red); break;
				case 4: putimage(x, y, &deep_yellow); break;
				case 5: putimage(x, y, &purple); break;
				case 6: putimage(x, y, &green); break;
				case 7: putimage(x, y, &light_yellow); break;
			}
		}
	}
}
int line_erase(int board[18][14])
{
	int sum = 0;
	again:
	for (int i = 0; i < 18; i++)
	{
		bool judge = true;
		for (int j = 0; j < 14; j++)
		{
			if (!board[i][j])
			{
				judge = false;
				break;
			}
		}
		if (judge)
		{
			sum++;
			for (int I = i; I >= 1; I--)
			{
				for (int J = 0; J < 14; J++)
				{
					board[I][J] = board[I - 1][J];
				}
			}
			for (int k = 0; k < 14; k++)
			{
				board[0][k] = 0;
			}
			goto again;
		}
	}
	return sum;
}
void initial_print()
{
	IMAGE background, white;
	loadimage(&background, ".\\相关图片\\background.jpg", 480, 640);
	loadimage(&white, ".\\相关图片\\white.jpg", 30, 30);
	putimage(0, 0, &background);
	for (int i = 0; i < 18; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			int x = 30 + j * 30;
			int y = 95 + i * 30;
			putimage(x, y, &white);
		}
	}
}
bool available_Shape1_moveLeft(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_1[condition % 4][i][j])
			{
				if (x + j * 30 - 30 < 30)
					return false;
				if (x + j * 30 - 30 >= 30 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 - 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape2_moveLeft(int x, int y,int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_2[condition % 4][i][j])
			{
				if (x + j * 30 - 30 < 30)
					return false;
				if (x + j * 30 - 30 >= 30 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 - 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape3_moveLeft(int x, int y)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (Shape_3[i][j])
			{
				if (x + j * 30 - 30 < 30)
					return false;
				if (x + j * 30 - 30 >= 30 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 - 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape4_moveLeft(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_4[condition % 4][i][j])
			{
				if (x + j * 30 - 30 < 30)
					return false;
				if (x + j * 30 - 30 >= 30 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 - 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape5_moveLeft(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_5[condition % 4][i][j])
			{
				if (x + j * 30 - 30 < 30)
					return false;
				if (x + j * 30 - 30 >= 30 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 - 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape6_moveLeft(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_6[condition % 4][i][j])
			{
				if (x + j * 30 - 30 < 30)
					return false;
				if (x + j * 30 - 30 >= 30 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 - 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape7_moveLeft(int x, int y, int condition)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Shape_7[condition % 4][i][j])
			{
				if (x + j * 30 - 30 < 30)
					return false;
				if (x + j * 30 - 30 >= 30 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 - 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape1_moveRight(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (Shape_1[condition % 4][i][j])
			{
				if (x + j * 30 + 30 > 420)
					return false;
				if (x + j * 30 + 30 <= 420 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 + 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape2_moveRight(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (Shape_2[condition%4][i][j])
			{
				if (x + j * 30 + 30 > 420)
					return false;
				if (x + j * 30 + 30 <= 420 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 + 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape3_moveRight(int x, int y)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j >= 0; j--)
		{
			if (Shape_3[i][j])
			{
				if (x + j * 30 + 30 > 420)
					return false;
				if (x + j * 30 + 30 <= 420 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 + 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape4_moveRight(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (Shape_4[condition % 4][i][j])
			{
				if (x + j * 30 + 30 > 420)
					return false;
				if (x + j * 30 + 30 <= 420 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 + 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape5_moveRight(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (Shape_5[condition % 4][i][j])
			{
				if (x + j * 30 + 30 > 420)
					return false;
				if (x + j * 30 + 30 <= 420 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 + 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape6_moveRight(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			if (Shape_6[condition % 4][i][j])
			{
				if (x + j * 30 + 30 > 420)
					return false;
				if (x + j * 30 + 30 <= 420 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 + 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape7_moveRight(int x, int y, int condition)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j >= 0; j--)
		{
			if (Shape_7[condition % 4][i][j])
			{
				if (x + j * 30 + 30 > 420)
					return false;
				if (x + j * 30 + 30 <= 420 && board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30 + 1])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape1_moveDown(int x, int y, int condition)
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (Shape_1[condition % 4][i][j])
			{
				if (y + i * 30 + 30 > 605)
					return false;
				if (y + i * 30 + 30 <= 605 && board[(y + i * 30 - 95) / 30 + 1][(x + j * 30 - 30) / 30])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape2_moveDown(int x, int y, int condition)
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (Shape_2[condition % 4][i][j])
			{
				if (y + i * 30 + 30 > 605)
					return false;
				if (y + i * 30 + 30 <= 605 && board[(y + i * 30 - 95) / 30 + 1][(x + j * 30 - 30) / 30])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape3_moveDown(int x, int y)
{
	for (int j = 0; j < 2; j++)
	{
		for (int i = 1; i >= 0; i--)
		{
			if (Shape_3[i][j])
			{
				if (y + i * 30 + 30 > 605)
					return false;
				if (y + i * 30 + 30 <= 605 && board[(y + i * 30 - 95) / 30 + 1][(x + j * 30 - 30) / 30])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape4_moveDown(int x, int y, int condition)
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (Shape_4[condition % 4][i][j])
			{
				if (y + i * 30 + 30 > 605)
					return false;
				if (y + i * 30 + 30 <= 605 && board[(y + i * 30 - 95) / 30 + 1][(x + j * 30 - 30) / 30])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape5_moveDown(int x, int y, int condition)
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (Shape_5[condition % 4][i][j])
			{
				if (y + i * 30 + 30 > 605)
					return false;
				if (y + i * 30 + 30 <= 605 && board[(y + i * 30 - 95) / 30 + 1][(x + j * 30 - 30) / 30])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape6_moveDown(int x, int y, int condition)
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 2; i >= 0; i--)
		{
			if (Shape_6[condition % 4][i][j])
			{
				if (y + i * 30 + 30 > 605)
					return false;
				if (y + i * 30 + 30 <= 605 && board[(y + i * 30 - 95) / 30 + 1][(x + j * 30 - 30) / 30])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape7_moveDown(int x, int y, int condition)
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i >= 0; i--)
		{
			if (Shape_7[condition % 4][i][j])
			{
				if (y + i * 30 + 30 > 605)
					return false;
				if (y + i * 30 + 30 <= 605 && board[(y + i * 30 - 95) / 30 + 1][(x + j * 30 - 30) / 30])
					return false;
				break;
			}
		}
	}
	return true;
}
bool available_Shape1_rotate(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_1[(condition + 1) % 4][i][j])
			{
				if ((x + j * 30) < 30 || (x + j * 30) > 420 || (y + i * 30) < 95 || (y + i * 30) > 605)
					return false;
				if (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					return false;
			}
		}
	}
}
bool available_Shape2_rotate(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_2[(condition + 1) % 4][i][j])
			{
				if ((x + j * 30) < 30 || (x + j * 30) > 420 || (y + i * 30) < 95 || (y + i * 30) > 605)
					return false;
				if (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					return false;
			}
		}
	}
}
bool available_Shape4_rotate(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_4[(condition + 1) % 4][i][j])
			{
				if ((x + j * 30) < 30 || (x + j * 30) > 420 || (y + i * 30) < 95 || (y + i * 30) > 605)
					return false;
				if (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					return false;
			}
		}
	}
}
bool available_Shape5_rotate(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_5[(condition + 1) % 4][i][j])
			{
				if ((x + j * 30) < 30 || (x + j * 30) > 420 || (y + i * 30) < 95 || (y + i * 30) > 605)
					return false;
				if (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					return false;
			}
		}
	}
}
bool available_Shape6_rotate(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_6[(condition + 1) % 4][i][j])
			{
				if ((x + j * 30) < 30 || (x + j * 30) > 420 || (y + i * 30) < 95 || (y + i * 30) > 605)
					return false;
				if (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					return false;
			}
		}
	}
}
bool available_Shape7_rotate(int x, int y, int condition)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Shape_7[(condition + 1) % 4][i][j])
			{
				if ((x + j * 30) < 30 || (x + j * 30) > 420 || (y + i * 30) < 95 || (y + i * 30) > 605)
					return false;
				if (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					return false;
			}
		}
	}
}
void Shape1_print(int x, int y, int condition)
{
	IMAGE deep_blue, light_blue, red, deep_yellow, purple, green, light_yellow, white;
	loadimage(&deep_blue, ".\\相关图片\\deep_blue.jpg", 30, 30);
	loadimage(&light_blue, ".\\相关图片\\light_blue.jpg", 30, 30);
	loadimage(&red, ".\\相关图片\\red.jpg", 30, 30);
	loadimage(&deep_yellow, ".\\相关图片\\deep_yellow.jpg", 30, 30);
	loadimage(&purple, ".\\相关图片\\purple.jpg", 30, 30);
	loadimage(&green, ".\\相关图片\\green.jpg", 30, 30);
	loadimage(&light_yellow, ".\\相关图片\\light_yellow.jpg", 30, 30);
	loadimage(&white, ".\\相关图片\\white.jpg", 30, 30);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (x + j * 30 >= 30 && x + j * 30 <= 420 && y + i * 30 >= 95 && y + i * 30 <= 605)
			{
				if (Shape_1[condition % 4][i][j])
				{
					putimage(x + j * 30, y + i * 30, &deep_blue);
				}
				else
				{
					switch (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					{
					case 0:putimage(x + j * 30, y + i * 30, &white); break;
					case 1:putimage(x + j * 30, y + i * 30, &deep_blue); break;
					case 2:putimage(x + j * 30, y + i * 30, &light_blue); break;
					case 3:putimage(x + j * 30, y + i * 30, &red); break;
					case 4:putimage(x + j * 30, y + i * 30, &deep_yellow); break;
					case 5:putimage(x + j * 30, y + i * 30, &purple); break;
					case 6:putimage(x + j * 30, y + i * 30, &green); break;
					case 7:putimage(x + j * 30, y + i * 30, &light_yellow); break;
					}
				}
			}
		}
	}
}
void Shape2_print(int x, int y, int condition)
{
	IMAGE deep_blue, light_blue, red, deep_yellow, purple, green, light_yellow, white;
	loadimage(&deep_blue, ".\\相关图片\\deep_blue.jpg", 30, 30);
	loadimage(&light_blue, ".\\相关图片\\light_blue.jpg", 30, 30);
	loadimage(&red, ".\\相关图片\\red.jpg", 30, 30);
	loadimage(&deep_yellow, ".\\相关图片\\deep_yellow.jpg", 30, 30);
	loadimage(&purple, ".\\相关图片\\purple.jpg", 30, 30);
	loadimage(&green, ".\\相关图片\\green.jpg", 30, 30);
	loadimage(&light_yellow, ".\\相关图片\\light_yellow.jpg", 30, 30);
	loadimage(&white, ".\\相关图片\\white.jpg", 30, 30);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (x + j * 30 >= 30 && x + j * 30 <= 420 && y + i * 30 >= 95 && y + i * 30 <= 605)
			{
				if (Shape_2[condition % 4][i][j])
				{
					putimage(x + j * 30, y + i * 30, &light_blue);
				}
				else
				{
					switch (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					{
					case 0:putimage(x + j * 30, y + i * 30, &white); break;
					case 1:putimage(x + j * 30, y + i * 30, &deep_blue); break;
					case 2:putimage(x + j * 30, y + i * 30, &light_blue); break;
					case 3:putimage(x + j * 30, y + i * 30, &red); break;
					case 4:putimage(x + j * 30, y + i * 30, &deep_yellow); break;
					case 5:putimage(x + j * 30, y + i * 30, &purple); break;
					case 6:putimage(x + j * 30, y + i * 30, &green); break;
					case 7:putimage(x + j * 30, y + i * 30, &light_yellow); break;
					}
				}
			}
		}
	}
}
void Shape3_print(int x, int y)
{
	IMAGE red;
	loadimage(&red, ".\\相关图片\\red.jpg", 30, 30);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (x + j * 30 >= 30 && x + j * 30 <= 420 && y + i * 30 >= 95 && y + i * 30 <= 605)
			{
				putimage(x + j * 30, y + i * 30, &red);
			}			
		}
	}
}
void Shape4_print(int x, int y, int condition)
{
	IMAGE deep_blue, light_blue, red, deep_yellow, purple, green, light_yellow, white;
	loadimage(&deep_blue, ".\\相关图片\\deep_blue.jpg", 30, 30);
	loadimage(&light_blue, ".\\相关图片\\light_blue.jpg", 30, 30);
	loadimage(&red, ".\\相关图片\\red.jpg", 30, 30);
	loadimage(&deep_yellow, ".\\相关图片\\deep_yellow.jpg", 30, 30);
	loadimage(&purple, ".\\相关图片\\purple.jpg", 30, 30);
	loadimage(&green, ".\\相关图片\\green.jpg", 30, 30);
	loadimage(&light_yellow, ".\\相关图片\\light_yellow.jpg", 30, 30);
	loadimage(&white, ".\\相关图片\\white.jpg", 30, 30);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (x + j * 30 >= 30 && x + j * 30 <= 420 && y + i * 30 >= 95 && y + i * 30 <= 605)
			{
				if (Shape_4[condition % 4][i][j])
				{
					putimage(x + j * 30, y + i * 30, &deep_yellow);
				}
				else
				{
					switch (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					{
					case 0:putimage(x + j * 30, y + i * 30, &white); break;
					case 1:putimage(x + j * 30, y + i * 30, &deep_blue); break;
					case 2:putimage(x + j * 30, y + i * 30, &light_blue); break;
					case 3:putimage(x + j * 30, y + i * 30, &red); break;
					case 4:putimage(x + j * 30, y + i * 30, &deep_yellow); break;
					case 5:putimage(x + j * 30, y + i * 30, &purple); break;
					case 6:putimage(x + j * 30, y + i * 30, &green); break;
					case 7:putimage(x + j * 30, y + i * 30, &light_yellow); break;
					}
				}
			}
		}
	}
}
void Shape5_print(int x, int y, int condition)
{
	IMAGE deep_blue, light_blue, red, deep_yellow, purple, green, light_yellow, white;
	loadimage(&deep_blue, ".\\相关图片\\deep_blue.jpg", 30, 30);
	loadimage(&light_blue, ".\\相关图片\\light_blue.jpg", 30, 30);
	loadimage(&red, ".\\相关图片\\red.jpg", 30, 30);
	loadimage(&deep_yellow, ".\\相关图片\\deep_yellow.jpg", 30, 30);
	loadimage(&purple, ".\\相关图片\\purple.jpg", 30, 30);
	loadimage(&green, ".\\相关图片\\green.jpg", 30, 30);
	loadimage(&light_yellow, ".\\相关图片\\light_yellow.jpg", 30, 30);
	loadimage(&white, ".\\相关图片\\white.jpg", 30, 30);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (x + j * 30 >= 30 && x + j * 30 <= 420 && y + i * 30 >= 95 && y + i * 30 <= 605)
			{
				if (Shape_5[condition % 4][i][j])
				{
					putimage(x + j * 30, y + i * 30, &purple);
				}
				else
				{
					switch (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					{
					case 0:putimage(x + j * 30, y + i * 30, &white); break;
					case 1:putimage(x + j * 30, y + i * 30, &deep_blue); break;
					case 2:putimage(x + j * 30, y + i * 30, &light_blue); break;
					case 3:putimage(x + j * 30, y + i * 30, &red); break;
					case 4:putimage(x + j * 30, y + i * 30, &deep_yellow); break;
					case 5:putimage(x + j * 30, y + i * 30, &purple); break;
					case 6:putimage(x + j * 30, y + i * 30, &green); break;
					case 7:putimage(x + j * 30, y + i * 30, &light_yellow); break;
					}
				}
			}
		}
	}
}
void Shape6_print(int x, int y, int condition)
{
	IMAGE deep_blue, light_blue, red, deep_yellow, purple, green, light_yellow, white;
	loadimage(&deep_blue, ".\\相关图片\\deep_blue.jpg", 30, 30);
	loadimage(&light_blue, ".\\相关图片\\light_blue.jpg", 30, 30);
	loadimage(&red, ".\\相关图片\\red.jpg", 30, 30);
	loadimage(&deep_yellow, ".\\相关图片\\deep_yellow.jpg", 30, 30);
	loadimage(&purple, ".\\相关图片\\purple.jpg", 30, 30);
	loadimage(&green, ".\\相关图片\\green.jpg", 30, 30);
	loadimage(&light_yellow, ".\\相关图片\\light_yellow.jpg", 30, 30);
	loadimage(&white, ".\\相关图片\\white.jpg", 30, 30);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (x + j * 30 >= 30 && x + j * 30 <= 420 && y + i * 30 >= 95 && y + i * 30 <= 605)
			{
				if (Shape_6[condition % 4][i][j])
				{
					putimage(x + j * 30, y + i * 30, &green);
				}
				else
				{
					switch (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					{
					case 0:putimage(x + j * 30, y + i * 30, &white); break;
					case 1:putimage(x + j * 30, y + i * 30, &deep_blue); break;
					case 2:putimage(x + j * 30, y + i * 30, &light_blue); break;
					case 3:putimage(x + j * 30, y + i * 30, &red); break;
					case 4:putimage(x + j * 30, y + i * 30, &deep_yellow); break;
					case 5:putimage(x + j * 30, y + i * 30, &purple); break;
					case 6:putimage(x + j * 30, y + i * 30, &green); break;
					case 7:putimage(x + j * 30, y + i * 30, &light_yellow); break;
					}
				}
			}
		}
	}
}
void Shape7_print(int x, int y, int condition)
{
	IMAGE deep_blue, light_blue, red, deep_yellow, purple, green, light_yellow, white;
	loadimage(&deep_blue, ".\\相关图片\\deep_blue.jpg", 30, 30);
	loadimage(&light_blue, ".\\相关图片\\light_blue.jpg", 30, 30);
	loadimage(&red, ".\\相关图片\\red.jpg", 30, 30);
	loadimage(&deep_yellow, ".\\相关图片\\deep_yellow.jpg", 30, 30);
	loadimage(&purple, ".\\相关图片\\purple.jpg", 30, 30);
	loadimage(&green, ".\\相关图片\\green.jpg", 30, 30);
	loadimage(&light_yellow, ".\\相关图片\\light_yellow.jpg", 30, 30);
	loadimage(&white, ".\\相关图片\\white.jpg", 30, 30);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (x + j * 30 >= 30 && x + j * 30 <= 420 && y + i * 30 >= 95 && y + i * 30 <= 605)
			{
				if (Shape_7[condition % 4][i][j])
				{
					putimage(x + j * 30, y + i * 30, &light_yellow);
				}
				else
				{
					switch (board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30])
					{
					case 0:putimage(x + j * 30, y + i * 30, &white); break;
					case 1:putimage(x + j * 30, y + i * 30, &deep_blue); break;
					case 2:putimage(x + j * 30, y + i * 30, &light_blue); break;
					case 3:putimage(x + j * 30, y + i * 30, &red); break;
					case 4:putimage(x + j * 30, y + i * 30, &deep_yellow); break;
					case 5:putimage(x + j * 30, y + i * 30, &purple); break;
					case 6:putimage(x + j * 30, y + i * 30, &green); break;
					case 7:putimage(x + j * 30, y + i * 30, &light_yellow); break;
					}
				}
			}
		}
	}
}
void record_Shape1_position(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_1[condition % 4][i][j] && y + i * 30 >= 95)
			{
				board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30] = 1;
			}
		}
	}
}
void record_Shape2_position(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_2[condition % 4][i][j] && y + i * 30 >= 95)
			{
				board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30] = 2;
			}
		}
	}
}
void record_Shape3_position(int x, int y)
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (y + i * 30 >= 95)
			{
				board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30] = 3;
			}			
		}
	}
}
void record_Shape4_position(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_4[condition % 4][i][j] && y + i * 30 >= 95)
			{
				board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30] = 4;
			}
		}
	}
}
void record_Shape5_position(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_5[condition % 4][i][j] && y + i * 30 >= 95)
			{
				board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30] = 5;
			}
		}
	}
}
void record_Shape6_position(int x, int y, int condition)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Shape_6[condition % 4][i][j] && y + i * 30 >= 95)
			{
				board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30] = 6;
			}
		}
	}
}
void record_Shape7_position(int x, int y, int condition)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (Shape_7[condition % 4][i][j] && y + i * 30 >= 95)
			{
				board[(y + i * 30 - 95) / 30][(x + j * 30 - 30) / 30] = 7;
			}
		}
	}
}
bool is_gameover(int board[18][14])
{
	for (int j = 0; j < 14; j++)
	{
		if (board[0][j])
			return true;
	}
	return false;
}
void paint_next(int shape)
{
	IMAGE deep_blue, light_blue, red, deep_yellow, purple, green, light_yellow;
	loadimage(&deep_blue, ".\\相关图片\\deep_blue.jpg", 30, 30);
	loadimage(&light_blue, ".\\相关图片\\light_blue.jpg", 30, 30);
	loadimage(&red, ".\\相关图片\\red.jpg", 30, 30);
	loadimage(&deep_yellow, ".\\相关图片\\deep_yellow.jpg", 30, 30);
	loadimage(&purple, ".\\相关图片\\purple.jpg", 30, 30);
	loadimage(&green, ".\\相关图片\\green.jpg", 30, 30);
	loadimage(&light_yellow, ".\\相关图片\\light_yellow.jpg", 30, 30);
	switch (shape)
	{
	case 1:
		putimage(350, 10, &deep_blue);
		putimage(350, 40, &deep_blue);
		putimage(380, 40, &deep_blue);
		putimage(410, 40, &deep_blue);
		break;
	case 2:
		putimage(410, 10, &light_blue);
		putimage(350, 40, &light_blue);
		putimage(380, 40, &light_blue);
		putimage(410, 40, &light_blue);
		break;
	case 3:
		putimage(350, 10, &red);
		putimage(380, 10, &red);
		putimage(350, 40, &red);
		putimage(380, 40, &red);
		break;
	case 4:
		putimage(350, 40, &deep_yellow);
		putimage(380, 10, &deep_yellow);
		putimage(380, 40, &deep_yellow);
		putimage(410, 40, &deep_yellow);
		break;
	case 5:
		putimage(350, 40, &purple);
		putimage(380, 40, &purple);
		putimage(380, 10, &purple);
		putimage(410, 10, &purple);
		break;
	case 6:
		putimage(350, 10, &green);
		putimage(380, 10, &green);
		putimage(380, 40, &green);
		putimage(410, 40, &green);
		break;
	case 7:
		putimage(350, 40, &light_yellow);
		putimage(380, 40, &light_yellow);
		putimage(410, 40, &light_yellow);
		putimage(440, 40, &light_yellow);
		break;
	}
}
void game_over()
{
	IMAGE title;
	loadimage(&title, ".\\相关图片\\title.jpg", 220, 40);
	settextcolor(BLUE);
	settextstyle(40, 0, "宋体");
	putimage(130, 300, &title);
	outtextxy(160, 300, "游戏失败");
	Sleep(2000);
}
void level_up()
{
	IMAGE level_up_1;
	IMAGE level_up_2;
	IMAGE level_up_3;
	IMAGE level_up_4;
	IMAGE temp;
	loadimage(&level_up_1, ".\\相关图片\\level_up_1.jpg", 300, 100);
	loadimage(&level_up_2, ".\\相关图片\\level_up_2.jpg", 300, 100);
	loadimage(&level_up_3, ".\\相关图片\\level_up_3.jpg", 300, 100);
	loadimage(&level_up_4, ".\\相关图片\\level_up_4.jpg", 300, 100);
	getimage(&temp, 90, 270, 300, 100);
	putimage(90, 270, &level_up_4);
	Sleep(50);
	putimage(90, 270, &level_up_3);
	Sleep(50);
	putimage(90, 270, &level_up_2);
	Sleep(50);
	putimage(90, 270, &level_up_1);
	Sleep(1000);
	putimage(90, 270, &level_up_2);
	Sleep(50);
	putimage(90, 270, &level_up_3);
	Sleep(50);
	putimage(90, 270, &level_up_4);
	Sleep(50);
	putimage(90, 270, &temp);
}
void play()
{
	memset(board, 0, sizeof(board));
	initial_print();
	IMAGE background;
	loadimage(&background, ".\\相关图片\\background.jpg", 480, 640);
	IMAGE next;
	getimage(&next, 350, 10, 120, 60);
	int score = 0;
	int level = 1;
	int best_score;
	FILE *fp = fopen(".\\相关文档\\best_score.txt", "r");
	fscanf(fp, "%d", &best_score);
	fclose(fp);
	TCHAR Best_score[8];
	TCHAR Score[8];
	TCHAR Level[2];
	_stprintf(Best_score, _T("%d"), best_score);
	_stprintf(Score, _T("%d"), score);
	_stprintf(Level, _T("%d"), level);
	settextcolor(RED);
	settextstyle(30, 0, "宋体");
	outtextxy(10, 0, "Record:");
	outtextxy(10, 30, "Score:");
	outtextxy(10, 60, "Level:");
	outtextxy(120, 0, Best_score);
	outtextxy(100, 30, Score);
	outtextxy(100, 60, Level);
	outtextxy(250, 0, "Next:");
	int shape_1 = rand() % 7 + 1;
	int shape_2 = shape_1;
	int sleep_time;
	while (1)
	{
		shape_1 = shape_2;
		shape_2 = rand() % 7 + 1;
		putimage(350, 10, &next);
		paint_next(shape_2);
		sleep_time = max(100 - level * 10, 10);///////改变初始下落速度
		int x = (rand() % 11 + 1) * 30;
		int y = 35;
		int condition = rand() % 4;
		int count = 0;
		char choice='0';
		bool available_left = false;
		bool available_right = false;
		bool available_rotate = false;
		bool available_down = false;
		int length;
		if (shape_1 == 3) length = 2;
		else if (shape_1 == 7) length = 4;
		else length = 3;
		IMAGE current_situation;
		getimage(&current_situation, 30, 95, 420, 540);
		while (1)
		{
			available_left = false;
			available_right = false;
			available_rotate = false;
			available_down = false;
			count++;
			if ((choice == 'j'|| choice == 'l' || choice == 'i') || count == 6)
			{
				putimage(30, 95, &current_situation);
				if (count == 6)
				{
					count = 1;
				}
			}				
			choice = '0';
			switch (shape_1)
			{
				case 1:Shape1_print(x, y, condition); break;
				case 2:Shape2_print(x, y, condition); break;
				case 3:Shape3_print(x, y); break;
				case 4:Shape4_print(x, y, condition); break;
				case 5:Shape5_print(x, y, condition); break;
				case 6:Shape6_print(x, y, condition); break;
				case 7:Shape7_print(x, y, condition); break;
			}
			if (_kbhit())
			{
				choice = _getch();
				switch (choice)
				{
				case 'j': 
					switch (shape_1)
					{
						case 1:available_left = available_Shape1_moveLeft(x, y, condition); break;
						case 2:available_left = available_Shape2_moveLeft(x, y, condition); break;
						case 3:available_left = available_Shape3_moveLeft(x, y); break;
						case 4:available_left = available_Shape4_moveLeft(x, y, condition); break;
						case 5:available_left = available_Shape5_moveLeft(x, y, condition); break;
						case 6:available_left = available_Shape6_moveLeft(x, y, condition); break;
						case 7:available_left = available_Shape7_moveLeft(x, y, condition); break;
					}
					if (available_left) x -= 30; break;
				case 'l': 
					switch (shape_1)
					{
						case 1:available_right = available_Shape1_moveRight(x, y, condition); break;
						case 2:available_right = available_Shape2_moveRight(x, y, condition); break;
						case 3:available_right = available_Shape3_moveRight(x, y); break;
						case 4:available_right = available_Shape4_moveRight(x, y, condition); break;
						case 5:available_right = available_Shape5_moveRight(x, y, condition); break;
						case 6:available_right = available_Shape6_moveRight(x, y, condition); break;
						case 7:available_right = available_Shape7_moveRight(x, y, condition); break;
					}
					if (available_right) x += 30; break;
				case 'i': 
					switch (shape_1)
					{
					case 1:available_rotate = available_Shape1_rotate(x, y, condition); break;
					case 2:available_rotate = available_Shape2_rotate(x, y, condition); break;
					case 3:break;
					case 4:available_rotate = available_Shape4_rotate(x, y, condition); break;
					case 5:available_rotate = available_Shape5_rotate(x, y, condition); break;
					case 6:available_rotate = available_Shape6_rotate(x, y, condition); break;
					case 7:available_rotate = available_Shape7_rotate(x, y, condition); break;
					}
					if (available_rotate) condition++; break;
				case 'k':
					sleep_time = 5;
					break;
				case 'q':
					IMAGE pause;
					getimage(&pause, 190, 60, 100, 60);
					settextcolor(BLACK);
					settextstyle(30, 0, "宋体");
					outtextxy(195, 60, "已暂停");
					while (1)
					{
						if (_kbhit())
						{
							char choice_2 = _getch();
							if (choice_2 == 'q')
							{
								putimage(190, 60, &pause);
								break;
							}
						}
					}
					break;
				}
			}
			Sleep(sleep_time);//控制方块下落速度，sleep_time越小，方块下落越快；
			if (count == 5)
			{
				switch (shape_1)
				{
					case 1:available_down = available_Shape1_moveDown(x, y, condition); break;
					case 2:available_down = available_Shape2_moveDown(x, y, condition); break;
					case 3:available_down = available_Shape3_moveDown(x, y); break;
					case 4:available_down = available_Shape4_moveDown(x, y, condition); break;
					case 5:available_down = available_Shape5_moveDown(x, y, condition); break;
					case 6:available_down = available_Shape6_moveDown(x, y, condition); break;
					case 7:available_down = available_Shape7_moveDown(x, y, condition); break;
				}
				if (available_down)
				{
					y += 30;
				}
				else
				{
					switch (shape_1)
					{
						case 1:record_Shape1_position(x, y, condition); break;
						case 2:record_Shape2_position(x, y, condition); break;
						case 3:record_Shape3_position(x, y); break;
						case 4:record_Shape4_position(x, y, condition); break;
						case 5:record_Shape5_position(x, y, condition); break;
						case 6:record_Shape6_position(x, y, condition); break;
						case 7:record_Shape7_position(x, y, condition); break;
					}
					board_reprint(board);
					if (is_gameover(board) == true)
					{
						FILE* fp = fopen(".\\相关文档\\best_score.txt", "w");
						fprintf(fp, "%d", best_score);
						fclose(fp);
						game_over();
						return;
					}
					int erase_sum = line_erase(board);
					int pre_level = level;
					if (erase_sum > 0)
					{
						Sleep(300);
						score += (10 * erase_sum)*erase_sum;
						if (score >= 200 && score < 400)
						{
							level = 2;
						}
						else if (score >= 400 && score < 700)
						{
							level = 3;
						}
						else if (score >= 700 && score < 1100)
						{
							level = 4;
						}
						else if (score >= 1100 && score < 1500)
						{
							level = 5;
						}
						else if (score >= 1500 && score < 2000)
						{
							level = 6;
						}
						else if (score >= 2000 && score < 2500)
						{
							level = 7;
						}
						else if (score >= 2500 && score < 3000)
						{
							level = 8;
						}
						else if (score >= 3600)
						{
							level = 9;
						}
						if (pre_level < level)
						{
							level_up();
						}
						best_score = max(best_score, score);
						putimage(0, 0, &background);
						board_reprint(board);
						TCHAR Best_score[8];
						TCHAR Score[8];
						TCHAR Level[2];
						_stprintf(Best_score, _T("%d"), best_score);
						_stprintf(Score, _T("%d"), score);
						_stprintf(Level, _T("%d"), level);
						settextcolor(RED);
						settextstyle(30, 0, "宋体");
						outtextxy(10, 0, "Record:");
						outtextxy(10, 30, "Score:");
						outtextxy(10, 60, "Level:");
						outtextxy(120, 0, Best_score);
						outtextxy(100, 30, Score);
						outtextxy(100, 60, Level);
						outtextxy(250, 0, "Next:");
					}
					break;
				}
			}
		}
	}
}
int main()
{
	initgraph(480, 640);
	srand(time(0));
	while (1)
	{
		int choice = main_menu();
		switch (choice)
		{
		case 1:play(); break;
		case 2:help(); break;
		case 3:exit(); return 0;
		}
	}
}