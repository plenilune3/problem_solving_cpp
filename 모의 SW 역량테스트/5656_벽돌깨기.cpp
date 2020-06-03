#include <iostream>
#include <climits>

using namespace std;

const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int T, N, H, W, answer;
int board[15][12];

void gravity()
{
    for (int j = 0; j < W; j++)
        for (int i = H - 1; i >= 0; i--)
            if (board[i][j] != 0)
                for (int k = H - 1; k > i; k--)
                    if (board[k][j] == 0)
                    {
                        swap(board[i][j], board[k][j]);
                        break;
                    }
}

void explode(int x, int y)
{
    int range = board[x][y];
    board[x][y] = 0;

    for (int i = 0; i < range; i++)
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j] * i, ny = y + dy[j] * i;

            if (nx < 0 || nx >= H || ny < 0 || ny >= W || board[nx][ny] == 0)
                continue;
            
            explode(nx, ny);
        }
}

void play(int depth)
{
    if (depth == N)
    {
        int cnt = 0;
        
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (board[i][j] != 0)
                    cnt += 1;
        
        answer = min(answer, cnt);
        return;
    }

    int board_copy[15][12];
    copy(&board[0][0], &board[0][0] + 15 * 12, &board_copy[0][0]);

    for (int y = 0; y < W; y++)
    {
        for (int x = 0; x < H; x++)
            if (board[x][y] != 0)
            {
                explode(x, y);
                gravity();
                break;
            }

        play(depth + 1);
        copy(&board_copy[0][0], &board_copy[0][0] + 15 * 12, &board[0][0]);
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        answer = INT_MAX;
        cin >> N >> W >> H;

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                cin >> board[i][j];
        
        play(0);

        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}
