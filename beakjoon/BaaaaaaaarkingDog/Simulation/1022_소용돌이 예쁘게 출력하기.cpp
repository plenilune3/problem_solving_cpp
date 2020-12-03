#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 1e4 + 1;

int r1, c1, r2, c2, max_num, count_;
int A[50][5];

bool is_out_of_range(int x, int y);
void vortex(int x, int y, int &k);
int get_length();

int main(int argc, char const *argv[])
{
    cin >> r1 >> c1 >> r2 >> c2;

    int R = r2 - r1 + 1, C = c2 - c1 + 1;
    int max_count = R * C;

    int x = MAX / 2, y = MAX / 2;
    int k = 0, d = 0, sw = 1;

    vortex(x, y, k);

    while (true)
    {
        d += 1;

        for (int i = 0; i < d; i++)
        {
            y += sw;
            vortex(x, y, k);

            if (k >= MAX * MAX || count_ == max_count) break;
        }

        if (k >= MAX * MAX || count_ == max_count) break;

        for (int i = 0; i < d; i++)
        {
            x -= sw;
            vortex(x, y, k);
        }

        sw *= -1;
    }

    int length = get_length();

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
            printf("%*d ", length, A[i][j]);
        printf("\n");
    }
    
    return 0;
}

int get_length()
{
    int k = max_num;
    int length = 0;

    while (k)
    {
        int q = k / 10;
        k = q;
        length += 1;
    }

    return length;
}

void vortex(int x, int y, int &k)
{
    if (is_out_of_range(x, y))
        k += 1;
    else
    {
        int nx = (x - 5000) - r1, ny = (y - 5000) - c1;
        A[nx][ny] = ++k;
        max_num = max(max_num, A[nx][ny]);
        count_ += 1;
    }
}

bool is_out_of_range(int x, int y)
{
    x -= 5000, y -= 5000;
    if (x < r1 || x > r2 || y < c1 || y > c2)
        return true;
    
    return false;
}
