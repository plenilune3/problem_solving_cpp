#include <iostream>

using namespace std;

const int MAX = 101;
const int dx[] = { -1, -1, -1, 1, 1, 1 };
const int dy[] = { -1, 0, 1, 1, 0, -1 };

int N, answer;
int A[MAX][MAX];
bool visited[MAX][MAX];

void find_move(int depth, int x, int y, int sx, int sy);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < MAX; i++)
	{
		int k = 0;

		if (i % 4 == 0 || i % 4 == 3)
			k = 1;

		for (int j = k; j < MAX; j += 2)
			A[i][j] = 1;
	}

	visited[50][50] = true;
	visited[49][50] = true;

	find_move(0, 49, 50, 50, 50);

	cout << answer << "\n";

	return 0;
}

void find_move(int depth, int x, int y, int sx, int sy)
{
	if (depth == N)
	{
		if (visited[x][y])
			answer += 1;
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];

		if (!A[nx][ny]) continue;
		if (depth == N - 1 && !(sx == nx && sy == ny))
		{
			find_move(depth + 1, nx ,ny, x, y);
			continue;
		}
		if (visited[nx][ny]) continue;

		visited[nx][ny] = true;
		find_move(depth + 1, nx, ny, x, y);
		visited[nx][ny] = false;
	}
}