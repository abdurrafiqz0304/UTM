#include <iostream>
using namespace std;
#define SIZE 50

class stackNode {
	char data;
	stackNode *next;
};

class stack {
	private:
		stackNode* top;
	public:
		void createstack() { top = NULL;}
		void push(int newItem) {
			stackNode* newNode = new stackNode;
			if (newNode == NULL)
			cout << "Cannot allocate memory..." << endl;
			else {
				newNode->data = newItem;
				newNode->net = top;
				top = newNode;
			}
		}
		
		bool isEmpty() {
			return top = NULL;
		}
		
		void pop() {
			stackNode* delnode = new stackNode;
			
			if (isEmpty()) {
				cout << "Cannot pop." << endl;
			}
			else
			{
				delnode = top;
				cout << "Item to be popped" << endl;
				top = delnode->next;
				delete(delnode);
			}
		}
		
		int stackTop() {
			return top->data;
		}
};

bool isOperator (char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
		
	}
}

int main() {
	stack myStack;
	char input[SIZE];
	cout << "Enter your infix expression: ";
	
	cin.getline(input, SIZE);
	int i = 0;
	char ch;
	myStack.push('#');
	while (input[i] != '\0') {
		ch = input[i];
		if (!isOperator(ch)) {
			myStack.push(ch);
		}
		else if (ch == '(') {
			myStack.push(ch);
		} 
		else if (ch == ')') {
			ch = myStack.stackTop();
			myStack.pop();
		}
		
		
		i++
	}
}