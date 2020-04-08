#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> S;
    int N;
    cin >> N;


    for (int i = 0; i < N; i++)
    {
        string instruction;
        cin >> instruction;

        if (instruction == "push")
        {
            int operand;
            cin >> operand;
            S.push(operand);
        }
        else if (instruction == "pop")
        {
            if (S.empty())
                cout << -1 << "\n";
            else
            {
                cout << S.top() << "\n";
                S.pop();
            }
        }
        else if (instruction == "size")
            cout << S.size() << "\n";
        else if (instruction == "empty")
            cout << (int) S.empty() << "\n";
        else
            if (S.empty())
                cout << -1 << "\n";
            else
                cout << S.top() << "\n";
    }



    return 0;
}
