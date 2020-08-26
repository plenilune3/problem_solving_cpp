#include <iostream>
#include <vector>

using namespace std;

const int MAX = 901;

int K, N, F;
bool visited[MAX], is_finished;
bool friendship[MAX][MAX];
int friend_cnt[MAX];
vector<int> v;

void go_picnic(int depth);
bool is_all_friend(int num);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> K >> N >> F;

    while (F--)
    {
        int u, v;

        cin >> u >> v;

        friendship[u][v] = true, friend_cnt[u] += 1;
        friendship[v][u] = true, friend_cnt[v] += 1;
    }

    go_picnic(1);

    if (is_finished == false)
        cout << -1 << "\n";

    return 0;
}

bool is_all_friend(int num)
{
    for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
        if (friendship[num][(*iter)] == false)
            return false;

    return true;
}

void go_picnic(int depth) 
{
    if (is_finished)
        return;

    if (depth == K + 1)
    {
        is_finished = true;

        for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
            cout << (*iter) << "\n";

        return;
    }

    for (int i = depth; i <= N; i++)
    {
        if (visited[i] || is_all_friend(i) == false) continue;
        if (friend_cnt[i] < K - depth) continue;
        
        visited[i] = true;
        v.push_back(i);
        go_picnic(depth + 1);
        visited[i] = false;
        v.pop_back();
    }
}
