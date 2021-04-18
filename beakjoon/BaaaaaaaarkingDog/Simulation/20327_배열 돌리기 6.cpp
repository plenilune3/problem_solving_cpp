#include <iostream>

using namespace std;

const int MAX = (1 << 7) + 1;

int N, R, L, A[MAX][MAX];

void divide(int length, int x, int y, int k, int l);
void reverse(int l, int k);
void reverse_area(int l, int k);
void rotate(int l, int k);
void rotate_area(int l, int k);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> R;
    L = (1 << N);

    for (int i = 0; i < L; i++)
        for (int j = 0; j < L; j++)
            cin >> A[i][j];
    
    while (R--)
    {
        int k, l; cin >> k >> l;

        l = (1 << l);

        if (k == 1 || k == 2)
            reverse(l, k);
        else if (k == 3 || k == 4)
            rotate(l, k);
        else if (k == 5 || k == 6)
            reverse_area(l, k);
        else
            rotate_area(l, k);
    }

    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < L; j++)
            cout << A[i][j] << " ";
        cout << "\n";
    }

    return 0;
}

void reverse_area(int l, int k)
{
    if (k == 5)
    {
        reverse(L, 1);
        reverse(l, 1);
    }
    else
    {
        reverse(L, 2);
        reverse(l, 2);
    }
}

void rotate_area(int l, int k)
{
    if (k == 7)
    {
        rotate(L, 3);
        rotate(l, 4);
    }
    else
    {
        rotate(L, 4);
        rotate(l, 3);
    }
}

void reverse(int l, int k)
{
    for (int i = 0; i < L; i += l)
    {
        for (int j = 0; j < L; j += l)
        {
            int C[l][l];
            for (int x = 0; x < l; x++)
                for (int y = 0; y < l; y++)
                    C[x][y] = A[i + x][j + y];

            for (int x = 0; x < l; x++)
                for (int y = 0; y < l; y++)
                    if (k == 1)
                        A[i + x][j + y] = C[l - 1 - x][y];
                    else
                        A[i + x][j + y] = C[x][l - 1 - y];
        }
    }
}

void rotate(int l, int k)
{
    for (int i = 0; i < L; i += l)
    {
        for (int j = 0; j < L; j += l)
        {
            int C[l][l];
            for (int x = 0; x < l; x++)
                for (int y = 0; y < l; y++)
                    C[x][y] = A[i + x][j + y];

            for (int x = 0; x < l; x++)
                for (int y = 0; y < l; y++)
                    if (k == 3)
                        A[i + x][j + y] = C[l - 1 - y][x];
                    else
                        A[i + x][j + y] = C[y][l - 1 - x];
        }
    }
}
