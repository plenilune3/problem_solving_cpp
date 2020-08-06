#include <iostream>

using namespace std;

int N, r, c, answer;
bool isFinished;

void ZSearch(int x, int y, int size);

int main(int argc, char const *argv[])
{
    cin >> N >> r >> c;

    ZSearch(0, 0, (1 << N));

    cout << answer << "\n";

    return 0;
}

void ZSearch(int x, int y, int length)
{
    if (isFinished)
        return;
    
    if (x == r && y == c)
    {
        isFinished = true;
        return;
    }

    if (r >= x && r < x + length && c >= y && c < y + length)
    {
        int nextLength = length / 2;

        ZSearch(x, y, nextLength);
        ZSearch(x, y + nextLength, nextLength);
        ZSearch(x + nextLength, y, nextLength);
        ZSearch(x + nextLength, y + nextLength, nextLength);
    }
    else
        answer += length * length;
}
