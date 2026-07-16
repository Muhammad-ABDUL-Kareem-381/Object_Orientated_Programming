#include "Set.h"

Set::Set() : data(nullptr), capacity(0), noe(0)
{

}

Set::~Set()
{
    delete[] data;
}

void Set::createSet()
{
    if (capacity > 0)
    {
        data = new int[capacity];
    }
}

void Set::inputSet(int n)
{
    if (!data)
    {
		createSet();
    }
    for (int i = 0; i < n && i < capacity; i++)
    {
        int value;
		cout << "Enter element " << (i + 1) << ": ";
        cin >> value;
        addElement(value);
    }
}

bool Set::addElement(int element)
{
    if (!data)
    {
        createSet();
    }
    if (isFull() || searchElement(element))
    {
        return false;
    }
    data[noe++] = element;
    return true;
}

bool Set::removeElement(int element)
{
    int pos = searchElementPosition(element);
    if (pos == -1)
    {
        return false;
    }
    for (int i = pos; i < noe - 1; i++)
    {
        data[i] = data[i + 1];
    }
    --noe;
    return true;
}

bool Set::searchElement(int element) const
{
    for (int i = 0; i < noe; i++)
    {
        if (data[i] == element)
        {
            return true;
        }
    }
    return false;
}

int Set::searchElementPosition(int element) const
{
    for (int i = 0; i < noe; i++)
    {
        if (data[i] == element)
        {
            return (i+1);
        }
    }
    return -1;
}

bool Set::isEmpty() const
{
    return noe == 0;
}

bool Set::isFull() const
{
    return noe == capacity;
}

void Set::displaySet()
{
    cout << *this;
}

Set Set::calcIntersection(const Set& B, int newSetCapacity) const
{
    Set result;
    result.capacity = newSetCapacity;
    result.createSet();
    for (int i = 0; i < noe; i++)
    {
        if (B.searchElement(data[i]))
        {
            result.addElement(data[i]);
        }
    }
    return result;
}

int Set::commonElements(const Set& B) const
{
    int count = 0;
    for (int i = 0; i < noe; i++)
    {
        if (B.searchElement(data[i]))
        {
            ++count;
        }
    }
    return count;
}

Set Set::calculateUnion(const Set& B, int newSetCapacity) const
{
    Set result;
    result.capacity = newSetCapacity;
    result.createSet();
    for (int i = 0; i < noe; i++)
    {
        result.addElement(data[i]);
    }
    for (int i = 0; i < B.noe; i++)
    {
        result.addElement(B.data[i]);
    }
    return result;
}

Set Set::calculateDifference(const Set& B, int newSetCapacity) const
{
    Set result;
    result.capacity = newSetCapacity;
    result.createSet();
    for (int i = 0; i < noe; i++)
    {
        if (!B.searchElement(data[i]))
        {
            result.addElement(data[i]);
        }
    }
    return result;
}

bool Set::isSubset(const Set& B) const
{
    for (int i = 0; i < noe; i++)
    {
        if (!B.searchElement(data[i]))
        {
            return false;
        }
    }
    return true;
}

void Set::reSize(int newSize)
{
    if (newSize <= 0)
    {
        return;
    }
    int* temp = new int[newSize];
    int copySize = noe < newSize ? noe : newSize;
    myMemCpy(temp, data, sizeof(int) * copySize);
    delete[] data;
    data = temp;
    capacity = newSize;
    noe = copySize;
}

void Set::displayPowerSet() const
{
    int powerSetSize = 1 << noe;
    cout << "{ ";
    for (int counter = 0; counter < powerSetSize; counter++)
    {
        cout << "{";
        bool first = true;
        for (int j = 0; j < noe; j++)
        {
            if (counter & (1 << j))
            {
                if (!first)
                {
                    cout << ", ";
                }
                cout << data[j];
                first = false;
            }
        }
        cout << "}";
        if (counter != powerSetSize - 1)
        {
            cout << ", ";
        }
    }
    cout << " }\n";
}

void Set::setCapacity(int n)
{
    if (n >= 0)
    {
        capacity = n;
    }
}

void Set::setNoe(int n)
{
    if (n >= 0 && n <= capacity)
    {
        noe = n;
    }
}

int Set::getCapacity() const
{
    return capacity;
}

int Set::getNoe() const
{
    return noe;
}

int Set::countNoe() const
{
    return noe;
}

void myMemCpy(void* des, const void* src, int byteCount)
{
    char* d = static_cast<char*>(des);
    const char* s = static_cast<const char*>(src);
    for (int i = 0; i < byteCount; ++i)
    {
        d[i] = s[i];
    }
}

istream& operator>>(istream& is, Set& set)
{
    set.inputSet(set.getCapacity());
    return is;
}

ostream& operator<<(ostream& os, Set& set)
{
    os << "{";
    for (int i = 0; i < set.getNoe(); i++)
    {
        os << set.data[i];
        if (i < set.getNoe() - 1)
        {
            os << ", ";
        }
    }
    os << "}";
    return os;
}
