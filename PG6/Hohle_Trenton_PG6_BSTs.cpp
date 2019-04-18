// Roster Number: 15
//
// Author: Trenton Hohle
// Due Date: 4/25/18
// Programming Assignment Number 6
//
// Spring 2018 - CS 3358 - 260
//
// Instructor - Husain Gholoom
//
// takes a group of integers from main and sorts them into a binary search
// tree, then it displays the tree and all locations, displays the pre-ordered,
// then post ordered forms of the tree, all right then left sub roots, then
// it displays the number of leaves, followed by the leaves of the tree.

#include <iostream>

using namespace std;


class Tree
{ //Tree class
    public:
        int size;
        int *array;
        //function prototypes
        void insertElement(int x);
        int extendSize(int x);
        void values();
        void preOrder(int);
        void postOrder(int);
        void displayRSR(int);
        void displayLSR(int);
        int treeLeafsCount();
        void displayLeafValues();

        Tree(int size)
        { //constructor
            int newSize = extendSize(size);
            array = new int[newSize];
            for(int i = 0; i < newSize; i++)
                array[i] = 0;
        }
};

int main()
{
    Tree tree(1); //make instance of Tree class

    cout << "Binary Search Tree By Trenton Hohle\n\n";
    cout << "Inserting nodes.\n\n";
    tree.insertElement(70); //adding stuff to the tree
    tree.insertElement(50);
    tree.insertElement(100);
    tree.insertElement(30);
    tree.insertElement(60);
    tree.insertElement(80);
    tree.insertElement(110);
    tree.insertElement(20);
    tree.insertElement(68);
    tree.insertElement(90);
    tree.insertElement(120);
    tree.insertElement(25);
    tree.insertElement(62);

    cout << "Building BST is completed  : \n\n";

    cout << "\nValues of the Binary Search tree   :\n\n";

    tree.values();

    //Pre-Order traversal
    cout << "\nPre-Order Traversal of the BST :\n\n";
    tree.preOrder(0);

    //Post-Order traversal
    cout << "\nPost-Order Traversal of the BST :\n\n";
    tree.postOrder(0);

    //All right sub root values.
    cout << "\nHere are all right sub root values for the BST :\n\n";
    tree.displayRSR(0);

    //All right sub root values.
    cout << "\nHere are all left sub root values for the BST :\n\n";
    tree.displayLSR(0);

    //Counting Number of Leafs
    cout << "\n\nNumber of leafs =    " << tree.treeLeafsCount();

    //Display the leaf values.
    cout << "\n\nHere are the leaf values in the BST: \n\n";
    tree.displayLeafValues();

    cout << "\n\n\nApril 25, 2018\n\nWritten by Trenton Hohle \n\n";
}


int Tree :: extendSize(int x)
{ //extends the size of the array
    int value = size;
    for(int i = 0; i < x + 1; i++)
    {
        value = (2*value) + 2;
    }
    return value; //returns new array size
}

void Tree :: insertElement(int x)
{ //adds elements to the tree
    int index = 0;
    while(true)
    {
        if(index >= size)
        { //expands the array size
            int newSize = extendSize(size);
            int newArray[newSize];
            for(int i = 0; i < size; i++)
                newArray[i] = array[i];
            array = new int [newSize];
            for(int i = 0; i < newSize; i++)
                array[i] = newArray[i];
        }
        if(array[index] == 0)
        {
            array[index] = x;
            //cout << " Inserted at index: " << index << endl;
            break;
        }else if(array[index] <= x)
        {
            if(array[index] == x)
            {
                cout << "Error! -- Repeating element" << endl;
                break;
            }//else
                //cout << "Right ";
            index = (2*index + 2);
        }else if(array[index] >= x)
        {
            if(array[index] == x)
            {
                cout << "Error! -- Repeating element" << endl;
                break;
            }//else
               // cout << "Left ";
            index = (2 * index + 1);
        }
    }
}

void Tree :: values()
{ //outputs the tree and all values in each spot
    for(int i = 0; i < size; i++)
    {
        if(array[i] != 0)
            cout << i+1 << ":\t" << array[i] << endl;
        else
            cout << i+1 << ":\tempty" << endl;
    }
}

void Tree :: preOrder(int root)
{ //outputs the pre-order traversal of the tree
    if(array[root]!=0)
    {
        cout << array[root] << endl;
        preOrder(2*root + 1);
        preOrder(2*root + 2);
    }
}

void Tree :: postOrder(int root)
{ //outputs the post-order traversal of the tree
    if(array[root]!=0)
    {
        preOrder(2*root + 1);
        preOrder(2*root + 2);
        cout << array[root] << endl;
    }
}

void Tree :: displayRSR(int root)
{ //outputs the right sub roots of the tree
    if(root != 0 && array[root] != 0)
        cout << array[root] << endl;
    if(array[root] != 0)
        displayRSR(2 * root + 2);

}

void Tree :: displayLSR(int root)
{ //outputs the left sub roots of the tree
    if(root != 0 && array[root] != 0)
        cout << array[root] << endl;
    if(array[root] != 0)
        displayRSR(2 * root + 1);

}

int Tree :: treeLeafsCount()
{ //counts the number of leaves and outputs that number
    int counter = 0;
    for(int i = 0; i < size; i++)
        if((array[2*i+1]) == (array[2*i+2]) && array[i] != 0)
            counter++;

    return counter;
}

void Tree :: displayLeafValues()
{ //outputs all the leaves from the tree
    for(int i = 0; i < size; i++)
        if((array[2*i+1]) == (array[2*i+2]) && array[i] != 0)
            cout << array[i] << endl;
}
