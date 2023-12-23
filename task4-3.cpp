#include <iostream>
#include <set>
#include <map>
#include <sstream> 
#include <string> 

using namespace std;

void tokenize(string const& str, const char delim, set<int>& out)
{
	stringstream ss(str);

	string s;
	while (getline(ss, s, delim)) {
		int token = stoi(s);
		if (token != 0) {
			out.insert(token);
		}
	}
}

bool canGoToVertex(map<int, set<int>>& vertices, set<int>& skip, int from, int to) {
	if (skip.find(from) != skip.end()) {
		return false;
	}
	skip.insert(from);
	set<int> verticesForFrom = vertices[from];
	if (verticesForFrom.find(to) != verticesForFrom.end()) {
		return true;
	}
	for (int i : verticesForFrom) {
		if (canGoToVertex(vertices, skip, i, to)) {
			verticesForFrom.insert(to);
			return true;
		}
	}

	return false;
}

int main()
{
	string line;

	int vertexNum;

	cin >> vertexNum;
	getline(std::cin, line);

	map<int, set<int>> vertices;
	for (int i = 1; i <= vertexNum; i++) {

		getline(std::cin, line);

		set<int> numsForCurrentVertes;
		tokenize(line, ' ', numsForCurrentVertes);
		vertices[i] = numsForCurrentVertes;
	}

	for (int from = 1; from <= vertexNum; from++) {

		for (int to = 1; to <= vertexNum; to++) {
			int result = 0;
			set<int> skip;
			if (from == to || canGoToVertex(vertices, skip, from, to)) {
				result = 1;
			}
			cout << result << ' ';
		}
		cout << endl;
	}
}
