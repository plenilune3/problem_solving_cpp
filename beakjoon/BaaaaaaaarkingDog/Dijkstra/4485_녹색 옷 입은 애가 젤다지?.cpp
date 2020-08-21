#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 125;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct link
{
    int coin, x, y;
};

bool operator<(link a, link b)
{
    if (a.coin != b.coin) return a.coin > b.coin;
    else if (a.x != b.x) return a.x < b.x;
    else return a.y < b.y;
}

int N;
int board[MAX][MAX];

vector< vector<int> > find_shortest_path(int sx, int sy);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int count = 1;

    while (true)
    {
        cin >> N;

        if (N == 0)
            break;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> board[i][j];
        
        vector< vector<int> > dist = find_shortest_path(0, 0);

        cout << "Problem " << count++ << ": " << dist[N - 1][N - 1] << "\n";
    }

    return 0;
}

link make_link(int coin, int x, int y)
{
    return { coin, x, y };
}

vector< vector<int> > find_shortest_path(int sx, int sy)
{
    vector< vector<int> > dist(N, vector<int> (N, INT_MAX));
    priority_queue<link> pq;
    dist[sx][sy] = board[sx][sy];
    pq.push(make_link(board[sx][sy], 0, 0));

    while (!pq.empty())
    {
        int coin = pq.top().coin, x = pq.top().x, y = pq.top().y;
        pq.pop();

        if (coin > dist[x][y])
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            
            int ncoin = board[nx][ny];
            
            if (coin + ncoin < dist[nx][ny])
            {
                dist[nx][ny] = coin + ncoin;
                pq.push(make_link(coin + ncoin, nx, ny));
            }
        }
    }

    return dist;
}
