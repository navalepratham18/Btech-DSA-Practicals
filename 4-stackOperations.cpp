#include <iostream>
using namespace std;

class Stack
{
    int top;
    int *arr;
    int maxSize;

public:
    Stack(int size)
    {
        maxSize = size;
        arr = new int[maxSize];
        top = -1;
    }

    void push(int data)
    {
        if (top >= maxSize - 1)
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            arr[++top] = data;
            cout << data << " pushed to stack\n";
        }
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow\n";
        }
        else
        {
            cout << arr[top--] << " popped from stack\n";
        }
    }

    void display()
    {
        if (top < 0)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size);
    int choice, value;

    cout << "\nChoose an operation:\n";
    cout << "1. Push\n2. Pop\n3. Display\n4. Exit\n";

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
