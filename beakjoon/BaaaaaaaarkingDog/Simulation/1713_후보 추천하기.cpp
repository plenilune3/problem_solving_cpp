#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 101;

int N, M;
int recommend[MAX];
bool is_framed[MAX];

struct candidate
{
    int t, id;

    bool operator<(const candidate &c)
    {
        if (recommend[id] != recommend[c.id])
            return recommend[id] < recommend[c.id];
        else
            return t < c.t;
    }

    bool operator==(const candidate &c)
    {
        return id == c.id;
    }
};

candidate make_candidate(int t, int id);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N >> M;

    vector<candidate> frame;

    for (int t = 0; t < M; t++)
    {
        sort(frame.begin(), frame.end());

        int id; cin >> id;
        recommend[id] += 1;

        candidate c = make_candidate(t, id);
        vector<candidate>::iterator it = find(frame.begin(), frame.end(), c);

        if (it == frame.end())
        {
            if (frame.size() == N)
            {
                recommend[frame[0].id] = 0;
                frame.erase(frame.begin());
            }

            frame.push_back(c);
        }
    }

    vector<int> answer;

    for (int i = 0; i < N; i++)
        answer.push_back(frame[i].id);
    
    sort(answer.begin(), answer.end());

    for (int i = 0; i < N; i++)
        cout << answer[i] << " ";
    cout << "\n";

    return 0;
}

candidate make_candidate(int t, int id)
{
    candidate c = { t, id };
    return c;
}