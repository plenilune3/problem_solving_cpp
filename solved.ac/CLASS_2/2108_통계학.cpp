#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 5e5 + 1;

int N;
int nums[MAX];
int counter[8001];

bool compare_(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    int sum = 0;
    int max_counter = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
        sum += nums[i];
        int temp = nums[i] <= 0 ? abs(nums[i]) : nums[i] + 4000;
        counter[temp] += 1;

        if (counter[temp] > max_counter)
            max_counter = counter[temp];
    }

    sort(nums, nums + N);

    int mode = 0;
    bool is_second = false;

    for (int i = -4000; i <= 4000; i++)
    {
        int temp = i <= 0 ? abs(i) : i + 4000;

        if (counter[temp] == max_counter)
        {
            mode = i;

            if (is_second)
                break;

            is_second = true;
        }
    }

    int mean = round(sum / (double) N);
    int median = nums[N / 2];
    int range = nums[N - 1] - nums[0];

    cout << mean << "\n";
    cout << median << "\n";
    cout << mode << "\n";
    cout << range << "\n";

    return 0;
}
