#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1000000;

int N, A[MAX];
long long M;

int find_max_height();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    sort(&A[0], &A[0] + N);

    int answer = find_max_height();

    cout << answer << "\n";

    return 0;
}

int find_max_height()
{
    int left = 0, right = 2000000000;
    int answer = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++)
        {
            int cut = A[i] - mid;

            if (cut > 0)
                sum += cut;
        }

        if (sum >= M)
        {
            answer = max(answer, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return answer;
}
