#include "hashtable.h"

#include <algorithm>

TChainingHashTable::TChainingHashTable(size_t initialSize)
	: table(initialSize)
{}

void TChainingHashTable::Insert(int key, TValue value) {
	int hash = CalcHash(key);
	TChain& chain = table[hash];
	TChain::iterator it = find(chain.begin(), chain.end(), make_pair(key, value));
	if (it == chain.end()) {
		chain.push_front(make_pair(key, value));
	} else {
		(*it).second = value;
	}
}

bool TChainingHashTable::Find(int key, TValue& value) const {
	int hash = CalcHash(key);
	const TChain& chain = table[hash];
	for (TChain::const_iterator it = chain.begin(); it != chain.end(); it++) {
		if (it->first == key) {
			value = it->second;
			return true;
		}
	}
	return false;	
}

bool TChainingHashTable::Has(int key) const {
	int hash = CalcHash(key);
	const TChain& chain = table[hash];
	for (TChain::const_iterator it = chain.begin(); it != chain.end(); it++) {
		if (it->first == key) {
			return true;
		}
	}	
	return false;
}

void TChainingHashTable::Remove(int key) {
	if (Has(key)) {
		int hash = CalcHash(key);
		TChain& chain = table[hash];
	 	TValue value;
		for (TChain::iterator it = chain.begin(); it != chain.end(); it++) {
			if (it->first == key) {
				value = it->second;
			}
		}
		chain.remove(make_pair(key, value));
	}
}

int TChainingHashTable::CalcHash(int key) const {
	return key % table.size();
}
