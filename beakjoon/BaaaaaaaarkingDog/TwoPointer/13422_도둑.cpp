#include <iostream>

using namespace std;

const int MAX = 1e5 + 1;

int N, M, K;
int houses[MAX];

int count_houses();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;

    while (T--)
    {
        cin >> N >> M >> K;

        for (int i = 0; i < N; i++)
            cin >> houses[i];
        
        cout << count_houses() << "\n";
    }

    return 0;
}

int count_houses()
{
    int sum = 0, cnt = 0;

    for (int i = 0; i < M; i++)
        sum += houses[i];
    
    if (N == M)
        return sum < K;
   
    for (int i = 0; i < N; i++)
    {
        sum -= houses[i];
        sum += houses[(i + M) % N];

        if (sum < K)
            cnt += 1;
    }

    return cnt;
}
