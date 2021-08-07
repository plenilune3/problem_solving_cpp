#include <iostream>

using namespace std;

string N;
int A[10], answer;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (string::iterator i = N.begin(); i != N.end(); i++)
    {
        char c = (*i);
        A[c - '0'] += 1;
    }

    answer = min(A[6], A[9]);

    int temp = A[6] >= A[9] ? A[6] - A[9] : A[9] - A[6];
    answer = answer + (temp / 2) + (temp % 2);

    for (int i = 0; i < 10; i++)
    {
        if (i == 6 || i == 9)
            continue;

        answer = max(answer, A[i]);
    }
    
    cout << answer << "\n";

    return 0;
}