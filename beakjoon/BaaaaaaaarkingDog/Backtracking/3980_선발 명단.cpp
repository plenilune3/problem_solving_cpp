#include <iostream>
#include <algorithm>

using namespace std;

int T, answer;
int board[11][11];
bool visited[11];

void make_starting_lineup(int depth, int result);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;

    while (T--)
    {
        answer = -1;
        fill_n(&visited[0], 11, false);

        for (int i = 0; i < 11; i++)
            for (int j = 0; j < 11; j++)
                cin >> board[i][j];

        make_starting_lineup(0, 0);

        cout << answer << "\n";
    }

    return 0;
}

void make_starting_lineup(int depth, int result)
{
    if (depth == 11)
    {
        answer = max(answer, result);
        return;
    }

    for (int i = 0; i < 11; i++)
        if (visited[i] == false && board[depth][i] > 0)
        {
            visited[i] = true;
            make_starting_lineup(depth + 1, result + board[depth][i]);
            visited[i] = false;
        }
}
