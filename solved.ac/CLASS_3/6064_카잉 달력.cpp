#include <iostream>

using namespace std;

int get_count(int M, int N, int x, int y);
int gcd(int a, int b);
int lcm(int a, int b);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T; cin >> T;
    while (T--)
    {
        int M, N, x, y;

        cin >> M >> N >> x >> y;

        int answer = get_count(M, N, x, y);
        
        cout << answer << "\n";
    }

    return 0;
}

int get_count(int M, int N, int x, int y)
{
    int max_counter = lcm(M, N);
    int answer = -1;
    int counter = 0;
    int a = x, b = x % N;
    counter += x;

    while (counter <= max_counter)
    {
        if (b == 0)
            b = N;

        if (a == x && b == y)
        {
            answer = counter;
            break;
        }

        b = (b + M) % N;
        counter += M;
    }

    return answer;
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int gcd(int a, int b)
{
    if (a > b) swap(a, b);

    while (b)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}
