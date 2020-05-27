#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 501;
const int ldx[] = { -1, 1, 0 };
const int ldy[] = { 0, 0, -1 };
const int rdx[] = { -1, 1, 0 };
const int rdy[] = { 0, 0, 1 };

struct person
{
    int lx, ly, rx, ry, tile;
    vector<int> path;
};

int N;
int board[MAX][MAX * 2];
int dist[MAX][MAX * 2];
int tile[MAX][MAX * 2];

void set_tile()
{
    int num = 1;
    for (int i = 0; i < N; i++)
    {
        int j;
        for ((i % 2) ? j = 1 : j = 0; j < N * 2 - 1; j += 2)
        {
            tile[i][j] = num;
            tile[i][j + 1] = num;
            num += 1;
        }
    }
}

person bfs()
{
    queue<person> q;
    vector<int> path;
    path.push_back(1);
    person init = { 0, 0, 0, 1, tile[0][0], path };
    dist[0][0] = 1;
    dist[0][1] = 1;
    q.push(init);

    int tile_max = 1;
    person last = init;

    while(!q.empty())
    {
        person p = q.front();
        q.pop();

        if (p.tile == N * N - N / 2)
            return p;
        
        if (p.tile > tile_max)
        {
            tile_max = p.tile;
            last = p;
        }
        
        for (int i = 0; i < 3; i++)
        {
            int nlx = p.lx + ldx[i];
            int nly = p.ly + ldy[i];

            if (nlx < 0 || nlx >= N || nly < 0 || nly >= 2 * N || dist[nlx][nly] != 0 || board[nlx][nly] == 0)
                continue;
            
            if (board[p.lx][p.ly] != board[nlx][nly])
                continue;
            
            dist[nlx][nly - 1] = dist[p.lx][p.ly] + 1;
            dist[nlx][nly] = dist[p.lx][p.ly] + 1;

            p.path.push_back(tile[nlx][nly]);
            person np = { nlx, nly - 1, nlx, nly, tile[nlx][nly], p.path };
            q.push(np);
            p.path.pop_back();
        }

        for (int i = 0; i < 3; i++)
        {
            int nrx = p.rx + rdx[i];
            int nry = p.ry + rdy[i];

            if (nrx < 0 || nrx >= N || nry < 0 || nry >= 2 * N || dist[nrx][nry] != 0 || board[nrx][nry] == 0)
                continue;
            
            if (board[p.rx][p.ry] != board[nrx][nry])
                continue;
            
            dist[nrx][nry + 1] = dist[p.rx][p.ry] + 1;
            dist[nrx][nry] = dist[p.rx][p.ry] + 1;

            p.path.push_back(tile[nrx][nry]);
            person np = { nrx, nry, nrx, nry + 1, tile[nrx][nry], p.path };
            q.push(np);
            p.path.pop_back();
        }
    }

    return last;
}

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int j;
        for ((i % 2) ? j = 1 : j = 0; j < N * 2 - 1; j += 2)
        {
            cin >> board[i][j];
            cin >> board[i][j + 1];
        }
    }

    set_tile();
    person answer = bfs();

    cout << dist[answer.lx][answer.ly] << "\n";
    for (vector<int>::iterator i = answer.path.begin(); i != answer.path.end(); i++)
        cout << (*i) << " ";

    return 0;
}
