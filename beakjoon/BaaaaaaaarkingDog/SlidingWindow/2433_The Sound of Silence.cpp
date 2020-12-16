#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX = 1e6 + 1;

int N, M, C, A[MAX];

vector<int> get_silence();

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M >> C;

    for (int i = 0; i < N; i++)
        cin >> A[i];
    
    vector<int> answer = get_silence();

    if (!answer.empty())
        for (vector<int>::iterator i = answer.begin(); i != answer.end(); i++)
            cout << (*i) << "\n";
    else
        cout << "NONE" << "\n";

    return 0;
}

vector<int> get_silence()
{
    vector<int> result;
    deque< pair<int, int> > window_max, window_min;

    for (int i = 0; i < N; i++)
    {
        while (!window_max.empty() && window_max.front().first <= i - M)
            window_max.pop_front();

        while (!window_max.empty() && window_max.back().second < A[i])
            window_max.pop_back();

        while (!window_min.empty() && window_min.front().first <= i - M)
            window_min.pop_front();
        
        while (!window_min.empty() && window_min.back().second > A[i])
            window_min.pop_back();
        
        window_max.push_back(make_pair(i, A[i]));
        window_min.push_back(make_pair(i, A[i]));

        if (i >= M - 1 && window_max.front().second - window_min.front().second <= C)
            result.push_back(i - (M - 1) + 1);
    }

    return result;
}
