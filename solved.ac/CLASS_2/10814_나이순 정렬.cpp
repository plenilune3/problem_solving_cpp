#include <iostream>
#include <algorithm>

using namespace std;

struct user
{
    int age;
    string name;

    bool operator< (const user &u) const
    {
        return age < u.age;
    }
};

const int MAX = 1e5 + 1;

int N;
user users[MAX];

user make_user(int age, string name);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int age; string name;
        cin >> age >> name;
        users[i] = make_user(age, name);
    }

    stable_sort(users, users + N);

    for (int i = 0; i < N; i++)
        cout << users[i].age << " " << users[i].name << "\n";

    return 0;
}

user make_user(int age, string name)
{
    user u = { age, name };
    return u;
}