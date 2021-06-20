#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

int N, parent[MAX];

int find_(int u);
void union_(int u, int v);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	fill_n(&parent[0], MAX, -1);

	cin >> N;

	while (N--)
	{
		char c;
		cin >> c;

		if (c == 'I')
		{
			int u, v; cin >> u >> v;
			union_(u, v);
		}
		else
		{
			int u; cin >> u;
			cout << -parent[find_(u)] << "\n";
		}
	}

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