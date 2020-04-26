#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 21;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int N, answer;
int board[MAX][MAX];

void get(int i, int j, queue<int>& q)
{
    if (board[i][j])
    {
        q.push(board[i][j]);
        board[i][j] = 0;
    }
}

void merge(int i, int j, int di, int dj, queue<int>&q) 
{
    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        if (board[i][j] == 0)
            board[i][j] = x;
        else if (board[i][j] == x)
        {
            board[i][j] = x * 2;
            i += di, j += dj;
        }
        else
        {
            i += di, j += dj;
            board[i][j] = x;
        }
    }
}

void move(int k)
{
    queue<int> q;

    if (k == 0)
    {
        for (int j = 0; j < N; j++)
        {
            for (int i = 0; i < N; i++)
                get(i, j, q);
            merge(0, j, 1, 0, q);
        }
    }
    else if (k == 1)
    {
        for (int j = 0; j < N; j++)
        {
            for (int i = N-1; i >= 0; i--)
                get(i, j, q);
            merge(N-1, j, -1, 0, q);
        }
    }
    else if (k == 2)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                get(i, j, q);
            merge(i, 0, 0, 1, q);
        }
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = N-1; j >= 0; j--)
                get(i, j, q);
            merge(i, N-1, 0, -1, q);
        }
    }
}

void dfs(int depth)
{
    if (depth == 5)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                answer = max(answer, board[i][j]);
        return;
    }

    int nboard[MAX][MAX];
    memcpy(nboard, board, sizeof(board));

    for (int k = 0; k < 4; k++)
    {
        move(k);
        dfs(depth + 1);
        memcpy(board, nboard, sizeof(nboard));
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &board[i][j]);
    
    dfs(0);

    printf("%d\n", answer);

    return 0;
}
