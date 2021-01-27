#include <iostream>

using namespace std;

const int MAX = 26;

int N, K;
char board[MAX];
bool visited[26];

void rotate_(int S);
bool is_impossible(char a);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    fill_n(&board[0], N, '?');

    bool possible = true;

    while (K--)
    {
        int S; char a; cin >> S >> a;

        rotate_(S);

        if (is_impossible(a))
        {
            possible = false;
            break;
        }

        visited[a - 'A'] = true;
        board[0] = a;
    }

    if (possible)
    {
        for (int i = 0; i < N; i++)
            cout << board[i];
        cout << "\n";
    }
    else
        cout << "!" << "\n";

    return 0;
}

void rotate_(int S)
{
    char board_c[MAX];
    copy(&board[0], &board[0] + MAX, &board_c[0]);

    for (int i = 0; i < N; i++)
        board[(i + S) % N] = board_c[i];
}

bool is_impossible(char a)
{
    if (visited[a - 'A'])
    {
        if (board[0] == a) return false;
        else return true;
    }
    else
    {
        if (board[0] != '?') return true;
        else return false;
    }
}
