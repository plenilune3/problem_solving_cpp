#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;
const int MaxLengthOfArray = 32768;
const int MaxLengthOfCommands = 128000;

int N;
char arr[MaxLengthOfArray];
char commands[MaxLengthOfCommands];
map<int, int> indexOfPairBracket;

bool IsCommand(char command);
string ExecuteCommands(int countCommand);

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        fill_n(arr, MaxLengthOfArray, 0);
        string input = "", output = "";
        stack<int> s;
        int countCommand = 0;
        indexOfPairBracket.clear();

        while (true)
        {
            getline(cin, input);

            if (input == "end")
                break;
            
            for (string::iterator iter = input.begin(); iter != input.end(); iter++)
            {
                if ((*iter) == '%')
                    break;
                
                if (IsCommand((*iter)))
                {
                    commands[countCommand++] = (*iter); 

                    if ((*iter) == '[')
                        s.push(countCommand - 1);
                    else if ((*iter) == ']')
                    {
                        if (s.empty())
                        {
                            output = "COMPILE ERROR";
                            break;
                        }

                        int indexOfOpenBracket = s.top(), indexOfClosedBracket = countCommand - 1;
                        s.pop();

                        indexOfPairBracket[indexOfOpenBracket] = indexOfClosedBracket;
                        indexOfPairBracket[indexOfClosedBracket] = indexOfOpenBracket;
                    }
                }

                if (output == "COMPILE ERROR")
                    break;
            }
        }

        cout << "PROGRAM #" << i << ":" << "\n";
        output == "COMPILE ERROR" ? cout << output << "\n" : cout << ExecuteCommands(countCommand) << "\n";
  }

    return 0;
}

bool IsCommand(char command)
{
    return command == '>' || command == '<' || command == '+' || command == '-' || command == '.' || command == '[' || command == ']';
}

string ExecuteCommands(int countCommand)
{
    string output = "";
    int pointer = 0;

    for (int i = 0; i < countCommand; i++)
    {
        if (commands[i] == '.')
            output += arr[pointer];
        
        else if (commands[i] == '[' || commands[i] == ']')
        {
            if (indexOfPairBracket[i] == 0)
            {
                output = "COMPILE ERROR";
                break;
            }

            if (commands[i] == '[' && arr[pointer] == 0)
                i = indexOfPairBracket[i];
            
            if (commands[i] == ']' && arr[pointer] != 0)
                i = indexOfPairBracket[i];
        }

        else if (commands[i] == '>')
            pointer == MaxLengthOfArray - 1 ? pointer = 0 : pointer++;
        else if (commands[i] == '<')
            pointer == 0 ? pointer = MaxLengthOfArray - 1 : pointer--;
        else if (commands[i] == '+')
            arr[pointer] == 255 ? arr[pointer] = 0 : arr[pointer]++;
        else if (commands[i] == '-')
            arr[pointer] == 0 ? arr[pointer] = 255 : arr[pointer]--;
    }

    return output;
}

