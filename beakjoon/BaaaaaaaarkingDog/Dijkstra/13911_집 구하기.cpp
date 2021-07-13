#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 1e4 + 1;


struct edge
{
	int v, w;

	edge() : v(0), w(0) {}
	edge(int _v, int _w) : v(_v), w(_w) {}

	bool operator<(const edge &e) const
	{
		return w > e.w;
	}
};

int V, E, M, x, S, y, answer = INT_MAX;
bool mcdonald[MAX], startbucks[MAX];
vector< vector<edge> > node(MAX);

vector<int> find_path(int N, bool A[MAX]);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		node[u].push_back(edge(v, w));
		node[v].push_back(edge(u, w));
	}

	cin >> M >> x;

	for (int i = 0; i < M; i++)
	{
		int m; cin >> m;
		mcdonald[m] = true;
	}

	cin >> S >> y;
	
	for (int i = 0; i < S; i++)
	{
		int s; cin >> s;
		startbucks[s] = true;
	}

	vector<int> dist_m = find_path(V, mcdonald);
	vector<int> dist_s = find_path(V, startbucks);

	for (int i = 1; i <= V; i++)
	{
		if (mcdonald[i] || startbucks[i])
			continue;
		
		if (dist_m[i] <= x && dist_s[i] <= y)
			answer = min(answer, dist_m[i] + dist_s[i]);
	}

	if (answer != INT_MAX)
		cout << answer << "\n";
	else
		cout << -1 << "\n";

	return 0;
}

vector<int> find_path(int N, bool A[MAX])
{
	vector<int> dist(MAX, INT_MAX);
	priority_queue<edge> pq;

	for (int i = 1; i <= N; i++)
		if (A[i])
		{
			dist[i] = 0;
			pq.push(edge(i, 0));
		}
	
	while (!pq.empty())
	{
		int v = pq.top().v, w = pq.top().w;
		pq.pop();

		if (dist[v] < w)
			continue;
		
		for (vector<edge>::iterator i = node[v].begin(); i != node[v].end(); i++)
		{
			int nv = (*i).v, nw = (*i).w;

			if (dist[nv] > nw + w)
			{
				dist[nv] = nw + w;
				pq.push(edge(nv, nw + w));
			}
		}
	}

	return dist;
}