#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 2e4 + 1;

int N;
string words[MAX];

bool compare_(const string &a, const string &b);

int main(int argc, char const *argv[])
{
    cin >> N; 

    for (int i = 0; i < N; i++)
        cin >> words[i];
    
    vector<string> answer;

    sort(words, words + N, compare_);
    unique_copy(words, words + N, back_inserter(answer));

    for (vector<string>::iterator i = answer.begin(); i != answer.end(); i++)
        cout << (*i) << "\n";

    return 0;
}

bool compare_(const string &a, const string &b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    else return a < b;
}
