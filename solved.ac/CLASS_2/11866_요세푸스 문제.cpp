#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, K;
    int *result = new int[N];

    cin >> N >> K;

    queue<int> q;

    for (int i = 1; i <= N; i++)
        q.push(i);
    
    int idx = 0;
    while (!q.empty())
    {
        for (int i = 0; i < K - 1; i++)
        {
            int x = q.front(); q.pop();
            q.push(x);
        }

        int x = q.front();
        q.pop();

        result[idx++] = x;
    }

    cout << "<";
    for (int i = 0; i < N - 1; i++)
        cout << result[i] << ", ";
    cout << result[N - 1] << ">\n";

    return 0;
}
