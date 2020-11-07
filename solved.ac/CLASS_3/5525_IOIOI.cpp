#include <iostream>
#include <vector>

using namespace std;

vector<int> get_pi(string p);
vector<int> search(string t, string p);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int length = 3 + (N - 1) * 2;

    string p, t;

    for (int i = 0; i < length; i++)
        if (i % 2)
            p.append(string(1, 'O'));
        else
            p.append(string(1, 'I'));
    
    cin >> t;

    cout << search(t, p).size() << "\n";

    return 0;
}

vector<int> get_pi(string p)
{
    int M = (int) p.size(), j = 0;
    vector<int> pi(M, 0);

    for (int i = 1; i < M; i++)
    {
        while (j > 0 && p[i] != p[j])
            j = pi[j - 1];
        
        if (p[i] == p[j])
            pi[i] = ++j;
    }

    return pi;
}

vector<int> search(string t, string p)
{
    vector<int> result, pi = get_pi(p);
    int N = (int) t.size(), M = (int) p.size(), j = 0;

    for (int i = 0; i < N; i++)
    {
        while (j > 0 && t[i] != p[j])
            j = pi[j - 1];
        
        if (t[i] == p[j])
        {
            if (j == M - 1) result.push_back(i - M + 1), j = pi[j];
            else j++;
        }
    }

    return result;
}