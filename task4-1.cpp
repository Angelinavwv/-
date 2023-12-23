#include <iostream> 
#include <string> 
#include <vector> 
#include <map> 
#include <sstream> 
#include <algorithm> 

using namespace std;

void tokenize(string const& str, const char delim, vector<string>& out)
{
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}

int main()
{
    string input;
    getline(cin, input);

    vector<string> strings;
    tokenize(input, ' ', strings);

    sort(strings.begin(), strings.end(), [](const string& a, const string& b) -> bool
        {
            return a < b;
        });
    map<string, int> mp;
    for (int i = 0; i < strings.size(); i++) {
        mp[strings[i]] = 0;
    }

    for (int i = 0; i < strings.size(); i++) {
        mp[strings[i]] = mp[strings[i]] + 1;
    }
    for (auto const& imap : mp)
        cout << imap.first << ' ' << imap.second << endl;
}
