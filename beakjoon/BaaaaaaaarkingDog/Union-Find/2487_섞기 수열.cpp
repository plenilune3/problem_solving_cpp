#include <iostream>

using namespace std;

const int MAX = 2e4 + 1;

int N, A[MAX], parent[MAX];

int find_(int u);
void union_(int u, int v);
int gcd(int a, int b);
int lcm(int a, int b);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	fill_n(&parent[0], MAX, -1);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> A[i];
	
	for (int i = 1; i <= N; i++)
	{
		int u = A[i];

		while (find_(u) != find_(i))
		{
			union_(i, u);
			u = A[u];
		}
	}

	long long answer = 1;

	for (int i = 1; i <= N; i++)
		answer = lcm(answer, -parent[find_(i)]);
	
	cout << answer << "\n";

	return 0;
}

int find_(int u)
{
	if (parent[u] < 0)
		return u;
	else
	{
		int v = find_(parent[u]);
		return parent[u] = v;
	}
}

void union_(int u, int v)
{
	u = find_(u), v = find_(v);
	
	if (u == v) return;

	if (u > v) swap(u, v);

	parent[u] += parent[v];
	parent[v] = u;
}

int gcd(int a, int b)
{
    if (a > b) swap(a, b);

    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}
