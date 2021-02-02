#include <iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

class node
{
private:
    map<string, node*> child;
    bool finished = false;
public:
    void insert(vector<string> &v, int d);
    void print(int d);
};

int N;

vector<string> split(string s, char d);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    node *root = new node();

    cin >> N;

    while (N--)
    {
        string s; cin >> s;
        vector<string> dirs = split(s, '\\');
        root->insert(dirs, 0);
    }

    root->print(0);

    delete root;

    return 0;
}

void node::print(int d)
{
    for (map<string, node*>::iterator i = child.begin(); i != child.end(); i++)
    {
        for (int i = 0; i < d; i++)
            cout << " ";
        cout << i -> first << "\n";

        i -> second -> print(d + 1);
    }
}

void node::insert(vector<string> &v, int d)
{
    if (d == (int) v.size())
    {
        finished = true;
        return;
    }

    string next = v[d];

    if (child[next] == NULL)
        child[next] = new node();
    
    child[next]->insert(v, d + 1);
}

vector<string> split(string s, char d)
{
    vector<string> result;
    stringstream ss(s);
    string temp;

    while (getline(ss, temp, d))
        result.push_back(temp);
    
    return result;
}