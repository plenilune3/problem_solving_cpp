#include <iostream>
#include <vector>
#include <climits>

using namespace std;
const int MAX = 20;

int N, answer = INT_MAX;
int S[MAX][MAX];
vector<int> s;
vector<int> l;

int get_difference(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

void dfs(int depth, int start, int link)
{
    if (start == N || link == N)
        return;

    if (start + link == N)
    {
        int team_start = 0;
        for (vector<int>::iterator aiter = s.begin(); aiter != s.end(); aiter++)
            for (vector<int>::iterator biter = s.begin(); biter != s.end(); biter++)
                team_start += S[(*aiter)][(*biter)];

        int team_link = 0;
        for (vector<int>::iterator aiter = l.begin(); aiter != l.end(); aiter++)
            for (vector<int>::iterator biter = l.begin(); biter != l.end(); biter++)
                team_link += S[(*aiter)][(*biter)];
        
        answer = min(answer, get_difference(team_start, team_link));
        return;
    }
    
    s.push_back(depth);
    dfs(depth + 1, start + 1, link);
    s.pop_back();

    l.push_back(depth);
    dfs(depth + 1, start, link + 1);
    l.pop_back();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> S[i][j];
    
    dfs(0, 0, 0);
    cout << answer << "\n";

    return 0;
}
