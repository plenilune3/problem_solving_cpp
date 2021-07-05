#include <iostream>
#include <sstream>
#include <vector>
#include <stack>

using namespace std;

int N;
string op = " +-";
vector<string> exp_;

void find_exp(int depth);
vector<string> convert(vector<string> &exp_);
int calculate_exp(vector<string> &exp_);
void get_result(stack<int> &result, stack<string> &op);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int T; cin >> T;
	while (T--)
	{
		cin >> N;
		exp_.push_back(to_string(1));
		find_exp(1);
		cout << "\n";
		exp_.pop_back();
	}

	return 0;
}

void find_exp(int depth)
{
	if (depth == N)
	{
		vector<string> temp = convert(exp_);
		int result = calculate_exp(temp);
		if (!result)
		{
			for (vector<string>::iterator i = exp_.begin(); i != exp_.end(); i++)
				cout << (*i);
			cout << "\n";
		}
		return;
	}
	for (int i = 0; i < 3; i++)
	{
		exp_.push_back(string(1, op[i]));
		exp_.push_back(to_string(depth + 1));
		find_exp(depth + 1);
		exp_.pop_back();
		exp_.pop_back();
	}
}

vector<string> convert(vector<string> &exp_)
{
	vector<string> result;

	for (vector<string>::iterator i = exp_.begin(); i != exp_.end(); i++)
	{
		if (*i != " ")
			result.push_back(*i);
		else
		{
			int temp = stoi(*(result.end() - 1)) * 10 + stoi(*(i + 1));
			result.pop_back();
			result.push_back(to_string(temp));
			i++;
		}
	}

	return result;
}

int calculate_exp(vector<string> &exp_)
{
	stack<int> result;
	stack<string> op;

	for (vector<string>::iterator i = exp_.begin(); i != exp_.end(); i++)
	{
		string e = (*i);

		if (e == "+" || e == "-")
		{
			while (!op.empty())
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

void get_result(stack<int> &result, stack<string> &op)
{
	int x, y, z;
	y = result.top(); result.pop();
	x = result.top(); result.pop();
	string e = op.top(); op.pop();

	if (e == "+") z = x + y;
	else z = x - y;

	result.push(z);
}