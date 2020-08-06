#include <iostream>
#include <queue>

using namespace std;

const int MAX = 101;

int N;
int arr[MAX];
bool visited[MAX];
bool cycle[MAX];
priority_queue<int> pq;

void SelectNumber(int depth);

int main(int argc, char const *argv[])
{
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    
    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";
    cout << "\n";

    SelectNumber(0);

    return 0;
}

void SelectNumber(int index)
{
    visited[index] = true;

    int nextNumber = arr[index];

    if (visited[nextNumber] == false)
        SelectNumber(nextNumber);
    else if (cycle[nextNumber] == 0)
    {

    }

    cycle[index] = true;
}
