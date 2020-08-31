#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 1e4;

int N, M, province[MAX];
int max_province;

int find_max_budget();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> province[i];
        max_province = max(max_province, province[i]);
    }
    
    cin >> M;

    int answer = find_max_budget();

    cout << answer << "\n";

    return 0;
}

int find_max_budget()
{
    int left = 0, right = max_province;
    int max_budget = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int budget_sum = 0;

        for (int i = 0; i < N; i++)
            budget_sum += min(mid, province[i]);
        
        if (budget_sum <= M)
        {
            max_budget = max(max_budget, mid);
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return max_budget;
}
