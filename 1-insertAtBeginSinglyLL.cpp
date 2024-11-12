#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr; 

void insertAtBeginning(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int data, int position) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (position == 1) {
        insertAtBeginning(data);
        return;
    }

    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << "Position out of bounds\n";
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertAtBeginning(3);
    insertAtBeginning(2);
    insertAtBeginning(1);
    insertAtPosition(4, 2);
    insertAtPosition(5, 5);
    display();
    return 0;
}
