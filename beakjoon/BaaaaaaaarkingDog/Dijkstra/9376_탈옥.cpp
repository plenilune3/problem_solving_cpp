#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 105;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct edge
{
    int x, y, w;

    bool operator< (const edge &e) const
    {
        if (w != e.w) return w > e.w;
        else if (x != e.x) return x < e.x;
        else return y < e.y;
    }
};

int H, W;
char board[MAX][MAX];

vector< vector<int> > find_path(int x, int y, int w);
edge make_edge(int x, int y, int w);
bool is_out_of_range(int x, int y);
bool is_wall(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        vector< pair<int, int> > v;
        v.push_back(make_pair(0, 0));

        cin >> H >> W;

        fill_n(&board[0][0], MAX * MAX, '.');

        for (int i = 1; i <= H; i++)
        {
            char row[W]; cin >> row;

            for (int j = 0; j < W; j++)
            {
                board[i][j + 1] = row[j];

                if (board[i][j + 1] == '$')
                {
                    board[i][j + 1] = '.';
                    v.push_back(make_pair(i, j + 1));
                }
            }
        }

        vector< vector<int> > dist[3];

        for (int i = 0; i < 3; i++)
            dist[i] = find_path(v[i].first, v[i].second, 0);
        
        int answer = MAX * MAX;

        for (int i = 0; i < H + 2; i++)
            for (int j = 0; j < W + 2; j++)
            {
                if (is_wall(i, j)) continue;

                int w = dist[0][i][j] + dist[1][i][j] + dist[2][i][j];

                if (board[i][j] == '#') w = w - 2;

                answer = min(answer, w);
            }
        
        cout << answer << "\n";
    }

    return 0;
}

vector< vector<int> > find_path(int x, int y, int d)
{
    vector< vector<int> > dist(MAX, vector<int> (MAX, MAX * MAX));

    priority_queue<edge> pq;
    dist[x][y] = d;
    pq.push(make_edge(x, y, d));

    while (!pq.empty())
    {
        int cx = pq.top().x, cy = pq.top().y, cw = pq.top().w;
        pq.pop();

        if (dist[cx][cy] < cw) continue;

        for (int d = 0; d < 4; d++)
        {
            int nx = cx + dx[d], ny = cy + dy[d];

            if (is_out_of_range(nx, ny) || is_wall(nx, ny))
                continue;
            
            int nw = (board[nx][ny] == '#') ? cw + 1 : cw;

            if (dist[nx][ny] > nw)
            {
                dist[nx][ny] = nw;
                pq.push(make_edge(nx, ny, nw));
            }
        }
    }

    return dist;
}

edge make_edge(int x, int y, int w)
{
    edge e = { x, y, w };
    return e;
}

bool is_out_of_range(int x, int y)
{
    return x < 0 || x > H + 2 || y < 0 || y > W + 2;
}

bool is_wall(int x, int y)
{
    return board[x][y] == '*';
}
