#include <iostream>

using namespace std;

long long X, Y;

int find_game(long long Z);

int main(int argc, char const *argv[])
{
    cin >> X >> Y;

    long long Z = (Y * 100) / X;

    if (Z == 99 || Z == 100)
        cout << -1 << "\n";
    else
    {
        int answer = find_game(Z);
        cout << answer << "\n";
    }

    return 0;
}

int find_game(long long Z)
{
    int left = 1, right = X;
    int game = 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long winning_rate = ((Y + mid) * 100) / (X + mid);

        if (winning_rate <= Z)
            left = mid + 1;
        else
        {
            game = mid;
            right = mid - 1;
        }
    }

    return game;
}
