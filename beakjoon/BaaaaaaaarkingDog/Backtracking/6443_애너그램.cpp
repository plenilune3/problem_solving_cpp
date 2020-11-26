#include <iostream>
#include <algorithm>

using namespace std;

int length, alpha[26];
string word, result;

void backtracking(int depth);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N; cin >> N;

    while (N--)
    {
        fill_n(&alpha[0], 26, 0);
        cin >> word;
        length = (int) word.size();
        sort(word.begin(), word.end());

        for (string::iterator i = word.begin(); i != word.end(); i++)
            alpha[(*i) - 'a'] += 1;
        
        backtracking(0);
    }

    return 0;
}

void backtracking(int depth)
{
    if (depth == length)
    {
        cout << result << "\n";
        return;
    }

    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == 0)
            continue;
        
        alpha[i] -= 1;
        result.append(1, 'a' + i);
        backtracking(depth + 1);
        alpha[i] += 1;
        result.erase(result.end() - 1);
    }
}


