#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 3e3 + 10;

int N;
char A[MAX];

bool origami(int left, int right);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        cin >> A;

        N = strlen(A);

        bool answer = origami(0, N - 1);

        if (answer)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}

bool origami(int left, int right)
{
    if (left == right)
        return true;
    
    int l = left, r = right;

    while (l < r)
    {
        if (A[l++] == A[r--])
            return false;
    }
    
    int mid = (left + right) / 2;

    return origami(left, mid - 1) && origami(mid + 1, right);
}