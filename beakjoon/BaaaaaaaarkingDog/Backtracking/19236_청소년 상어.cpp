#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dy[] = { 0, -1, -1, -1, 0, 1, 1, 1 };

struct fish
{
    int num, dir;

    bool operator< (const fish &f) const
    {
        return num > f.num;
    }
};

struct shark
{
    int x, y, feed;
};

int answer;
fish board[4][4];

fish make_fish(int num, int dir);
void feed_shark(int x, int y, int result);
void move_fish(fish board[4][4]);
bool is_out_of_range(int x, int y);

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            int num, dir;
            cin >> num >> dir;
            board[i][j] = make_fish(num, dir - 1);
        }
    
    feed_shark(0, 0, 0);

    cout << answer << "\n";
    
    return 0;

}

void feed_shark(int x, int y, int result)
{
    result += board[x][y].num;
    int dir = board[x][y].dir;
    board[x][y].num = 17;

    answer = max(answer, result);

    move_fish(board);
    fish board_copy[4][4];
    copy(&board[0][0], &board[0][0] + 4 * 4, &board_copy[0][0]);

    for (int i = 1; i < 4; i++)
    {
        int nx = x + (dx[dir] * i), ny = y + (dy[dir] * i);

        if (is_out_of_range(nx, ny))
            continue;
        
        if (board[nx][ny].num == 0)
            continue;
        
        board[x][y].num = 0;
        feed_shark(nx, ny, result);

        copy(&board_copy[0][0], &board_copy[0][0] + 4 * 4, &board[0][0]);
    }
}

fish make_fish(int num, int dir)
{
    return { num, dir };
}

bool is_out_of_range(int x, int y)
{
    if (x < 0 || x >= 4 || y < 0 || y >= 4)
        return true;
    
    return false;
}

void move_fish(fish board[4][4])
{
    for (int i = 1; i <= 16; i++)
    {
        bool is_moved = false;

        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                if (board[x][y].num == i)
                {
                    int nx, ny;

                    while (true)
                    {
                        nx = x + dx[board[x][y].dir], ny = y + dy[board[x][y].dir];

                        if (!is_out_of_range(nx, ny) && board[nx][ny].num != 17)
                            break;
                        
                        board[x][y].dir = (board[x][y].dir + 1) % 8;
                    }

                    swap(board[x][y], board[nx][ny]);
                    is_moved = true;
                    break;
                }
            }

            if (is_moved)
                break;
        }
    }
}
