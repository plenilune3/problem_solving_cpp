#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 5e5 + 1;

int N, M, answer = MAX + 1;
bool is_broken[10];

int is_possible(int channel);

int main(int argc, char const *argv[])
{
    cin >> N >> M;

    while (M--)
    {
        int num; cin >> num;
        is_broken[num] = true;
    }

    int diff = abs(N - 100);
    answer = min(answer, diff);

    for (int channel = 0; channel < MAX * 2; channel++)
    {
        int length = is_possible(channel);

        if (length == -1)
            continue;
        
        diff = abs(channel - N);
        answer = min(answer, diff + length);
    }

    cout << answer << "\n";

    return 0;
}

int is_possible(int channel)
{
    int length = 0;
    bool possible = true;

    if (channel == 0)
        return is_broken[0] ? -1 : 1;

    while (channel)
    {
        int q = channel / 10, r = channel % 10;
        length += 1;

        if (is_broken[r])
        {
            possible = false;
            break;
        }

        channel = q;
    }

    return possible ? length : -1;
}

