#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 501;

int N, M, B;
int board[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int answer_time = INT_MAX;
    int answer_height = 0;
    int max_height = 0, min_height = INT_MAX;

    cin >> N >> M >> B;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];

            max_height = max(max_height, board[i][j]);
            min_height = min(min_height, board[i][j]);
        }
    
    for (int k = min_height; k <= max_height; k++)
    {
        int result = 0, h = k, b = B;

        for (int x = 0; x < N; x++)
            for (int y = 0; y < M; y++)
            {
                int diff = abs(board[x][y] - h);

                if (board[x][y] == h) continue;
                else if (board[x][y] > h)
                {
                    b += diff;
                    result += (diff * 2);
                }
                else
                {
                    b -= diff;
                    result += diff;
                }
            }
        
        if (b >= 0)
            if (result <= answer_time)
            {
                answer_time = result;
                answer_height = h;
            }
    }

    cout << answer_time << " " << answer_height << "\n";

    return 0;
}
