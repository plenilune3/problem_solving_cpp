#include <iostream>

using namespace std;

const int MAX = 9;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int N, M, answer;
int lab[MAX][MAX];
bool visited[MAX][MAX];

int dfs(int depth, int x, int y)
{
    int result = 1;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if (lab[nx][ny] != 0 || visited[nx][ny] == true)
            continue;
        
        result += dfs(depth + 1, nx, ny);
    }

    return result;
}

void backtracking(int depth, int x, int y)
{
    if (depth == 3)
    {
        int virus = 0;
        int wall = 0;
        fill_n(&visited[0][0], MAX*MAX, false);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                if (lab[i][j] == 2)
                    virus += dfs(0, i, j);
                if (lab[i][j] == 1)
                    wall++;
            }

        answer = max(answer, N*M - virus - wall);
        return;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (lab[i][j] == 0)
            {
                lab[i][j] = 1;
                backtracking(depth + 1, i, j);
                lab[i][j] = 0;
            }
}


int main(int argc, char const *argv[])
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> lab[i][j];
    
    backtracking(0, 0, 0);

    cout << answer << "\n";
    
    return 0;
}
