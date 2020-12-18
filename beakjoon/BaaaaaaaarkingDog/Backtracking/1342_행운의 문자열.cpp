#include <iostream>
#include <vector>

using namespace std;

const int MAX = 10;

int N, answer;
int alpha[26];
char S[MAX];
bool visited[MAX];
vector<char> v;

void make_lucky_string(int depth);
int factorial(int num);
bool is_lucky();

int main(int argc, char const *argv[])
{
    string input;

    cin >> input;
    N = input.size();

    for (int i = 0; i < N; i++)
    {
        S[i] = input[i];
        alpha[input[i] - 'a'] += 1;
    }

    make_lucky_string(0);

    for (int i = 0; i < 26; i++)
        if (alpha[i])
            answer /= factorial(alpha[i]);
    
    cout << answer << "\n";

    return 0;
}

int factorial(int num)
{
    int result = 1;

    for (int i = num; i >= 1; i--)
        result *= i;
    
    return result;
}

bool is_lucky()
{
    for (int i = 0; i < N - 1; i++)
        if (v[i] == v[i + 1])
            return false;
    
    return true;
}

void make_lucky_string(int depth)
{
    if (depth == N)
    {
        if (is_lucky())
            answer++;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            v.push_back(S[i]);
            make_lucky_string(depth + 1);
            visited[i] = false;
            v.pop_back();
        }
    }
}


