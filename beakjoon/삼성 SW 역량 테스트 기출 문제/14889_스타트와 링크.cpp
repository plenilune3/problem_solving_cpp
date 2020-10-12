#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 21;

int N, M, answer = INT_MAX;
int board[MAX][MAX];
bool visited[MAX];

void combinations(int depth, int index);

int main(int argc, char const *argv[])
{
    cin >> N;
    M = N / 2;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> board[i][j];
    
    combinations(0, 0);

    cout << answer << "\n";
    
    return 0;
}

void combinations(int depth, int index)
{
    if (depth == M)
    {
        int a = 0, b = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (visited[i] && visited[j])
                    a += board[i][j];

                if (!visited[i] && !visited[j])
                    b += board[i][j];
            }
        
        answer = min(answer, abs(a - b));

        return;
    }

    for (int i = index; i < N; i++)
    {
        if (visited[i]) continue;

        visited[i] = true;
        combinations(depth + 1, i);
        visited[i] = false;
    }
}