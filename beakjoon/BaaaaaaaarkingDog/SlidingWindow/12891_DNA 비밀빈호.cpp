#include <iostream>
#include <queue>
#include <map>

using namespace std;

const int MAX = 1e6 + 2;

int N, P, A, C, G, T, answer;
map<char, int> counter;
char S[MAX];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> P;
    cin >> S;
    cin >> A >> C >> G >> T;

    queue< pair<int, char> > window;

    for (int i = 0; i < N; i++)
    {
        window.push(make_pair(i, S[i]));
        counter[S[i]] += 1;

        while (!window.empty() && window.front().first <= i - P)
        {
            counter[window.front().second] -= 1;
            window.pop();
        }

        if (i >= P - 1 && counter['A'] >= A && counter['C'] >= C && counter['G'] >= G && counter['T'] >= T)
            answer += 1;
    }

    cout << answer << "\n";

    return 0;
}
