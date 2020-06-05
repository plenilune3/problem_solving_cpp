#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

bool film[13][20];

int D, W, K, answer;

bool is_possible()
{
    for (int j = 0; j < W; j++)
    {
        int cnt_max = 0;
        int cnt = 1;

        for (int i = 0; i < D - 1; i++)
        {
            if (film[i][j] == film[i + 1][j])
                cnt += 1;
            else
            {
                cnt_max = max(cnt, cnt_max);
                cnt = 1;
            }
        }

        cnt_max = max(cnt, cnt_max);
        
        if (cnt_max < K)
            return false;
    }

    return true;
}

void dfs(int depth, int cnt)
{
    if (cnt > answer)
        return;

    if (depth == D)
    {
        if (is_possible())
            answer = min(answer, cnt);

        return;
    }

    dfs(depth + 1, cnt);

    int film_floor[20];

    copy(&film[depth][0], &film[depth][0] + 20, &film_floor[0]);
    for (int k = 0; k < W; k++)
        film[depth][k] = 0;
    dfs(depth + 1, cnt + 1);
    copy(&film_floor[0], &film_floor[0] + 20, &film[depth][0]);

    copy(&film[depth][0], &film[depth][0] + 20, &film_floor[0]);
    for (int k = 0; k < W; k++)
        film[depth][k] = 1;
    dfs(depth + 1, cnt + 1);
    copy(&film_floor[0], &film_floor[0] + 20, &film[depth][0]);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        answer = INT_MAX;

        cin >> D >> W >> K;

        for (int i = 0; i < D; i++)
            for (int j = 0; j < W; j++)
                cin >> film[i][j];
        
        dfs(0, 0);

        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}
