#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 21;

int N, answer = INT_MAX;
int ability[MAX][MAX];
bool team[MAX];

void combinations(int depth, int cnt)
{
    if (depth == N)
        return;
    
    if (cnt == N / 2)
    {
        int start = 0, link = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                {
                    if (team[i] && team[j])
                        start += ability[i][j];
                    if (!team[i] && !team[j])
                        link += ability[i][j];
                }
        
        answer = min(answer, abs(start - link));
        return;
    }

    team[depth] = true;
    combinations(depth + 1, cnt + 1);
    team[depth] = false;
    combinations(depth + 1, cnt);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> ability[i][j];
    
    combinations(0, 0);

    cout << answer << "\n";

    return 0;
}

