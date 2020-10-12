#include <iostream>
#include <queue>

using namespace std;

const int MAX = 20;

int N, answer = 0;
int board[MAX][MAX];

void backtracking(int depth);
void rotate(int board[MAX][MAX]);
void merge_board(int board[MAX][MAX]);
int get_max(int board[MAX][MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
   
    backtracking(0);
    cout << answer << "\n";

    return 0;
}

void backtracking(int depth)
{
    if (depth == 5)
    {
        answer = max(answer, get_max(board));
        return;
    }

    int board_c[MAX][MAX];
    copy(&board[0][0], &board[0][0] + MAX * MAX, &board_c[0][0]);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < i; j++)
            rotate(board);
        
        merge_board(board);
        backtracking(depth + 1);
        copy(&board_c[0][0], &board_c[0][0] + MAX * MAX, &board[0][0]);
    }
}

void merge_board(int board[MAX][MAX])
{
    int board_c[MAX][MAX];
    fill_n(&board_c[0][0], MAX * MAX, 0);
    
    for (int i = 0; i < N; i++)
    {
        deque<int> dq;
        int idx = 0;

        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
                continue;
            
            if (!dq.empty() && dq.back() == board[i][j])
            {
                dq.pop_back();
                dq.push_back(board[i][j] * 2);

                while (!dq.empty())
                {
                    board_c[i][idx++] = dq.front();
                    dq.pop_front();
                }
            }
            else
                dq.push_back(board[i][j]);
        }

        while (!dq.empty())
        {
            board_c[i][idx++] = dq.front();
            dq.pop_front();
        }
    }

    copy(&board_c[0][0], &board_c[0][0] + MAX * MAX, &board[0][0]);
}

void rotate(int board[MAX][MAX])
{
    int board_r[MAX][MAX];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board_r[i][j] = board[N - 1 - j][i];
    
    copy(&board_r[0][0], &board_r[0][0] + MAX * MAX, &board[0][0]);
}

int get_max(int board[MAX][MAX])
{
    int max_num = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            max_num = max(max_num, board[i][j]);
    
    return max_num;
}
