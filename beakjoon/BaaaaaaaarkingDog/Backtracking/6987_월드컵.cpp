#include <iostream>

using namespace std;

int result[6][3];
int simulation[6][3];
int visited[6];
bool is_possible;

void backtracking(int depth, int x, int y);

int main(int argc, char const *argv[])
{
    int M = 4;

    while (M--)
    {
        fill_n(&simulation[0][0], 6 * 3, 0);
        fill_n(&visited[0], 6, 0);
        is_possible = false;

        int cnt = 0;

        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
            {
                cin >> result[i][j];
                cnt += result[i][j];
            }
        
        if (cnt == 30)
            backtracking(0, 0, 1);

        cout << is_possible << " ";
    }

    cout << "\n";
    
    return 0;
}

void backtracking(int depth, int x, int y)
{
    if (is_possible)
        return;

    if (x == 6)
    {
        is_possible = true;
        return;
    }

    if (y == 6)
    {
        backtracking(depth, x + 1, x + 2);
        return;
    }

    if (simulation[x][0] < result[x][0] && simulation[y][2] < result[y][2])
    {
        simulation[x][0] += 1, simulation[y][2] += 1;
        backtracking(depth + 1, x, y + 1);
        simulation[x][0] -= 1, simulation[y][2] -= 1;
    }

    if (simulation[x][1] < result[x][1] && simulation[y][1] < result[y][1])
    {
        simulation[x][1] += 1, simulation[y][1] += 1;
        backtracking(depth + 1, x, y + 1);
        simulation[x][1] -= 1, simulation[y][1] -= 1;
    }

    if (simulation[x][2] < result[x][2] && simulation[y][0] < result[y][0])
    {
        simulation[x][2] += 1, simulation[y][0] += 1;
        backtracking(depth + 1, x, y + 1);
        simulation[x][2] -= 1, simulation[y][0] -= 1;
    }
}
