#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;

int N, P[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int answer = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> P[i];
    
    sort(&P[0], &P[0] + N, greater<int>());

    for (int i = 0; i < N; i++)
    {
        answer += P[i];

        if (i % 3 == 2)
            answer -= P[i];
    }

    cout << answer << "\n";

    return 0;
}
