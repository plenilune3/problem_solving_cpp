#include <iostream>
#include <set>

using namespace std;

const int MAX = 1e4 + 1;

class Trie
{
private:
    Trie* child[96];
    bool finished;
    int cnt;
public:
    Trie();
    ~Trie();
    int char_to_index(char a);
    int count_species(const char* word);
    void insert(const char* word);
    bool find(const char* word);
};

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int total_species = 0;

    Trie *T = new Trie();
    string species; set<string> s;

    while (getline(cin, species))
    {
        total_species += 1;
        T -> insert(species.c_str());
        s.insert(species);
    }

    cout << fixed;
    cout.precision(4);

    for (set<string>::iterator i = s.begin(); i != s.end(); i++)
    {
        cout << (*i) << " ";
        cout << (double) T->count_species((*i).c_str()) / total_species * 100 << "\n";
    }

    delete T;
   
    return 0;
}

int Trie::count_species(const char* word)
{
    int next = char_to_index(*word);

    if (*word == '\0') return cnt; 

    if (child[next] == NULL) return 0;

    return child[next]->count_species(word + 1);
}

bool Trie::find(const char* word)
{
    int next = char_to_index(*word);

    if (*word == '\0') return finished;

    if (child[next] == NULL) return false;

    return child[next]->find(word + 1);
}

void Trie::insert(const char* word)
{
    if (*word == '\0')
    {
        finished = true;
        cnt += 1;
        return;
    }
    
    int next = char_to_index(*word);

    if (child[next] == NULL) child[next] = new Trie();

    child[next]->insert(word + 1);
}

int Trie::char_to_index(const char a)
{
    return a - 32;
}

Trie::Trie()
{
    for (int i = 0; i < 96; i++)
        child[i] = NULL;
    finished = false, cnt = 0;
}

Trie::~Trie()
{
    for (int i = 0; i < 96; i++)
        if (child[i] != NULL)
            delete child[i];
}
