#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    stack< pair<int, int> > s;
    
    int N;
    cin >> N;

    for (int i = 1; i < N + 1; i++)
    {
        int top;
        cin >> top;
        
        while (!s.empty())
        {
            if (s.top().second > top)
            {
                cout << s.top().first << " ";
                break;
            }
            else
                s.pop();
        }

        if (s.empty())
            cout << "0 ";

        s.push(make_pair(i, top));
    }

    return 0;

}
