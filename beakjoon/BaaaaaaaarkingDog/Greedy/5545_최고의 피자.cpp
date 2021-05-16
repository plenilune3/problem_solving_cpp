#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 101;

int N, A, B, C, D[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> A >> B >> C;

    for (int i = 0; i < N; i++)
        cin >> D[i];

    sort(&D[0], &D[0] + N, greater<int> ());

    int answer = 0;

    answer = C / A;

    for (int i = 0; i < N; i++)
    {
        int temp = 0;
        C += D[i];
        A += B;
        temp = C / A;

        if (answer <= temp)
            answer = temp;
        else
            break;
    }

    cout << answer << "\n";

    return 0;
}
