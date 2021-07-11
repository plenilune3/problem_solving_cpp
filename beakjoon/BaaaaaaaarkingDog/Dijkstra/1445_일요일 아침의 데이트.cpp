#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int MAX = 51;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

struct edge
{
	int x, y, a, b;

	edge() : x(0), y(0), a(0), b(0) {}
	edge(int _x, int _y, int _a, int _b) : x(_x), y(_y), a(_a), b(_b) {}

	bool operator<(const edge &e) const
	{
		if (a != e.a)
			return a > e.a;
		else
			return b > e.b;
	}
};

int N, M;
char board[MAX][MAX];
edge S, F;

pair<int, int> find_path(edge S, edge F);
int count_garbage(int x, int y);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> M;

	for (int x = 0; x < N; x++)
		for (int y = 0; y < M; y++)
		{
			cin >> board[x][y];

			if (board[x][y] == 'S')
				S = edge(x, y, 0, 0);
			if (board[x][y] == 'F')
				F = edge(x, y, 0, 0);
		}
	
	pair<int, int> answer = find_path(S, F);

	cout << answer.first << " " << answer.second << "\n";

	return 0;
}

pair<int, int> find_path(edge S, edge F)
{
	vector< vector<int> > A(MAX, vector<int> (MAX, INT_MAX));
	vector< vector<int> > B(MAX, vector<int> (MAX, INT_MAX));
	priority_queue<edge> pq;
	pq.push(S);
	A[S.x][S.y] = 0, B[S.x][S.y] = 0;

	while (!pq.empty())
	{
		int x = pq.top().x, y = pq.top().y, a = pq.top().a, b = pq.top().b;
		pq.pop();
		
		if (A[x][y] < a && B[x][y] < b)
			continue;
		
		if (x == F.x && y == F.y)
			break;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			
			int na = a, nb = b;
			if (board[nx][ny] == 'g')
				na += 1;
			else
				nb += count_garbage(nx, ny);

			if (board[nx][ny] == 'F')
			{
				if (A[nx][ny] > a && B[nx][ny] > b)
				{
					A[nx][ny] = a;
					B[nx][ny] = b;
					pq.push(edge(nx, ny, a, b));
				}
			}
			else
			{
				if (A[nx][ny] > na && B[nx][ny] > nb)
				{
					A[nx][ny] = na;
					B[nx][ny] = nb;
					pq.push(edge(nx, ny, na, nb));
				}
			}
		}
	}

	return make_pair(A[F.x][F.y], B[F.x][F.y]);
}

int count_garbage(int x, int y)
{
	int result = 0;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		
		if (board[nx][ny] == 'g')
			result += 1;
	}
	
	return result > 0;
}