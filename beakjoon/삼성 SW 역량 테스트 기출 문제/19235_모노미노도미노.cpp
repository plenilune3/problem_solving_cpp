#include <iostream>

using namespace std;

const int BLUE = 0;
const int GREEN = 1;
const int dx[] = { -1, 0 };
const int dy[] = { 0, 1 };

int N, score, count;
int board[2][10][4];

void put(int type, int target, int color, int label);

void remove(int x, int color);
void move(int start_x, int color);
void delete_filled_block(int color);
void delete_overflow_block(int color);
void move_point(int x, int y, int color);
void move_h_block(int x, int y, int color);
void move_w_block(int x, int y, int color);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int t, x, y; cin >> t >> x >> y;
        put(t, x, BLUE, i);
        put(t, y, GREEN, i);
    }

    for (int color = 0; color < 2; color++)
        for (int x = 4; x < 10; x++)
            for (int y = 0; y < 4; y++)
                if (board[color][x][y] != 0)
                    count += 1;
    
    cout << score << "\n";
    cout << count << "\n";

    return 0;
}

void put(int type, int target, int color, int label)
{
    if (type == 1)
    {
        board[color][0][target] = label;
        move_point(0, target, color);
    }
    else if ((type == 2 && color == BLUE) || (type == 3 && color == GREEN))
    {
        board[color][0][target] = label;
        board[color][1][target] = label;
        move_h_block(1, target, color);
    }
    else if ((type == 3 && color == BLUE) || (type == 2 && color == GREEN))
    {
        board[color][0][target] = label;
        board[color][0][target + 1] = label;
        move_w_block(0, target, color);
    }

    delete_filled_block(color);
    delete_overflow_block(color);
}

void remove(int x, int color)
{
    for (int y = 0; y < 4; y++)
        board[color][x][y] = 0;
}

void move(int start_x, int color)
{
    for (int x = start_x; x >= 4; x--)
        for (int y = 0; y < 4; y++)
        {
            if (board[color][x][y] == 0) continue;
            
            int type = 1;

            for (int d = 0; d < 2; d++)
            {
                int nx = x + dx[d], ny = y + dy[d];

                if (nx < 4 || ny >= 4) continue;

                if (board[color][x][y] == board[color][nx][ny])
                {
                    if (d == 0) type = 2;
                    else type = 3;
                }
            }

            if (type == 1) move_point(x, y, color);
            else if (type == 2) move_h_block(x, y, color);
            else move_w_block(x, y, color);
        }
            
}

void delete_filled_block(int color)
{
    bool is_remove = false;

    for (int x = 6; x < 10; x++)
    {
        int counter = 0;

        for (int y = 0; y < 4; y++)
            if (board[color][x][y] != 0)
                counter += 1;
        
        if (counter == 4)
        {
            is_remove = true;
            score += 1;
            remove(x, color);
            move(x - 1, color);
        }
    }

    if (is_remove)
        delete_filled_block(color);
}

void delete_overflow_block(int color)
{
    int counter = 0;

    for (int x = 4; x <= 5; x++)
    {
        bool has_block = false;

        for (int y = 0; y < 4; y++)
            if (board[color][x][y] != 0)
            {
                has_block = true;
                break;
            }
        
        if (has_block) counter += 1;
    }

    if (counter)
    {
        for (int x = 9; x >= 6; x--)
            for (int y = 0; y < 4; y++)
                board[color][x][y] = board[color][x - counter][y];
        
        for (int x = 4; x <= 5; x++)
            for (int y = 0; y < 4; y++)
                board[color][x][y] = 0;
    }
}

void move_point(int x, int y, int color)
{
    int label = board[color][x][y];
    board[color][x][y] = 0;

    while (x < 10)
    {
        if (board[color][x][y] != 0)
            break;
        x += 1;
    }

    x -= 1;

    board[color][x][y] = label;
}

void move_h_block(int x, int y, int color)
{
    int label = board[color][x][y];
    board[color][x][y] = 0;
    board[color][x - 1][y] = 0;

    while (x < 10)
    {
        if (board[color][x][y] != 0)
            break;
        x += 1;
    }

    x -= 1;

    board[color][x][y] = label;
    board[color][x - 1][y] = label;
}

void move_w_block(int x, int y, int color)
{
    int label = board[color][x][y];
    board[color][x][y] = 0;
    board[color][x][y + 1] = 0;

    while (x < 10)
    {
        if (board[color][x][y] != 0 || board[color][x][y + 1] != 0)
            break;
        x += 1;
    }

    x -= 1;

    board[color][x][y] = label;
    board[color][x][y + 1] = label;
}
