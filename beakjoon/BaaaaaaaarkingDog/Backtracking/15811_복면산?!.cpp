#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

const int MAX = 18;

int D;
string A, B, C;
bool visited[10], possible;
int num_of_alpha[26];
vector<int> alpha;

void find_num(int depth);
unsigned long long stoll(string &S);
vector<int> find_alpha(string &A, string &B, string &C);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> A >> B >> C;

	alpha = find_alpha(A, B, C);
	D = (int) alpha.size();

	find_num(0);

	if (possible)
		cout << "YES" << "\n";
	else
		cout << "NO" << "\n";

	return 0;
}

void find_num(int depth)
{
	if (possible)
		return;

	if (depth == D)
	{
		if ((stoll(A) + stoll(B)) == stoll(C))
			possible = true;
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (visited[i]) continue;
		
		visited[i] = true;
		num_of_alpha[alpha[depth]] = i;
		find_num(depth + 1);
		visited[i] = false;
	}
}

unsigned long long stoll(string &S)
{
	unsigned long long result = 0;
	int N = (int) S.size();

	for (int i = 0; i < N; i++)
		result = result * 10 + num_of_alpha[S[i] - 'A'];
	
	return result;
}

vector<int> find_alpha(string &A, string &B, string &C)
{
	vector<int> result;
	set<char> s;

	for (int i = 0; i < A.size(); i++)
		s.insert(A[i]);
	for (int i = 0; i < B.size(); i++)
		s.insert(B[i]);
	for (int i = 0; i < C.size(); i++)
		s.insert(C[i]);
	for (set<char>::iterator i = s.begin(); i != s.end(); i++)
		result.push_back((*i) - 'A');

	return result;
}