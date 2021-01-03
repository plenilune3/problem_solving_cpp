#include <iostream>
#include <map>

using namespace std;

const int MAX = 1e5 + 1;

int N, K, answer, breed[MAX];
map<int, int> breed_count;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> breed[i];
   
    int left = 0, right = 0;
    int cnt = 0, max_breed_count = 0;

    while (true)
    {
        if (cnt > K + 1)
        {
            if (breed_count[breed[left]] == 1)
                cnt -= 1;
            
            breed_count[breed[left]] -= 1;
            max_breed_count = max(max_breed_count, breed_count[breed[left]]);
            left += 1;
        }
        else if (right == N)
            break;
        else
        {
            if (breed_count[breed[right]] == 0)
                cnt += 1;
            
            breed_count[breed[right]] += 1;
            max_breed_count = max(max_breed_count, breed_count[breed[right]]);
            right += 1;
        }
    }

    cout << max_breed_count << "\n";

    return 0;
}
