#include <iostream>
#include <string>
#include <map>

using namespace std;

const int N = 5;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int answer;
string board[N][N];
map<string, bool> visited;

void dfs(int depth, int x, int y, string s)
{
    if (depth == 6)
    {
        if (visited[s] == false)
        {
            visited[s] = true;
            answer += 1;
        }
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;

        dfs(depth + 1, nx, ny, s + board[nx][ny]);
    }

}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dfs(0, i, j, "");
    
    cout << answer << "\n";

    return 0;
}

