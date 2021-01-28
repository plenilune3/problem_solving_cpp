#include <iostream>

using namespace std;

const int MAX = (1 << 7);

int K, x, y, num;
int tile[MAX][MAX];

void install_(int length, int x, int y);
bool is_possible(int length, int x, int y);

int main(int argc, char const *argv[])
{
    cin >> K;
    cin >> y >> x;

    int length = (1 << K);

    tile[(length - 1) - (x - 1)][y - 1] = -1;

    install_(length, 0, 0);

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
            cout << tile[i][j] << " "; 
        cout << "\n";
    }

    return 0;
}

void install_(int length, int x, int y)
{
    num += 1;

    int l = length / 2;

    if (is_possible(l, x, y)) tile[x + l - 1][y + l - 1] = num;
    if (is_possible(l, x + l, y)) tile[x + l][y + l - 1] = num;
    if (is_possible(l, x, y + l)) tile[x + l - 1][y + l] = num;
    if (is_possible(l, x + l, y + l)) tile[x + l][y + l] = num;

    if (length == 2) return;

    install_(l, x, y);
    install_(l, x + l, y);
    install_(l, x, y + l);
    install_(l, x + l, y + l);
}

bool is_possible(int length, int x, int y)
{
    for (int i = x; i < x + length; i++)
        for (int j = y; j < y + length; j++)
            if (tile[i][j] != 0)
                return false;
    return true;
}
