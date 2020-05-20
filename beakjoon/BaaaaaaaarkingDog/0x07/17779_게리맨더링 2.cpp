#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 22;

int N, answer = INT_MAX;
int A[MAX][MAX];

void gerrymandering(int x, int y, int a, int b, int C[MAX][MAX])
{
    for (int i = 0; i <= a; i++)
        C[x + i][y - i] = 5;
    
    for (int i = 0; i <= b; i++)
        C[x + i][y + i] = 5;
    
    for (int i = 0; i <= b; i++)
        C[x + a + i][y - a + i] = 5;
    
    for (int i = 0; i <= a; i++)
        C[x + b + i][y + b - i] = 5;
    
    for (int r = 1; r <= N; r++)
    {
        int p = -1;
        for (int c  = 1; c <= N; c++)
        {
            if (C[r][c] == 5 && p == -1)
                p = c;
            else if (C[r][c] == 5 && p != -1)
                for (int i = p; i <= c; i++)
                    C[r][i] = 5;
        }
    }
    
    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++)
        {
            if (r >= 1 && r < x + a && c >= 1 && c <= y && C[r][c] != 5)
                C[r][c] = 1;
            
            if (r >= 1 && r <= x + b && c > y && c <= N && C[r][c] != 5)
                C[r][c] = 2;
            
            if (r >= x + a && r <= N && c >= 1 && c < y - a + b && C[r][c] != 5)
                C[r][c] = 3;
            
            if (r > x + b && r <= N && c >= y - a + b && c <= N && C[r][c] != 5)
                C[r][c] = 4;
        }
}

int get_difference(int C[MAX][MAX])
{
    int population[5] = { 0 };

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            population[C[i][j] - 1] += A[i][j];
    
    sort(population, population + 5);

    return population[4] - population[0];
}

void dfs(int depth, int x, int y)
{
    if (x == N + 1)
        return;

    if (y == N + 1)
    {
        dfs(depth + 1, x + 1, 1);
        return;
    }

    for (int a = 1; a <= N; a++)
        for (int b = 1; b <= N; b++)
            if (x >= 1 && x < x + a + b && x + a + b <= N && y - a >= 1 && y - a < y && y < y + b && y + b <= N)
                {
                    int C[MAX][MAX] = { 0 };
                    gerrymandering(x, y, a, b, C);
                    answer = min(answer, get_difference(C));
                }
    
    dfs(depth + 1, x, y + 1);
}


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];

    dfs(0, 1, 1);

    cout << answer << "\n";

    return 0;
}
