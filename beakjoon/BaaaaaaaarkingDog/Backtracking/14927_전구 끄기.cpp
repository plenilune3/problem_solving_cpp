#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 18;
const int dx[] = { 0, -1, 1, 0, 0 };
const int dy[] = { 0, 0, 0, -1, 1 };

int N, answer = INT_MAX;
bool board[MAX][MAX];
bool visited[MAX];

void flip(int x, int y, bool board[MAX][MAX]);
bool is_all_off(bool board[MAX][MAX]);
int turn_off();
void combinations(int depth, int index);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    combinations(0, 0);

    if (answer != INT_MAX)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

void flip(int x, int y, bool board[MAX][MAX])
{
    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0|| ny >= N)
            continue;
        
        board[nx][ny] = !board[nx][ny];
    }
}

bool is_all_off(bool board[MAX][MAX])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j])
                return false;
    
    return true;
}

int turn_off()
{
    int cnt = 0;
    bool board_c[MAX][MAX];
    copy(&board[0][0], &board[0][0] + MAX * MAX, &board_c[0][0]);

    for (int i = 0; i < N; i++)
        if (visited[i])
        {
            cnt += 1;
            flip(0, i, board_c);
        }
    
    for (int i = 1; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board_c[i-1][j])
            {
                cnt += 1;
                flip(i, j, board_c);
            }
    
    if (!is_all_off(board_c))
        return INT_MAX;
    
    return cnt;
}

void combinations(int depth, int index)
{
    int cnt = turn_off();

    answer = min(answer, cnt);

    for (int i = index; i < N; i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        combinations(depth + 1, i);
        visited[i] = false;
    }
}
