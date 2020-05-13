#include <iostream>
#include <stack>
#include <string>

using namespace std;

const int MAX = 100;

string expression;
stack<char> op;
string answer;

int priority(char c)
{
	if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return 0;
}

int main()
{
	cin >> expression;

	string::iterator iter;

	for (iter = expression.begin(); iter != expression.end(); iter++)
	{
		char c = (*iter);

		if (c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')')
			answer += c;
		else if (c == '(')
			op.push(c);
		else if (c == ')')
		{
			while (op.top() != '(')
			{
				answer += op.top();
				op.pop();
			}
			op.pop();
		}
		else
		{
			while (!op.empty() && (priority(c) <= priority(op.top())))
			{
				answer += op.top();
				op.pop();
			}
			op.push(c);
		}
	}

	while (!op.empty())
	{
		answer += op.top();
		op.pop();
	}

	cout << answer << "\n";

	return 0;
}