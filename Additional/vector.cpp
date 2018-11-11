#include <iostream>
#include <vector>
#include <string>

using namespace std;
using std::vector;

int main() {
	int n;
	cin >> n;
	vector<int> a;
	for (size_t i = 0; i < n; i++) {
		int element;
		cin >> element;
		a.push_back(element);
		cout << a[a.size()-1] << endl;
	}

	string s;
	cin >> s;
	cout << s[0] << endl;
	cout << s.size() << endl; 
	s += "aaa";
	
	return 0;
}
