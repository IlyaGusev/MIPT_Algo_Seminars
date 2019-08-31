#include "arrayset.h"
#include <cassert>
#include <iostream>

void CArraySet::Insert(int key) {
    collection.push_back(key);
}
    
void CArraySet::Remove(int key) {
    assert(Has(key));
    vector<int>::iterator it = collection.begin();
    for (; it != collection.end(); it++) {
        if (*it == key) {
            collection.erase(it);
            return;
        }
    }
}

bool CArraySet::Has(int key) const {
    vector<int>::const_iterator it = collection.begin();
    for (; it != collection.end(); it++) {
        if (*it == key) {
            return true;
        }
    }
    return false;
}
