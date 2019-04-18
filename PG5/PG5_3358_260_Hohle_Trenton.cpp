// Roster Number : 15
//
// Author : Trenton Hohle
// Due Date : 4/8/18
// Programming Assignment Number 5
//
// Spring 2018 - CS 3358 - 260
//
// Instructor : Husain Gholoom
//
// This program gathers an array size input from a user between 10-1000
// it then creates an array of that size, populating it with random numbers
// between 10-1000, it displays the first 10 numbers, displays the squares
// of numbers from 1 - the last number, raises the first number to the power
// of 2, finds and returns the highest element in the array, sorts the array
// in descending order, and then sums the digits of the first integer in the
// array.


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iomanip>



using namespace std;

void programExplanation();
int getArraySize();
int * generateArray(int);
void displayArray(int *);
void displayArrayCommas(int *);
void nSquaredFormat(int*, int);
void nSquared(int *, int, int);
int powerFunction(int , int);
int maxArrayNum(int *, int, int, int);
void quickSort(int *, int, int);
int digitSum( int, int);
void determinePrime(int *, int, int);



int main()
{
    srand(time(NULL)); //seeds time
    char answer = ' '; //initializing menu answer
    int arraySize = -1; //initializing variable to hold array size
    time_t timerStart, timerEnd; //initializing timer variables


    programExplanation();

    do
    { //menu in loop so user gets returned after each go through
        cout << "\nSelect from the following menu" << endl;
        cout << "A.   Enter Array Size that is >= 10." << endl;
        cout << "X.   Terminate The Program.       ";
        cin >> answer;
        cout << endl;

        if(cin.fail()) //make sure input is correct
        {
            cout << "\n*** Invalid Option ***" << endl << endl;
            cin.ignore(100, '\n');
            cin.clear();
        }
        if(answer == 'A' || answer == 'a')
        { //triggers full program is A/a is chosen
            arraySize = getArraySize(); //gathers array size
            cout << arraySize << endl;

            time(&timerStart); //logs first timer
            tm *tStart = localtime(&timerStart);

            int *array = new int();
            array = generateArray(arraySize); //generates random numbers into array
            cout << "the generated array is:\n" << endl;
            displayArray(array); //displays first 10 ints from array

            nSquaredFormat(array, arraySize); //displays 1 - n numbers and there squares

            cout << "\n\n\n"; //newline buffer zone

            cout << "\nPower Function:\n" << endl; //shows first array term squared
            cout << array[0] << " raised to the 2nd power is: "
                 << powerFunction(array[0], 2) << endl << endl;

            cout << "\nMax Number of ";
            displayArrayCommas(array); //displays array separated with commas
            cout << " is : " << maxArrayNum(array, 0, array[0], arraySize-1)
                 << endl << endl; //finds and outputs highest number in array

            cout << "\nSorted Array" << endl << endl;
            quickSort(array, 0, arraySize-1); //sorts array
            displayArray(array); //displays first 10 elements of array

            time(&timerEnd); //gets time at end
            tm *tEnd = localtime(&timerStart);

            cout << "Start Time " << tStart->tm_hour << " : " << tStart->tm_min
                 << " : " << tStart->tm_sec << endl; //outputs start time
            cout << "End Time " << tEnd->tm_hour << " : " << tEnd->tm_min
                 << " : " << tEnd->tm_sec << endl; //outputs end time
            //outputs time difference
            cout << "Actual CPU Clock time " << tStart->tm_hour - tEnd->tm_hour
                 << " : " << tStart->tm_min - tEnd->tm_min << " : "
                 << tStart->tm_sec - tEnd->tm_sec <<  endl << endl;

            //outputs sum of digits of first int
            cout << "\nSum of digits for the number " << array[0] << " is " << digitSum(array[0], 0) << endl;

            cout << "\nIs it prime: " << endl << endl;
            determinePrime(array, 0, arraySize); //outputs each number and if it
            cout << endl;                        //is prime or not prime
        }
        else
        {
            cout << "*** Invalid Option ***" << endl;
            cin.ignore(100, '\n'); //valids menu options
            cin.clear();
        }
    }while(answer != 'X' || answer != 'x'); //only escapes if x/X is chosen

    cout << "\n\nTrenton Hohle - Tweak Programming Developer" << endl;
    cout << "April 2018" << endl; //closing comments
}
void programExplanation()
{ //program explanation
    cout << "Thinking Recursively\n" << endl;
    cout << "The function of this program is to" << endl;
    cout << "use recursion in order to perform the following operations  :-\n" << endl;
    cout << "\t1.  Display squares of integers in ascending order form 1 to the" << endl;
    cout << "\t    last element in the array" << endl;
    cout << "\t2.  Raise the first number to a power 2" << endl;
    cout << "\t3.  Find the array's max value." << endl;
    cout << "\t4.  Sort the array in descending order" << endl;
    cout << "\t5.  Calculating sum of digits" << endl;
    cout << "\t6.  Determine if a number is prime (processes all array values)" << endl;
}

