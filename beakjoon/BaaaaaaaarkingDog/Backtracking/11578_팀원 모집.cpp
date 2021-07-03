#include <iostream>
#include <climits>

using namespace std;

const int MAX = 11;

int N, M, answer = INT_MAX, P[MAX];
bool visited[MAX];

void find_team(int depth, int index, int result);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int k; cin >> k;

		for (int j = 0; j < k; j++)
		{
			int x; cin >> x;
			P[i] = P[i] | (1 << (x - 1));
		}
	}

	find_team(0, 0, 0);

	if (answer != INT_MAX)
		cout << answer << "\n";
	else
		cout << "-1" << "\n";

	return 0;
}

void find_team(int depth, int index, int result)
{
	if (result == ((1 << N) - 1))
	{
		answer = min(answer, depth);
		return;
	}
	if (depth == M)
		return;
	if (depth > answer)
		return;
	for (int i = index; i < M; i++)
	{
		if (visited[i]) continue;

		visited[i] = true;
		find_team(depth + 1, i, result | P[i]);
		visited[i] = false;
	}
}