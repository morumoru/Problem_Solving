#include <iostream>

using namespace std;

int n, m;
int x, y, k;
int map[21][21];
int dir;
int dice_row[3]; // �ֻ��� row ����
int dice_col[4]; // �ֻ��� col ����
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
		if (dir == 1) // ����
		{
			int temp = dice_row[0];
			dice_row[0] = dice_row[1];
			dice_row[1] = dice_row[2];
			dice_row[2] = dice_col[3];
			dice_col[3] = temp;
			dice_col[1] = dice_row[1];
		}
		else if (dir == 2) // ����
		{
			int temp = dice_col[3];
			dice_col[3] = dice_row[2];
			dice_row[2] = dice_row[1];
			dice_row[1] = dice_row[0];
			dice_row[0] = temp;
			dice_col[1] = dice_row[1];
		}
		else if (dir == 3) // ����
		{
			int temp = dice_col[3];
			dice_col[3] = dice_col[2];
			dice_col[2] = dice_col[1];
			dice_col[1] = dice_col[0];
			dice_col[0] = temp;
			dice_row[1] = dice_col[1];

		}
		else if (dir == 4) // ����
		{

			int temp = dice_col[0];
			dice_col[0] = dice_col[1];
			dice_col[1] = dice_col[2];
			dice_col[2] = dice_col[3];
			dice_col[3] = temp;
			dice_row[1] = dice_col[1];

		}
		if (map[ly][lx] == 0) // map�� ���� 0�� ���
			map[ly][lx] = dice_row[1];
		else // map�� ���� 0�� �ƴ� ���
		{
			dice_row[1] = map[ly][lx];
			dice_col[1] = dice_row[1];
			map[ly][lx] = 0;
		}
		y = ly;
		x = lx;
		cout << dice_col[3] << endl; // ���� �ִ� �� ���

	}
}