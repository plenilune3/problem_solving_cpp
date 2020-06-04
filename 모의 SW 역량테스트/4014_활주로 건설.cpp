#include <iostream>

using namespace std;

const int MAX = 21;

int T, N, L, answer;
int board[MAX][MAX];

void ramp(int i, bool c)
{
    int cnt = 1;

    for (int j = 0; j < N-1; j++)
    {
        int d = c == true ? board[i][j+1] - board[i][j] : board[j+1][i] - board[j][i];
        if (d == 0) cnt += 1;
        else if (d == 1 && cnt >= L) cnt = 1;
        else if (d == -1 && cnt >= 0) cnt = -L+1;
        else return;
    }

    if(cnt >= 0)
        answer += 1;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        answer = 0;
        cin >> N >> L;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> board[i][j];
            
        for (int i = 0; i < N; i++)
        {
            ramp(i, 0);
            ramp(i, 1);
        }

        cout << "#" << t <<  " " << answer << "\n";
    }

    return 0;
}