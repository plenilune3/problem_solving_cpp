#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
 
using namespace std;

vector<string> split(string str, char delimiter);
 
int main(int argc, char **argv) {
    string line = "[1,2,3,4]";
    char *a;
    strcpy(a, line.c_str());
    vector<string> line_vector;

    char *ptr = strtok(a, "[,]");

    while (ptr != NULL)
    {
        line_vector.push_back(string(ptr));
        ptr = strtok(NULL, "[,]");
    }
 
    for (int i = 0; i < line_vector.size(); ++i)
        cout << line_vector[i] << endl;
}
 
vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
 
    return internal;
}