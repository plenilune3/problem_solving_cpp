#include <iostream>
#include <vector>

using namespace std;

const int MAX = 9;

int board[MAX][MAX], N;
int answer[MAX][MAX];
bool is_finished = false;
bool row[MAX][MAX + 1], column[MAX][MAX + 1], square[MAX][MAX + 1];
vector< pair<int, int> > v;

int get_square_number(int x, int y);
void backtracking(int depth);

int main(int argc, char const *argv[])
{
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
        {
            cin >> board[i][j];

            int num = board[i][j];

            if (num)
            {
                int square_number = get_square_number(i, j);
                row[i][num] = column[j][num] = square[square_number][num] = true;
            }
            else
                v.push_back(make_pair(i, j));
        }
    
    N = v.size();
    backtracking(0);

    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
            cout << answer[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

int get_square_number(int x, int y)
{
    return x / 3 * 3 + y / 3;
}

void backtracking(int depth)
{    
    if (is_finished)
        return;

    if (depth == N)
    {
        is_finished = true;
        copy(&board[0][0], &board[0][0] + MAX * MAX, &answer[0][0]);
        return;
    }

    int x = v[depth].first, y = v[depth].second;
    int square_number = get_square_number(x, y);

    for (int i = 1; i <= MAX; i++)
    {
        if (row[x][i] || column[y][i] || square[square_number][i])
            continue;
        
        row[x][i] = column[y][i] = square[square_number][i] = true;
        board[x][y] = i;
        backtracking(depth + 1);
        row[x][i] = column[y][i] = square[square_number][i] = false;
        board[x][y] = 0;
    }
}