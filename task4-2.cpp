#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calculateS(vector<int>& ints) {
	double sum = 0.0;
	for (int i = 0; i < ints.size(); i++) {
		sum += ints[i];
	}
	return sum / ints.size();
}

int main()
{
	vector<int> ints;

	int currentNum;

	cin >> currentNum;
	while (currentNum != 0) {
		ints.push_back(currentNum);
		cin >> currentNum;
	}
	double s = calculateS(ints);

	double top = 0.0;

	for (int i = 0; i < ints.size(); i++) {
		double razn = ints[i] - s;
		top += razn * razn;
	}
	cout << sqrt(top / (ints.size() - 1));

	
}

