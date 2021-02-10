#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e4 + 1;

int N, A[MAX], B[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int answer = 0;
    bool possible = false;
    int l = 0, r = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;

        if (num < 0)
            A[l++] = num;
        else if (num == 0)
            possible = true;
        else if (num == 1)
            answer += 1;
        else
            B[r++] = num;
    }

    sort(&A[0], &A[0] + l);
    sort(&B[0], &B[0] + r, greater<int> ());

    if (l % 2 == 1)
        answer += possible ? 0 : A[l-- - 1];

    if (r % 2 == 1)
        answer += B[r-- - 1];

    for (int i = 0; i < l; i += 2)
        answer += A[i] * A[i + 1];
    
    for (int i = 0; i < r; i += 2)
        answer += B[i] * B[i + 1];

    cout << answer << "\n";

    return 0;
}
