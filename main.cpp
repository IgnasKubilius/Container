#include "Container.h"
#include <iostream>
#include <exception>
using namespace std;

int main()
{
    cout << "*********LINKEDLIST**********" << endl;
    LinkedList<int> intObject;
    cout << "--------------after createNode--------------"<<endl;
    intObject.createNode(5);
    intObject.print();
    cout << "--------------after addLast-----------------"<<endl;
    intObject.addLast(6);
    intObject.print();
    cout << "--------------after addFirst----------------"<<endl;
    intObject.addFirst(9);
    intObject.print();
    cout << "--------------after addData-----------------"<<endl;
    intObject.addData(3,55);
    intObject.addData(3,7);
    intObject.addData(4,92);
    intObject.print();
    cout << "--------------after removeFirst-------------"<<endl;
    intObject.removeFirst();
    intObject.print();
    cout << "--------------after removeLast--------------"<<endl;
    intObject.removeLast();
    intObject.print();
    cout << "--------------after removeData--------------"<<endl;
    intObject.removeData(2);
    intObject.print();
    cout << "--------------after getFirst----------------"<<endl;
    cout << intObject.getFirst() << endl;
    cout << "--------------after getLast-----------------"<<endl;
    cout << intObject.getLast() << endl;
    cout << "--------------after getData-----------------"<<endl;
    cout << intObject.getData(2) << endl;
    cout << "--------------after getSize-----------------"<<endl;
    cout << intObject.getSize() << endl;

    //*****************STACK*******************************

    cout << "*********STACK**********" << endl;
    Stack <string> stringStack;
    cout << "--------------after addLast-----------------"<<endl;
    stringStack.addLast("It");
    stringStack.print();
    cout << "--------------after addLast-----------------"<<endl;
    stringStack.addLast("works");
    stringStack.print();
    cout << "--------------after addLast-----------------"<<endl;
    stringStack.addLast("fine");
    stringStack.print();
    cout << "--------------after getFirst----------------"<<endl;
    cout << stringStack.getFirst() << endl;
    cout << "--------------after getLast-----------------"<<endl;
    cout << stringStack.getLast() << endl;
    cout << "--------------after removeLast--------------"<<endl;
    stringStack.removeLast();
    stringStack.print();
    cout << "--------------after getSize-----------------"<<endl;
    cout << stringStack.getSize() << endl;
    return 0;
}
