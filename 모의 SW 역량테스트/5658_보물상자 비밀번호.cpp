#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

const int MAX = 28;

int T, N, K;
set<int> s;

void rotate(char num[MAX])
{
    char num_copy[MAX];

    for (int i = 0; i < N; i++)
        num_copy[(i + 1) % N] = num[i];
    
    copy(&num_copy[0], &num_copy[0] + MAX, &num[0]);
}

void split(char num[MAX], string nums[4])
{
    int length = N / 4;

    for (int i = 0; i < N; i++)
        nums[i / length] += num[i];
}

void append(string nums[4])
{
    for (int i = 0; i < 4; i++)
        s.insert(stoi(nums[i], 0, 16));
}

bool cmp(int a, int b)
{
    return a > b;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        char num[MAX];
        s.clear();

        cin >> N >> K;

        string str;
        cin >> str;

        for (int i = 0; i < N; i++)
            num[i] = str[i];
        
        for (int i = 0; i < N / 4; i++)
        {
            string nums[4];
            rotate(num);
            split(num, nums);
            append(nums);
        }

        vector<int> v;
        v.assign(s.begin(), s.end());
        sort(v.begin(), v.end(), cmp);

        cout << "#" << t << " " << v[K-1] << "\n";
    }

    return 0;
}

