#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1e6 + 3;

int N;
char S[MAX];

int convert_(char S[MAX], char a);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> S;

    N = strlen(S);

    int answer = min(convert_(S, '1'), convert_(S, '0'));

    cout << answer << "\n";

    return 0;
}

int convert_(char S[MAX], char a)
{
    int result = 0;

    for (int i = 0; i < N - 1; i++)
    {
        if (S[i] != a && S[i + 1] == a)
            result += 1;
    }

    return S[N - 1] == a ? result : result + 1;
}

