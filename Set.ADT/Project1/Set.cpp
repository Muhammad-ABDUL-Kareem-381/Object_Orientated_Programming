#include"Set.h"
Set::Set()
{
    data = nullptr;
    capacity = 0;
    noe = 0;
}

Set::~Set()
{
    delete[] data;
    data = nullptr;
    noe = 0;
    capacity = 0;
}
void Set::inputSet(int noe)
{
    int i = 0;
    while (i < noe && i < capacity)
    {
        cin >> data[i];
    }
    data[i] = '\0';
    setNoe(noe);
}
void Set::reSize(int newSize)
{
    int counter = 0;
    int* p = new int[newSize];
    myMemCpy(p, data, newSize);
    setCapacity(newSize);
    setNoe(countNoe());
    /*for (int i = 0; i < noe; i++)
    {
        p[i] = *data[0] + counter;
        counter = counter + 1;
    }*/
}
bool Set::isSubset(Set B)
{
    int i = 0;
    bool subSetStatus = true;
    while (i < noe)
    {
        if (! B.searchElement(data[i]))
        {
            return false;
        }
        i++;
    }
    return true;
    /*int counter = 0;
    while ((counter < noe) && (searchElement(setB, setBNoe, *data[counter]) == 1))
    {
        counter = counter + 1;
    }
    if (counter != noe)
    {
        return false;
    }
    int counting = 0;
    for (int i = 0; i < setBNoe; i++)
    {
        if ((searchElement(*data,noe, setB[i]) == 1))
        {
            counting = counting + 1;
        }
    }
    if (counting == setBNoe)
    {
        return (true + true);
    }
    else
    {
        return true;
    }*/
}
Set Set::calculateDifference(Set B, int newSetCapacity)
{
    Set resultSet;
    resultSet.setCapacity(newSetCapacity);
    resultSet.createSet();
    //int* p = new int[*newSetCapacity];
    int k = 0;
    for (int i = 0; i < noe; i++)
    {
        if (B.searchElement(data[i]))
        {
            resultSet.data[k] = data[i];
           // p[k] = *data[i];
            k = k + 1;
            resultSet.noe++;
           // *newSetNoe = *newSetNoe + 1;
        }
    }
    return resultSet;
}
Set Set::calculateUnion(Set B, int newSetCapacity)
{
    Set resultSet;
    resultSet.setCapacity(newSetCapacity);
    //int* p = new int[*newSetCapacity];
    int k;
    /*for (int i = 0; i < noe; i++)
    {
        p[i] = a[i];
        *newSetNoe = *newSetNoe + 1;
    }*/
    myMemCpy(resultSet.data, data, noe);
    resultSet.noe = resultSet.noe + noe;
    k = noe;
    for (int i = 0; i < B.noe; i++)
    {
        if (! resultSet.searchElement(B.data[i]))
        {
            resultSet.data[k] = B.data[i];
           // p[k] = b[i];
            //k = k + 1;
            //*newSetNoe = *newSetNoe + 1;
            resultSet.noe++;
        }
    }
    return resultSet;

}
Set Set::calcIntersection(Set B, const int newSetCapacity)
{
    Set resultSet;
    resultSet.capacity = newSetCapacity;
    resultSet.data = new int[resultSet.capacity];
    int k = 0;
    for (int i = 0; i < B.noe; i++)
    {
        if (searchElement(B.data[i]))
        {
            resultSet.data[k] = B.data[i];
            k++;
            resultSet.noe++;
        }

        /*int counter = 0;
        while ((a[i] != b[counter]) && (counter < setBNoe))
        {
            counter = counter + 1;
        }
        if (a[i] == b[counter])
        {
            p[k] = b[counter];
            k = k + 1;
            *newSetNoe = *newSetNoe + 1;
        }*/
    }
    return resultSet;
}
void Set::createSet()
{
    data = new int[capacity];
    /*for (int i = 0; i < capacity; i++)
    {
        data[i] = new int[i];
    }*/
}
int Set::commonElements(Set B)
{
    int count = 0;
    for (int i = 0; i < B.noe; i++)
    {
        if (searchElement(B.data[i]))
        {
            count++;
        }
        i++;
        /*while ((a[counter] != b[i]) && (i < setBNoe))
        {
            i = i + 1;;
        }
        if (a[counter] == b[i])
        {
            count = count + 1;
        }
        i = 0;*/
    }
    return count;
}
void Set::displaySet()
{
    cout << '{';
    for (int i = 0; i < noe; i++)
    {
        cout << data[i] << ',';
    }
    cout << '}';
}
bool Set::isFull()
{
    return (noe == capacity) ? true : false;
}
bool Set::isEmpty()
{
    return (noe > 0) ? false : true;
}
bool Set::searchElement(int element)
{
    int i = 0;
    while ((i < noe) && (element != data[i]))
    {
        i = i + 1;
    }
    return (element == data[i]) ? true : false;
}
int Set::searchElementPosition(int element)
{
    int i = 0;
    while ((i < noe) && (data[i] != element))
    {
        i = i + 1;
    }
    return (data[i] == element) ? i : -1;
}
bool Set::removeElement(int element)
{
    int k = searchElementPosition(element);
    int j = k;
    if (k != -1)
    {
        myMemCpy(&(data[k]),&(data[k+1]), noe-k);
        /*for (int i = k + 1; i < capacity; i++)
        {
            set[k] = set[i];
            k = k + 1;
            j = i + 1;
        }
        *noe = *noe - 1;*/
        noe--;
        return true;
    }
    return false;
}
bool Set::addElement(int element)
{
    cout << "Entry in addElement ()\t";
    if (searchElement(element))
    {
        cout << "Exit\t";
        return false;
    }
    if (noe < capacity)
    {
        cout << 'a' << '\t';
        cout << "noe:" << noe;
        cout << 'b' << '\t';
        cout << "capacity:" << capacity;
        cout << 'c' << '\t';
        data[noe] = element;
        cout << 'd' << '\t';
        noe = noe + 1;
        cout << "Exit\t";
        return true;
    }
    return false;
}
//void Set::displayPowerSet()
//{
//    int counting = 1;
//    cout << "{ {} ";
//    for (int i = 0; i < noe; i++)
//    {
//        counting = counting + 1;
//        cout << ",{" << set[i] << "}";
//    }cout << "\n";
//    for (int starting = 1; starting < noe; starting++)
//    {
//        for (int counter = starting; counter < noe; counter++)
//        {
//            cout << "{" << set[starting - 1] << ",";
//            for (int i = starting; i <= counter; i++)
//            {
//
//                cout << set[i];
//                if (i + 1 <= counter)
//                {
//                    cout << ",";
//                }
//            }
//            counting = counting + 1;
//            cout << "}";
//        }
//    }
//    cout << "\n";
//    int starting = 0;
//    for (int m = 1; m < noe - 1; m++)
//    {
//        for (int j = m; j < noe - 1; j++)
//        {
//            for (int i = j + 1; i < noe; i++)
//            {
//                for (int ending = i; ending < noe; ending++)
//                {
//                    cout << "{";
//                    for (int k = starting; k < j; k++)
//                    {
//                        cout << set[k] << ",";
//                    }
//                    for (int l = i; l <= ending; l++)
//                    {
//                        cout << set[l] << ",";
//                    }
//                    counting = counting + 1;
//                    cout << "}";
//                }
//            }
//
//        }
//        starting = starting + 1;
//    }
//    cout << "\n" << "counting is " << counting;
//}
void Set::setCapacity(int n)
{
    if (n >= 0)
    {
        capacity = n;
    }
    else 
    {
        return;
    }
}
void Set::setNoe(int n)
{
    if (n >= 0)
    {
    noe = n;
    }
    else
    {
        return;
    }
}
int Set::getNoe() const
{
    return noe;
}
int Set::getCapacity() const
{
    return capacity;
}
int Set::countNoe()
{
    int i = 0;
    while (i < noe && data[i] != '\0')
    {
        i++;
    }
    return i;
}
void myMemCpy(void* des, const void* src, int byteCount)
{
    char* d = (char*)des;
    char* s = (char*)src;
    for (int i = 0; i < byteCount; i++)
    {
        d[i] = s[i];
    }
}
istream& operator >> (istream& is, Set& set)
{
    set.inputSet(set.capacity);
   // cin >> set.data[0];
    return is;
}
ostream& operator << (ostream& os, Set& set)
{
    cout << set.data;
    return os;
}