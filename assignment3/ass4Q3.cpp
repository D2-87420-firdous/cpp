#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;        
    int top;      
    int maxSize;     

public:
    
    Stack() : maxSize(5), top(-1) {
        arr = new int[maxSize];
    }

    
    Stack(int size) : maxSize(size), top(-1) {
        arr = new int[maxSize];
    }

    
    ~Stack() {
        delete[] arr;
    }

    
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop" << endl;
            return -1;
        }
        return arr[top--];
    }

    
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return -1; 
        }
        return arr[top];
    }

    
    bool isEmpty() const {
        return top == -1;
    }

   
    bool isFull() const {
        return top == maxSize - 1;
    }

    
    void print() const {
        if (isEmpty()) {
            cout << "Stack is empty! Nothing to print." << endl;
            return;
        }
        cout << "Stack contents: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    
    Stack stack1;
    
    
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.print();  
    stack1.push(6);

   
    cout << "Top element is: " << stack1.peek() << endl;

    
    cout << "Popped element is: " << stack1.pop() << endl;
    cout << "Popped element is: " << stack1.pop() << endl;
    stack1.print();  

    Stack stack2(3);
    stack2.push(5);
    stack2.push(15);
    stack2.push(25);
    stack2.print();  
    stack2.push(35);

    cout << "Popped element is: " << stack2.pop() << endl;
    stack2.print();  

    cout << "Top element is: " << stack2.peek() << endl;

    return 0;
}

