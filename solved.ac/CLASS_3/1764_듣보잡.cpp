#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 5e4 + 1;

int N, M;
string person[MAX];
vector<string> result;

bool find_(string target);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> person[i];
    
    sort(&person[0], &person[0] + N);
    
    while (M--)
    {
        string target; cin >> target;

        if (find_(target))
            result.push_back(target);
    }

    cout << (int) result.size() << "\n";

    sort(result.begin(), result.end());

    for (vector<string>::iterator i = result.begin(); i != result.end(); i++)
        cout << (*i) << "\n";

    return 0;
}

bool find_(string target)
{
    int left = 0, right = N - 1;
    bool possible = false;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (person[mid] == target)
        {
            possible = true;
            break;
        }

        if (target < person[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }

    return possible;
}



