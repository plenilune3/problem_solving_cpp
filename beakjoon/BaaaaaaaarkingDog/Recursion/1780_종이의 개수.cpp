#include <iostream>

using namespace std;

const int MAX = 2187;

int N;
int board[MAX][MAX];
int counter[3];

void find_(int x, int y, int length);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
        
    find_(0, 0, N);

    for (int i = 0; i < 3; i++)
        cout << counter[i] << "\n";

    return 0;
}

bool check(int x, int y, int length)
{
    for (int i = x; i < x + length; i++)
        for (int j = y; j < y + length; j++)
            if (board[x][y] != board[i][j])
                return false;
    
    return true;
}

void find_(int x, int y, int length)
{
    if (check(x, y, length))
    {
        counter[board[x][y] + 1] += 1;
        return;
    }

    int l = length / 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            find_(x + (l * i), y + (l * j), l);
}