#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int nums[10];
bool visited[10];
vector<long long> v;

void combinations(int depth, int index, int prev_n, long long num);

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
        nums[i] = i;
    
    cin >> N;

    if (N > 1023)
        cout << "-1" << "\n";
    else
    {
        combinations(0, 0, 10, 0);

        sort(v.begin(), v.end());

        cout << v[N - 1] << "\n";
    }

    return 0;
}

void combinations(int depth, int index, int prev_n, long long num)
{
    for (int i = 0; i < 10; i++)
    {
        if (visited[i])
            continue;
        
        if (nums[i] >= prev_n)
            continue;
        
        long long next_num = num * 10 + nums[i];
        visited[i] = true;
        v.push_back(next_num);
        combinations(depth + 1, i, nums[i], next_num);
        visited[i] = false;
    }
}

