#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct bucket
{
    int g, x;

    bool operator< (const bucket &b)
    {
        return x < b.x;
    }
};

int N, K;
vector<bucket> v;

bucket make_bucket(int g, int x);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;
    K = 2 * K + 1;

    while (N--)
    {
        int g, x; cin >> g >> x;
        v.push_back(make_bucket(g, x));
    }

    sort(v.begin(), v.end());
    
    int answer = 0, sum_g = 0;
    queue<bucket> window;

    for (vector<bucket>::iterator i = v.begin(); i != v.end(); i++)
    {
        int g = (*i).g, x = (*i).x;

        while (!window.empty() && window.front().x <= x - K)
        {
            sum_g -= window.front().g;
            window.pop();
        }

        sum_g += g;
        window.push((*i));

        answer = max(answer, sum_g);
    }

    cout << answer << "\n";

    return 0;
}

bucket make_bucket(int g, int x)
{
    bucket b = { g, x };
    return b;
}