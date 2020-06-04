#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int MAX = 16;

int S[MAX][MAX];
int N, answer;
vector<int> a;
vector<int> b;

int get_difference(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

void combinations(int depth)
{
    if (depth == N)
    {
        if (a.size() == b.size())
        {
            int S_a = 0, S_b = 0;

            for (vector<int>::iterator i = a.begin(); i != a.end(); i++)
                for (vector<int>::iterator j = a.begin(); j != a.end(); j++)
                    S_a += S[(*i)][(*j)];

            for (vector<int>::iterator i = b.begin(); i != b.end(); i++)
                for (vector<int>::iterator j = b.begin(); j != b.end(); j++)
                    S_b += S[(*i)][(*j)];
            
            answer = min(answer, get_difference(S_a, S_b));
        }

        return;
    }

    a.push_back(depth);
    combinations(depth + 1);
    a.pop_back();

    b.push_back(depth);
    combinations(depth + 1);
    b.pop_back();
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        answer = INT_MAX;

        cin >> N;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> S[i][j];
        
        combinations(0);

        cout << "#" << t << " " << answer << "\n";
    }
    return 0;
}
