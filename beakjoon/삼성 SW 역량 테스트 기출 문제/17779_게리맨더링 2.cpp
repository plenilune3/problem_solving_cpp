#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 22;

int N;
int population[MAX][MAX];
int board[MAX][MAX];

int gerrymandering();
void divide(int x, int y, int d1, int d2);
bool is_possible(int x, int y, int d1, int d2);
int get_differnce();

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> population[i][j];
    
    int answer = gerrymandering();

    cout << answer << "\n";

    return 0;
}

int gerrymandering()
{
    int min_difference = INT_MAX;

    for (int x = 1; x <= N; x++)
        for (int y = 1; y <= N; y++)
            for (int d1 = 1; d1 <= N / 2; d1++)
                for (int d2 = 1; d2 <= N / 2; d2++)
                    if (is_possible(x, y, d1, d2))
                    {
                        divide(x, y, d1, d2);
                        min_difference = min(min_difference, get_differnce());
                    }
    
    return min_difference;
}

int get_differnce()
{
    int temp[5] = { 0 };

    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++)
            temp[board[r][c] - 1] += population[r][c];
    
    sort(temp, temp + 5);

    return temp[4] - temp[0];
}

void divide(int x, int y, int d1, int d2)
{
    fill_n(&board[0][0], MAX * MAX, 0);

    for (int i = 0; i <= d1; i++)
    {
        board[x + i][y - i] = 5;
        board[x + d2 + i][y + d2 - i] = 5;
    }

    for (int i = 0; i <= d2; i++)
    {
        board[x + i][y + i] = 5;
        board[x + d1 + i][y - d1 + i] = 5;
    }

    for (int r = 1; r <= N; r++)
    {
        int start = -1, end = -1;

        for (int c = 1; c <= N; c++)
            if (board[r][c] == 5)
                start == -1 ? start = c : end = c;
        
        if (start != -1 && end != -1)
            for (int c = start; c <= end; c++)
                board[r][c] = 5;
    }

    for (int r = 1; r <= N; r++)
        for (int c = 1; c <= N; c++)
        {
            if (r < x + d1 && c <= y && board[r][c] != 5)
                board[r][c] = 1;
            
            if (r <= x + d2 && c > y && c <= N && board[r][c] != 5)
                board[r][c] = 2;
            
            if (r >= x + d1 && r <= N && c < y - d1 + d2 && board[r][c] != 5)
                board[r][c] = 3;
            
            if (r > x + d2 && r <= N && c >= y - d1 + d2 && c <= N && board[r][c] != 5)
                board[r][c] = 4;
        }
}

bool is_possible(int x, int y, int d1, int d2)
{
    if (x + d1 + d2 <= N && y - d1 >= 1 && y + d2 <= N)
        return true;

    return false;
}
