#include <iostream>

using namespace std;

const int MAX = 18;

int N;
bool board[MAX][MAX];

int dfs(int x, int y, int d);
bool is_out_of_range(int x, int y);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++) 
        for (int j = 1; j <= N; j++)
            cin >> board[i][j];
    
    int answer = dfs(1, 2, 0);

    cout << answer << "\n";

    return 0;
}

bool is_out_of_range(int x, int y)
{
    return x < 1 || x > N || y < 1 || y > N;
}

int dfs(int x, int y, int d)
{
    if (x == N && y == N)
        return 1;
    
    int ret = 0;

    if (!is_out_of_range(x + 1, y + 1) && !board[x][y + 1] && !board[x + 1][y + 1] && !board[x + 1][y])
        ret += dfs(x + 1, y + 1, 2);
    
    if (d != 0 && !is_out_of_range(x + 1, y) && !board[x + 1][y])
        ret += dfs(x + 1, y, 1);
    
    if (d != 1 && !is_out_of_range(x, y + 1) && !board[x][y + 1])
        ret += dfs(x, y + 1, 0);

    return ret;
}
