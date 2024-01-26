//
//  main.cpp
//  InClass09_LinkedList
//
//  Created by Patricia Antlitz on 2/6/23.
//
/***********************************************
Author: <Patricia Antlitz>
Date: <02/07/2023-02/08/2023>
Time Spent: <5-7 hours?> -> this was really hard in my opinion. I studied data structures on my previous class in Java, but even though the concept is very similar, the implementation is completely different. I fell like the lecture on this topic did not go deep enough to cover the extent of this assignment. I tried to find good examples on the book, and I was taken all the way to chapter 17. Thats not a chapter I have read. My main source was a book I have called "Objective Oriented Data Structures Using Java". This book has better, more detailed examples.

What learned: <Everything was a learning curve on this assignment. I learned that I shouldn't leave this type of assignments to last minute (its 5 am. I worked on this all night. God help me on the quiz because I am not sleeping today). I learned how the linked list works, kind of...but I don't fully understand, I do, but I don't. I have been confused about it since I was first exposed to it on my previous class. I will research and read more about it.>
 I apologize not adding a README file this time.
 sources:
 "Objective Oriented Data Structures Using Java" - book
 https://www.delftstack.com/howto/cpp/print-linked-list-cpp/
 https://www.w3schools.blog/linked-list-with-classes-c
 https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/
 https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/null
 https://www.softwaretestinghelp.com/linked-list/
 https://gist.github.com/arunenigma/5183451
 https://www.bogotobogo.com/cplusplus/linkedlist.php
***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for
maintaining good order in the classroom, providing an enriching
learning experience for students, and as training as a practicing
computing professional upon graduation. This practice is
manifested in the University’s Academic Integrity policy.
Students are expected to strictly avoid academic dishonesty and
adhere to the Academic Integrity policy as outlined in the course
catalog. Violations will be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the
instructor and approved tutors.
I certify that the work submitted with this assignment is mine
and was generated in a manner consistent with this document, the
course academic policy on the course website on Blackboard, and
the UMass Lowell academic code.
Date: Patricia Antlitz
Name: 02/08/2023
*/

#include <iostream>
#include <cstdlib>          //  for the random number
#include <ctime>            //  random number seed
using namespace std;

class ListNode
{
public:
    //default constructor
    ListNode();
    //value constructors:
    //I didn't find a real use for this constructor, which was given to us in class. I created a constructor definition that is not being used
    ListNode(int node, ListNode *next);
    //So I created this one instead. I don't think there is a need to pass the next pointer in order to get the right outcome.
    ListNode(int data);
    
    //accessors
    int getData() const;
    ListNode *getNext() const;
    //mutators
    void setData(int newValue);
    void setNext(ListNode *newValue);
    
private:
    int data;
    ListNode *next;
};

class LinkedList
{
public:
    //default constructor
    LinkedList();
    LinkedList(ListNode *initHead);
    LinkedList(const int *arr, int arrSize);
    //Write the prototype and definition for the Copy Constructor.
    LinkedList(const LinkedList &srcList);
    
    void display(void);
    //will append numbers at the front of the list
    void preAppend(int node);
    //will append numbers at the end of the list
    void posAppend(int nodeNum);
    
    //why do we usually place the accessors before the mutators? Don't you need to set in order to get?
    ListNode getLinkedList(void) const;
    void setLinkedList(ListNode *initHead);
    
    ~LinkedList();
private:
    ListNode *head;
};

int main(int argc, const char * argv[])
{
    ListNode node;

    int randomNumber;
    int size = 10;
    int *arr;
    arr = new int[size];
    
    srand(static_cast<unsigned>(time(NULL)));
    
    for(int i = 0; i < size; i++)
    {
        //generate a random number from minimum to max range
        randomNumber = 5 + (rand() % 30);
        arr[i] = randomNumber;
    }
    //create nul
    LinkedList list;
    LinkedList newNode(arr, size);
    cout << "Array Linked List values: " << endl;
    newNode.display();
    
    newNode.preAppend(7);
    newNode.preAppend(24);
    cout << endl << "Appending at the head:" << endl;
    newNode.display();
    
    newNode.posAppend(44);
    newNode.posAppend(85);
    newNode.posAppend(1);
    cout << endl << "Appending at the tail:" << endl;
    newNode.display();
    
    delete []arr;

    return 0;
}

//ListNode - default constructor
ListNode::ListNode()
{
    //data currently has no value and doesn't point anywhere
    data = 0;
    next = nullptr;
}

//constructor 2, this is the one I am using to create the node instances throughout the code
ListNode::ListNode(int aData)
{
    data = aData;
    next = nullptr;
}

//not used
ListNode::ListNode(int node, ListNode *aNext)
{
    next = aNext;
    data = node;
}

//sets a value to be used as data
void ListNode::setData(int newData)
{
    data = newData;
}

//gets the value to "share it"
int ListNode::getData() const
{
    return data;
}

//next node
void ListNode::setNext(ListNode *newValue)
{
    next = newValue;
}

ListNode* ListNode::getNext() const
{
    return next;
}

//LINKEDLIST - default
LinkedList::LinkedList()
{
    head = nullptr;
}

//this constructor is also not being used
LinkedList::LinkedList(ListNode *initHead)
{
    *head = *initHead;
}

//mutator and accessor not in use
void LinkedList::setLinkedList(ListNode *headNum)
{
    head = headNum;
}

ListNode LinkedList::getLinkedList(void) const
{
    return *head;
}

//will append numbers to the front of the linked list
void LinkedList::preAppend(int nodeNum)
{
    //we initiate a new node
    ListNode* node = new ListNode(nodeNum);
    
    //assign it to the head
    if(head == nullptr)
    {
        head = node;
        return;
    }

    //then set the value of the next node to the value of head
    //this moves the head to the "second" position from left to right
    node->setNext(head);
    //now the value of node will become the head
    head = node;
}

//array constructor, will create a list of nodes using an array of elements
LinkedList::LinkedList(const int *arr, int size)
{
    //initialize pointer array
    const int *nodeArr = arr;
    nodeArr = new int[size];
    //initialize head. we wanna add from the from to the back, we should make sure the head is not pointing to a node
    head = nullptr;
    
    for(int i = 0; i < size; i++)
    {
        preAppend(arr[i]);
    }
}
//preAppend used to go here

//will append numbers to the end of the linked list
void LinkedList::posAppend(int nodeNum)
{
    ListNode* node = new ListNode(nodeNum);
    
    if(head == nullptr)
    {
        head = node;
        return;
    }
    
    //here the temporary node will have the value of the head
    ListNode* tempNode = head;
    
    //while we have a next node
    while(tempNode->getNext() != nullptr)
    {
        tempNode = tempNode->getNext();
    }
    
    tempNode->setNext(node);
}

//display function
void LinkedList::display(void)
{
    ListNode* tempNode = head;
    
    if(head == nullptr)
    {
        cout << "This linked list is empty" << endl;
        return;
    }
    
    while(tempNode != nullptr)
    {
        cout << tempNode->getData() << " ";
        
        tempNode = tempNode->getNext();
    }
    cout << endl;
}
