#include "sequential-list.h"
#include <iostream>
using namespace std;

//Constructor
SequentialList::SequentialList(unsigned int cap)
{
    data_ = new DataType [cap];
    capacity_ = cap;
    size_ = 0;
}

//Copy Constructor
SequentialList::SequentialList(const SequentialList& rhs)
{
    data_ = new DataType [rhs.capacity()];
    capacity_ = rhs.capacity();
    size_ = rhs.size();
    for (int i=0; i<size(); i++)
        data_[i] = rhs.select(i);
}

//Destructor
SequentialList::~SequentialList()
{
    delete data_;
    data_ = nullptr;
    capacity_ = 0;
    size_ = 0;
}

unsigned int SequentialList::size() const
{
    return size_;
}

unsigned int SequentialList::capacity() const
{
    return capacity_;
}

bool SequentialList::empty() const
{
    if (size() == 0)
        return true;
    else
        return false;
}

bool SequentialList::full() const
{
    if (size() == capacity())
        return true;
    else
        return false;
}

SequentialList::DataType SequentialList::select(unsigned int index) const
{
    if (index >= size()) //if index is invalid, also since index is unsigned, it will never be < 0
        return data_[size()-1];
    else
        return data_[index];
}

unsigned int SequentialList::search(DataType val) const
{
    for (unsigned int i=0; i<size(); i++)
    {
        if (data_[i] == val)
            return i;
    }
    return size();
}

void SequentialList::print() const
{
    for (unsigned int i=0; i<size(); i++)
    {
        cout << data_[i] << " ";
    }
}

bool SequentialList::insert(DataType val, unsigned int index)
{
    if (index > size() || full()) //check validity of index
        return false;
    else
    {
        for (unsigned int i=size(); i+1>index; i--) //shift all elements after index value up 1 position
            data_[i + 1] = data_[i];
        data_[index] = val;
        size_++;
        return true;
    }
}

bool SequentialList::insert_front(DataType val)
{
    return insert(val, 0);
}

bool SequentialList::insert_back(DataType val)
{
    return insert(val, size());
}

bool SequentialList::remove(unsigned int index)
{
    if (empty() || index >= size())
        return false;
    else
    {
        for (unsigned int i=index; i+1<size(); i++) //shift position of elements after index value down by 1
            data_[i] = data_[i+1];
        size_--;
        return true;
    }
}

bool SequentialList::remove_front()
{
    return remove(0);
}

bool SequentialList::remove_back()
{
    return remove(size()-1);
}

bool SequentialList::replace(unsigned int index, DataType val)
{
    if (full() || index >= size())
        return false;
    else
        data_[index] = val;
    return true;
}

