#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAX = 1e9;

struct line
{
    int n, s, e;

    line() : n(0), s(0), e(0) {};
    line(int _n, int _s, int _e) : n(_n), s(_s), e(_e) {};

    bool operator<(const line l) const
    {
        if (s != l.s)
            return s < l.s;
        else
            return e > l.e;
    }
};

int N, M;
vector<line> v;
set<int> answer;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int s, e; cin >> s >> e;

        if (s < e)
            v.push_back(line(i + 1, s, e));
        else
        {
            v.push_back(line(i + 1, s, e + N));
            v.push_back(line(i + 1, s - N, e));
        }
    }

    sort(v.begin(), v.end());

    answer.insert(v.front().n);
    int min_end = v.front().e;

    for (int i = 1; i < M; i++)
        if (min_end < v[i].e)
        {
            answer.insert(v[i].n);
            min_end = v[i].e;
        }

    for (set<int>::iterator i = answer.begin(); i != answer.end(); i++)
        cout << (*i) << " ";
    cout << "\n";

    return 0;
}
