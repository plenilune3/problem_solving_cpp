#include <iostream>
#include <deque>
#include <queue>

using namespace std;

const int MAX = 20;
const int MAX_VALUE = 10e6;
const int dx[] = { -1, 1, 0, 0 };
const int dy[] = { 0, 0, -1, 1 };

int R, C, length;
int dp[(1 << 11)][11];
int W[11][11];
char board[MAX][MAX];

int tsp(int current, int visited);
int bfs(pair<int, int> s, pair<int, int> t);

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	while (true)
	{
		deque< pair<int ,int> > v;
		cin >> C >> R;

		if (R == 0 && C == 0)
			break;

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
			{
				cin >> board[i][j];

				if (board[i][j] == 'o')
					v.push_front(make_pair(i, j));
				if (board[i][j] == '*')
					v.push_back(make_pair(i, j));
			}

		length = v.size();

		bool is_possible = false;

		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				if (i == j)
					continue;
				
				W[i][j] = bfs(v[i], v[j]);
				
				if (W[i][j] == -1)
				{
					is_possible = true;
					break;
				}
			}

			if (is_possible)
				break;
		}

		if (is_possible)
		{
			cout << -1 << "\n";
			continue;
		}

		fill_n(&dp[0][0], (1 << 11) * 11, -1);
		int answer = tsp(0, 0);
		
		cout << answer << "\n";
	}

	return 0;
}

int tsp(int current, int visited)
{
	visited |= (1 << current);

	if (visited == (1 << length) - 1)
		return 0;

	int &ret = dp[visited][current];

	if (ret != -1)
		return ret;

	ret = MAX_VALUE;

	for (int i = 0; i < length; i++)
	{
		if (visited & (1 << i) || W[current][i] == 0)
			continue;

		ret = min(ret, tsp(i, visited) + W[current][i]);
	}

	return ret;
}

int bfs(pair<int, int> s, pair<int, int> t)
{
	int dist[MAX][MAX];
	fill_n(&dist[0][0], MAX * MAX, -1);

	queue< pair<int, int> > q;
	dist[s.first][s.second] = 0;
	q.push(make_pair(s.first, s.second));

	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop();

		if (x == t.first && y == t.second)
			return dist[x][y];

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;

			if (dist[nx][ny] != -1 || board[nx][ny] == 'x')
				continue;

			dist[nx][ny] = dist[x][y] + 1;
			q.push(make_pair(nx, ny));
		}
	}

	return -1;
}

// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// const int MAX = 20;

// int W, H;
// char A[MAX][MAX];
// int dist[MAX][MAX];
// int room_distance[11][11];

// pair<int, int> robot;
// vector< pair<int, int> > dust;
// vector< pair<int, int> > v;

// int bfs(pair<int, int> r, pair<int, int> d)
// {
// 	const int dx[] = { -1, 1, 0, 0 };
// 	const int dy[] = { 0, 0, -1, 1 };

// 	fill_n(&dist[0][0], MAX * MAX, -1);
// 	queue< pair<int, int> > q;
// 	dist[r.first][r.second] = 0;
// 	q.push(r);

// 	while (!q.empty())
// 	{
// 		pair<int, int> c = q.front();
// 		q.pop();

// 		if (c.first == d.first && c.second == d.second)
// 			return dist[c.first][c.second];

// 		for (int i = 0; i < 4; i++)
// 		{
// 			int nx = c.first + dx[i];
// 			int ny = c.second + dy[i];

// 			if (nx < 0 || nx >= H || ny < 0 || ny >= W || dist[nx][ny] != -1)
// 				continue;

// 			if (A[nx][ny] != 'x')
// 			{
// 				dist[nx][ny] = dist[c.first][c.second] + 1;
// 				q.push(make_pair(nx, ny));
// 			}
// 		}
// 	}

// 	return -1;
// }

// bool visited[11];
// int answer = MAX * MAX;

// void permutaions(int depth, int N, int result, int now)
// {
// 	if (answer < result)
// 		return;

// 	if (depth == N)
// 	{
// 		answer = min(answer, result);
// 		return;
// 	}

// 	for (int i = 1; i < N; i++)
// 		if (visited[i] == false)
// 		{
// 			visited[i] = true;
// 			result += room_distance[now][i];
// 			permutaions(depth + 1, N, result, i);
// 			visited[i] = false;
// 			result -= room_distance[now][i];
// 		}
// }



// int main(int argc, char const *argv[])
// {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL), cout.tie(NULL);

// 	while (true)
// 	{
// 		answer = MAX * MAX;
// 		v.clear();
// 		dust.clear();
// 		fill_n(&A[0][0], MAX * MAX, 'x');
// 		fill_n(&visited[0], 11, false);
// 		fill_n(&room_distance[0][0], MAX * MAX, 0);

// 		cin >> W >> H;
		
// 		if (W == 0 && H == 0)
// 			break;

// 		for (int i = 0; i < H; i++)
// 			for (int j = 0; j < W; j++)
// 			{
// 				cin >> A[i][j];

// 				if (A[i][j] == 'o')
// 					robot.first = i, robot.second = j;
// 				else if (A[i][j] == '*')
// 					dust.push_back(make_pair(i, j));
// 			}

// 		v.push_back(robot);

// 		int length_dust = dust.size();

// 		for (int i = 0; i < length_dust; i ++)
// 			v.push_back(dust[i]);

// //		vector< pair<int, int> >::iterator iter;
// //		for (iter = dust.begin(); iter != dust.end(); iter++)
// //			v.push_back(*iter);

// 		int length = v.size();
// 		bool possible = true;

// 		for (int i = 0; i < length; i++)
// 		{
// 			for (int j = i + 1; j < length; j++)
// 			{
// 				int distance = bfs(v[i], v[j]);
// 				room_distance[i][j] = distance;
// 				room_distance[j][i] = distance;

// 				if (distance == -1)
// 				{
// 					possible = false;
// 					break;
// 				}
// 			}

// 			if (possible == false)
// 				break;
// 		}

// 		if (possible)
// 			permutaions(1, length, 0, 0);
// 		else
// 			answer = -1;

// 		cout << answer << "\n";
// 	}

// 	return 0;
// }
