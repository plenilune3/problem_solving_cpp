#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX = 9;

int N, board[MAX][MAX];
bool row[MAX][MAX + 1], column[MAX][MAX + 1], square[MAX][MAX + 1];
bool is_possible;
vector< pair<int, int> > v;

void play(int depth);
void print_board();
int get_squre(int x, int y);

int main(int argc, char const *argv[])
{
    for (int i = 0; i < MAX; i++)
    {
        string input;
        cin >> input;

        for (int j = 0; j < MAX; j++)
        {
            board[i][j] = input[j] - '0';

            if (board[i][j] == 0)
            {
                v.push_back(make_pair(i, j));
            }
            else
            {
                row[i][board[i][j]] = column[j][board[i][j]] = square[get_squre(i, j)][board[i][j]] = true;
            }
        }
    }

    N = v.size();
    play(0);

    return 0;
}

void print_board()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
            cout << board[i][j];
        cout << "\n";
    }
}

int get_squre(int x, int y)
{
    return x / 3 * 3 + y / 3;
}

void play(int depth)
{
    if (is_possible)
        return;
    
    if (depth == N)
    {
        is_possible = true;
        print_board();
        return;
    }

    int x = v[depth].first, y = v[depth].second;

    for (int j = 1; j <= MAX; j++)
    {
        if (row[x][j] || column[y][j] || square[get_squre(x, y)][j])
            continue;
        
        row[x][j] = column[y][j] = square[get_squre(x, y)][j] = true;
        board[x][y] = j;
        play(depth + 1);
        row[x][j] = column[y][j] = square[get_squre(x, y)][j] = false;
        board[x][y] = 0;
    }
}
