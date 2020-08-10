#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, M, K, length;
char board[MAX][MAX];
int dp[MAX][MAX][80];
string word;

int dfs(int depth, int x, int y)
{
    if (dp[x][y][depth] != -1)
        return dp[x][y][depth];
    
    if (depth == length)
        return 1;
    
    dp[x][y][depth] = 0;
    
    for (int i = 0; i < 4; i++)
        for (int k = 1; k <= K; k++)
        {
            int nx = x + dx[i] * k, ny = y + dy[i] * k;

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            if (board[nx][ny] != word[depth])
                continue;
            
            dp[x][y][depth] += dfs(depth + 1, nx, ny);
        }

    return dp[x][y][depth];
}

int main(int argc, char const *argv[])
{
    int answer = 0;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];
    
    cin >> word;

    length = word.length();
    char wordInit = word[0];
    fill_n(&dp[0][0][0], MAX * MAX * 80, -1);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (board[i][j] == wordInit)
                answer += dfs(1, i, j);
    
    cout << answer << "\n";
    
    return 0;
}

