//    Roster Number : 15
//    Author: Trenton Hohle
//    Programming Assignment # 3
//    Spring 2018 - CS 3358 - 260
//    Due Date: March 5, 2018
//    Instructor : Husain  Gholoom
//
//    This program is designed to generate two lists 15 ints long, then
//    combine them into a third list, output the number of occurances of the
//    first int in the third list, then remove all duplicates, while becoming
//    list four. It will then move the last element to the 4th slot on list 4,
//    output the list, then sort the list and re-output it. All of this in a
//    loop that only breaks if the user selections option 2.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class LinkedList
{
    private: //struct to make all nodes
        struct Node
        {
            int data;
            Node *next;
        };
        Node *head;
    public: //function prototypes
        LinkedList();
        LinkedList(LinkedList, LinkedList);
        ~LinkedList();
        void appendNode(int);
        void displayLinkedList();
        void populateLinkedList();
        int numberOfOccurances();
        void removeDups();
        int listSize();
        void backwardDisplay(int);
        void moveLastElement(int);
        void sortedList(int);
};

int main()
{
    srand(time(NULL));
    int answer = -1; //sentinel variable to check user input for a loop
    do
    {
        cout << "Would you like to: " << endl;
        cout << "1. Run the Program" << endl;
        cout << "2. Terminate Program" << endl;
        cout << "Answer: "; //menu options for user
        cin >> answer;
        cout << endl << endl;

        if(answer == 1) //if users chooses 1 do the program
        {
            LinkedList list_1, list_2;
            list_1.populateLinkedList();
            cout << "list 1 -> ";
            list_1.displayLinkedList();
            list_2.populateLinkedList();
            cout << "list 2 -> ";
            list_2.displayLinkedList();
            LinkedList list_3(list_1, list_2);
            cout << "list 3 -> ";
            list_3.displayLinkedList();
            cout << endl;
            list_3.numberOfOccurances();
            LinkedList list_4 = list_3;
            list_4.removeDups();
            cout << "\nlist 4 -> ";
            list_4.displayLinkedList();
            cout << endl;
            int listSize = list_4.listSize();
            cout << endl;
            list_4.backwardDisplay(listSize);
            list_4.moveLastElement(listSize);
            list_4.sortedList(listSize);
            cout << endl << endl;
        }
        else if(answer == 2) //if user choose 2 leave the program
            cout << "This LL Program is implemented by : "
                 << "\nTrenton Hohle - March 5th, 2018" << endl;
        else //all other input is an error
            cout << "\nError *** invalid input!\n\n" << endl;
        if(!cin)
        {
            answer = -1;
            cin.clear();
            cin.ignore(100, '\n');
        }
    }while(answer!=2);
}

