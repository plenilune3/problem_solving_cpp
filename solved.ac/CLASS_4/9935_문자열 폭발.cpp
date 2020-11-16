#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

string A, B;
char result[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> A >> B;

    int length = (int) A.size();
    int L = (int) B.size();
    int S = B[L - 1];
    int idx = 0;

    for (int i = 0; i < length; i++)
    {
        result[idx++] = A[i];

        if (result[idx - 1] == S)
        {
            bool bomb = true;

            if (idx < L) continue;

            for (int j = 0; j < L; j++)
                if (result[idx - 1 - j] != B[L - 1 - j])
                {
                    bomb = false;
                    break;
                }

            if (bomb) idx -= L;
        }
    }

    if (idx != 0)
    {
        for (int i = 0; i < idx; i++)
            cout << result[i];
        cout << "\n";
    }
    else
        cout << "FRULA" << "\n";

    return 0;
}

