#include "Sequence.h"

Sequence::Sequence()
	:mSize(0)
{
	mDummy->next = nullptr;
	mDummy->prev = nullptr;
	mDummy->mValue = ItemType();
	mHead = mDummy->next;
}

bool Sequence::empty() const
{
	return mSize == 0;
}

int Sequence::size() const
{
	return mSize;
}

int Sequence::insert(int pos, const ItemType& value)
{
	// Check for errors
	if (pos < 0 || pos > mSize)
	{
		return -1;
	}
	// Insert at the end
	if (mSize == pos)
	{
		// Create new node
		mNode* newNode = new mNode;
		// Set newNode
		newNode->mValue = value;
		newNode->prev = mDummy->prev;
		newNode->next = mDummy;
		// Set Dummy node
		mDummy->prev->next = newNode;	// Set next pointer of last node to new node
		mDummy->prev = newNode;			// Set prev of dummy node to the last node
		// Set tail and head if needed
		mHead = mDummy->next;
		mSize++;
		return pos;
	}

	// TO DO: INSERT AT POS
	// Temp node for current value
	mNode* currentNode = mHead->next;

	// Loop through list until the node before posiiton
	for (int i = 0; i < pos; i++)
	{
		currentNode = currentNode->next;
	}
	// Create new node to insert into list
	mNode* newNode = new mNode;
	newNode->mValue = value;
	newNode->next = currentNode->next;	// Set new node next to node at pos
	newNode->prev = currentNode;		// Set new node previous to node at pos
	// Set next of node at pos to new node
	currentNode->next->prev = newNode;
	// Set prev of node after pos to new node
	currentNode->next = newNode;
	mSize++;
	return pos;
}

int Sequence::insert(const ItemType& value)
{
	// Check for errors
	if (mSize > 0)
	{
		int counter = 0;
		// Compare value to elements
		mNode* currentNode = mHead->next;
		while (currentNode != mDummy && currentNode->mValue <= value)
		{
			counter++;
			currentNode = currentNode->next;
		}

		// Change current node to the node before that
		currentNode = currentNode->prev;

		// Add value in front of currentNode
		mNode* newNode = new mNode;
		newNode->mValue = value;
		newNode->next = currentNode->next;
		newNode->prev = currentNode;

		// Adjust pointers for currentNode
		currentNode->next->prev = newNode;
		currentNode->next = newNode;

		mSize++;
		return counter;
	}

	// If list is empty create new node
	mNode* newNode = new mNode;
	// Set newNode
	newNode->mValue = value;
	newNode->prev = mDummy->prev;
	newNode->next = mDummy;
	// Set Dummy node
	mDummy->prev->next = newNode;	// Set next pointer of last node to new node
	mDummy->prev = newNode;			// Set prev of dummy node to the last node
	// Set tail and head if needed
	mHead = mDummy->next;
	mSize++;
	return 0;
}

bool Sequence::erase(int pos)
{
	// Check for errors
	if (pos >= mSize || pos < 0 || mSize == 0)
		return false;

	// Create node to traverse list
	mNode* currentNode = mHead->next;

	// POS IN THE MIDDLE
	if (pos > 1 && pos < mSize - 1 && mSize > 2)
	{
		// Get to pos
		for (int i = 0; i < pos; i++)
		{
			currentNode = currentNode->next;
		}

		// Properly set pointers for nodes before and after currentNode
		currentNode->prev->next = currentNode->next;
		currentNode->next->prev = currentNode->prev;

		// Delete currentNode
		delete currentNode;
		mSize--;
		return true;
	}

	// POS IN THE FRONT
	if (pos == 0)
	{
		mNode* deleteNode = mHead->next;
		
		// Change before and after deleteNode
		mDummy->next = mHead->next->next;
		mDummy->next->next->prev = mDummy;

		// Delete node
		delete deleteNode;
		mSize--;
		return true;
	}

	// POS AT THE END
	if (pos == mSize - 1)
	{
		mNode* deleteNode = mHead->prev;

		// Change before the last node
		mHead->prev->prev->next = mDummy;
		mDummy->prev = mHead->prev->prev;

		// Delete node
		delete deleteNode;
		mSize--;
		return true;
	}

	// REMOVING ONE ELEMENT LIST
	if (mSize == 1)
	{
		mNode* deleteNode = mHead->next;

		// Set dummy node pointers
		mDummy->next = mDummy;
		mDummy->prev = mDummy;

		// Delete node
		delete deleteNode;
		mSize--;
		return true;
	}
	return false;
}

int Sequence::remove(const ItemType& value)
{
	mNode* deleteNode = mHead->next;
	int pCounter = 0;
	int deleteCounter = 0;
	// Loop through linked list
	for (mNode* i = mHead->next; i != mDummy; i = i->next)
	{
		pCounter++;
		// Compare values to elements
		if (i->mValue == value)
		{
			erase(pCounter);
			deleteCounter++;
		}
	}
	return deleteCounter;
}

bool Sequence::get(int pos, ItemType& value) const
{
	if (pos > 0 || pos >= mSize)
	{
		return false;
	}

	// Set value to value at pos
	mNode* temp = mHead->next;
	for (int i = 0; i <= pos; i++)
	{
		temp = temp->next;
	}
}

bool Sequence::set(int pos, const ItemType& value)
{
	return false;
}

int Sequence::find(const ItemType& value) const
{
	return 0;
}

void Sequence::swap(Sequence& other)
{
}
