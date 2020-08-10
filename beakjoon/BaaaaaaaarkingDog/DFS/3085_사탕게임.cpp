#include <iostream>

using namespace std;

const int MAX = 50;

int N, answer;
char board[MAX][MAX];

void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

int candy_cnt(char board[MAX][MAX])
{
    int cnt_max = 0;
    for (int i = 0; i < N; i++)
    {
        int cnt = 1;
        for (int j = 0; j < N - 1; j++)
        {
            if (board[i][j] == board[i][j + 1])
                cnt += 1;
            else
            {
                cnt_max = max(cnt_max, cnt);
                cnt = 1;
            }
        }
        cnt_max = max(cnt_max, cnt);
    }

    for (int j = 0; j < N; j++)
    {
        int cnt = 1;
        for (int i = 0; i < N - 1; i++)
        {
            if (board[i][j] == board[i + 1][j])
                cnt += 1;
            else
            {
                cnt_max = max(cnt_max, cnt);
                cnt = 1;
            }
        }
        cnt_max = max(cnt_max, cnt);
    }

    return cnt_max;
}

void backtracking(int x, int y)
{

    if (x == N)
        return;

    if (y == N)
    {
        backtracking(x + 1, 0);
        return;
    }

    if (x + 1 < N)
    {
        swap(board[x][y], board[x + 1][y]);
        answer = max(answer, candy_cnt(board));
        swap(board[x][y], board[x + 1][y]);
    }

    if (y + 1 < N)
    {
        swap(board[x][y], board[x][y + 1]);
        answer = max(answer, candy_cnt(board));
        swap(board[x][y], board[x][y + 1]);
    }

    backtracking(x, y + 1);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    answer = max(answer, candy_cnt(board));

    backtracking(0, 0);
    
    cout << answer << "\n";

    return 0;
}
