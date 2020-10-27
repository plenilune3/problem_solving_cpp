#include <iostream>

using namespace std;

int N, r, c, answer;
bool is_finished;

void search(int x, int y, int length);

int main(int argc, char const *argv[])
{
    cin >> N >> r >> c;

    search(0, 0, (1 << N));

    cout << answer << "\n";

    return 0;
}

void search(int x, int y, int length)
{
    if (is_finished)
        return;
    
    if (x == r && y == c)
    {
        is_finished = true;
        return;
    }

    if (r < x + length && c < y + length)
    {
        int next_length = length / 2;
        search(x, y, next_length);
        search(x, y + next_length, next_length);
        search(x + next_length, y, next_length);
        search(x + next_length, y + next_length, next_length);
    }
    else
        answer += length * length;
}
