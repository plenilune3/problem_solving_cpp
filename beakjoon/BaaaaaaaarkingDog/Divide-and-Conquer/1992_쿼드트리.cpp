#include <iostream>

using namespace std;

const int MAX = 65;

int N;
char board[MAX][MAX];

bool check(int x, int y, int length);
string quad(int x, int y, int length);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> board[i];
    
    cout << quad(0, 0, N) << "\n";

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

string quad(int x, int y, int length)
{
    if (check(x, y, length))
        return string(1, board[x][y]);

    string result = "";
    int l = length / 2;

    result.append("(");

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            result.append(quad(x + l * i, y + l * j, l));
    
    result.append(")");

    return result;
}
