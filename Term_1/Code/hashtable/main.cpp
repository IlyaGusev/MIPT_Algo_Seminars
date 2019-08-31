#include "hashtable.h"
#include <iostream>

using namespace std;

int main() {
	TChainingHashTable table(10);
	table.Insert(1, 2);
	table.Insert(100, 4);
	int value = 0;
	table.Find(100, value);
	cout << value << endl;
}
