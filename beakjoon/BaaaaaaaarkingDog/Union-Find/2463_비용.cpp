#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;
const int MOD = 1e9;

struct edge
{
	int u, v, w;

	edge() : u(0), v(0), w(0) {}
	edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}

	bool operator< (const edge &e) const
	{
		return w > e.w;
	}
};

int N, M;
long long parent[MAX], answer, total;
edge E[MAX];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	fill_n(&parent[0], MAX, -1);
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> E[i].u >> E[i].v >> E[i].w;
		total += E[i].w;
	}
	
	sort(&E[0], &E[0] + M);

	for (int i = 0; i < M; i++)
	{
		int u = E[i].u, v = E[i].v, w = E[i].w;

		if (find_(u) != find_(v))
		{
			answer += (((-parent[find_(u)] % MOD * -parent[find_(v)] % MOD) % MOD) * total) % MOD;
			answer %= MOD;
			union_(u, v);
		}

		total -= w;
	}

	cout << answer % MOD << "\n";

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

	if (parent[u] > parent[v]) swap(u, v);

	parent[u] += parent[v];
	parent[v] = u;
}