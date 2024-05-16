#include <iostream>
#include <list>
using namespace std;
struct p {
	int key;
	p* next;
}*p_start=NULL;
struct q {
	int key;
	q* next;
}*q_start=NULL;
void push_p(int val) {
	p* newNode = new p;
	newNode->key = val;
	newNode->next = p_start;
	p_start = newNode;
}
void push_q(int val) {
	q* newNode = new q;
	newNode->key = val;
	newNode->next = q_start;
	q_start = newNode;
}
void pop_p() {
	if (p_start) {
		p* temp = p_start;
		p_start = p_start->next;
		delete temp;
	}
}
void pop_q() {
	if (q_start) {
		q* temp = q_start;
		q_start = q_start->next;
		delete temp;
	}
}
list<int> createList() {
	list<int> result;
	p* current_p = p_start;
	q* current_q = q_start;
	while (current_p) {
		bool found_in_q = false;
		current_q = q_start;
		while (current_q) {
			if (current_p->key == current_q->key) {
				found_in_q = true;
				break;
			}
			current_q = current_q->next;
		}
		if (!found_in_q) {
			result.push_back(current_p->key);
		}
		current_p = current_p->next;
	}
	return result;
}
int main() {
	push_p(5);
	push_p(10);
	push_p(3);
	push_p(7);

	push_q(3);
	push_q(8);
	push_q(12);

	list<int> resultList = createList();

	cout << "Elementi na lista: ";
	for (int element : resultList) {
		cout << element << " ";
	}
	cout << endl;
}