#include <iostream>
#include "list.h"

List::List() {
	List::first = nullptr;
}

List::~List() {
	while(!List::empty()){
		Node* curNode = List::first;
		List::first = List::first->next;
		delete curNode;
	}
	delete List::first;
}

bool List::exists(int d) const {
	Node* curNode = List::first;
	while (curNode != nullptr) {
		if (curNode->value == d) { //If correct value return true:
			return true;
		}
		curNode = curNode->next;
	}
	delete curNode;
	return false; //Not found in list.
}

int List::size() const {
	int count = 0;
	Node* curNode = List::first;
	while (curNode != nullptr) {
		++count;
		curNode = curNode->next;
	}
	return count;
}

bool List::empty() const {
	if (List::first != nullptr) {
		return false;
	}
	return true;
}

void List::insertFirst(int d) {
	List::first = new Node(d, List::first);
}

void List::remove(int d, DeleteFlag df) {
	//Node* curNode = List::first; //Init current Node
	//Node* preNode = nullptr; //Init previous Node
	bool found = false;

	/* First case to initate correct preNode */
	switch (df) {
		case List::DeleteFlag::LESS:
			if (List::first->value < d) {
				Node* delNode = List::first;
				List::first = List::first->next;
				delete delNode;
				found = true;
			}
			break;
		case List::DeleteFlag::EQUAL:
			if (List::first->value == d) {
				Node* delNode = List::first;
				List::first = List::first->next;
				delete delNode;
				found = true;
			}
			break;
		case List::DeleteFlag::GREATER:
			if (List::first->value > d) {
				Node* delNode = List::first;
				List::first = List::first->next;
				delete delNode;
				found = true;
			}
			break;
		default:
			break;
	}

	if (!found) {
		Node* preNode = List::first; //Init current Node
		Node* curNode = List::first->next; //Init previous Node
		while (curNode != nullptr && !found) {
			switch (df) {
				case List::DeleteFlag::LESS:
					if (curNode->value < d) {
						preNode->next = curNode->next;
						delete curNode;
						found = true;
					}
					break;
				case List::DeleteFlag::EQUAL:
					if (curNode->value == d) {
						preNode->next = curNode->next;
						delete curNode;
						found = true;
					}
					break;
				case List::DeleteFlag::GREATER:
					if (curNode->value > d) {
						preNode->next = curNode->next;
						delete curNode;
						found = true;
					}
				  break;
				default:
					break;
			}
			preNode = curNode;
			curNode = curNode->next;
		}
	}
}

void List::print() const {
	Node* curNode = List::first;
	std::cout << "[";
	while (curNode != nullptr) {
		std::cout << curNode->value << ", ";
		curNode = curNode->next;
	}
	std::cout << "]" << std::endl;
}
