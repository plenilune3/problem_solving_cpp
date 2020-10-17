#include <iostream>

using namespace std;

const int MAX = 40;

struct sticker
{
    int r, c;
    bool S[10][10];
};

int N, M, K, answer;
bool board[MAX][MAX];
sticker stickers[100];

void dfs(int depth);
bool is_possible(int x, int y, sticker &s);
void attach(int x, int y, sticker &s);
void rotate(sticker &s);

int main(int argc, char const *argv[])
{
    cin >> N >> M >> K;

    for (int k = 0; k < K; k++)
    {
        cin >> stickers[k].r >> stickers[k].c;

        for (int i = 0; i < stickers[k].r; i++)
            for (int j = 0; j < stickers[k].c; j++)
                cin >> stickers[k].S[i][j];
    }

    dfs(0);

    cout << answer << "\n";

    return 0;
}

void dfs(int depth)
{
    if (depth == K)
    {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (board[i][j])
                    answer += 1;
        
        return;
    }

    for (int d = 0; d < 4; d++)
    {
        for (int x = 0; x < N; x++)
            for (int y = 0; y < M; y++)
                if (is_possible(x, y, stickers[depth]))
                {
                    attach(x, y, stickers[depth]);
                    dfs(depth + 1);
                    return;
                }
        
        rotate(stickers[depth]);
    }

    dfs(depth + 1);
}

void attach(int x, int y, sticker &s)
{
    int r = s.r, c = s.c;

    for (int i = x; i < x + r; i++)
        for (int j = y; j < y + c; j++)
            if (s.S[i - x][j - y])
                board[i][j] = true;
}

bool is_possible(int x, int y, sticker &s)
{
    int r = s.r, c = s.c;

    if (x + r > N || y + c > M)
        return false;
    
    for (int i = x; i < x + r; i++)
        for (int j = y; j < y + c; j++)
            if (s.S[i - x][j - y] && board[i][j])
                return false;
    
    return true;
}

void rotate(sticker &s)
{
    bool S_c[10][10];

    for (int i = 0; i < s.c; i++)
        for (int j = 0; j < s.r; j++)
            S_c[i][j] = s.S[s.r - 1 - j][i];
    
    swap(s.r, s.c);
    copy(&S_c[0][0], &S_c[0][0] + 10 * 10, &s.S[0][0]);
}
