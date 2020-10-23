#include <iostream>

using namespace std;

int counter[10001];

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N;
    cin >> N;

    int max_num = 0;

    for (int i = 0; i < N; i++)
    {
        int num; cin >> num;
        counter[num] += 1;
        max_num = max(max_num, num);
    }

    for (int i = 0; i <= max_num; i++)
        for (int j = 0; j < counter[i]; j++)
            cout << i << " ";

    return 0;
}
