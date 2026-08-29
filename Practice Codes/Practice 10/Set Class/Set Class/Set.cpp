#include"Set.h"
bool Set::isFull() const
{
    return  (noOfElements == data.getCapacity());
}
bool Set::isEmpty() const 
{
    return (data.getCapacity() == 0);
}
const int Set::searchElementPosition(const int element) const
{
    if (isEmpty())
    {
        return -1;
    }
    int count = 0;
    while (count < noOfElements && data.getSet(count) != element)
    {
        count = count + 1;
    }
    return (count<noOfElements)? count:-1;
}
float Set::calculatePower(const int base, const int exponent) const
{
    float result = 1;
    if (exponent<0)
    {
        for (int i = -1; i >= exponent; i--)
        {
            result = result / base;
        }
    }
    else if (exponent > 0)
    {
        for (int i = 1; i <= exponent; i++)
        {
            result = result * base;
        }
    }
    return result;
}





Set::Set(int cap):data(cap)
{
    cout << "h";
	noOfElements = 0;
}
void Set::insert(int element)
{
    if (isEmpty()||isFull())
    {
        reSize(data.getCapacity()+1);
    }
    if (!isMember(element))
    {
        data.getSet(noOfElements) = element;
        noOfElements++;
    }
}
bool Set::isMember(int val) const
{
    if (isEmpty())
    {
        return false;
    }
    int count = 0;
    while (count < noOfElements && data.getSet(count) != val)
    {
        count++;
    }
    if (count == noOfElements)
    {
        return false;
    }
    else
    {
        return true;
    }
}
void Set::remove(int element)
{
    if (isEmpty())
    {
        return;
    }
    if (isMember(element))
    {
        for (int i = searchElementPosition(element); i < noOfElements - 1; i++)
        {
            data.getSet(i) = data.getSet(i + 1);
        }
        noOfElements = noOfElements - 1;
    }
}
void Set::print() const
{
    if (isEmpty())
    {
        return;
    }
    cout << "\n" << "{";
    for (int i = 0; i < noOfElements; i++)
    {
        if (i > 0)
        {
            cout << ",";
        }
        cout << data.getSet(i);
    }
    cout << "}" << "\n\n";
}
int Set::getCardinality() const
{
    return noOfElements;
}
int Set::isSubSet(Set s2) const
{
    if (isEmpty() || s2.isEmpty())
    {
        return 0;
    }
    if (noOfElements > 0 && s2.noOfElements == 0)
    {
        return -1;
    }
    if (noOfElements == 0 && s2.noOfElements > 0)
    {
        return 1;
    }
    if (noOfElements == 0 && s2.noOfElements == 0)
    {
        return 2;
    }
    int callingObjectLength = noOfElements, receivingObjectLength = s2.noOfElements;
    if (callingObjectLength > receivingObjectLength)
    {
        for (int i = 0; i <= (callingObjectLength - receivingObjectLength); i++)
        {
            int count = 0;
            for (int j = 0; j < receivingObjectLength; j++)
            {
                if (data.getSet(i + j) == s2.data.getSet(j))
                {
                    count++;
                }
            }
            if (count == receivingObjectLength)
            {
                return -1;
            }
        }
    }
    else if (callingObjectLength < receivingObjectLength)
    {
        for (int i = 0; i <= (receivingObjectLength - callingObjectLength); i++)
        {
            int count = 0;
            for (int j = 0; j < callingObjectLength; j++)
            {
                if (s2.data.getSet(i + j) == data.getSet(j))
                {
                    count++;
                }
            }
            if (count == callingObjectLength)
            {
                return 1;
            }
        }
    }
    else if (callingObjectLength == receivingObjectLength)
    {
        int count = 0;
        for (int i = 0; i < callingObjectLength; i++)
        {
            if (data.getSet(i) == s2.data.getSet(i))
            {
                count++;
            }
        }
        if (count == callingObjectLength)
        {
            return 2;
        }
        else
        {
            return 0;
        }
    }
}
void Set::reSize(int newCapacity)
{
    data.reSize(newCapacity);
}
Set Set::calcUnion(const Set& s2) const
{
    Set newSet;
    if (isEmpty()||s2.isEmpty())
    {
        return newSet;
    }
    for (int i = 0; i < noOfElements; i++)
    {
        newSet.insert(data.getSet(i));
    }
    for (int i = 0; i < s2.noOfElements; i++)
    {
        newSet.insert(s2.data.getSet(i));
    }
    return newSet;
}
Set Set::calcIntersection(const Set& s2) const
{
    Set newSet;
    if (isEmpty() || s2.isEmpty())
    {
        return newSet;
    }
    for (int i = 0; i < s2.noOfElements; i++)
    {
        if (isMember(s2.data.getSet(i)))
        {
            newSet.insert(s2.data.getSet(i));
        }
    }
    return newSet;
}
Set Set::calcDifference(const Set& s2) const
{
    Set newSet;
    if (isEmpty() && s2.isEmpty())
    {
        return newSet;
    }
    if (isEmpty())
    {
        return newSet;
    }
    for (int i = 0; i < noOfElements; i++)
    {
        if (!s2.isMember(data.getSet(i)))
        {
            newSet.insert(data.getSet(i));
        }
    }
    return newSet;
}
void Set::displayPowerSet() const 
{
    if (isEmpty()) 
    {
        return;
    }
    int size = calculatePower(2, noOfElements);
    std::cout << "{ ";
    for (int i = 0; i < size; ++i) 
    {
        if (i > 0) 
        {
            std::cout << ", ";
        }
        std::cout << "{";
        bool first = true;
        for (int j = 0; j < noOfElements; ++j)
        {
            if (i & (1 << j)) 
            {
                if (!first) 
                {
                    std::cout << ", ";
                }
                std::cout << data.getSet(j);
                first = false;
            }
        }
        std::cout << "}";
    }
    std::cout << " }\n";
}