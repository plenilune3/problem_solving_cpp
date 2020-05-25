#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int s;
    string n;
    cin >> s >> n;

    for (int i = 0; i < 2 * s + 3; i++)
    {
        for (int k = 0; k < n.size(); k++)
        {
            if (i == 0)
            {
                if (n[k] == '0' || n[k] == '2' || n[k] == '3' || n[k] == '5' || n[k] == '6' || n[k] == '7' || n[k] == '8' || n[k] == '9')
                {
                    cout << " ";
                    for (int i = 0; i < s; i++)
                        cout << "-";
                    cout << " ";
                }
                else
                {
                    for (int i = 0; i < s + 2; i++)
                        cout << " ";
                }
            }

            else if (i >= 1 && i <= s)
            {
                if (n[k] == '0' || n[k] == '4' || n[k] == '8' || n[k] == '9')
                {
                    cout << "|";
                    for (int i = 0; i < s; i++)
                        cout << " ";
                    cout << "|";
                }
                else if (n[k] == '1' || n[k] == '2' || n[k] == '3' || n[k] == '7')
                {
                    for (int i = 0; i < s + 1; i++)
                        cout << " ";
                    cout << "|";
                }
                else
                {
                    cout << "|";
                    for (int i = 0; i < s + 1; i++)
                        cout << " ";
                }
            }

            else if (i == s + 1)
            {
                if (n[k] == '2' || n[k] == '3' || n[k] == '4' || n[k] == '5' || n[k] == '6' || n[k] == '8' || n[k] == '9')
                {
                    cout << " ";
                    for (int i = 0; i < s; i++)
                        cout << "-";
                    cout << " ";
                }

                else
                {
                    for (int i = 0; i < s + 2; i++)
                        cout << " ";
                }
            }

            else if (i >= s + 2 && i <= 2 * s + 1)
            {
                if (n[k] == '0' || n[k] == '6' || n[k] == '8')
                {
                    cout << "|";
                    for (int i = 0; i < s; i++)
                        cout << " ";
                    cout << "|";
                }
                else if (n[k] == '1' || n[k] == '3' || n[k] == '4' || n[k] == '5' || n[k] == '7' || n[k] == '9')
                {
                    for (int i = 0; i < s + 1; i++)
                        cout << " ";
                    cout << "|";
                }
                else
                {
                    cout << "|";
                    for (int i = 0; i < s + 1; i++)
                        cout << " ";
                }
            }

            else
            {
                if (n[k] == '1' || n[k] == '4' || n[k] == '7')
                {
                    for (int i = 0; i < s + 2; i++)
                        cout << " ";
                }
                else
                {
                    cout << " ";
                    for (int i = 0; i < s; i++)
                        cout << "-";
                    cout << " ";
                }
            }
            cout << " ";
        }
        cout << "\n";
    }

    return 0;
}

