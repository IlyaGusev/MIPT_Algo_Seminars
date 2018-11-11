#include "set.h"
#include <vector>
using namespace std;

// Array implementation of Set inteface
class CArraySet : public CSet {
public:
    void Insert(int key); 
    void Remove(int key); 
    bool Has(int key) const;

private:
    vector<int> collection;

    int find(int key) const;
};
