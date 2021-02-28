#include <iostream>

using namespace std;

const int MAX = 1e5 + 1; 

int N, X, Y, answer;
char A[MAX], B[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        cin >> N;
        answer = 0, X = 0, Y = 0;

        for (int i = 0; i < N; i++)
            cin >> A[i];
        
        for (int i = 0; i < N; i++)
            cin >> B[i];
        
        for (int i = 0; i < N; i++)
        {
            if (A[i] == B[i])
                continue;

            if (A[i] == 'W') X += 1;
            else if (A[i] == 'B') Y += 1;
        }

        answer = X + Y - min(X, Y);
        cout << answer << "\n";
    }

    return 0;
}
