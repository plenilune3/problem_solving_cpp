#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> v;

void find_decresing_number(long long num, int cnt)
{
    if (cnt > 10)
        return;
    
    v.push_back(num);

    for (int i = 0; i < 10; i++)
        if (num % 10 > i)
            find_decresing_number(num * 10 + i, cnt + 1);
}

int main(int argc, char const *argv[])
{
    cin >> N; 

    for (int i = 0; i < 10; i++)
        find_decresing_number(i, 1);
    
    sort(v.begin(), v.end());

    long long result = (v.size() > N) ? v[N] : -1;

    cout << result << "\n";
    
    return 0;
}