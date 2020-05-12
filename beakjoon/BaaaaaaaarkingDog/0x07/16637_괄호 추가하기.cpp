#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

template<typename T>
string to_string(const T& value)
{
    stringstream ss;
    ss << value;
    return ss.str();
}

const int MAX = 19;

int N;
vector<string> expression;
bool selected[MAX];

void calculate_plus(int length)
{
    vector<string>::iterator iter;
    for (iter = expression.begin(); iter != expression.end(); iter++)
    {
        int result;

        if ((*iter) == "+")
        {
            int a = atoi((*(iter - 1)).c_str());
            int b = atoi((*(iter + 1)).c_str());

            result = a + b;
            expression.erase(iter - 1, iter + 2);
            expression.insert(iter - 1, to_string(result));
            break;
        }
   }
}

void calculate_sub(int length)
{
    vector<string>::iterator iter;
    for (iter = expression.begin(); iter != expression.end(); iter++)
    {
        int result;

        if ((*iter) == "-")
        {
            int a = atoi((*(iter - 1)).c_str());
            int b = atoi((*(iter + 1)).c_str());

            result = a - b;
            expression.erase(iter - 1, iter + 2);
            expression.insert(iter - 1, to_string(result));
            break;
        }
   }
}

void calculate_mul(int length)
{
    vector<string>::iterator iter;
    for (iter = expression.begin(); iter != expression.end(); iter++)
    {
        int result;

        if ((*iter) == "*")
        {
            int a = atoi((*(iter - 1)).c_str());
            int b = atoi((*(iter + 1)).c_str());

            result = a * b;
            expression.erase(iter - 1, iter + 2);
            expression.insert(iter - 1, to_string(result));
            break;
        }
   }
}

// void backtracking(int depth, int length)
// {
//     if (depth == length / 2)
//     {
//         return;
//     }

//     for (int i = 0; i < length; i++)
//     {

//     }
// }

void dfs(int depth, int length, vector<string> e)
{
    if (depth == length / 2)
    {
        return;
    }

    vector<string> a;
    a.assign(e.begin(), e.end());
}

int main(int argc, char const *argv[])
{
    cin >> N;

    int index = 0;
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

    calculate_mul(expression.size());

    for (int i = 0; i < expression.size(); i++)
        cout << expression[i] << " ";
    cout << "\n";

    return 0;
}
