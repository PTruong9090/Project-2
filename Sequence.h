#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
#include <string>

using ItemType = std::string;

class Sequence
{
public:
    Sequence();
    bool empty() const;
    int size() const;
    int insert(int pos, const ItemType& value);
    int insert(const ItemType& value);
    bool erase(int pos);
    int remove(const ItemType& value);
    bool get(int pos, ItemType& value) const;
    bool set(int pos, const ItemType& value);
    int find(const ItemType& value) const;
    void swap(Sequence& other);
private:
	struct mNode
	{
		ItemType mValue;
		mNode* next;
		mNode* prev;
        mNode() : mValue(ItemType()), next(nullptr), prev(nullptr) {};
	};

    int mSize;
    mNode* mHead;
    mNode* mDummy;
};

#endif