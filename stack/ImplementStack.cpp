// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <bits/stdc++.h>

class Stack{
public :
int * arr;
int size;
int top;

Stack(int size) {
   arr  = new int[size];
    this -> size = size;
    this -> top = -1;
}

void push(int data) {
    if(size == top-1) {
        cout<<"Stack Overflow"<<endl;
    }
      top++;
    arr[top] = data;
}

void pop() {
    if(size == -1) {
        cout<<"Stack Underflow"<<endl;
    }
    top--;
}
bool isEmpty() {
    if (size == -1) return true;
   return false;
}

int getSize() {
    return top+1;
}
int getTop() {
    if(top== -1) {
        cout<<" Stack is empty" <<endl;
    }
    return arr[top];
}

void Print() {
for(int i=0; i<getSize();i++) {
   cout<<arr[i]<< " ";
}
    cout<<endl;
}
};
int main() {
   Stack s(5);
    s.push(5);
        s.push(4);
        s.push(3);
        s.push(2);
        s.push(1);

    s.Print();
    s.pop();
    s.Print();
   cout<< s.getTop();
    return 0;
}