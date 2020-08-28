#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX = 5000;
int N;
long long solution[MAX], answer[3];

void three_solution();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> solution[i];
    
    sort(&solution[0], &solution[0] + N);

    three_solution();

    cout << answer[0] << " " << answer[1] << " " << answer[2] << "\n";

    return 0;
}

void three_solution()
{
    long long min_sum = LONG_LONG_MAX;

    for (int i = 0; i < N; i++)
    {
        int left = i + 1, right = N - 1; 

        while (left < right)
        {
            long long sum = solution[i] + solution[left] + solution[right];

            if (llabs(sum) < min_sum)
            {
                min_sum = llabs(sum);
                answer[0] = solution[i], answer[1] = solution[left], answer[2] = solution[right];
            }

            if (sum < 0)
                left++;
            else
                right--;
        }
    }
}
