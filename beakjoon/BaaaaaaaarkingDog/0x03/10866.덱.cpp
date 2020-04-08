#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    deque<int> deq;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string instruction;
        cin >> instruction;

        if (instruction == "push_front")
        {
            int operand;
            cin >> operand;
            deq.push_front(operand);
        }
        else if (instruction == "push_back")
        {
            int operand;
            cin >> operand;
            deq.push_back(operand);
        }
        else if (instruction == "pop_front")
        {
            if (deq.empty())
                cout << -1 << "\n";
            else
            {
                cout << deq.front() << "\n"; deq.pop_front();
            }
        }
        else if (instruction == "pop_back")
        {
            if (deq.empty())
                cout << -1 << "\n";
            else
            {
                cout << deq.back() << "\n"; deq.pop_back();
            }
        }
        else if (instruction == "size")
            cout << deq.size() << "\n";
        else if (instruction == "empty")
            cout << (int) deq.empty() << "\n";
        else if (instruction == "front")
        {
            if (deq.empty())
                cout << -1 << "\n";
            else
                cout << deq.front() << "\n";
        }
        else if (instruction == "back")
        {
            if (deq.empty())
                cout << -1 << "\n";
            else
                cout << deq.back() << "\n";
        }
    }

    return 0;
}
