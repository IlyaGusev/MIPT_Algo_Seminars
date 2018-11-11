#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector<int> collection(n);
	for (size_t i = 0; i < n; i++) {
		collection[i] = i + 1;
	}
	random_shuffle(collection.begin(), collection.end());
	cout << n << " " << k << endl;
	for (size_t i = 0; i < n; i++) {
		cout << collection[i] << " ";
	}
	cout << endl;
	return 0;
}
