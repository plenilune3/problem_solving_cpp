#include <iostream>

using namespace std;

const int MAX = 10;

int N, M, C;
int board[MAX][MAX];
bool visited[MAX][MAX];

void get_price(int x, int y, int cnt, int sum, int price, int &result)
{
    if (sum > C)
        return;

    result = max(result, price);

    if (cnt == M)
        return;
    
    get_price(x, y + 1, cnt + 1, sum + board[x][y], price + board[x][y] * board[x][y], result);
    get_price(x, y + 1, cnt + 1, sum, price, result);
}

int get_benefit(int x, int y)
{
    for (int i = 0; i < M; i++)
        visited[x][y + i] = true;
    
    int price_a = 0, price_b = 0;
    get_price(x, y, 0, 0, 0, price_a);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N - M + 1; j++)
            if (visited[i][j] == false)
            {
                int result = 0;
                get_price(i, j, 0, 0, 0, result);
                price_b = max(price_b, result);
            }
    
    return price_a + price_b;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        fill_n(&visited[0][0], MAX * MAX, false);

        cin >> N >> M >> C;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> board[i][j];
        
        int answer = 0;

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N - M + 1; j++)
                answer = max(answer, get_benefit(i, j));
        
        cout << "#" << t << " " << answer << "\n";
    }

    return 0;
}

