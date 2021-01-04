#include <iostream>
#include <climits>
#include <algorithm>
#include <deque>

using namespace std;

const int MAX = 1e6 + 1;

int N, K, answer = INT_MAX;
int V[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> V[i];
    
    sort(&V[0], &V[0] + N);

    int T = N - K - 1;

    deque< pair<int, int> > window;

    for (int i = 1; i < N; i++)
    {
        int d = V[i] - V[i - 1];

        while (!window.empty() && window.front().second > d)
            window.pop_back();
        
        window.push_back(make_pair(i, d));

        while (!window.empty() && window.front().first <= i - T)
            window.pop_front();
        
        if (i >= T)
            answer = min(answer, V[i] - V[i - T] + window.front().second);
    }

    cout << answer << "\n";

    return 0;
}