LinkedList :: LinkedList()
{ //constructor
    head = NULL;
}
LinkedList :: LinkedList(LinkedList first, LinkedList second)
{ //constructor to make the list 3, combining lists 1 and 2
    head = NULL;
    Node *firstHead = new Node;
    Node *secondHead = new Node;
    firstHead = first.head;
    secondHead = second.head;

    while(firstHead != NULL)
    { //adds all of the first list in
        appendNode(firstHead->data);
        firstHead = firstHead->next;
    }
    while(secondHead != NULL)
    { //adds the second list behind the first
        appendNode(secondHead->data);
        secondHead = secondHead->next;
    }
}
LinkedList :: ~LinkedList()
{ //destructor
    Node *deleteNode = new Node;
    while(deleteNode->next)
    {
        deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
}
void LinkedList :: displayLinkedList()
{ //displays any list that calls it
    Node *temp = new Node;
    temp = head;
    cout << "[ ";
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "]" << endl;
}
void LinkedList :: appendNode(int num)
{ //adds any integer to the list that calls it, at the end of the list
    Node *newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;

    if(!head)
    { //if their is no head, it makes a head
        head = newNode;
    }
    else
    {
        Node *p = head;

        while(p->next) //finds the end of the list
            p = p->next;
        p->next = newNode; //adds node to the end of the list
    }
}
void LinkedList :: populateLinkedList()
{
    for(int i = 0; i < 15; i++)
    { //generates a random number and adds it to the list that called this
        int randNum = ((rand()%19)+1);
        appendNode(randNum);
    }
}
int LinkedList :: numberOfOccurances()
{
    Node *check = new Node;
    check = head; //check variable to test all other values against
    Node *p = new Node;
    p = head; //variable to traverse the list to check everything
    int checkNum = check->data, counter = 0;
    while(p->next)
    {
        if(checkNum == p->data)
            counter++;
        p = p->next;
    }
    cout << "list 3 has the number " << checkNum << " in it " << counter
         << " times." << endl; //output for number of times found
}
void LinkedList :: removeDups()
{ //removes duplicates from the list that calls it
    Node *temp = new Node;
    Node *p = new Node;
    Node *q = new Node;
    temp = head;
    while(temp != NULL && temp->next != NULL)
    { //outer loop to handle the starting value of each time through the list
        p = temp;
        while(p->next != NULL)
        { //inner loop to go from the start to the end of the list each time
            if(temp->data == p->next->data)
            { //checks if the check variable equals the current node, if so
                q = p->next; //it deletes the duplicate
                p->next = p->next->next;
                delete(q);
            }
            else
                p = p->next;
        }
        temp = temp->next;
    }
}
int LinkedList :: listSize()
{ //traverses the array with a counter, returns the number of nodes
    Node *tempNode = new Node;
    tempNode = head;
    int counter = 0;
    while(tempNode->next != NULL)
    {
        counter++; //counter to track nodes
        tempNode = tempNode->next;
    }

    cout << "The size of the list is: " << counter << endl;
    return counter;
}
void LinkedList :: backwardDisplay(int size)
{ //outputs the list backwards
    Node *endList = new Node; //tracks the end of the list, "as defined"
    Node * p = new Node;
    Node *q = new Node;
    endList = head; // holds "defined" end of the list
    p = head;
    q = p->next;
    cout << "Backward List -> [ ";
    for(int i = 0; i < size+1; i++)
    {
        while(p->next != NULL && p->next != endList)
        {
            q = q->next; //moving down the list
            p = p->next;
        }
        endList = p; //redefine end of list to only iterate to this point
        cout << endList->data << " ";
        p = head;
        q = p->next;
    }
    cout << "] " << endl;
}
void LinkedList :: moveLastElement(int size)
{ //moves the last element of the list to the 4th slot
    Node *last = new Node; //temp to hold last node
    Node *secondToLast = new Node; //temp to hold second to last node
    Node *third = new Node; //temp to hold the third node
    last = head->next; //setting it up to get to the last node
    secondToLast = head; //setting it up to get to the second to last node
    for(int i = 0; i < size-1; i++)
    {
        if(i == 2)
            third = secondToLast; //to set it as the third node
        last = last->next; //traversing the list
        secondToLast = secondToLast->next;
    }
    secondToLast->next = NULL; //setting the second to last to be last
    last->next = third->next; //inserting the node in its new home
    third->next = last;

    cout << "Moved List -> ";
    displayLinkedList(); //output list
}
void LinkedList :: sortedList(int size)
{
    Node *tempHead = new Node;
    Node *tempNode = new Node;
    tempHead = head;
    int temp = 0;
    for(int i = 0; i < size; i++)
    {//bubble sorting it, plenty of comparisons to shift the biggest
        while(tempHead->next) //integer to the end
        {
            if((tempHead->data) > (tempHead->next->data))
            { //each comparison
                temp = tempHead->data;
                tempHead->data = tempHead->next->data;
                tempHead->next->data = temp;
                tempHead = tempHead->next;
            }
            else //moves the compared value does the list
                tempHead = tempHead->next;
        }
        tempHead = head;
    }
    cout << "list 4 sorted -> ";
    displayLinkedList(); //outputs sorted list

}
