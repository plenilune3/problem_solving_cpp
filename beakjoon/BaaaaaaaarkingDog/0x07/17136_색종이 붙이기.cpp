#include <iostream>
#include <climits>

using namespace std;

const int N = 10;

bool A[N][N];
int paper[6] = {0, 5, 5, 5, 5, 5};
int length, answer = INT_MAX;

bool is_possible(int x, int y, int s)
{
    bool possible = true;

    if (x + s > N || y + s > N)
        possible = false;
    else
    {
        for (int i = x; i < x + s; i++)
        {
            for (int j = y; j < y + s; j++)
                if (A[i][j] == false)
                {
                    possible = false;
                    break;
                }
            if (possible == false)
                break;
        }
    }

    return possible;
}

void attach(int x, int y, int s)
{
    paper[s] -= 1;
    for (int i = x; i < x + s; i++)
        for (int j = y; j < y + s; j++)
            A[i][j] = false;
}

void detach(int x, int y, int s)
{
    paper[s] += 1;
    for (int i = x; i < x + s; i++)
        for (int j = y; j < y + s; j++)
            A[i][j] = true;
}

void backtracking(int depth, int x, int y, int cnt)
{
    if (answer <= cnt)
        return;

    if (x == N)
    {
        bool finished = true;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                if (A[i][j])
                {
                    finished = false;
                    break;
                }
            
            if (finished == false)
                break;
        }

        if (finished)
            answer = min(answer, cnt);

        return;
    }

    if (y == N)
    {
        backtracking(depth + 1, x + 1, 0, cnt);
        return;
    }

    if (A[x][y])
        for (int s = 1; s <= 5; s++)
        {
            if (paper[s] > 0 && is_possible(x, y, s))
            {
                attach(x, y, s);
                backtracking(depth + 1, x, y + 1, cnt + 1);
                detach(x, y, s);
            }
        }
    else
        backtracking(depth + 1, x, y + 1, cnt);

}


int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    
    backtracking(0, 0, 0, 0);
    
    if (answer == INT_MAX)
        cout << -1 << "\n";
    else
        cout << answer << "\n";

    return 0;
}