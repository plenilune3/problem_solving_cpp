#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 11;
const int MAX_M = 11;
const int MAX_H = 31;

int N, M, H, K, answer = 4;
int board[MAX_H][MAX_N];
bool selected[MAX_H * MAX_N];
vector< pair<int, int> > v;

bool is_possible(int x, int y);
bool is_manipulated();
void backtracking(int depth, int index);

int main(int argc, char const *argv[])
{
    cin >> N >> M >> H;

    while (M--)
    {
        int a, b; cin >> a >> b;
        board[a - 1][b - 1] = true;
    }

    for (int x = 0; x < H; x++)
        for (int y = 0; y < N - 1; y++)
            if (is_possible(x, y))
                v.push_back(make_pair(x, y));

    K = (int) v.size();

    backtracking(0, 0);

    if (answer != 4)
        cout << answer << "\n";
    else
        cout << -1 << "\n";
    
    return 0;
}

void backtracking(int depth, int index)
{   
    if (is_manipulated())
    {
        answer = min(answer, depth);
        return;
    }

    if (depth == 3 || depth >= answer)
        return;
 
    for (int i = index; i < K; i++)
    {
        if (selected[i]) continue;

        int x = v[i].first, y = v[i].second;

        if (!is_possible(x, y))
            continue;
        
        selected[i] = true;
        board[x][y] = true;
        backtracking(depth + 1, i);
        selected[i] = false;
        board[x][y] = false;
    }
}

bool is_manipulated()
{
    for (int y = 0; y < N; y++)
    {
        int play = y;

        for (int x = 0; x < H; x++)
            if (board[x][play])
                play += 1;
            else if (play - 1 >= 0 && board[x][play - 1])
                play -= 1;
        
        if (play != y)
            return false;
    }

    return true;
}

bool is_possible(int x, int y)
{
    if (board[x][y])
        return false;

    if (y - 1 >= 0 && board[x][y - 1])
        return false;
    
    if (y + 1 <= N - 1 && board[x][y + 1])
        return false;
    
    return true;
}