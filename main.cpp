#include <iostream>

using namespace std;

struct Node {

    int data;
    Node *next;

    Node(int x) {

        data = x;
        next = NULL;
    }
};

class Queue {

private:
    Node *front;
    Node *rear;
    int count;

public:
    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
    }

    void enqueue(int x) {

        Node *temp = new Node(x);

        if (rear == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        count++;
    }

    void dequeue() {

        if (front == NULL) {
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
        count--;
    }

    int top() {

        if (front == NULL) {
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {

        return (front == NULL);
    }

    int size() {
        return count;
    }
};

int main() {

    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Front element: " << q.top() << endl;
    q.dequeue();

    if (q.isEmpty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "Queue is not empty\n";
    }

    cout << "Size of queue: " << q.size() << endl;

    return 0;
}
