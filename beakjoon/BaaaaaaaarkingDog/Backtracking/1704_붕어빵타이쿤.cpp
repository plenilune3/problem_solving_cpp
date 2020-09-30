#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

const int MAX = 15;
const int dx[] = { 0, -1, 1, 0, 0 };
const int dy[] = { 0, 0, 0, -1, 1 };

int M, N, min_cnt = INT_MAX;
bool board[MAX][MAX], flip[MAX][MAX], answer[MAX][MAX];

void bread(int x, int y, bool board[MAX][MAX]);
int get_count(int k);
bool is_all_front(bool board[MAX][MAX]);

int main(int argc, char const *argv[])
{
    cin >> M >> N;

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    for (int i = 0; i < (1 << N); i++)
    {
        int cnt = get_count(i);

        if (cnt < min_cnt)
        {
            min_cnt = cnt;
            copy(&flip[0][0], &flip[0][0] + MAX * MAX, &answer[0][0]);
        }
    }

    if (min_cnt == INT_MAX)
        cout << "IMPOSSIBLE" << "\n";
    else
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
                cout << answer[i][j] << " ";
            cout << "\n";
        }

    return 0;
}

int get_count(int k)
{
    bool board_copy[MAX][MAX];
    copy(&board[0][0], &board[0][0] + MAX * MAX, &board_copy[0][0]);
    fill_n(&flip[0][0], MAX * MAX, false);

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        if (k & (1 << i))
        {
            cnt += 1;
            flip[0][N - 1 - i] = 1;
            bread(0, N - 1 - i, board_copy);
        }
    }

    for (int i = 1; i < M; i++)
        for (int j = 0; j < N; j++)
            if (board_copy[i - 1][j])
            {
                cnt += 1;
                flip[i][j] = 1;
                bread(i, j, board_copy);
            }
    
    if (!is_all_front(board_copy))
        return INT_MAX;
    
    return cnt;
}

void bread(int x, int y, bool board[MAX][MAX])
{
    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        
        board[nx][ny] = !board[nx][ny];
    }
}

bool is_all_front(bool board[MAX][MAX])
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j])
                return false;
    return true;
}
