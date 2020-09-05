#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct tank
{
    int x, y, d;
    
    bool operator< (const tank &t) const
    {
        if (d != t.d) return d > t.d;
        else if (x != t.x) return x < t.x;
        else return y < t.y;
    }
};

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };
const int MAX = 1000;

int N, D;
int board[MAX][MAX];

vector< vector<int> > find_path(tank src);
tank make_tank(int x, int y, int d);

int main()
{
    cin >> N >> D;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    vector< vector<int> > dist = find_path(make_tank(0, 0, board[0][0]));

    int answer = D - dist[N-1][N-1];

    if (answer > 0)
        cout << answer << "\n";
    else
        cout << "-1" << "\n";

	return 0;
}

tank make_tank(int x, int y, int d)
{
    tank t = { x, y, d };
    return t;
}

vector< vector<int> > find_path(tank src)
{
    vector< vector<int> > dist(N, vector<int> (N, INT_MAX));
    priority_queue<tank> pq;
    dist[src.x][src.y] = src.d;
    pq.push(src);

    while (!pq.empty())
    {
        int x = pq.top().x, y = pq.top().y, d = pq.top().d;
        pq.pop();

        if (dist[x][y] < d)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            int nd = board[nx][ny];

            if (dist[nx][ny] > nd + d)
            {
                dist[nx][ny] = nd + d;
                pq.push(make_tank(nx, ny, nd + d));
            }
        }
    }

    return dist;
}