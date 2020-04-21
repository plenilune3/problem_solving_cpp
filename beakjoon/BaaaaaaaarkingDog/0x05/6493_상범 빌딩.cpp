#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 30;

struct person
{
    int l;
    int r;
    int c;
    int depth;
};

struct coordinate
{
    int l;
    int r;
    int c;
};

int dl[] = {-1, 1, 0, 0, 0, 0};
int dr[] = {0, 0, -1, 1, 0, 0};
int dc[] = {0, 0, 0, 0, -1, 1};
int L, R, C;

int bfs(queue<person> &q, coordinate S, coordinate E, char building[][MAX][MAX])
{
    bool visited[MAX][MAX][MAX];
    fill_n(&visited[0][0][0], MAX*MAX*MAX, false);
    visited[S.l][S.r][S.c] = true;

    while (!q.empty())
    {
        person c = q.front();
        q.pop();

        if (c.l == E.l && c.r == E.r && c.c == E.c)
            return c.depth;

        for (int i = 0; i < 6; i++)
        {
            int nl = c.l + dl[i];
            int nr = c.r + dr[i];
            int nc = c.c + dc[i];

            if (nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C)
                continue;

            if (building[nl][nr][nc] != '#' && visited[nl][nr][nc] == false)
            {
                visited[nl][nr][nc] = true;
                q.push({nl, nr, nc, c.depth + 1});
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        queue<person> q;
        char building[MAX][MAX][MAX];
        coordinate S, E;

        scanf("%d %d %d", &L, &R, &C);

        if (L == 0 || R == 0 || C == 0)
            break;

        for (int i = 0; i < L; i++)
            for (int j = 0; j < R; j++)
                for (int k = 0; k < C; k++)
                {
                    scanf("%1s", &building[i][j][k]);
                    
                    if (building[i][j][k] == 'S')
                    {
                        S = {i, j, k};
                        q.push({i, j, k, 0});
                    }
                    else if (building[i][j][k] == 'E')
                        E = {i, j, k};
                }
        
        int answer = bfs(q, S, E, building);

        if (answer == -1)
            printf("Trapped!\n");
        else
            printf("Escaped in %d minute(s).\n", answer);
    }
    
    return 0;
}
