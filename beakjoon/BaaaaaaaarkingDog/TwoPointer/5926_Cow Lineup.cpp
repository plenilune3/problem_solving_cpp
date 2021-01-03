#include <iostream>
#include <algorithm>
#include <climits>
#include <map>
#include <set>

using namespace std;

const int MAX = 5e4 + 1;

struct cow
{
    int x, id;

    bool operator< (const cow &c)
    {
        if (x != c.x) return x < c.x;
        else return id < c.id;
    }
};

int N, total_herd;
map<int, int> herd_cnt;
cow cows[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    set<int> herd;

    for (int i = 0; i < N; i++)
    {
        cin >> cows[i].x >> cows[i].id;
        herd.insert(cows[i].id);
    }

    total_herd = (int) herd.size();
    sort(&cows[0], &cows[0] + N);

    int left = 0, right = 0;
    int cnt = 0, min_cost = INT_MAX;

    while (true)
    {
        if (cnt >= total_herd)
        {
            if (herd_cnt[cows[left].id] == 1)
                cnt -= 1;
            
            herd_cnt[cows[left].id] -= 1;
            left += 1;
        }
        else if (right == N)
            break;
        else
        {
            if (herd_cnt[cows[right].id] == 0)
                cnt += 1;
            
            herd_cnt[cows[right].id] += 1;
            right += 1;
        }

        if (cnt == total_herd)
            min_cost = min(min_cost, cows[right - 1].x - cows[left].x);
    }

    cout << min_cost << "\n";

    return 0;
}
