#include <iostream>

using namespace std;

const int MAX = 1e3 + 1;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int M, N;
bool board[MAX][MAX];
bool visited[MAX][MAX];

bool find_path(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        string row; cin >> row;

        for (int j = 0; j < N; j++)
            board[i][j] = row[j] == '1' ? true : false;
    }

    bool possible = false;

    for (int j = 0; j < N; j++)
    {
        if (board[0][j] || visited[0][j])
            continue;
        
        possible = find_path(0, j);

        if (possible)
            break;
    }
    
    if (possible)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
    
    return 0;
}

bool find_path(int x, int y)
{
    visited[x][y] = true;

    if (x == M - 1)
        return true;
    
    bool is_possible = false;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        
        if (board[nx][ny] || visited[nx][ny])
            continue;
        
        is_possible += find_path(nx, ny);

        if (is_possible)
            break;
    }

    return is_possible;
}