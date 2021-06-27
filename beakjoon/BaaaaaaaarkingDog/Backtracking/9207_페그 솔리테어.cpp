#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 8;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

const int N = 5;
const int M = 9;

int answer, moving;
bool visited[MAX];
char A[N][M];
vector< pair<int ,int> > v;

void play(int depth);
void move(int x, int y, int d, char A[N][M]);
void undo(int x, int y, int d, char A[N][M]);
bool is_possible(int x, int y, int d, char A[N][M]);
int count_possible(char A[N][M]);
int count_pin(char A[N][M]);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T; cin >> T;

	while (T--)
	{
		answer = MAX;
		moving = MAX;
		v.clear();

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> A[i][j];

		play(0);
		sort(v.begin(), v.end());
		cout << v[0].first << " " << v[0].second << "\n";
	}

	return 0;
}

void play(int depth)
{
	if (!count_possible(A))
	{
		v.push_back(make_pair(count_pin(A), depth));
		return;
	}

	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
			for (int d = 0; d < 4; d++)
				if (is_possible(x, y, d, A))
				{
					move(x, y, d, A);
					play(depth + 1);
					undo(x, y, d, A);
				}
}

void move(int x, int y, int d, char A[N][M])
{
	int nx = x + dx[d], ny = y + dy[d];
	int nnx = nx + dx[d], nny = ny + dy[d];

	A[x][y] = '.';
	A[nx][ny] = '.';
	A[nnx][nny] = 'o';
}

void undo(int x, int y, int d, char A[N][M])
{
	int nx = x + dx[d], ny = y + dy[d];
	int nnx = nx + dx[d], nny = ny + dy[d];

	A[x][y] = 'o';
	A[nx][ny] = 'o';
	A[nnx][nny] = '.';
}

bool is_possible(int x, int y, int d, char A[N][M])
{
	if (A[x][y] != 'o')
		return false;
	
	int nx = x + dx[d], ny = y + dy[d];
	int nnx = nx + dx[d], nny = ny + dy[d];
	
	if (nx < 0 || nx >= N || ny < 0 || ny >= M)
		return false;
	if (nnx < 0 || nnx >= N || nny < 0 || nny >= M)
		return false;
	if (A[nx][ny] == 'o' && A[nnx][nny] == '.')
		return true;

	return false;
}

int count_possible(char A[N][M])
{
	int result = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			for (int d = 0; d < 4; d++)
				result += is_possible(i, j, d, A);

	return result;
}

int count_pin(char A[N][M])
{
	int result = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (A[i][j] == 'o')
				result += 1;
	
	return result;
}