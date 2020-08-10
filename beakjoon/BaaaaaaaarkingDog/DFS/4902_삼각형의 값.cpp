#include <iostream>
#include <climits>

using namespace std;

const int MAX = 401;

int N, answer;
int A[MAX][2 * (MAX - 1) + 1];
int AC[MAX][2 * (MAX - 1) + 1];

void dfs(int x, int yleft, int yright, int result)
{
    if (x == N + 1 || yleft < 1 || yright > 2 * (x - 1) + 1)
        return;
    
    result += AC[x][yright] - AC[x][yleft - 1];
    answer = max(answer, result);

    if (yleft % 2)
        dfs(x + 1, yleft, yright + 2, result);
    else
        dfs(x - 1, yleft - 2, yright, result);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int case_num = 1;

    while (true)
    {
        answer = INT_MIN;

        cin >> N;

        if (N == 0)
            break;

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= 2 * (i - 1) + 1; j++)
            {
                cin >> A[i][j];
                AC[i][j] = AC[i][j - 1]  + A[i][j];
            }
        
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= 2 * (i - 1) + 1; j++)
                dfs(i, j, j, 0);

        cout << case_num++ << ". " << answer << "\n";
    }

    return 0;
}
