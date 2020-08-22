#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct node
{
    int dist, x, y;

    bool operator<(const node& n) const
    {
        if (dist != n.dist) return dist > n.dist;
        else if (x != n.x) return x < n.x;
        else return y < n.y;
    }
};

int N;
char board[MAX][MAX];

node make_node(int dist, int x, int y);
vector< vector<int> > find_shortest_path(node s);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> board[i];
    
    node s = { board[0][0] == '1' ? 0 : 1, 0, 0 };

    vector< vector<int> > dist = find_shortest_path(s);

    cout << dist[N - 1][N - 1] << "\n";

    return 0;
}

node make_node(int dist, int x, int y)
{
    return { dist, x, y };
}

vector< vector<int> > find_shortest_path(node s)
{
    vector< vector<int> > dist(MAX, vector<int> (MAX, INT_MAX));
    priority_queue<node> pq;
    dist[s.x][s.y] = s.dist;
    pq.push(make_node(s.dist, s.x, s.y));

    while (!pq.empty())
    {
        int d = pq.top().dist, x = pq.top().x, y = pq.top().y;
        pq.pop();

        if (d > dist[x][y])
            continue;
        
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            int ndist = board[nx][ny] == '1' ? 0 : 1;

            if (d + ndist < dist[nx][ny])
            {
                dist[nx][ny] = d + ndist;
                pq.push(make_node(d + ndist, nx, ny));
            }
        }
    }

    return dist;
}



