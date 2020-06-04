#include <iostream>

using namespace std;

void rotate(int n, int d, int gear[5][8])
{
    int t[8];

    if (d == 1)
        for (int i = 0; i < 8; i++)
            t[(i + 1) % 8] = gear[n][i];
    else
        for (int i = 0; i < 8; i++)
            t[i] = gear[n][(i + 1) % 8];
    
    for (int i = 0; i < 8; i++)
        gear[n][i] = t[i];
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int gear[5][8];
        int answer = 0;
       
        int K;
        cin >> K;

        for (int i = 1; i <= 4; i++)
            for (int j = 0; j < 8; j++)
                cin >> gear[i][j];
 
        for (int k = 0; k < K; k++)
        {
            int n, d;
            cin >> n >> d;

            int direct[5] = { 0 };
            direct[n] = d;

            for (int i = n; i <= 4; i++)
                if (gear[i][2] != gear[i + 1][6])
                    direct[i + 1] = -direct[i];
            
            for (int i = n; i >= 1; i--)
                if (gear[i][6] != gear[i - 1][2])
                    direct[i - 1] = -direct[i];
            
            for (int i = 1; i < 5; i++)
                if (direct[i])
                    rotate(i, direct[i], gear);
        }

        for (int i = 0; i < 4; i++)
            if (gear[i+1][0])
                answer += (1 << i);

        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}