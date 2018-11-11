#include "arrayset.h"
#include <iostream>
using namespace std;

int main () {
    CArraySet aset;
    CSet* set = &aset;
    set->Insert(4);
    set->Insert(5);
    cout << set->Has(5) << endl;
    cout << set->Has(6) << endl;
    set->Remove(5);
    cout << set->Has(5) << endl;
}
