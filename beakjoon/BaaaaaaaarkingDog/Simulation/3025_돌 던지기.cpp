#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int R, C, N;

    cin >> R >> C;

    char board[R][C];
    

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> board[i][j];
    
    cin >> N;

    while (N--)
    {
        int r;
        cin >> r;
    }
    
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            cout << board[i][j];
        cout << "\n";
    }

    return 0;
}

