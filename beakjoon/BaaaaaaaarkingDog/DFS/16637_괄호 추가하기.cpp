#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>

using namespace std;

template<typename T>
string to_string(const T& value)
{
    stringstream ss;
    ss << value;
    return ss.str();
}

const int MAX = 19;

int N, answer = INT_MIN;
vector<string> expression;

int calculate_add (string a, string b)
{
    int x = atoi(a.c_str());
    int y = atoi(b.c_str());

    return x + y;
}

int calculate_sub (string a, string b)
{
    int x = atoi(a.c_str());
    int y = atoi(b.c_str());

    return x - y;
}

int calculate_mul (string a, string b)
{
    int x = atoi(a.c_str());
    int y = atoi(b.c_str());

    return x * y;
}

int calculate(string a, string b, string op)
{
    if (op == "+")
        return calculate_add(a, b);
    else if (op == "-")
        return calculate_sub(a, b);
    else if (op == "*")
        return calculate_mul(a, b);
}

void dfs(int depth, int result)
{
    if (depth > N - 1)
    {
        answer = max(answer, result);
        return;
    }

    string op = (depth == 0) ? "+" : expression[depth - 1];

    if (depth + 2 < N)
    {
        int bracket = calculate(expression[depth], expression[depth + 2], expression[depth + 1]);
        dfs(depth + 4, calculate(to_string(result), to_string(bracket), op));
    }

    dfs(depth + 2, calculate(to_string(result), expression[depth], op));
}

int main(int argc, char const* argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    string s = "";
    for (int i = 0; i < N; i++)
    {
        char a;
        cin >> a;

        if (a == '+' || a == '-' || a == '*')
        {
            string t(1, a);
            expression.push_back(s);
            expression.push_back(t);
            s = "";
        }
        else
            s += a;
    }

    expression.push_back(s);

    dfs(0, 0);

    cout << answer << "\n";

    return 0;
}

