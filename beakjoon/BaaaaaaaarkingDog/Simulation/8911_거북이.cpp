#include <iostream>

using namespace std;

const int dx[] = { -1, 0, 1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        int min_x = 0, max_x = 0;
        int min_y = 0, max_y = 0;
        int x = 0, y = 0, d = 0;

        string moves; cin >> moves;

        for (string::iterator i = moves.begin(); i != moves.end(); i++)
        {
            char move = (*i);

            if (move == 'F') x += dx[d], y += dy[d];
            else if (move == 'B') x -= dx[d], y -= dy[d];
            else if (move == 'L') d = (d + 3) % 4;
            else if (move == 'R') d = (d + 1) % 4;

            min_x = min(min_x, x), max_x = max(max_x, x);
            min_y = min(min_y, y), max_y = max(max_y, y);
        }

        int answer = (max_x - min_x) * (max_y - min_y);
        cout << answer << "\n";
    }

    return 0;
}
