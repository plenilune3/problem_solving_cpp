#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 531441 + 1;

int N;
char A[MAX];

void cantor(int length, int left, int right);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> N)
    {
        fill_n(&A[0], N, '-');

        int length = pow(3, N);

        cantor(length, 0, length);

        for (int i = 0; i < length; i++)
            cout << A[i];
        cout << "\n";
    }

    return 0;
}

void cantor(int length, int left, int right)
{
    if (length == 1)
        return;

    int l = length / 3;

    for (int i = left + l; i < right - l; i++)
        A[i] = ' ';

    cantor(l, left, left + l);
    cantor(l, right - l, right);
}