int getArraySize()
{ //gathers array size and valids input
    int size = -1;
    cout << "Enter Array Size: ";
    cin >> size;
    cout << endl;

    do
    {
        if(cin.fail())
        { //catches invalid input type
            size = -1;
            cout << "*** Invalid Array Size Value ***" << endl;
            cout << "Enter an integer not a char: ";
            cin.clear();
            cin.ignore(100, '\n');
            cin >> size;
            cout << endl;
        }else if(size < 10 || size > 1000)
        { //catches invalid input numbers
            cout << "*** Invalid Array Size Value ***" << endl;
            cout << "*** Enter Array Size That is >=10 and <= 1000 : ";
            cin >> size;
            cout << endl;
        }

    }while (size < 10 || size > 1000); //looped to keep bugging them
    return size;
}

int *generateArray(int size)
{ //populates array with random integers 10-1000
    int *array = new int [size];
    int temp = -1;

    for(int i = 0; i < size; i++)
    {
        temp = (rand() % 991) + 10;
        array[i] = temp;
    }
    return array;
}

void displayArray(int array[])
{ //outputs first 10 integers in array
    for(int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

void displayArrayCommas(int array [])
{ //displays the array with integers separated by commas
    cout << "( ";
    for(int i = 0; i < 10; i++)
    {
        cout << array[i];
        if(i != 9)
            cout << " , ";
    }
    cout << " ) ";
}

void nSquaredFormat(int array[], int size)
{ //sets up to output numbers  1 - last number plus there squares
    cout << "Table of square values 1 - " << array[size-1] << endl << endl;
    cout << setw(6) << left << "N" << "N Squared" << endl;
    nSquared(array, 1, size);
}
void nSquared(int array[], int spot, int size)
{ //outputs numbers 1 - last integer and there squares
    if(spot <= array[size-1])
    {
        cout << setw(6) << left << spot << spot*spot << endl;
        nSquared(array, spot+1, size);
    }
}

int powerFunction(int number, int power)
{ //outputs the first integer in the array's square value
    if(power < 1)
        return 1;

    return  number * (number^(power-1));
}

int maxArrayNum(int array[], int spot, int max, int size)
{ //finds the max number in the array
    if(spot == size)
    {
        //cout << max;
        return max;
    }
    if(max < array[spot])
    {
        max = array[spot];
        maxArrayNum(array, spot+1, max, size);
    }
    else
        maxArrayNum(array, spot+1, max, size);
}

void quickSort(int array[],int left, int right)
{ //sorts the array in descending order
    int i = left, j = right;
    int temp;
    int pivot = array[(left+right)/2];

    while (i<=j)
    {
        while(array[i] < pivot)
            i++;
        while(array[j]>pivot)
            j--;
        if(i <= j)
        {
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(array, left, j);
    if(i < right)
        quickSort(array, i, right);
}

int digitSum(int num, int sum)
{ //sums the value of the digits of the first integer in the array
    if(num != 0)
    {
        sum += num%10;
        num /= 10;
        digitSum(num, sum);
    }
    else
        return sum;
}

void determinePrime(int array[], int spot, int size)
{ //determines if each number in the array is prime or not
    bool prime = false;
    for(int i =2; i < array[spot]/2; i++)
    {
        if(array[spot]%i == 0)
            prime = true;
    }

    if(prime == true)
        cout << array[spot] << " is Prime" << endl;
    else
        cout << array[spot] << " is Not Prime" << endl;

    if(spot != size-1)
        determinePrime(array, spot+1, size);
}
