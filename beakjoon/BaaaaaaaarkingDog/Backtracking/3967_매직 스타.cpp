#include <iostream>
#include <vector>

using namespace std;

const int MAX = 12;
const int N = 5;
const int M = 9;

int X;
char A[N][M], B[N][M];
bool visited[MAX], is_finished;
vector< pair<int, int> > v;

void find_magic(int depth);
bool is_possible(char A[N][M]);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];

			if (A[i][j] == 'x')
			{
				X += 1;
				v.push_back(make_pair(i, j));
			}
			if (A[i][j] >= 'A' && A[i][j] <= 'L')
				visited[A[i][j] - 'A'] = true;
		}
	
	find_magic(0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << B[i][j];
		cout << "\n";
	}

	return 0;
}

void find_magic(int depth)
{
	if (is_finished)
		return;
	if (depth == X)
	{
		if (is_possible(A))
		{
			is_finished = true;
			copy(&A[0][0], &A[0][0] + N * M, &B[0][0]);
		}
		return;
	}

	int x = v[depth].first, y = v[depth].second;
	for (int i = 0; i < MAX; i++)
	{
		if (visited[i]) continue;

		visited[i] = true;
		A[x][y] = 'A' + i;
		find_magic(depth + 1);
		visited[i] = false;
		A[x][y] = 'x';
	}
}

bool is_possible(char A[N][M])
{
	if (((A[1][1] - 'A') + (A[1][3] - 'A') + (A[1][5] - 'A') + (A[1][7] - 'A') + 4) != 26 )
		return false;
	if (((A[3][1] - 'A') + (A[3][3] - 'A') + (A[3][5] - 'A') + (A[3][7] - 'A') + 4) != 26 )
		return false;
	if (((A[0][4] - 'A') + (A[1][3] - 'A') + (A[2][2] - 'A') + (A[3][1] - 'A') + 4) != 26 )
		return false;
	if (((A[0][4] - 'A') + (A[1][5] - 'A') + (A[2][6] - 'A') + (A[3][7] - 'A') + 4) != 26 )
		return false;
	if (((A[1][1] - 'A') + (A[2][2] - 'A') + (A[3][3] - 'A') + (A[4][4] - 'A') + 4) != 26 )
		return false;
	if (((A[1][7] - 'A') + (A[2][6] - 'A') + (A[3][5] - 'A') + (A[4][4] - 'A') + 4) != 26 )
		return false;
	return true;
}