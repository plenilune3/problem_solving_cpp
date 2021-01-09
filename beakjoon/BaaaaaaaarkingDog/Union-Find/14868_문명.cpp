#include <iostream>
#include <queue>

using namespace std;

const int MAX_N = 2e3 + 1;
const int MAX_K = 1e5 + 1;
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };

int N, K;
int parent[MAX_K];
int visited[MAX_N][MAX_N];
queue< pair<int, int> > q1, q2;

int find_(int u);
void union_(int u, int v);
void spread_(queue< pair<int, int> > &q);
void adjacent_(queue< pair<int, int> > &q);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    fill_n(&parent[0], MAX_K, -1);

    for (int i = 1; i <= K; i++)
    {
        int x, y; cin >> x >> y;
        visited[x][y] = i;
        q1.push(make_pair(x, y));
    }

    int answer = 0;

    while (true)
    {
        adjacent_(q1);

        if (-parent[find_(1)] == K)
            break;

        spread_(q2);
        answer += 1;
    }

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

    if (parent[u] > parent[v]) swap(u, v);

    parent[u] += parent[v];
    parent[v] = u;
}

void adjacent_(queue< pair<int, int> > &q)
{
    while (!q.empty())
    {
        q2.push(q.front());
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 1 || nx > N || ny < 1 || ny > N)
                continue;

            if (visited[nx][ny] != 0)
                union_(visited[x][y], visited[nx][ny]);
        }
    }
}

void spread_(queue< pair<int, int> > &q)
{
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++)
        {
            int nx = x + dx[d], ny = y + dy[d];

            if (nx < 1 || nx > N || ny < 1 || ny > N)
                continue;
            
            if (visited[nx][ny])
                continue;

            visited[nx][ny] = visited[x][y];
            q1.push(make_pair(nx, ny));
        }
    }
}
