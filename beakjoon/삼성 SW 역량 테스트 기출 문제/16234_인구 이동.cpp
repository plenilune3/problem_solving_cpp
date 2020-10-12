#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int N, L, R, num = 1;
int board[MAX][MAX], visited[MAX][MAX];
int alliance[MAX * MAX], population[MAX * MAX];

int ally(int depth, int x, int y, int num);
void move_population();

int main(int argc, char const *argv[])
{
    cin >> N >> L >> R;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    int answer = 0;
   
    while (true)
    {
        fill_n(&visited[0][0], MAX * MAX, 0);
        fill_n(&alliance[0], MAX * MAX, 0);
        fill_n(&population[0], MAX * MAX, 0);
        num = 1;

        for (int x = 0; x < N; x++)
            for (int y = 0; y < N; y++)
                if (visited[x][y] == 0)
                {
                    alliance[num] = ally(0, x, y, num);
                    num += 1;
                }
        
        if (num - 1 == N * N)
            break;

        move_population();

        answer += 1;
    }

    cout << answer << "\n";

    return 0;
}

int ally(int depth, int x, int y, int num)
{
    visited[x][y] = num;

    int ret = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        
        int diff = abs(board[x][y] - board[nx][ny]);
        
        if (visited[nx][ny] || diff < L || diff > R)
            continue;
        
        ret += ally(depth + 1, nx, ny, num);
    }

    return ret;
}

void move_population()
{
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            if (visited[x][y] != 0)
                population[visited[x][y]] += board[x][y];
    
    for (int i = 1; i < num; i++)
        population[i] = population[i] / alliance[i];
    
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            board[x][y] = population[visited[x][y]];
}
