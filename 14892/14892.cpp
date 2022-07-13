#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string wheel[5];
int turn;
// 3시 index는 2, 9시 index는 6
int direction[5];

void turn_wheel(int wheel_num, int dir)
{
	direction[wheel_num] = dir;
	for (int i = wheel_num - 1; i >= 1; i--)
	{
		if (wheel[i][2] != wheel[i + 1][6])
		{
			direction[i] = -direction[i + 1];
		}
		else
			break;
	}
	for (int i = wheel_num + 1; i <= 4; i++)
	{
		if (wheel[i][6] != wheel[i - 1][2])
		{
			direction[i] = -direction[i - 1];
		}
		else
			break;
	}
	for (int i = 1; i <= 4; i++)
	{
		if (direction[i] == 0)continue;
		else
		{
			if (direction[i] == 1)
			{
				char temp = wheel[i][wheel[i].size() - 1];
				for (int j = wheel[i].size() - 1; j > 0; j--)
				{
					wheel[i][j] = wheel[i][j - 1];
				}
				wheel[i][0] = temp;
			}
			else if (direction[i] == -1)
			{
				char temp = wheel[i][0];
				for (int j = 1; j < wheel[i].size(); j++)
				{
					wheel[i][j - 1] = wheel[i][j];
				}
				wheel[i][wheel[i].size() - 1] = temp;
			}
		}
	}
}

int main()
{
	for (int i = 1; i <= 4; i++)
		cin >> wheel[i];
	cin >> turn;
	for (int i = 0; i < turn; i++)
	{
		memset(direction, 0, sizeof(direction));
		int wheel_num, dir;
		cin >> wheel_num >> dir;
		turn_wheel(wheel_num, dir);
	}
	int score = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (i == 1 && wheel[i][0] == '1')
			score++;
		else if (i == 2 && wheel[i][0] == '1')
			score += 2;
		else if (i == 3 && wheel[i][0] == '1')
			score += 4;
		else if (i == 4 && wheel[i][0] == '1')
			score += 8;
	}
	cout << score;
	
}