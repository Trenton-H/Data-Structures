// Roster Number: 15
// Author: Trenton Hohle
// Due Date: 3/28/18
// Programming Assignment Number 4
//
// String 2018 - CS3358 - 260
//
// Instructor: Husain Gholoom
//
// This program will take a divided string from the user and tell if it is the reverse
// or identical depending on what the user chooses to check.



#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack
{ //Stack class prototypes
    private:
        int stackSize;
        struct Node
        {
            char data;
            Node *next;
        };
        Node *head;
        Node *rear;
    public:
        Stack();
        //~Stack();
        void push(char);
        char pop();
        bool isFull() const;
        bool isEmpty() const;
        int getSize();
};

class Queue
{ //Queue Class prototypes
    private:
        int queueSize;
        struct Node
        {
            char data;
            Node *next;
        };
        Node *head;
        Node *rear;
    public:
        Queue();
        //~Queue();
        void enqueue(char);
        char dequeue();
        bool isFull() const;
        bool isEmpty() const;
        int getSize();
};
//regular prototypes of the program
void stackComparison();
void queueReverse();
int findDivide(string);
bool identicalStrings(Stack , Stack);
bool identicalQueues(Queue , Queue );

int main()
{
   int answer = -1; //temp variable to keep track of user menu picks
   cout << "*** Welcome to My stack / Queue Program ***\n" << endl;
   cout << "The function of this program is to :\n" << endl; //program explanation
   cout << "\t1. Use stack to determine whether or not two strings are the same.\n" << endl;
   cout << "\t2. Use queue to determine whether or not STRING2 is the reversed of STRING1." << endl;

   do
   { //menu options
       cout << "\nSelect from the following menu" << endl;
       cout << "\t1. Enter Stack Values." << endl;
       cout << "\t2. Enter Queue Values." << endl;
       cout << "\t9. Terminate the program.\t";
       cin >> answer;
       cout << endl;
       cin.ignore(100, '\n');
       cin.clear();
       if(!cin)
       { //checker to make sure an int is input
           cout << "Invalid Option\n" << endl;
           cin.clear();
           cin.ignore(100, '\n');
       }
       else
       {
           switch(answer)
           { //directs program depending on users menu choice
               case(1):
                   stackComparison();
                   break;
               case(2):
                   queueReverse();
                   break;
               case(9):
                   break;
               default:
                   cout << "Invalid Option\n" << endl;
                   break;
           }
       }//do while loop to keep the user in the program till they chose to exit
   }while(answer!=9);
   //closing statements
   cout << endl << endl;
   cout << "*** End of the program. ***" << endl;
   cout << "*** Written by Trenton Hohle ***" << endl;
   cout << "March 28 - 2018 ***" << endl;
}

void stackComparison()
{ //main stack function
    Stack stack1, stack2;
    string stackTemp, string1, string2;

    cout << "Enter Stack Values :\t";
    getline(cin, stackTemp); //gathers the string to test with stack

    cout << endl;

    int divide = findDivide(stackTemp); //finds the '#' divider

    if(divide == -1) //errors if no divider is found
        cout << "Error *** Invalid String input!" << endl;
    else
    { //pushes both strings into their respective stacks
        for(int i = 0; i < divide; i++)
        {
            stack1.push(stackTemp[i]);
        }
        for(int i = divide+1; i < stackTemp.length(); i++)
        {
            stack2.push(stackTemp[i]);
        }

        bool test = identicalStrings(stack1, stack2); //tests if stacks are identical

        if(!test) //output depending on identical results
            cout << "Strings are not identical\n" << endl;
        else
            cout << "Strings are identical\n" << endl;
    }
}

void queueReverse()
{ //main queue function to call all other functions
    Queue queue1, queue2;
    string queueTemp;
    int divide;

    cout << "Enter Queue Values :\t";
    getline(cin, queueTemp); //gathers string to test

    cout << endl;

    divide = findDivide(queueTemp); //finds the '#' divider

    if(divide == -1) //erros if no divider is found
        cout << "Error *** Invalid String input!" << endl;
    else
    { //puts the 2 strings into their queues
        for(int i = 0; i < divide; i++)
            queue1.enqueue(queueTemp[i]);
        for(int i = queueTemp.length()-1; i > divide; i--)
            queue2.enqueue(queueTemp[i]);

        bool test = identicalQueues(queue1, queue2); //checks if queues are reverse of each other

        if(!test) //output depending on reserve test
            cout << "STRING1 is not reversed of STRING2.\n" << endl;
        else
            cout << "STRING1 is reversed of STRING2.\n" << endl;
    }


}

