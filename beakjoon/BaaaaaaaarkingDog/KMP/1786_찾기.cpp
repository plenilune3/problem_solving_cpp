#include <iostream>
#include <vector>

using namespace std;


vector<int> get_pi(string p);
vector<int> search(string t, string p);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string t, p;

    getline(cin, t);
    getline(cin, p);

    vector<int> answer = search(t, p);

    cout << answer.size() << "\n";

    for (vector<int>::iterator iter = answer.begin(); iter != answer.end(); iter++)
        cout << (*iter) + 1 << "\n";

    return 0;
}

vector<int> get_pi(string p)
{
    int M = p.size(), j = 0;
    vector<int> pi(M, 0);

    for (int i = 1; i < M; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j-1];
        
        if (p[i] == p[j])
            pi[i] = ++j;
    }

    return pi;
}

vector<int> search(string t, string p)
{
    vector<int> result, pi = get_pi(p);
    int N = t.size(), M = p.size(), j = 0;

    for (int i = 0; i < N; i++)
    {
        while (j > 0 && t[i] != p[j])
            j = pi[j-1];
        
        if (t[i] == p[j])
        {
            if (j == M - 1) result.push_back(i-M+1), j = pi[j];
            else j++;
        }
    }

    return result;
}
