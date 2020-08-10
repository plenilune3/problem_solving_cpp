#include <iostream>

using namespace std;

const int MAX = 1501;

struct stone
{
	int a, b, c;
};

int A, B, C;
bool visited[MAX][MAX];
bool answer = false;

void dfs(int x, int y, int sum)
{
	int z = sum - (x + y);
	visited[x][y] = true;

	if (answer)
		return;

	if (x == y && y == z)
	{
		answer = true;
		return;
	}

	if (x < y)
	{
		int nx = x + x, ny = y - x;
		if(visited[nx][ny] == false)
			dfs(nx, ny, sum);
	}
	else
	{
		int nx = x - y, ny = y + y;
		if(visited[nx][ny] == false)
			dfs(nx, ny, sum);
	}

	if (y < z)
	{
		int nx = x, ny = y + y;
		if(visited[nx][ny] == false)
			dfs(nx, ny, sum);
	}
	else
	{
		int nx = x, ny = y - z;
		if(visited[nx][ny] == false)
			dfs(nx, ny, sum);
	}

	if (x < z)
	{
		int nx = x + x, ny = y;
		if(visited[nx][ny] == false)
			dfs(nx, ny, sum);
	}
	else
	{
		int nx = x - z, ny = y;
		if(visited[nx][ny] == false)
			dfs(nx, ny, sum);
	}
}

int main()
{
	cin >> A >> B >> C;

	dfs(A, B, A + B + C);

	cout << answer << "\n";

	return 0;
}