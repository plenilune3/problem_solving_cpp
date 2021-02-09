#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 2e5 + 1;

struct lecture
{
    int left, right;

    bool operator< (const lecture &l) const
    {
        if (right != l.right) return right > l.right;
        else return left > l.left;
    }
};

int N;
lecture L[MAX];

bool compare(const lecture &a, const lecture &b);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;


    for (int i = 0; i < N; i++)
        cin >> L[i].left >> L[i].right;
    
    sort(&L[0], &L[0] + N, compare);

    int answer = 1;

    priority_queue<lecture> pq;
    pq.push(L[0]);

    for (int i = 1; i < N; i++)
    {
        if (pq.top().right > L[i].left)
            answer += 1;
        else
            pq.pop();
        
        pq.push(L[i]);
    }

    cout << answer << "\n";
   
    return 0;
}

bool compare(const lecture &a, const lecture &b)
{
    if (a.left != b.left) return a.left < b.left;
    else return a.right < b.right;
}


