#include <iostream>
#include <set>

using namespace std;

const int MAX = 101;

int N, startNode, endNode;
int arr[MAX];
int previous[MAX];
bool visited[MAX];
bool cycle[MAX];

void SelectNumber(int);

int main(int argc, char const *argv[])
{
    set<int> answer;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    
    for (int i = 1; i <= N; i++)
        if (visited[i] == false)
        {
            SelectNumber(i);

            while (true)
            {
                answer.insert(endNode);
                if (endNode == startNode)
                    break;
                endNode = previous[endNode];
            }
        }

    cout << answer.size() << "\n";

    for (set<int>::iterator iter = answer.begin(); iter != answer.end(); iter++)
        cout << (*iter) << "\n";
    cout << "\n";   

    return 0;
}

void SelectNumber(int index)
{
    visited[index] = true;

    int nextNumber = arr[index];

    if (visited[nextNumber] == false)
    {
        previous[nextNumber] = index;
        SelectNumber(nextNumber);
    }
    else if (cycle[nextNumber] == false)
    {
        startNode = nextNumber;
        endNode = index;
    }

    cycle[index] = true;
}
