#include <iostream>
#include <map>

using namespace std;

int cube[6][8];

void rotate(int x, int y, bool d)
{
    int cube_copy[2][2];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            if (d)
                cube_copy[i][j] = cube[x + 2 - j - 1][y + i];
            else
                cube_copy[i][j] = cube[x + j][y + 2 - i - 1];
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cube[i + x][j + y] = cube_copy[i][j];
}

void rotate_up(bool d)
{
    rotate(0, 2, d);

    int cube_copy[8];

    for (int i = 0; i < 8; i++)
        if (d)
            cube_copy[i] = cube[2][(i + 2) % 8];
        else
            cube_copy[(i + 2) % 8] = cube[2][i];
    
    for (int i = 0; i < 8; i++)
        cube[2][i] = cube_copy[i];
}

void rotate_down(bool d)
{
    rotate(4, 2, d);

    int cube_copy[8];

    for (int i = 0; i < 8; i++)
        if (d)
            cube_copy[(i + 2) % 8] = cube[3][i];
        else
            cube_copy[i] = cube[3][(i + 2) % 8];
    
    for (int i = 0; i < 8; i++)
        cube[3][i] = cube_copy[i];
}

void rotate_front(bool d)
{
    rotate(2, 2, d);

    int temp[] = { cube[1][2], cube[1][3] };

    if (d)
    {
        cube[1][2] = cube[3][1];
        cube[1][3] = cube[2][1];

        cube[2][1] = cube[4][2];
        cube[3][1] = cube[4][3];

        cube[4][2] = cube[2][4];
        cube[4][3] = cube[3][4];

        cube[2][4] = temp[0];
        cube[3][4] = temp[1];
    }
    else
    {
        cube[1][2] = cube[2][4];
        cube[1][3] = cube[3][4];

        cube[2][4] = cube[4][3];
        cube[3][4] = cube[4][2];

        cube[4][3] = cube[3][1];
        cube[4][2] = cube[2][1];

        cube[2][1] = temp[1];
        cube[3][1] = temp[0];
    }
}

void rotate_back(bool d)
{
    rotate(2, 6, d);

    int temp[] = { cube[0][2], cube[0][3] };

    if (d)
    {
        cube[0][2] = cube[2][5];
        cube[0][3] = cube[3][5];

        cube[2][5] = cube[5][3];
        cube[3][5] = cube[5][2];

        cube[5][3] = cube[3][0];
        cube[5][2] = cube[2][0];

        cube[3][0] = temp[0];
        cube[2][0] = temp[1];
    }
    else
    {
        cube[0][2] = cube[3][0];
        cube[0][3] = cube[2][0];

        cube[2][0] = cube[5][2];
        cube[3][0] = cube[5][3];

        cube[5][2] = cube[3][5];
        cube[5][3] = cube[2][5];

        cube[3][5] = temp[1];
        cube[2][5] = temp[0];
    }
}

void rotate_left(bool d)
{
    rotate(2, 0, d);

    int temp[] = { cube[2][7], cube[3][7] };

    if (d)
    {
        cube[2][7] = cube[5][2];
        cube[3][7] = cube[4][2];

        cube[5][2] = cube[3][2];
        cube[4][2] = cube[2][2];

        cube[3][2] = cube[1][2];
        cube[2][2] = cube[0][2];

        cube[0][2] = temp[1];
        cube[1][2] = temp[0];
    }
    else
    {
        cube[2][7] = cube[1][2];
        cube[3][7] = cube[0][2];

        cube[0][2] = cube[2][2];
        cube[1][2] = cube[3][2];

        cube[2][2] = cube[4][2];
        cube[3][2] = cube[5][2];

        cube[4][2] = temp[1];
        cube[5][2] = temp[0];
    }
}

void rotate_right(bool d)
{
    rotate(2, 4, d);

    int temp[] = { cube[2][6], cube[3][6] };

    if (d)
    {
        cube[2][6] = cube[1][3];
        cube[3][6] = cube[0][3];

        cube[0][3] = cube[2][3];
        cube[1][3] = cube[3][3];

        cube[2][3] = cube[4][3];
        cube[3][3] = cube[5][3];

        cube[4][3] = temp[1];
        cube[5][3] = temp[0];
    }
    else
    {
        cube[2][6] = cube[5][3];
        cube[3][6] = cube[4][3];

        cube[4][3] = cube[2][3];
        cube[5][3] = cube[3][3];

        cube[2][3] = cube[0][3];
        cube[3][3] = cube[1][3];

        cube[0][3] = temp[1];
        cube[1][3] = temp[0];
    }
}

bool is_possible()
{
    map<int, int> duplicate;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int temp = duplicate[(i / 2) * 4 + (j / 2)];
            
            if (temp == 0)
                duplicate[(i / 2) * 4 + (j / 2)] = cube[i][j];
            else if (temp != cube[i][j])
                return false;
        }
    }

    return true;
}

bool up_down()
{
    rotate_up(true);
    if (is_possible())
        return true;
    rotate_up(false);

    rotate_up(false);
    if(is_possible())
        return true;
    rotate_up(true);

    rotate_down(true);
    if (is_possible())
        return true;
    rotate_down(false);

    rotate_down(false);
    if (is_possible())
        return true;
    rotate_down(true);

    return false;
}

bool left_right()
{
    rotate_left(true);
    if (is_possible())
        return true;
    rotate_left(false);

    rotate_left(false);
    if (is_possible())
        return true;
    rotate_left(true);

    rotate_right(true);
    if (is_possible())
        return true;
    rotate_right(false);

    rotate_right(false);
    if (is_possible())
        return true;
    rotate_right(true);

    return false;
}

bool front_back()
{
    rotate_front(true);
    if (is_possible())
        return true;
    rotate_front(false);

    rotate_front(false);
    if (is_possible())
        return true;
    rotate_front(true);

    rotate_back(true);
    if (is_possible())
        return true;
    rotate_back(false);

    rotate_back(false);
    if (is_possible())
        return(true);
    rotate_back(true);

    return false;
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 6; i++)
    {
        cin >> cube[i][2];
        cin >> cube[i][3];
    }

    for (int i = 2; i < 4; i++)
    {
        cin >> cube[i][0];
        cin >> cube[i][1];
    }

    for (int i = 2; i < 4; i++)
    {
        cin >> cube[i][4];
        cin >> cube[i][5];
    }

    for (int i = 2; i < 4; i++)
    {
        cin >> cube[i][6];
        cin >> cube[i][7];
    }

    cout << (bool) (up_down() + left_right() + front_back()) << "\n";

    return 0;
}
