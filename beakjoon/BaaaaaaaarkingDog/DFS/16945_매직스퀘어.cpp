#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 3;

int answer = INT_MAX;
int board[MAX][MAX];
int squre[MAX][MAX];
bool visited[10];

bool is_magic_squre();
int get_cost();
void find_min_cost(int depth);

int main(int argc, char const *argv[])
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cin >> board[i][j];
    
    find_min_cost(0);
    cout << answer << "\n";

    return 0;
}

void find_min_cost(int depth)
{
    if (depth == 9)
    {
        if (is_magic_squre())
            answer = min(answer, get_cost());
        return;
    }
    
    int x = depth / 3, y = depth % 3;
    for (int i = 1; i <= 9; i++)
    {
        if (visited[i])
            continue;
        
        visited[i] = true;
        squre[x][y] = i;
        find_min_cost(depth + 1);
        visited[i] = false;
    }
}

int get_cost()
{
    int cost = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cost += abs(board[i][j] - squre[i][j]);
    
    return cost;
}

bool is_magic_squre()
{
    int sum = squre[0][0] + squre[0][1] + squre[0][2];

    if (sum != (squre[1][0] + squre[1][1] + squre[1][2])) return false;
    if (sum != (squre[2][0] + squre[2][1] + squre[2][2])) return false;

    if (sum != (squre[0][0] + squre[1][0] + squre[2][0])) return false;
    if (sum != (squre[0][1] + squre[1][1] + squre[2][1])) return false;
    if (sum != (squre[0][2] + squre[1][2] + squre[2][2])) return false;

    if (sum != (squre[0][0] + squre[1][1] + squre[2][2])) return false;
    if (sum != (squre[0][2] + squre[1][1] + squre[2][0])) return false;

    return true;
}
