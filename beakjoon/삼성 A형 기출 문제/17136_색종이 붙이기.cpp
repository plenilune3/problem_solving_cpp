#include <iostream>

using namespace std;

const int MAX = 10;

int answer = MAX * MAX;
int paper_counter[5];
bool board[MAX][MAX];

void backtacking(int x, int y, int result);
bool is_finished();
bool is_possible(int x, int y, int d);
void attach(int x, int y, int d);
void dettach(int x, int y, int d);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    fill_n(&paper_counter[0], 5, 5);

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cin >> board[i][j];
    
    backtacking(0, 0, 0);

    if (answer != MAX * MAX)
        cout << answer << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

void backtacking(int x, int y, int result)
{
    if (result >= answer)
        return;
        
    if (x == MAX)
    {
        if (is_finished())
            answer = min(answer, result);

        return;
    }
    
    if (y == MAX)
    {
        backtacking(x + 1, 0, result);
        return;
    }

    if (board[x][y])
    {
        for (int d = 0; d < 5; d++)
        {
            if (paper_counter[d] == 0 || !is_possible(x, y, d))
                continue;
            
            paper_counter[d] -= 1;
            attach(x, y, d);
            backtacking(x, y + 1, result + 1);
            paper_counter[d] += 1;
            dettach(x, y, d);
        }
    }
    else
    {
        backtacking(x, y + 1, result);
    }
}

bool is_possible(int x, int y, int d)
{
    if (x + d >= MAX || y + d >= MAX)
        return false;
    
    for (int i = x; i <= x + d; i++)
        for (int j = y; j <= y + d; j++)
            if (board[i][j] == false)
                return false;
    
    return true;
}

bool is_finished()
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            if (board[i][j])
                return false;
    
    return true;
}

void attach(int x, int y, int d)
{
    for (int i = x; i <= x + d; i++)
        for (int j = y; j <= y + d; j++)
            board[i][j] = 0;
}

void dettach(int x, int y, int d)
{
    for (int i = x; i <= x + d; i++)
        for (int j = y; j <= y + d; j++)
            board[i][j] = 1;
}

