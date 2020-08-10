#include <iostream>
#include <queue>

using namespace std;

struct coordinate {
    int m;
    int n;
    int h;
};


const int MAX = 100;
int dn[] = {-1, 1, 0, 0, 0, 0};
int dm[] = {0, 0, -1, 1, 0, 0};
int dh[] = {0, 0, 0, 0, -1, 1};

int H, N, M;
int tomato[MAX][MAX][MAX];
queue<coordinate> q;

int bfs()
{

    while (!q.empty())
    {
        coordinate c = q.front();
        q.pop();

        for (int i = 0; i < 6; i++)
        {
            int nh = c.h + dh[i];
            int nn = c.n + dn[i];
            int nm = c.m + dm[i];

            if (nh < 0 || nh >= H || nn < 0 || nn >= N || nm < 0 || nm >= M)
                continue;

            if (tomato[nh][nn][nm] == 0)
            {
                tomato[nh][nn][nm] = tomato[c.h][c.n][c.m] + 1;
                coordinate nc = {nm, nn, nh};
                q.push(nc);
            }
        }
    }

    int depth = 0;
    bool possible = true;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (tomato[i][j][k] == 0)
                {
                    possible = false;
                    break;
                }
                else
                    depth = max(depth, tomato[i][j][k]);
            }

            if (possible == false)
                break;
        }

        if (possible == false)
            break;
    }

    if (possible)
        return depth - 1;
    else
        return -1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
            {
                cin >> tomato[i][j][k];

                if (tomato[i][j][k] == 1)
                {
                    coordinate c = {k, j, i};
                    q.push(c);
                }
            }

    int answer = bfs();
    cout << answer << "\n";

    return 0;
}
