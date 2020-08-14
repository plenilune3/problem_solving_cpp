#include <iostream>

using namespace std;

const int MAX = 101;

int heavy[MAX][MAX];
int light[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M, answer = 0;;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            heavy[i][j] = light[i][j] = (i == j) ? 0 : MAX;

    while (M--)
    {
        int a, b;
        cin >> a >> b;

        heavy[a][b] = 1;
        light[b][a] = 1;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
            {
                if (heavy[i][j] > heavy[i][k] + heavy[k][j])
                    heavy[i][j] = heavy[i][k] + heavy[k][j];
                
                if (light[i][j] > light[i][k] + light[k][j])
                    light[i][j] = light[i][k] + light[k][j];
            }
    

    for (int i = 1; i <= N; i++)
    {
        int middle = (N + 1) / 2;
        int heavy_cnt = 0, light_cnt = 0;

        for (int j = 1; j <= N; j++)
        {
            if (heavy[i][j] != MAX) heavy_cnt++;
            if (light[i][j] != MAX) light_cnt++;
        }

        if (heavy_cnt > middle || light_cnt > middle)
            answer += 1;
    }

    cout << answer << "\n";

    return 0;
}
