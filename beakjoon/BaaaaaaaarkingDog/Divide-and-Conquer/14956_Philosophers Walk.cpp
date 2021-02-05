#include <iostream>

using namespace std;

int N, M, X, Y;

void d2xy(int length, int target, int &x, int &y);
void rotate_(int length, int &x, int &y, int rx, int ry);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    d2xy(N, M - 1, X, Y);

    cout << X + 1 << " " << Y + 1 << "\n";

    return 0;
}

void d2xy(int length, int target, int &x, int &y)
{
    int rx, ry, t = target;
    x = y = 0;

    for (int s = 1; s < length; s *= 2)
    {
        int rx = 1 & (t / 2), ry = 1 & (t ^ rx);
        rotate_(s, x, y, rx, ry);
        x += s * rx, y += s * ry;
        t /= 4;
    }
}

void rotate_(int length, int &x, int &y, int rx, int ry)
{
    if (ry == 0)
    {
        if (rx == 1)
        {
            x = length - 1 - x;
            y = length - 1 - y;
        }

        swap(x, y);
    }
}