#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct p {
	int key;
	p* next;
}*p_start=NULL;
struct q {
	int key;
	q* next;
}*q_start=NULL;
struct Node {
	int key;
	Node* next;
};
struct List {
	Node* head = nullptr;
	void insertSorted(int value) {
		Node* newNode = new Node;
		newNode->key = value;
		newNode->next = nullptr;
		if (!head || head->key > value) {
			newNode->next = head;
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next && current->next->key < value) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	void print() const {
		Node* current = head;
		while (current) {
			cout << current->key << " ";
			current = current->next;
		}
		cout << endl;
	}
};
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
void print_stack_p() {
	p* current = p_start;
	cout << "Stack p: ";
	while (current) {
		cout << current->key << " ";
		current = current->next;
	}
	cout << endl;
}
void print_stack_q() {
	q* current = q_start;
	cout << "Stack q: ";
	while (current) {
		cout << current->key << " ";
		current = current->next;
	}
	cout << endl;
}
List createList() {
	List result;
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
			result.insertSorted(current_p->key);
		}
		current_p = current_p->next;
	}
	return result;
}
int main() {
	srand(time(NULL));
	const int N = 10;
	int array_p[N];
	int array_q[N];

	for (int i = 0; i < N; i++) {
		array_p[i] = rand() % 100 + 1;
		push_p(array_p[i]);
	}
	for (int i = 0; i < N; i++) {
		array_q[i] = rand() % 100 + 1;
		push_q(array_q[i]);
	}
	print_stack_p();
	print_stack_q();
	List resultList = createList();
	cout << "Elementi na lista: ";
	resultList.print();
}