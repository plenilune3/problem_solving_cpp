#include <iostream>

using namespace std;

const int MAX = 1e4 + 1;

int A[MAX];

int find_(int N, int M);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    int answer = find_(N, M);

    cout << answer << "\n";

    return 0;
}

int find_(int N, int M)
{
    int left = 0, right = 0;
    int sum = 0, answer = 0;

    while (true)
    {
        if (sum > M)
            sum -= A[left++];
        else if (right == N)
            break;
        else
            sum += A[right++];

        if (sum == M)
            answer += 1;
    }

    return answer;
}
