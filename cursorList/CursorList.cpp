//
// Created by user on 11/27/25.
//
#include <iostream>
#include "CursorList.h"
#include "../utils/InputHelper.h"
using namespace std;

// ==============================
//      Construction & State
// ==============================
CursorList::CursorList() {
	head = cursor = prev = nullptr;
}

CursorList::~CursorList() {
	makeListEmpty();
}

bool CursorList::listIsEmpty() const {
	return head == nullptr;
}

bool CursorList::curIsEmpty() const {
	return cursor == nullptr;
}

// ==============================
//          Navigation
// ==============================
void CursorList::toFirst() {
	cursor = head;
	prev = nullptr;
}

bool CursorList::atFirst() const {
	return (cursor == head);
}

void CursorList::advance() {
	prev = cursor;
	cursor = cursor->next;
}

void CursorList::toEnd() {
	toFirst();
	while (!curIsEmpty() && cursor->next != nullptr)
		advance();
}

bool CursorList::atEnd() const {
	return listIsEmpty()
	|| !curIsEmpty()
	|| cursor->next == nullptr;
}

// ==============================
//       Metrics & Updates
// ==============================
int CursorList::listSize() const
{
	NodePointer current = head;
	int count = 0;

	while (current != nullptr){
		current = current->next;
		count++;
	}

	return count;
}

void CursorList::updateData(const int data) const {
	cursor->data = data;
}

// ==============================
//           Insertion
// ==============================
void CursorList::insertFirst(const int &data) {
	head = createNewNode(data);
	cursor = head;
	prev = nullptr;
}

void CursorList::insertAfter(const int &data)
{
	NodePointer newNode = createNewNode(data);
	newNode->next = cursor->next;
 	cursor->next = newNode;
 	prev = cursor;
 	cursor = newNode;
}

void CursorList::insertBefore(const int &data)
{
	NodePointer newNode = createNewNode(data);
	newNode->next = cursor;
    prev->next = newNode;
	cursor = newNode;
}

void CursorList::insertEnd(const int &data){
	return listIsEmpty() ? insertFirst(data) : insertAfter(data);
}

void CursorList::orderInsert(const int &data){
	toFirst();
	while ((cursor != nullptr)) advance();
	if (prev == nullptr) insertFirst(data); else insertBefore(data);
}

// ==============================
//            Deletion
// ==============================
void CursorList::deleteNode()
{
	if (curIsEmpty())
		return;

	// delete first node
	const Node *temp = cursor;
	if (atFirst()) {
		cursor = cursor->next;
		head = cursor;
		delete temp;
		return;
	}

	// delete end node
	cursor = cursor->next;
	prev->next = cursor;
	delete temp;
}

void CursorList::deleteFirst(){
	if(!listIsEmpty()) {
		toFirst();
		deleteNode();
	}
}

void CursorList::deleteEnd() {
	if(!listIsEmpty()) {
		toEnd();
		deleteNode();
	}
}

void CursorList::makeListEmpty()
{
     toFirst();
     while (!listIsEmpty())
        deleteNode();
}

// ==============================
//     Search & Displaying
// ==============================
bool CursorList::search(const int data)
{
  	toFirst();
	while (cursor != nullptr) {
		if (data == cursor->data) return true;
		advance();
	}

	return false;
}

void CursorList::traverse(){
	toFirst();
	while (!curIsEmpty()){
		cout << cursor->data << endl;
		advance();
	}
}

void CursorList::handleSelection(const int selection) {
	int data;

	switch (selection) {
		case 1:
			data = cinListElement(">> Insert first: ");
			insertFirst(data);
			break;
		case 2:
			data = cinListElement(">> Insert after cursor: ");
			insertAfter(data);
			break;
		case 3:
			data = cinListElement(">> Insert before cursor: ");
			insertBefore(data);
			break;
		case 4:
			data = cinListElement(">> Insert at end: ");
			insertEnd(data);
			break;
		case 5:
			data = cinListElement(">> Ordered insert: ");
			orderInsert(data);
			break;
		case 6:
			toFirst();
			cout << ">> Cursor moved to first." << endl;
			break;
		case 7:
			toEnd();
			cout << ">> Cursor moved to end." << endl;
			break;
		case 8:
			if (curIsEmpty()) {
				cout << ">> Cursor is empty; cannot advance." << endl;
			} else {
				advance();
				cout << ">> Cursor advanced." << endl;
			}
			break;
		case 9:
			if (curIsEmpty()) {
				cout << ">> Cursor is empty; cannot update." << endl;
			} else {
				data = cinListElement(">> New cursor value: ");
				updateData(data);
			}
			break;
		case 10:
			deleteNode();
			cout << ">> Cursor node deleted." << endl;
			break;
		case 11:
			deleteFirst();
			cout << ">> First node deleted." << endl;
			break;
		case 12:
			deleteEnd();
			cout << ">> Last node deleted." << endl;
			break;
		case 13:
			makeListEmpty();
			cout << ">> List cleared." << endl;
			break;
		case 14:
			cout << ">> List is: [";
			traverse();
			cout << "]" << endl;
			break;
		case 15:
			cout << ">> Display list size: " << listSize() << endl;
			break;
		case 16:
			data = cinListElement(">> Search value: ");
			cout << "Is Found: " << search(data) << endl;
			break;
		case 17:
			cout << "Is List Empty: " << listIsEmpty() << endl;
			break;
		case 18:
			cout << "Is Cursor Empty: " << curIsEmpty() << endl;
			break;
		default:
			cout << "Invalid selection. Try again." << endl;
	}
}

void CursorList::displayMenu() {
	using std::cout;
	using std::endl;

	cout << "=============================" << endl;
	cout << "       CursorList Program    " << endl;
	cout << "=============================" << endl;

	cout << "Choose an operation:" << endl;
	cout << "1. Insert first" << endl;
	cout << "2. Insert after cursor" << endl;
	cout << "3. Insert before cursor" << endl;
	cout << "4. Insert at end" << endl;
	cout << "5. Ordered insert" << endl;
	cout << "6. Move cursor to first" << endl;
	cout << "7. Move cursor to end" << endl;
	cout << "8. Advance cursor" << endl;
	cout << "9. Update cursor data" << endl;
	cout << "10. Delete cursor node" << endl;
	cout << "11. Delete first node" << endl;
	cout << "12. Delete last node" << endl;
	cout << "13. Make list empty" << endl;
	cout << "14. Display list" << endl;
	cout << "15. Display size" << endl;
	cout << "16. Search" << endl;
	cout << "17. Is list empty" << endl;
	cout << "18. Is cursor empty" << endl;
	cout << "0. Exit" << endl << endl;
}
