
#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int size;
    int front;
    int rear;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void enqueue(int data)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
        }
    }
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            front++;
        }
    }
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
    int getfront()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            return arr[front];
        }
    }
    int getrear()
    {
        if (rear == -1)
        {
            cout << "Queue is empty" << endl;
        }
        else
        {
            return arr[rear];
        }
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (rear == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.display();
    q.dequeue();
    q.display();
}
