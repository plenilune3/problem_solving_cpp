#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

int N, B[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int answer = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int height; cin >> height;

        if (B[height + 1] == 0)
            answer += 1;
        else
            B[height + 1] -= 1;

        B[height] += 1;
    }

    cout << answer << "\n";

    return 0;
}
