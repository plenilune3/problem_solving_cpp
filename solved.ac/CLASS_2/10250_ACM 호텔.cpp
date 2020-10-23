#include <iostream>

using namespace std;

const int MAX = 100;

int H, W, N;
int board[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        cin >> H >> W >> N;

        int answer = 0;
        int counter = 0;

        for (int j = 0; j < W; j++)
            for (int i = H - 1; i >= 0; i--)
                if (++counter == N)
                {
                    answer = (H - i) * 100 + j + 1;
                    break;
                }
        
        cout << answer << "\n";
    }

    return 0;
}
