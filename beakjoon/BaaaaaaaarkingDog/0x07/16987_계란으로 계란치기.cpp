#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 8;

struct egg
{
	int d, w;
};

int N, answer;
egg e[MAX];

void permutations(int depth)
{
	if (depth == N)
	{
		int cnt = 0;
		for (int i = 0; i < N; i++)
			if (e[i].d <= 0)
				cnt += 1;

		answer = max(answer, cnt);

		return;
	}

	if (e[depth].d <= 0)
	{
		permutations(depth + 1);
		return;
	}

	bool possible = false;

	for (int i = 0; i < N; i++)
	{
		if (depth == i || e[i].d <= 0)
			continue;

		possible = true;
		e[depth].d -= e[i].w;
		e[i].d -= e[depth].w;
		permutations(depth + 1);
		e[depth].d += e[i].w;
		e[i].d += e[depth].w;
	}

	if (possible == false)
		permutations(depth + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int d, w;
		cin >> d >> w;
		e[i].d = d, e[i].w = w;
	}

	permutations(0);

	cout << answer << "\n";

	return 0;
}

