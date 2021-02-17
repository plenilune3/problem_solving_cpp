#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e5 + 1;

int N, rope[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> rope[i];
    
    sort(&rope[0], &rope[0] + N, greater<int>());

    int answer = 0;

    for (int i = 0; i < N; i++)
        answer = max(answer, rope[i] * (i + 1));
    
    cout << answer << "\n";

    return 0;
}
