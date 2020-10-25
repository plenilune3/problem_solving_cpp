#include <iostream>

using namespace std;

const int MAX = (1 << 7);

int N;
bool board[MAX][MAX];
int counter[2]; 

void find_(int x, int y, int length);
bool check(int x, int y, int length);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    find_(0, 0, N);

    for (int i = 0; i < 2; i++)
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
        counter[board[x][y]] += 1;
        return;
    }

    int l = length / 2;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            find_(x + i * l, y + j * l, l);
}