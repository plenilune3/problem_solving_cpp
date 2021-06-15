#include <iostream>
#include <vector>

using namespace std;

const int MAX = 2e5 + 1;

int N, skill[MAX];
int dp[MAX][2];
vector< vector<int> > tree(MAX);

int calculate_synergy(int u, bool has_mentor);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    fill_n(&dp[0][0], MAX * 2, -1);

    cin >> N;

    for (int u = 2; u <= N; u++)
    {
        int p; cin >> p;
        tree[p].push_back(u);
    }

    for (int u = 1; u <= N; u++)
        cin >> skill[u];
    
    int answer = calculate_synergy(1, 0);

    cout << answer << "\n";

    return 0;
}

int calculate_synergy(int u, bool has_mentor)
{
    int &ret = dp[u][has_mentor];

    if (ret != -1) return ret;

    ret = 0;

    int sum = 0;
    for (vector<int>::iterator i = tree[u].begin(); i != tree[u].end(); i++)
        sum += calculate_synergy(*i, 0);

    if (has_mentor)
        ret = sum;
    else
    {
        for (vector<int>::iterator i = tree[u].begin(); i != tree[u].end(); i++)
        {
            int synergy = sum - calculate_synergy(*i, 0) + calculate_synergy(*i, 1) + skill[u] * skill[*i];
            ret = max(ret, synergy);
        }

        ret = max(ret, sum);
    }

    return ret;
}