int findDivide(string temp)
{ //function to find the divider '#'
    int index = -1;
    for(int i = 0; i < temp.length(); i++)
    {
        if(temp[i] == '#') //if found it will mark the dividers index
            index = i;
    }
    return index; //returns the index of the last # found
}

bool identicalStrings(Stack string1, Stack string2)
{ //starts by assuming strings are identical, proves they aren't
    bool testVar = true;
    char one, two;
    if(string1.getSize() != string2.getSize())
    { //starts by checking size, because is sizes don't equal then strings can't
        testVar = false;
        return testVar;
    }
    else
    { //loops through stacks to check each character to see if they are equal
        for(int i = 0; i < string1.getSize() && testVar == true; i++)
        {
            one = string1.pop();
            two = string2.pop();
            if(one != two)
            {
                testVar = false;
                return testVar;
            }
        }
    } //returns if true, or instantly returns false if proven false
    return testVar;
}
bool identicalQueues(Queue queue1, Queue queue2)
{ //auto assumes queues are reversed and proves they aren't
    bool testVar = true;
    char one, two;
    if(queue1.getSize() != queue2.getSize())
    { //checks sizes first, because if sizes don't match neither will the reverse
        testVar = false;
        return testVar;
    }
    else
    {
        for(int i = 0; i < queue1.getSize() && testVar == true; i++)
        { //checks characters one by one though the queues
            one = queue1.dequeue();
            two = queue2.dequeue();
            if(one != two)
            {
                testVar = false;
                return testVar;
            }
        }
    } //returns the results
    return testVar;
}

Stack :: Stack()
{ //stack constructor
    head = NULL;
    stackSize = 0;
}
void Stack :: push(char c)
{ //pushes a character into the stack at the top
    Node *newNode = new Node;
    newNode->data = c;
    newNode->next = NULL;

    if(!head)
    {
        head = newNode;
        rear = head;
    }
    else
    {
        Node *p = head;
        while(p->next)
            p = p->next;
        p->next = newNode;
        rear = p;
    }
    stackSize++;
}
char Stack :: pop()
{//returns the top character from the stack while removing it from the stack
    char toReturn = ' ';
    if(!head)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        Node *p = head;
        Node *q = NULL;
        while(p->next)
        {
            q = p;
            p = p->next;
        }

        toReturn = p->data;
        q->next = NULL;
        rear = q;
        delete p;
        stackSize--;
        return toReturn;
    }
}
bool Stack :: isFull() const
{ //LL stacks are never full so auto returns false
    return false;
}
bool Stack :: isEmpty() const
{ //checks if stack is empty via the head
    if(!head)
        return true;
    else
        return false;
}
int Stack :: getSize()
{ //returns the size of the stack via a running counter
    return stackSize;
}
/*Stack :: ~Stack()
{ //commented out because kept crashing my program
    Node *p = head;
    while(p!=0)
    {
        head = head->next;
        delete p;
        p = head;
    }
    head = NULL;
}*/

Queue :: Queue()
{ //Queue constructor
    queueSize = 0;
    head = NULL;
    rear = NULL;
}
void Queue :: enqueue(char c)
{ //adds char into the queue at the back
    Node *newNode = new Node;
    newNode->data = c;
    newNode->next = NULL;

    if(!head)
    {
        head = newNode;
        rear = head;

    }
    else
    {
        Node *p = head;
        while(p->next)
            p = p->next;
        p->next = newNode;
        rear = p;
    }
    queueSize++;
}
char Queue :: dequeue()
{ //removes the front character from the queue and returns it
    char toReturn = ' ';
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        Node *p = head;
        head = head->next;
        toReturn = p->data;
        delete p;
        return toReturn;
    }
}
bool Queue :: isFull() const
{ //queue is also not full because LL don't get "full"
    return false;
}
bool Queue :: isEmpty() const
{ //checks if queue is empty via the head
    if(!head)
        return true;
    else
        return false;
}
int Queue :: getSize()
{ //returns the size of the queue via a running counter
    return queueSize;
}
/*Queue :: ~Queue()
{ //commented out destructor because it kept crashing my program after 1 run
    Node * p = head;
    while(p)
    {
        head = head->next;
        delete p;
        p = head;
    }
}*/
