#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    queue<int> Q;
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
            Q.push(operand);
        }
        else if(instruction == "pop")
        {
            if (Q.empty())
                cout << -1 << "\n";
            else
            {
                cout << Q.front() << "\n";
                Q.pop();
            }
        }
        else if (instruction == "size")
        {
            cout << Q.size() << "\n";
        }
        else if (instruction == "empty")
            cout << (int) Q.empty() << "\n";
        else if (instruction == "front")
        {
            if (Q.empty())
                cout << -1 << "\n";
            else
                cout << Q.front() << "\n";
        }
        else if (instruction == "back")
        {
            if (Q.empty())
                cout << -1 << "\n";
            else
                cout << Q.back() << "\n";
        }
    }
    return 0;
}
