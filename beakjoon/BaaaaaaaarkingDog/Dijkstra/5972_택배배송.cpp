#include <iostream>
#include <queue>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 5e4 + 1;

struct edge
{
	int v, w;

	edge() : v(0), w(0) {}
	edge(int _v, int _w) : v(_v), w(_w) {}

	bool operator< (const edge &e) const
	{
		return w > e.w;
	}
};

int N, M;
vector< vector<edge> > node(MAX);

vector<int> find_dist(int start, int end);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		node[u].push_back(edge(v, w));
		node[v].push_back(edge(u, w));
	}

	vector<int> dist = find_dist(1, N);
	int answer = dist[N];

	cout << answer << "\n";

	return 0;
}

vector<int> find_dist(int start, int end)
{
	vector<int> dist(MAX, INT_MAX);
	priority_queue<edge> pq;

	pq.push(edge(start, 0));
	dist[start] = 0;

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
