#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1002;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct state
{
    int x, y, depth;
};

int N, M, P;
queue< state > q[10];
int S[10];
int result[10];
char board[MAX][MAX];

bool bfs()
{
    bool possible = false;

    for (int k = 1; k <= P; k++)
    {
        queue<state> nq = q[k];

        while (!q[k].empty())
            q[k].pop();

        while (!nq.empty())
        {
            state c = nq.front();
            nq.pop();

            if (c.depth == S[k])
                break;

            for (int i = 0; i < 4; i++)
            {
                int nx = c.x + dx[i], ny = c.y + dy[i];

                if (board[nx][ny] != '.')
                    continue;
                
                state s = { nx, ny, c.depth + 1 };
                state ns = { nx, ny, 0 };
                board[nx][ny] = '0' + k;
                q[k].push(ns);
                nq.push(s);
                result[k] += 1;
                possible = true;
            }
        }
    }

    return possible;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> P;

    for (int i = 1; i <= P; i++)
        cin >> S[i];
    
    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < M + 2; j++)
        {
            if (i == 0 || j == 0 || i == N + 1 || j == M + 1)
                board[i][j] = '#';
            else
                cin >> board[i][j];

            if (board[i][j] != '.' && board[i][j] != '#')
            {
                state s = { i, j, 0 };
                q[board[i][j] - '0'].push(s);
                result[board[i][j] - '0'] += 1;
            }
        }
    
    while (true)
        if (bfs() == false)
            break;

    for (int i = 1; i <= P; i++)
        cout << result[i] << " ";
    cout << "\n";

    return 0;
}
