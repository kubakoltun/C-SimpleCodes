#include <iostream>
#include <string>

template<typename E>
class MyStack {
class Node
	struct Node {
		E data;
		Node* next;
		Node(E data, Node* next)
			: data(data), next(next)
		{ }
	};
	Node* head;

public:
	E pop() {
		E data = head->data;
		Node* temp = head->next;
		delete head;
		head = temp;
		return data;
	}

	void push(const E& d) {
		head = new Node(d, head);
	}

	bool empty() const {
		return head == nullptr;
	}

	MyStack() {
		head = nullptr;
	}
	
	MyStack(const MyStack&) = delete;
	MyStack* operator=(const MyStack&) = delete;

	~MyStack() {
		while (head) {
			Node* node = head;
			head = head->next;
			delete node;
		}
	}
};

int main() {
	using std::cout; using std::endl; using std::string;

	MyStack<string> stS;
	MyStack<double> stD;
	for (int i = 5; i > 0; --i) {
		stS.push(std::to_string(double(i)));
		stD.push(double(i));
	}
	while (!stS.empty())
		cout << "string: " << stS.pop() << "  "
		<< "double: " << stD.pop() << endl;
}
