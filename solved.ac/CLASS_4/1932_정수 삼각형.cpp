#include <iostream>

using namespace std;

const int MAX = 501;

int N, T[MAX][MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < i + 1; j++)
            cin >> T[i][j];

    for (int i = N - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            T[i][j] = T[i][j] + max(T[i + 1][j], T[i + 1][j + 1]);
    
    cout << T[0][0] << "\n";

    return 0;
}
