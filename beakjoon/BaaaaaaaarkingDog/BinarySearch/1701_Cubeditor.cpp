#include <iostream>
#include <map>

using namespace std;

int find_length(string t);

int main(int argc, char const *argv[])
{
    string t;
    getline(cin, t);

    int answer = find_length(t);
    cout << answer << "\n";

    return 0;
}

int find_length(string t)
{
    int length = t.size();
    int left = 1, right = length;
    int answer = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        bool possible = false;
        map<string, bool> visited;
        string p = t.substr(0, mid);

        for (int i = 0; i < length - mid + 1; i++)
        {
            if (visited[p])
            {
                possible = true;
                break;
            }

            visited[p] = true;

            p.erase(p.begin());
            p.push_back(t[i + mid]);
        }

        if (possible)
        {
            answer = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }

    return answer;
}
