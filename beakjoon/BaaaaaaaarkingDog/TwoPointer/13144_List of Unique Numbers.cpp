#include <iostream>

using namespace std;

const int MAX = 1e5 + 1;

int N, A[MAX];

long long count_();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    cout << count_() << "\n";

    return 0;
}

long long count_()
{
    bool visited[MAX] = { false };
    int left = 0, right = 0, cnt = 0;
    long long result = 0;

    while (true)
    {
        if (visited[A[right]])
        {
            visited[A[left++]] = false;
            cnt -= 1;
        }
        else if (right == N)
            break;
        else
        {
            visited[A[right++]] = true;
            cnt += 1;
            result += (long long) cnt;
        }
    }

    return result;
}
