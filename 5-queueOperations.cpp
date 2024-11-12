#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear, size;
    int *queue;

public:
    Queue(int size)
    {
        this->size = size;
        queue = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int ele)
    {
        if (rear == size - 1)
        {
            cout << "Queue is Full\n";
        }
        else
        {
            if (front == -1)
                front = 0;
            rear++;
            queue[rear] = ele;
            cout << ele << " enqueued to queue\n";
        }
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            cout << "Dequeued Element: " << queue[front] << endl;
            front++;
        }
    }

    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size, ele, choice;

    cout << "Enter size of Queue: ";
    cin >> size;

    Queue q(size);

    cout << "\nQueue Operations:\n";
    cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";

    do
    {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element to insert: ";
            cin >> ele;
            q.enqueue(ele);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
