#include <iostream>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

const int MAX = 11;

int N, A, S, M, D;
int min_result = INT_MAX, max_result = INT_MIN;
int nums[MAX];

int get_priority(string op);
void get_result(stack<int> &result, stack<string> &op);
int calculate(vector<string> exp);
void dfs(int depth, vector<string> exp, int a, int s, int m, int d);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> nums[i];
    
    cin >> A >> S >> M >> D;

    vector<string> exp;
    exp.push_back(to_string(nums[0]));
    dfs(1, exp, A, S, M, D);

    cout << max_result << "\n";
    cout << min_result << "\n";

    return 0;
}

int get_priority(string op)
{
    if (op == "*" || op  == "/") return 2;
    else if (op == "+" || op == "-") return 1;
    else return 0;
}

void get_result(stack<int> &result, stack<string> &op)
{
    int x, y, z;
    y = result.top(); result.pop();
    x = result.top(); result.pop();
    string e = op.top(); op.pop();

    if (e == "+") z = x + y;
    else if (e == "-") z = x - y;
    else if (e == "*") z = x * y;
    else z = x / y;

    result.push(z);
}

int calculate(vector<string> exp)
{
    stack<int> result;
    stack<string> op;

    for (vector<string>::iterator iter = exp.begin(); iter != exp.end(); iter++)
    {
        string e = (*iter);

        if (e == "+" || e == "-" || e == "*" || e == "/")
        {
            while (!op.empty() && get_priority(e) <= get_priority(op.top()))
                get_result(result, op);

            op.push(e);
        }
        else
            result.push(stoi(e));
    }

    while (!op.empty())
        get_result(result, op);
    
    return result.top();
}


void dfs(int depth, vector<string> exp, int a, int s, int m, int d)
{
    if (depth == N)
    {
        int result = calculate(exp);

        min_result = min(min_result, result);
        max_result = max(max_result, result);
        return;
    }

    if (a)
    {
        exp.push_back("+"), exp.push_back(to_string(nums[depth]));
        dfs(depth + 1, exp, a - 1, s, m, d);
        exp.pop_back(), exp.pop_back();
    }
    if (s)
    {
        exp.push_back("-"), exp.push_back(to_string(nums[depth]));
        dfs(depth + 1, exp, a, s - 1, m, d);
        exp.pop_back(), exp.pop_back();
    }
    if (m)
    {
        exp.push_back("*"), exp.push_back(to_string(nums[depth]));
        dfs(depth + 1, exp, a, s, m - 1, d);
        exp.pop_back(), exp.pop_back();
    }
    if (d)
    {
        exp.push_back("/"), exp.push_back(to_string(nums[depth]));
        dfs(depth + 1, exp, a, s, m, d - 1);
        exp.pop_back(), exp.pop_back();
    }
}

// vector<string> change_to_postfix(vector<string> exp)
// {
//     stack <string> op;
//     vector<string> postfix;

//     for (vector<string>::iterator iter = exp.begin(); iter != exp.end(); iter++)
//     {
//         string c = (*iter);

//         if (c == "+" || c == "-" || c == "*" || c == "/")
//         {
//             while (!op.empty() && (get_priority(c) <= get_priority(op.top())))
//             {
//                 postfix.push_back(op.top());
//                 op.pop();
//             }

//             op.push(c);
//         }
//         else
//             postfix.push_back(c);
//     }

//     while(!op.empty())
//     {
//         postfix.push_back(op.top());
//         op.pop();
//     }

//     return postfix;
// }

// int calculate(vector<string> exp)
// {
//     stack<string> result;

//     for (vector<string>::iterator iter = exp.begin(); iter != exp.end(); iter++)
//     {
//         string c = (*iter);

//         if (c == "+" || c == "-" || c == "*" || c == "/")
//         {
//             int x = stoi(result.top()); result.pop();
//             int y = stoi(result.top()); result.pop();
//             int z;

//             if (c == "+") z = y + x;
//             else if (c == "-") z = y - x;
//             else if (c == "*") z = y * x;
//             else z = y / x;

//             result.push(to_string(z));
//         }
//         else
//             result.push(c);
//     }

//     return stoi(result.top());
// }

