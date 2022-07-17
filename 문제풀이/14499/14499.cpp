#include <iostream>

using namespace std;

int n, m;
int x, y, k;
int map[21][21];
int dir;
int dice_row[3]; // 주사위 row 값들
int dice_col[4]; // 주사위 col 값들
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

int main()
{
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	for (int i = 0; i < k; i++)
	{
		cin >> dir;
		int ly = y + dy[dir];
		int lx = x + dx[dir];
		if (ly < 0 || lx < 0 || ly >= n || lx >= m)continue;
		if (dir == 1) // 동쪽
		{
			int temp = dice_row[0];
			dice_row[0] = dice_row[1];
			dice_row[1] = dice_row[2];
			dice_row[2] = dice_col[3];
			dice_col[3] = temp;
			dice_col[1] = dice_row[1];
		}
		else if (dir == 2) // 서쪽
		{
			int temp = dice_col[3];
			dice_col[3] = dice_row[2];
			dice_row[2] = dice_row[1];
			dice_row[1] = dice_row[0];
			dice_row[0] = temp;
			dice_col[1] = dice_row[1];
		}
		else if (dir == 3) // 북쪽
		{
			int temp = dice_col[3];
			dice_col[3] = dice_col[2];
			dice_col[2] = dice_col[1];
			dice_col[1] = dice_col[0];
			dice_col[0] = temp;
			dice_row[1] = dice_col[1];

		}
		else if (dir == 4) // 남쪽
		{

			int temp = dice_col[0];
			dice_col[0] = dice_col[1];
			dice_col[1] = dice_col[2];
			dice_col[2] = dice_col[3];
			dice_col[3] = temp;
			dice_row[1] = dice_col[1];

		}
		if (map[ly][lx] == 0) // map의 값이 0인 경우
			map[ly][lx] = dice_row[1];
		else // map의 값이 0이 아닌 경우
		{
			dice_row[1] = map[ly][lx];
			dice_col[1] = dice_row[1];
			map[ly][lx] = 0;
		}
		y = ly;
		x = lx;
		cout << dice_col[3] << endl; // 위에 있는 값 출력

	}
}