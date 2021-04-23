#include <iostream>

#define GREEN 0
#define BLUE 1

using namespace std;

int N, board[2][10][4];

void put(int type, int x, int y, int color, int label);
void move_point(int x, int y, int color);
void move_w_block(int x, int y, int color);
void move_h_block(int x, int y, int color);
int delete_filled_block(int color);
void delete_overflow_block(int color);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int answer = 0;
    int counter_block = 0;

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int t, x, y; cin >> t >> x >> y;
        put(t, x, y, GREEN, i);
        put(t, y, x, BLUE, i);
        answer += delete_filled_block(GREEN);
        answer += delete_filled_block(BLUE);
        delete_overflow_block(GREEN);
        delete_overflow_block(BLUE);
    }

    for (int color = 0; color < 2; color++)
        for (int x = 0; x < 10; x++)
            for (int y = 0; y < 4; y++)
                if (board[color][x][y] != 0)
                    counter_block += 1;
    
    cout << answer << "\n";
    cout << counter_block << "\n";

    return 0;
}

void put(int type, int x, int y, int color, int label)
{
    if (type == 1)
    {
        board[color][x][y] = label;
        move_point(x, y, color);
    }

    if ((type == 2 && color == GREEN) || (type == 3 && color == BLUE))
    {
        board[color][x][y] = label;
        board[color][x][y + 1] = label;
        move_w_block(x, y, color);
    }

    if ((type == 3 && color == GREEN) || (type == 2 && color == BLUE))
    {
        board[color][x][y] = label;
        board[color][x + 1][y] = label;
        move_h_block(x, y, color);
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

void move_h_block(int x, int y, int color)
{
    int label = board[color][x][y];
    board[color][x][y] = 0;
    board[color][x + 1][y] = 0;

    while (x + 1 < 10)
    {
        if (board[color][x + 1][y] != 0)
            break;
        x += 1;
    }

    x -= 1;

    board[color][x][y] = label;
    board[color][x + 1][y] = label;
}

void remove(int x, int color)
{
    int C[10][4];
    copy(&board[color][0][0], &board[color][0][0] + 10 * 4, &C[0][0]);

    for (int i = 0; i <= x; i++)
        for (int j = 0; j < 4; j++)
            board[color][(i + 1) % (x + 1)][j] = C[i][j];
    
    for (int i = 0; i < 4; i++)
        board[color][0][i] = 0;
}

int delete_filled_block(int color)
{
    bool is_removed = false;
    int score = 0;

    for (int x = 6; x < 10; x++)
    {
        int counter = 0;

        for (int y = 0; y < 4; y++)
            if (board[color][x][y] != 0)
                counter += 1;
        
        if (counter == 4)
        {
            is_removed = true;
            remove(x, color);
            score += 1;
        }
    }

    if (is_removed)
        score += delete_filled_block(color);

    return score;
}

void delete_overflow_block(int color)
{
    int counter = 0;

    for (int x = 4; x <= 5; x++)
    {
        bool has_block = false;

        for (int y = 0; y < 4; y++)
            if (board[color][x][y] != 0)
                has_block = true;
        
        if (has_block)
            counter += 1;
    }

    while (counter--)
        remove(9, color);
}