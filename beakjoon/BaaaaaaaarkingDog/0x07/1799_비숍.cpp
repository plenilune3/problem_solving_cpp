#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 11;

int N;
int answer[2];
bool board[MAX][MAX];
bool rd[MAX+MAX-1];
bool ld[MAX+MAX-1];

void backtracking(int x, int y, int count, int color)
{
    if (x >= N)
    {
        answer[color] = max(answer[color], count);
        return;
    }
    
    if (y >= N)
    {
        x++;
        if (y % 2 == 0)
            y = 1;
        else
            y = 0;
    }

    if (board[x][y] && !rd[x + y] && !ld[x - y + N - 1])
    {
        rd[x + y] = ld[x - y + N - 1] = true;
        backtracking(x, y + 2, count + 1, color);
        rd[x + y] = ld[x - y + N - 1] = false;
    }
    backtracking(x, y + 2, count, color);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &board[i][j]);
    
    backtracking(0, 0, 0, 0);
    backtracking(0, 1, 0, 1);

    printf("%d\n", answer[0] + answer[1]);

    return 0;
}
