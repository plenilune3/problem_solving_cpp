#include <iostream>

using namespace std;

const int MAX = 1e5 + 1;

int N, X, Y;
char A[MAX], B[MAX], C[MAX], D[MAX];

void flip(int x, char T[MAX]);
bool is_possible(char T[MAX]);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    for (int i = 0; i < N; i++)
        cin >> B[i];
    
    for (int i = 0; i < N; i++)
        C[i] = D[i] = (A[i] != B[i]) ? '1' : '0';

    flip(0, D);
    Y += 1;

    for (int i = 1; i < N; i++)
    {
        if (C[i - 1] == '1')
        {
            flip(i, C);
            X += 1;
        }
        if (D[i - 1] == '1')
        {
            flip(i, D);
            Y += 1;
        }
    }

    if (is_possible(C) && is_possible(D))
        cout << min(X, Y) << "\n";
    else if (is_possible(C))
        cout << X << "\n";
    else if (is_possible(D))
        cout << Y << "\n";
    else
        cout << -1 << "\n";

    return 0;
}

void flip(int x, char T[MAX])
{
    T[x] = T[x] == '0' ? '1' : '0';
    if (x - 1 >= 0) T[x - 1] = T[x - 1] == '0' ? '1' : '0';
    if (x + 1 < N) T[x + 1] = T[x + 1] == '0' ? '1' : '0';
}

bool is_possible(char T[MAX])
{
    for (int i = 0; i < N; i++)
        if (T[i] == '1')
            return false;
    return true;
}
