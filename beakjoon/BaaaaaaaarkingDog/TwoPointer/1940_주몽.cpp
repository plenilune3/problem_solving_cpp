#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 15000;

int N, M;
int material[MAX];

int make_armor();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> material[i];
    
    sort(&material[0], &material[0] + N);

    int answer = make_armor();

    cout << answer << "\n";

    return 0;
}

int make_armor()
{
    int left = 0, right = N - 1;
    int count = 0;

    while (left < right)
    {
        int sum_material = material[left] + material[right];

        if (sum_material == M)
            count += 1;
        
        if (sum_material <= M)
            left += 1;
        else
            right -= 1;
    }

    return count;
}
