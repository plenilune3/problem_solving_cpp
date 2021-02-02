#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Trie
{
private:
    map<string, Trie*> child;
    bool finished;
public:
    void insert(vector<string> &v, int d);
    void find(int d);
};

int N;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    Trie *T = new Trie();

    cin >> N;

    while (N--)
    {
        vector<string> foods;
        int K; cin >> K;

        while (K--)
        {
            string food; cin >> food;
            foods.push_back(food);
        }

        T -> insert(foods, 0);
    }

    T -> find(0);

    delete T;
    return 0;
}

void Trie::find(int d)
{
    if (child.empty()) return;

    for (map<string, Trie*>::iterator i = child.begin(); i != child.end(); i++)
    {
        for (int j = 0; j < d; j++)
            cout << "--";
        cout << i -> first << "\n";

        i -> second -> find(d + 1);
    }
}

void Trie::insert(vector<string> &v, int d)
{
    if (d == v.size())
    {
        finished = true;
        return;
    }

    string food = v[d];

    if (child[food] == NULL)
        child[food] = new Trie();
    
    child[food]->insert(v, d + 1);
}