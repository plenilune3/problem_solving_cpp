#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e3 + 1;

int N, A[MAX], B[MAX], C[MAX];

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
        C[i] = A[i] - B[i];
    
    int answer = 0;
    int prev_tab = C[0];

    for (int i = 1; i < N; i++)
    {
        if (prev_tab * C[i] < 0)
            answer += abs(prev_tab);
        else if (abs(prev_tab) > abs(C[i]))
            answer += abs(prev_tab - C[i]);
        prev_tab = C[i];
    }
    answer += abs(prev_tab);

    cout << answer << "\n";

    return 0;
}
