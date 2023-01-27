#include <iostream>
#include <string>

using namespace std;

// Node Creation
class Node {
public:
    string value;
    Node* next = NULL;
    
    Node();
    Node(string val);
      
};

Node::Node() {
    
}

Node::Node(string val) {
    value = val;
}

class Queue {
private:
    Node* first = NULL;
    Node* last = NULL;
    int length = 0;
public:
    Queue();
    Node* peak();
    Node* enqueue(string val);
    Node* dequeue();
    void display();
};

Queue::Queue() {
}

Node* Queue::peak() {
    if (length != 0)
        cout << first->value << endl;
    return first;
}

Node* Queue::enqueue(string val) {
    Node* newNode = NULL;
    newNode = new Node(val);
    if (length == 0) {
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        last = newNode;
    }
    length++;
    return newNode;
}

Node* Queue::dequeue() {
    if (length == 0)
        return first;
    
    if (first == last)
        last = NULL;
    Node* holdingPointer = first;
    first = first->next;
    length--;
    return holdingPointer;
}

void Queue::display() {
    Node* head = first;
    while (head != NULL) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << "length: " << length <<endl;
}


int main(){
    Queue* myQueue = NULL;
    myQueue = new Queue();
    myQueue->enqueue("Joy");
    myQueue->enqueue("Matt");
    myQueue->enqueue("Pavel");
    myQueue->enqueue("Samir");
    myQueue->display();
    myQueue->peak();
    Node* danglingPointer = myQueue->dequeue();
    delete danglingPointer;
    myQueue->display();
    
    cout << endl;
    return 0;
}