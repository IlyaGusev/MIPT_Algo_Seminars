// Set interface
class CSet {
public:
    virtual void Insert(int key) = 0;
    virtual void Remove(int key) = 0;
    virtual bool Has(int key) const = 0;
};
