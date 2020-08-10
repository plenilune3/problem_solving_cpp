#include <iostream>
#include <algorithm>

using namespace std;

int N, answer;
int board[10][10];

void move_blue(int t, int x, int y)
{
    if (t == 1)
    {
        while (true)
        {
            if (y + 1 >= 10)
                break;
            
            if (board[x][y + 1] != 0)
                break;
            
            y += 1;
        }

        board[x][y] = t;
    }

    else if (t == 2)
    {
        while (true)
        {
            if (y + 2 >= 10)
                break;
            
            if (board[x][y + 2] != 0)
                break;
            
            y += 1;
        }

        board[x][y] = t;
        board[x][y + 1] = t;
    }

    else if (t == 3)
    {
        while (true)
        {
            if (y + 1 >= 10)
                break;
            
            if (board[x][y + 1] != 0 || board[x + 1][y + 1] != 0)
                break;
            
            y += 1;
        }

        board[x][y] = t;
        board[x + 1][y] = t;
    }
}

void move_green(int t, int x, int y)
{
    if (t == 1)
    {
        while (true)
        {
            if (x + 1 >= 10)
                break;

            if (board[x + 1][y] != 0)
                break;
            
            x += 1;
        }

        board[x][y] = t;
    }

    else if (t == 2)
    {
        while (true)
        {
            if (x + 1 >= 10)
                break;

            if (board[x + 1][y] != 0 || board[x + 1][y + 1] != 0)
                break;
            
            x += 1;
        }

        board[x][y] = t;
        board[x][y + 1] = t;
    }

    else if (t == 3)
    {
        while (true)
        {
            if (x + 2 >= 10)
                break;
               
            if (board[x + 2][y] != 0)
                break;
            
            x += 1;
        }

        board[x][y] = t;
        board[x + 1][y] = t;
    }
}

bool check_green()
{
    for (int i = 9; i >= 6; i--)
    {
        bool possible = true;

        for (int j = 0; j < 4; j++)
            if (board[i][j] == 0)
            {
                possible = false;
                break;
            }
        
        if (possible)
            return true;
    }

    return false;
}

bool check_blue()
{
    for (int j = 9; j >= 6; j--)
    {
        bool possible = true;

        for (int i = 0; i < 4; i++)
            if (board[i][j] == 0)
            {
                possible = false;
                break;
            }
        
        if (possible)
            return true;
    }

    return false;
}

void down_green()
{
    for (int j = 0; j < 4; j++)
        for (int i = 9; i >= 4; i--)
            if (board[i][j] != false)
                for (int k = 9; k > i; k--)
                    if (board[k][j] == false)
                    {
                        swap(board[i][j], board[k][j]);
                        break;
                    }
}

void down_blue()
{
    for (int i = 0; i < 4; i++)
        for (int j = 9; j >= 4; j--)
            if (board[i][j] != false)
                for (int k = 9; k > j; k--)
                    if (board[i][k] == false)
                    {
                        swap(board[i][j], board[i][k]);
                        break;
                    }
}

void explode_green()
{
    for (int i = 9; i >= 6; i--)
    {
        bool possible = true;

        for (int j = 0; j < 4; j++)
            if (board[i][j] == false)
            {
                possible = false;
                break;
            }
        
        if (possible)
        {
            for (int k = 0; k < 4; k++)
                board[i][k] = 0;
            
            down_green();

            answer += 1;
            break;
        }
    }
}

void explode_blue()
{
    for (int j = 9; j >= 6; j--)
    {
        bool possible = true;

        for (int i = 0; i < 4; i++)
            if (board[i][j] == 0)
            {
                possible = false;
                break;
            }
        
        if (possible)
        {
            for (int k = 0; k < 4; k++)
                board[k][j] = 0;
 
            down_blue();

            answer += 1;
            break;
        }
    }
}

bool check_light_blue()
{
    for (int j = 4; j <= 5; j++)
        for (int i = 0; i < 4; i++)
            if (board[i][j])
                return true;

    return false;
}

bool check_light_green()
{
    for (int i = 4; i <= 5; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j])
                return true;
    
    return false;
}

void down_light_blue()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 9; j >= 5; j--)
            board[i][j] = board[i][j - 1];
        
        board[i][4] = false;
    }
}

void down_light_green()
{
    for (int j = 0; j < 4; j++)
    {
        for (int i = 9; i >= 5; i--)
            board[i][j] = board[i - 1][j];
        
        board[4][j] = false;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;

        move_blue(t, x, y);
        move_green(t, x, y);

        while (check_green())
            explode_green();
        
        while (check_blue())
            explode_blue();
        
        // while (check_light_blue())
        //     down_light_blue();
        
        // while (check_light_green())
        //     down_light_green();
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }

    cout << answer << "\n";

    int cnt_green = 0, cnt_blue = 0;
    
    for (int i = 6; i < 10; i++)
        for (int j = 0; j < 4; j++)
            if (board[i][j])
                cnt_green += 1;
    
    for (int j = 6; j < 10; j++)
        for (int i = 0; i < 4; i++)
            if (board[i][j])
                cnt_blue += 1;
    
    cout << cnt_green + cnt_blue << "\n";

    return 0;
}
