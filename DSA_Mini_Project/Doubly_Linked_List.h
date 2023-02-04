#pragma once

#include <iostream>

using namespace std;

class LNode
{
public:
	int elem;
	LNode* next;
	LNode* prev;

	LNode() {
		elem = -1;
		next = NULL;
		prev = NULL;
	}

	LNode(int val) {
		elem = val;
		next = NULL;
		prev = NULL;
	}
};

class Doubly_Linked_List
{
private:
	LNode* head;
	LNode* tail;
	int size;

public:

	Doubly_Linked_List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void insertFirst(int val) {
		LNode* temp = new LNode(val);
		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head->prev = temp;
			head = temp;
			size++;
		}
	}

	void insertLast(int val) {
		LNode* temp = new LNode(val);
		if (head == NULL) {
			head == temp;
			tail == temp;
			size++;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			size++;
		}
	}

	void insertAt(int pos, int elem) {
		if (pos<0 || pos>size) {
			cout << "Invalid position" << endl;
		}
		else if (pos == 0) {
			insertFirst(elem);
		}
		else if (pos == size) {
			insertLast(elem);
		}
		else {
			LNode* temp = new LNode(elem);
			LNode* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}

			temp->next = current->next;
			temp->prev = current;
			current->next = temp;
			(temp->next)->prev = temp;
			size++;
		}
	}

	void deleteFirst() {
		if (head == NULL) {
			cout << "The list is empty" << endl;
		}
		else {
			LNode* temp = head;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				head = head->next;
				head->prev = NULL;
				delete temp;
				size--;
			}
		}
	}

	void deleteLast() {
		if (head == NULL) {
			cout << "The list is empty" << endl;
		}
		else {
			LNode* temp = tail;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				tail = tail->prev;
				tail->next = NULL;
				delete temp;
				size--;
			}
		}
	}

	void deleteAt(int pos) {
		if (pos < 0 || pos >= size) {
			cout << "Invalid position" << endl;
		}
		else if (pos == 0) {
			deleteFirst();
		}
		else if (pos == size - 1) {
			deleteLast();
		}
		else {
			LNode* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			LNode* temp = current;
			(current->prev)->next = temp->next;
			(current->next)->prev = temp->prev;
			delete temp;
			size--;
		}
	}

	bool search(int elem) {
		LNode* temp = head;
		while (temp != NULL) {
			if (temp->elem == elem) {
				//cout << "Key found" << endl;
				return true;
			}
			temp = temp->next;
		}
	}

	void print() {
		LNode* current = head;

		while (current->next != NULL) {
			cout << current->elem << " ";
			current = current->next;
		}
		cout << current->elem << endl;
	}
};