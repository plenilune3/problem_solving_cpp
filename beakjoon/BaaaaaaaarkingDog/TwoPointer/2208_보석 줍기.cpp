#include <iostream>

using namespace std;

const int MAX = 1e5 + 1;

int N, M, sum_value;
int jewels[MAX];

int get_max_value();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> jewels[i];
    
    cout << get_max_value() << "\n";
    
    return 0;
}

int get_max_value()
{
    int left = 0, right = 0;
    int sum_value = 0;

    while (true)
    {
        if (right - left)
    }

    return max_value;
}
