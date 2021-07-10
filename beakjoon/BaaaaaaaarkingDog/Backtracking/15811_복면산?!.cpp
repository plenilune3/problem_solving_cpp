#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int MAX = 18;

int N, M, K, D;
char A[MAX], B[MAX], C[MAX];
bool visited[10];
vector<int> v;
void find_num(int depth, int index);

int	count_alpha(char A[MAX], char B[MAX], char C[MAX]);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> A >> B >> C;

	N = strlen(A), M = strlen(B), K = strlen(C);

	D = count_alpha(A, B, C);

	find_num(0, 0);

	return 0;
}

void find_num(int depth, int index)
{
	if (depth == D)
	{
		for (vector<int>::iterator i = v.begin(); i != v.end(); i++)
			cout << (*i) << " ";
		cout << "\n";
		return;
	}

	for (int i = index; i < 10; i++)
	{
		if (visited[i]) continue;
		
		visited[i] = true;
		v.push_back(i);
		find_num(depth + 1, i);
		visited[i] = false;
		v.pop_back();
	}
}

int	count_alpha(char A[MAX], char B[MAX], char C[MAX])
{
	int result = 0;
	int alpha[26] = { 0 };

	for (int i = 0; i < N; i++)
		alpha[A[i] - 'A'] += 1;
	for (int i = 0; i < M; i++)
		alpha[B[i] - 'A'] += 1;
	for (int i = 0; i < K; i++)
		alpha[C[i] - 'A'] += 1;
	for (int i = 0; i < 26; i++)
		if (alpha[i])
			result += 1;
	
	return result;
}
