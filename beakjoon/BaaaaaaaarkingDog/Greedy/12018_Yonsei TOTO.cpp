#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 101;

int N, M;
vector<int> v;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int answer = 0;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        priority_queue<int> pq;
        int P, L; cin >> P >> L;

        for (int j = 0; j < P; j++)
        {
            int x; cin >> x;
            pq.push(x);
        }

        if (pq.size() < L)
        {
            v.push_back(1);
            continue;
        }

        while (L - 1)
        {
            int x = pq.top();
            pq.pop(); L--;
        }

        v.push_back(pq.top());
    }

    sort(v.begin(), v.end());

    for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
    {
        if (M < (*i))
            break;
        
        answer += 1;
        M -= (*i);
    }

    cout << answer << "\n";

    return 0;
}
