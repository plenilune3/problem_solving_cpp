#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e3 + 1;

int N, L;
int leak_point[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> L;

    for (int i = 0; i < N; i++)
        cin >> leak_point[i];

    sort(&leak_point[0], &leak_point[0] + N);

    int answer = 1;
    int min_ = leak_point[0];

    for (int i = 0; i < N; i++)
    {
        if (leak_point[i] - min_ > L - 1)
        {
            min_ = leak_point[i];
            answer += 1;
        }
    }
   
    cout << answer << "\n";

    return 0;
}
