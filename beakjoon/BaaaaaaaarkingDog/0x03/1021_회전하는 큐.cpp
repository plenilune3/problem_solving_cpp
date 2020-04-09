#include <iostream>
#include <deque>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> dq;
    int answer = 0;

    int N, M;
    cin >> N; cin >> M;

    for (int i = 1; i < N + 1; i++)
        dq.push_back(i);

    for (int i = 0; i < M; i++)
    {
        int num, index, count = 0;
        int left_shift, right_shift;
        cin >> num;
        
        for (int j = 0; j < dq.size(); j++)
        {
            if (num == dq[j])
                index = j + 1;
        }

        left_shift = index - 1;
        right_shift = dq.size() - index + 1;

        if (left_shift <= right_shift)
        {
            for (int j = 1; j <= left_shift; j++)
            {
                int temp;
                temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
                count++;
            }
        }
        else
        {
            for (int j = 1; j <= right_shift; j++)
            {
                int temp;
                temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
                count++;
            }
        }

        dq.pop_front();
        answer += count;
    }

    cout << answer << "\n";

    return 0;
}
