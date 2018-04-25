#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>
#define MAX 1000
//***********************LinkedList*************************
template <class anyType>
class LinkedList
{
public:
    LinkedList()
    {
        head=NULL;
        tail=NULL;
        //std::cerr << "LinkedList()" << std::endl;
    }
    ~LinkedList()
    {
        //std::cerr << "~Linkedlist()" << std::endl;
    }
//*************************************************
    void createNode(anyType value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    };
    //*************************************************
    void addFirst(anyType value)
    {
        {
            node *temp=new node;
            temp->data=value;
            temp->next=head;
            head=temp;
        }
    }
    //*************************************************
    void addLast(anyType value)
    {
        node *temp=new node;
        temp->data=value;
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
            temp=NULL;
        }
        else
        {
            tail->next=temp;
            tail=temp;
        }
    }
    //*************************************************
    void addData(int pos, anyType value)
    {
        if (pos == 1 || pos == 0)
            std::cout << "Invalid. Use addFirst()." << std::endl;
        else
        {
            node *pre=new node;
            node *cur=new node;
            node *temp=new node;
            cur=head;
            for(int i=1; i<pos; i++)
            {
                pre=cur;
                cur=cur->next;
            }
            temp->data=value;
            pre->next=temp;
            temp->next=cur;
        }
    }
    //*************************************************
    void removeFirst()
    {
        node *temp=new node;
        temp=head;
        head=head->next;
        delete temp;
    }
    //*************************************************
    void removeLast()
    {
        node *current=new node;
        node *previous=new node;
        current=head;
        while(current->next!=NULL)
        {
            previous=current;
            current=current->next;
        }
        tail=previous;
        previous->next=NULL;
        delete current;
    }
    //*************************************************
    void removeData(int pos)
    {
        node *current=new node;
        node *previous=new node;
        current=head;
        for(int i=1; i<pos; i++)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
    }
    //*************************************************
    anyType getFirst()
    {
        node *temp=new node;
        temp = head;
        try
        {
            if(temp!=NULL)
                return temp->data;
            else
            {
                throw std::underflow_error("LinkedList Underflow");
                return 0;
            }
        }
        catch(std::underflow_error &error)
        {
            std::cerr <<"Exception accured: " << error.what() << std::endl;
        }
    }
    //*************************************************
    anyType getLast()
    {
        node *temp=new node;
        temp=tail;
        try
        {
            if(temp!=NULL)
                return temp->data;
            else
            {
                throw std::underflow_error("LinkedList Underflow");
                return 0;
            }
        }
        catch(std::underflow_error &error){std::cerr <<"Exception accured: " << error.what() << std::endl;}
    }
    //*************************************************
    anyType getData(int pos)
    {
        node *current=new node;
        current=head;
        for(int i=1; i<pos; i++)
            current=current->next;
        return current->data;
    }
    //*************************************************
    anyType getSize()
    {
        node *temp=new node;
        int size = 0;
        temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            size++;
        }
        return size;
    }
    //*************************************************
    void print()
    {
        node *temp=new node;
        temp=head;
        while(temp!=NULL)
        {
            std::cout<<temp->data<<"\t";
            temp=temp->next;
        }
        std::cout << std::endl;
    }
    //*************************************************
private:
    struct node
    {
        anyType data;
        node *next;
    };
    node *head, *tail;
};
//**********************************************************
//***************************Stack**************************
template <class anyType>
class Stack
{
public:
    //*************************************************
    anyType a[MAX];    //Maximum size of Stack
    //*************************************************
    Stack()
    {
        top = -1;
        //std::cout << "Stack()" << std::endl;
    }
    //*************************************************
    ~Stack()
    {
        //std::cout << "~Stack()" << std::endl;
    }
    //*************************************************
    bool addLast(anyType x)
    {
        try
        {
            if (top+1 >= MAX)
            {
                throw std::overflow_error("Stack Overflow");
                return false;
            }
            else
            {
                a[++top] = x;
                return true;
            }
        }
        catch(std::overflow_error &error)
        {
            std::cerr <<"Exception accured: " << error.what() << std::endl;
        }
    }
    //*************************************************
    anyType removeLast()
    {
        try
        {
            if (top < 0)
            {
                throw std::underflow_error("Stack Underflow");
                return 0;
            }
            else
            {
                anyType x = a[top--];
                return x;
            }
        }
        catch(std::underflow_error &error)
        {
            std::cerr <<"Exception accured: " << error.what() << std::endl;
        }
    }
    //*************************************************
    anyType getFirst()
    {
        Stack tempStack;
        anyType firstElement;
        while(!isEmpty())
            tempStack.addLast(removeLast());
        firstElement = tempStack.removeLast();
        addLast(firstElement);
        while(!tempStack.isEmpty())
            addLast(tempStack.removeLast());
        return firstElement;
    }
    //*************************************************
    anyType getLast()
    {
        anyType lastElement;
        lastElement = removeLast();
        addLast(lastElement);
        return lastElement;
    }
    //*************************************************
    int getSize()
    {
        Stack tempStack;
        int stackSize = 0;
        while(!isEmpty())
            tempStack.addLast(removeLast());
        while(!tempStack.isEmpty())
        {
            addLast(tempStack.removeLast());
            stackSize++;
        }
        return stackSize;
    }
    //*************************************************
    bool isEmpty()
    {
        return (top < 0);
    }
    //*************************************************
    void print()
    {
        Stack tempStack;
        while(!isEmpty())
            tempStack.addLast(removeLast());
        while(!tempStack.isEmpty())
        {
            addLast(tempStack.removeLast());
            std::cout << getLast() << " ";
        }
        std::cout << std::endl;
    }
    //*************************************************
private:
    int top;
};
#endif // Container_H
