#include <iostream>
#include <algorithm>

using namespace std;

int N, count_o, count_x;
string board, result;
bool is_possible = false;
bool visited[9];

void backtracking(int depth, char prev_turn);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true)
    {
        result = ".........";
        is_possible = false;

        cin >> board;

        if (board == "end")
            break;
        
        count_o = count(board.begin(), board.end(), 'O');
        count_x = count(board.begin(), board.end(), 'X');
        N = count_o + count_x;

        backtracking(0, 'O');

        if (is_possible)
            cout << "valid" << "\n";
        else
            cout << "invalid" << "\n";
    }
    return 0;
}

bool is_win(char c)
{
    if (result[0] == c && result[0] == result[1] && result[1] == result[2])
        return true;
    if (result[3] == c && result[3] == result[4] && result[4] == result[5])
        return true;
    if (result[6] == c && result[6] == result[7] && result[7] == result[8])
        return true;

    if (result[0] == c && result[0] == result[3] && result[3] == result[6])
        return true;
    if (result[1] == c && result[1] == result[4] && result[4] == result[7])
        return true;
    if (result[2] == c && result[2] == result[5] && result[5] == result[8])
        return true;

    if (result[0] == c && result[0] == result[4] && result[4] == result[8])
        return true;
    if (result[2] == c && result[2] == result[4] && result[4] == result[6])
        return true;
    
    return false;
}

void backtracking(int depth, char prev_turn)
{
    if (is_possible)
        return;

    if (depth == N)
    {
        bool win_x = is_win('X'), win_o = is_win('O');

        if (win_x && !win_o)
        {
            if (count_x == count_o + 1)
                is_possible = true;
        }
        else if (!win_x && win_o)
        {
            if (count_x == count_o)
                is_possible = true;
        }
        else if (!win_x && !win_o)
        {
            if (N == 9)
                is_possible = true;
        }

        return;
    }

    for (int i = 0; i < 9; i++)
    {
        if (visited[i] || board[i] == '.' || board[i] == prev_turn)
            continue;
        
        visited[i] = true;
        result[i] = board[i];
        backtracking(depth + 1, board[i]);
        visited[i] = false;
        result[i] = '.';
    }
}
