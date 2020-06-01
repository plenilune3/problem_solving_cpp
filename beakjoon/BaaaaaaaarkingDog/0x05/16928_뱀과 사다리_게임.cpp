#include <iostream>
#include <queue>

using namespace std;

const int MAX = 101;

struct state
{
    int position, depth;
};


int N, M;
int board[MAX];

int bfs()
{
    bool visited[MAX];
    fill_n(&visited[0], MAX, false);

    queue<state> q;
    state init = { 1, 0 };
    visited[1] = true;
    q.push(init);

    while (!q.empty())
    {
        state c = q.front();
        q.pop();

        if (c.position == 100)
            return c.depth;

        for (int i = 1; i <= 6; i++)
        {
            int np = c.position + i;

            if (np > 100 || visited[np])
                continue;
            
            if (board[np] == 0)
            {
                state n = { np, c.depth + 1 };
                visited[np] = true;
                q.push(n);
            }
            else
            {
                state n = { board[np], c.depth + 1 };
                if (visited[np] == false)
                {
                    visited[np] = true;
                    q.push(n);
                }
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int now, next;
        cin >> now >> next;
        board[now] = next;
    }

    for (int i = 0; i < M; i++)
    {
        int now, next;
        cin >> now >> next;
        board[now] = next;
    }

    cout << bfs() << "\n";

    return 0;
}
