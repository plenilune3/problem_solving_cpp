#include <iostream>
#include <deque>

using namespace std;

const int MAX = 250001;

int N;
char beads[MAX];

int find_length();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;
    cin >> beads;

    cout << find_length() << "\n";

    return 0;
}

int find_length()
{
    int result = 0;
    deque<char> dq;

    for (int i = 0; i < N; i++)
    {
        if (!dq.empty() && (dq.back() == beads[i] || beads[i] == 'V' || dq.back() == 'V'))
            dq.clear();
        
        dq.push_back(beads[i]);

        result = max(result, (int) dq.size());
    }

    return result;
}
