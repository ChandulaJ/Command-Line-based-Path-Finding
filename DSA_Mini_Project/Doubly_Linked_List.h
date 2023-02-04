#pragma once

#include <iostream>

using namespace std;

class Node
{
public:
	int elem;
	Node* next;
	Node* prev;

	Node() {
		elem = -1;
		next = NULL;
		prev = NULL;
	}

	Node(int val) {
		elem = val;
		next = NULL;
		prev = NULL;
	}
};

class Doubly_Linked_List
{
private:
	Node* head;
	Node* tail;
	int size;

public:

	Doubly_Linked_List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void insertFirst(int val) {
		Node* temp = new Node(val);
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
		Node* temp = new Node(val);
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
			Node* temp = new Node(elem);
			Node* current = head;
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
			Node* temp = head;
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
			Node* temp = tail;
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
			Node* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			Node* temp = current;
			(current->prev)->next = temp->next;
			(current->next)->prev = temp->prev;
			delete temp;
			size--;
		}
	}

	/*
	void search(int elem) {
		Node* temp = head;
		while (temp != NULL) {
			if (temp->elem == elem) {
				cout << "Key found" << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "Key not found" << endl;
	}
	*/

	void print() {
		Node* current = head;

		while (current->next != NULL) {
			cout << current->elem << " ";
			current = current->next;
		}
		cout << current->elem << endl;
	}
};