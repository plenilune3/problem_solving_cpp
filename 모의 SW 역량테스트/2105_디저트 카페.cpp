#include <iostream>

using namespace std;

const int MAX = 20;
const int dx[] = { 1, 1, -1, -1 };
const int dy[] = { 1, -1, -1, 1 };

int cafe[MAX][MAX];
bool desert[101];
int N, answer;

void backtracking(int x, int y, int d, int cnt, int sx, int sy)
{
    if (d == 4)
        return;
    
    if (x == sx && y == sy && d == 3)
    {
        answer = max(answer, cnt);
        return;
    }

    if (desert[cafe[x][y]])
        return;
    
    desert[cafe[x][y]] = true;

    int nx = x + dx[d], ny = y + dy[d];

    if (nx >= 0 && nx < N && ny >= 0 && ny < N)
    {
        backtracking(nx, ny, d, cnt + 1, sx, sy);
        backtracking(nx, ny, d + 1, cnt + 1, sx, sy);
    }

    desert[cafe[x][y]] = false;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        cin >> N;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> cafe[i][j];
        
        answer = -1;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                backtracking(i, j, 0, 0, i, j);
        
        cout << "#" << t << " " << answer << "\n";
    }
    
    return 0;
}

