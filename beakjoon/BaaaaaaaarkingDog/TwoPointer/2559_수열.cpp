#include <iostream>

using namespace std;

const int MAX = 1e5;

int N, K;
int arr[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    long long sum = 0;

    for (int i = 0; i < K; i++)
        sum += arr[i];
    
    int left = 0, right = left + K;
    long long answer = sum;

    while (true)
    {
        if (right >= N)
            break;
 
        sum -= arr[left];
        sum += arr[right];

        answer = max(answer, sum);

        left++;
        right = left + K;
    }

    cout << answer << "\n";

    return 0;
}
