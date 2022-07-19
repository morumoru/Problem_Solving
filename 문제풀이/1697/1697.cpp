#include <iostream>
#include <queue>
using namespace std;

int n, k;
int ans = 100001;
int visited[100001];
struct node {
	int index;
	int value;
};

void bfs()
{
	queue<node> q;
	q.push({ n,0 });
	while (!q.empty())
	{
		node now = q.front();
		q.pop();
		if (visited[now.index] == 1)
			continue;
		else
			visited[now.index] = 1;
		if (now.index == k)
			ans = min(ans, now.value);
		int temp_idx = 2 * now.index;
		if (0 <= temp_idx && temp_idx <= 100000)
			q.push({ temp_idx, now.value + 1 });
		temp_idx = now.index + 1;
		if (0 <= temp_idx && temp_idx <= 100000)
			q.push({ temp_idx, now.value + 1 });
		temp_idx = now.index - 1;
		if (0 <= temp_idx && temp_idx <= 100000)
			q.push({ temp_idx, now.value + 1 });
	}
}

int main()
{

	cin >> n >> k;
	bfs();
	cout << ans;
}