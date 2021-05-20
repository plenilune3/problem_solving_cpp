#include <iostream>
#include <stack>

using namespace std;

const int MAX = 1e5 + 3;

int N, A[MAX];
long long psum[MAX], answer;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++)
        psum[i] = psum[i - 1] + A[i - 1];
    
    stack< pair<int, int> > s;

    // s.push(make_pair(0, 0));

    for (int i = 1; i <= N + 1; i++)
    {
        while (!s.empty() && s.top().second > A[i])
        {
            pair<int, int> c = s.top(); s.pop();
            int h = c.second;
            int p = s.top().first;
            answer = max(answer, (psum[i - 1] - psum[p]) * h);
        }

        s.push(make_pair(i, A[i]));
    }

    cout << answer << "\n";

    return 0;
}
