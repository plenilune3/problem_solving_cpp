#include <iostream>

using namespace std;

char cube[9][12];

void init()
{
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 12; j++)
        {
            int area = (i / 3) * 4 + (j / 3);

            if(area == 1)
                cube[i][j] = 'w';
            else if(area == 4)
                cube[i][j] = 'g';
            else if (area == 5)
                cube[i][j] = 'r';
            else if (area == 6)
                cube[i][j] = 'b';
            else if (area == 7)
                cube[i][j] = 'o';
            else if (area == 9)
                cube[i][j] = 'y';
            else
                cube[i][j] = '.';
        }
}

void move_u(char d)
{
    char a[3][3], b[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = cube[i][j+3];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (d == '+')
                b[i][j] = a[2-j][i];
            else
                b[i][j] = a[j][2-i];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[i][j+3] = b[i][j];
    
    char t[12];
    
    for (int i = 0; i < 12; i++)
        if (d == '+')
            t[i] = cube[3][(i + 3) % 12];
        else
            t[(i + 3) % 12] = cube[3][i];
    
    for (int i = 0; i < 12; i++)
        cube[3][i] = t[i];
}

void move_d(char d)
{
    char a[3][3], b[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = cube[i+6][j+3];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (d == '+')
                b[i][j] = a[2-j][i];
            else
                b[i][j] = a[j][2-i];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[i+6][j+3] = b[i][j];
    
    char t[12];
    
    for (int i = 0; i < 12; i++)
        if (d == '+')
            t[(i + 3) % 12] = cube[5][i];
        else
            t[i] = cube[5][(i + 3) % 12];
    
    for (int i = 0; i < 12; i++)
        cube[5][i] = t[i];
}

void move_f(char d)
{
    char a[5][5], b[5][5];

    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            a[i][j] = cube[i+2][j+2];
    
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (d == '+')
                b[i][j] = a[4-j][i];
            else
                b[i][j] = a[j][4-i];
    
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cube[i+2][j+2] = b[i][j];
}

void move_b(char d)
{
    char a[3][3], b[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = cube[i+3][j+9];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (d == '+')
                b[i][j] = a[2-j][i];
            else
                b[i][j] = a[j][2-i];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[i+3][j+9] = b[i][j];
    
    char t[9][9];

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (d == '+')
                t[i][j] = cube[j][8-i];
            else
                t[i][j] = cube[8-j][i];
    
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if(i == 0 || j == 0 || i == 8 || j == 8)
                cube[i][j] = t[i][j];
}

void move_l(char d)
{
    char a[3][3], b[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = cube[i+3][j];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (d == '+')
                b[i][j] = a[2-j][i];
            else
                b[i][j] = a[j][2-i];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[i+3][j] = b[i][j];
    
    char x[12], y[12];

    for (int i = 0; i < 9; i++)
        x[i] = cube[i][3];
    
    for (int i = 0; i < 3; i++)
        x[i+9] = cube[5-i][11];
    
    for (int i = 0; i < 12; i++)
        if (d == '+')
            y[(i + 3) % 12] = x[i];
        else
            y[i] = x[(i + 3) % 12];
    
    for (int i = 0; i < 9; i++)
        cube[i][3] = y[i];
    
    for (int i = 0; i < 3; i++)
        cube[i+3][11] = y[11-i];
}

void move_r(char d)
{
    char a[3][3], b[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            a[i][j] = cube[i+3][j+6];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (d == '+')
                b[i][j] = a[2-j][i];
            else
                b[i][j] = a[j][2-i];
    
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cube[i+3][j+6] = b[i][j];
    
    char x[12], y[12];

    for (int i = 0; i < 9; i++)
        x[i] = cube[i][5];
    
    for (int i = 0; i < 3; i++)
        x[i+9] = cube[5-i][9];
    
    for (int i = 0; i < 12; i++)
        if (d == '+')
            y[i] = x[(i + 3) % 12];
        else
            y[(i + 3) % 12] = x[i];
    
    for (int i = 0; i < 9; i++)
        cube[i][5] = y[i];
    
    for (int i = 0; i < 3; i++)
        cube[i+3][9] = y[11-i];
}

void move(char f, char d)
{
    if (f == 'U')
        move_u(d);
    else if (f == 'D')
        move_d(d);
    else if (f == 'F')
        move_f(d);
    else if (f == 'B')
        move_b(d);
    else if (f == 'L')
        move_l(d);
    else if (f == 'R')
        move_r(d);
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        init();

        int N;
        cin >> N;

        for (int n = 0; n < N; n++)
        {
            char f, d;
            cin >> f >> d;
            move(f, d);
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cout << cube[i][j+3];
            cout << "\n";
        }


    }

    return 0;
}


// char cube[12][9];

// void init()
// {
//     for (int i = 0; i < 12; i++)
//         for (int j = 0; j < 9; j++)
//         {
//             int area = (i / 3) * 3 + (j / 3);

//             if (area == 1)
//                 cube[i][j] = 'o';
//             else if (area == 3)
//                 cube[i][j] = 'g';
//             else if (area == 4)
//                 cube[i][j] = 'w';
//             else if (area == 5)
//                 cube[i][j] = 'b';
//             else if (area == 7)
//                 cube[i][j] = 'r';
//             else if (area == 10)
//                 cube[i][j] = 'y';
//             else 
//                 cube[i][j] = '.';
//         }
// }

// void move_U(char d)
// {
//     char a[5][5], b[5][5];

//     for (int i = 0; i < 5; i++)
//         for (int j = 0; j < 5; j++)
//             a[i][j] = cube[i + 2][j + 2];
    
//     for (int i = 0; i < 5; i++)
//         for (int j = 0; j < 5; j++)
//             if (d == '+')
//                 b[i][j] = a[4 - j][i];
//             else
//                 b[i][j] = a[j][4 - i];

//     for (int i = 0; i < 5; i++)
//         for (int j = 0; j < 5; j++)
//             cube[i + 2][j + 2] = b[i][j];
// }

// void move_D(char d)
// {
//     char a[3][3], b[3][3];

//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             a[i][j] = cube[i + 9][j + 3];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             if (d == '+')
//                 b[i][j] = a[2-j][i];
//             else
//                 b[i][j] = a[j][2-i];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             cube[i + 9][j + 3] = b[i][j];
    
//     char x[9][9], y[9][9];
    
//     for (int i = 0; i < 9; i++)
//         for (int j = 0; j < 9; j++)
//             x[i][j] = cube[i][j];
    
//     for (int i = 0; i < 9; i++)
//         for (int j = 0; j < 9; j++)
//             if (d == '+')
//                 y[i][j] = x[j][8-i];
//             else
//                 y[i][j] = x[8-j][i];
    
//     for (int i = 0; i < 9; i++)
//         for (int j = 0; j < 9; j++)
//             if (i == 0 || j == 0 || i == 8 || j == 8)
//                 cube[i][j] = y[i][j];
// }

// void move_L(char d)
// {
//     char t[12];

//     if (d == '+')
//         for (int i = 0; i < 12; i++)
//             t[(i + 3) % 12] = cube[i][3];
//     else
//         for (int i = 0; i < 12; i++)
//             t[i] = cube[(i + 3) % 12][3];
    
//     for (int i = 0; i < 12; i++)
//         cube[i][3] = t[i];

//     char a[3][3], b[3][3];

//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             a[i][j] = cube[i + 3][j];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             if (d == '+')
//                 b[i][j] = a[2-j][i];
//             else
//                 b[i][j] = a[j][2-i];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             cube[i + 3][j] = b[i][j];
// }

// void move_R(char d)
// {
//     char t[12];

//     if (d == '+')
//         for (int i = 0; i < 12; i++)
//             t[i] = cube[(i + 3) % 12][5];
//     else
//         for (int i = 0; i < 12; i++)
//             t[(i + 3) % 12] = cube[i][5];
    
//     for (int i = 0; i < 12; i++)
//         cube[i][5] = t[i];

//     char a[3][3], b[3][3];

//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             a[i][j] = cube[i + 3][j + 6];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             if (d == '+')
//                 b[i][j] = a[2-j][i];
//             else
//                 b[i][j] = a[j][2-i];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             cube[i + 3][j + 6] = b[i][j];
// }

// void move_F(char d)
// {
//     char x[12], y[12];

//     for (int i = 0; i < 9; i++)
//         x[i] = cube[5][i];
//     for (int i = 0; i < 3; i++)
//         x[9 + i] = cube[9][3 + i];

//     if (d == '+')
//         for (int i = 0; i < 12; i++)
//             y[(i + 3) % 12] = x[i];
//     else
//         for (int i = 0; i < 12; i++)
//             y[i] = x[(i + 3) % 12];
    
//     for (int i = 0; i < 9; i++)
//         cube[5][i] = y[i];
//     for (int i = 0; i < 3; i++)
//         cube[9][3 + i] = y[9 + i];
    
//     char a[3][3], b[3][3];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             a[i][j] = cube[6 + i][3 + j];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             if(d == '+')
//                 b[i][j] = a[2-j][i];
//             else
//                 b[i][j] = a[j][2-i];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             cube[6 + i][3 + j] = b[i][j];
// }

// void move_B(char d)
// {
//     char x[12], y[12];

//     for (int i = 0; i < 9; i++)
//         x[i] = cube[3][i];
//     for (int i = 0; i < 3; i++)
//         x[9 + i] = cube[11][3 + i];
    
//     if (d == '+')
//         for (int i = 0; i < 12; i++)
//             y[i] = x[(i + 3) % 12];
//     else
//         for (int i = 0; i < 12; i++)
//             y[(i + 3) % 12] = x[i];
    
//     for (int i = 0; i < 9; i++)
//         cube[3][i] = y[i];

//     for (int i = 0; i < 3; i++)
//         cube[11][3 + i] = y[9 + i];

//     char a[3][3], b[3][3];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             a[i][j] = cube[i][3 + j];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             if(d == '+')
//                 b[i][j] = a[2-j][i];
//             else
//                 b[i][j] = a[j][2-i];
    
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             cube[i][3 + j] = b[i][j];   
// }


// void move(char c, char d)
// {
//     if (c == 'U')
//         move_U(d);
//     else if (c == 'D')
//         move_D(d);
//     else if (c == 'L')
//         move_L(d);
//     else if (c == 'R')
//         move_R(d);
//     else if (c == 'F')
//         move_F(d);
//     else if (c == 'B')
//         move_B(d);
// }

// int main(int argc, char const *argv[])
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     int T;
//     cin >> T;

//     for (int t = 0; t < T; t++)
//     {
//         init();
//         // for (int i = 0; i < 12; i++)
//         // {
//         //     for (int j = 0; j < 9; j++)
//         //         cout << cube[i][j];
//         //     cout << "\n";
//         // }
//         int N;
//         cin >> N;

//         for (int i = 0; i < N; i++)
//         {
//             char f, d;
//             cin >> f >> d;
//             // cout << f << d << "\n";
//             move(f, d);
//         }
//         for (int i = 0; i < 12; i++)
//         {
//             for (int j = 0; j < 9; j++)
//                 cout << cube[i][j];
//             cout << "\n";
//         }
//         // for (int i = 0; i < 3; i++)
//         // {
//         //     for (int j = 0; j < 3; j++)
//         //         cout << cube[i + 3][j + 3];
//         //     cout << "\n";
//         // }
//     }

//     return 0;
// }
