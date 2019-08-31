#include <vector>
#include <forward_list>
#include <utility>

using namespace std;
typedef forward_list<pair<int, int>> TChain;
typedef int TValue;

class TChainingHashTable {
public:
	TChainingHashTable(size_t initialSize);

	void Insert(int key, TValue value);
	bool Find(int key, TValue& value) const;
	bool Has(int key) const;	
	void Remove(int key);

private:
	vector<TChain> table;
	size_t size;

	int CalcHash(int key) const;
};
