#include <iostream>
#include <vector>

using namespace std;

const int MAX = 8;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

const int N = 5;
const int M = 9;

int X;
bool visited[MAX];
char A[N][M];
vector< pair<int, int> > P;
vector<int> v;

void play(int depth);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int T; cin >> T;

	while (T--)
	{
		P.clear();
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> A[i][j];
		
		X = (int) P.size();
		cout << X << "\n";
		play(0);
	}

	return 0;
}

bool is_possible(int x, int y, char A[N][M])
{
	if (A[x][y] != 'o')
		return false;
	
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		int nnx = nx + dx[i], nny = ny + dy[i];
		
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		if (nnx < 0 || nnx >= N || nny < 0 || nny >= M)
			continue;
		if (A[nx][ny] == 'o' && A[nnx][nny] == '.')
			return true;
	}
	return false;
}

int count_possible(char A[N][M])
{
	int result = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			result += is_possible(i, j, A);

	return result;
}

void play(int depth)
{
	if (count_possible(A) == 0)
	{
		return;
	}
}