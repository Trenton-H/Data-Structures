//    Author: Trenton Hohle
//    Due Date: 2/5/18
//    Programming Assignment 1
//    Spring 2018 - CS 3358 - 260
//
//    Instructor: Husain Gholoom
//
//    This program creates 2 3x3 arrays to preform addition
//    and multiplication too, as well as finding the determinant
//    the sum of the rows/columns/diagonals and tell if it's
//    a special array.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void arrayPopulation(int[ ][3], int [ ][3], int);
void displayArrays1_2(int[ ][3], int [ ][3], int);
void arrayAddition(int[ ][3], int [ ][3], int);
void arrayMultiplication(int[ ][3], int [ ][3], int);
void arrayTransposal(int [ ][3], int);
void arrayDeterminant(int [ ][3]);
void rowSums(int [ ][3], int);
void columnSums(int [ ][3], int);
void diagonalSums(int [ ][3], int);
void specialArray(int [ ][3], int);


int main()
{
	int SIZE_OF_ARRAY = 3; //constant size of the arrays
    char answer = ' '; //initializing the user input variable
    bool pass = true; //sentinel variable to validate uses input
    int  Array_1 [SIZE_OF_ARRAY][3]; //initializing array 1
    int  Array_2 [SIZE_OF_ARRAY][3]; //initializing array 1


    cout << "Welcome to my Array program . The function of the program is to :"
         << endl;
    cout << "\t1. Create 2 Arrays (Array_1 , Array_2 ). Each Array is of "
	     << "size 3 x 3." << endl;
	cout << "\t2. Populate both Arrays with distinct random numbers that are "
	     << "between 1 \t    and 12. Display both Arrays." << endl;
	cout << "\t3. Adding and multiplying Array_1 and Array_2." << endl;
	cout << "\t4. Displaying the transposed and the determinate of Array_1." << endl;
	cout << "\t5. Displaying the sum of elements of each row of Array_1, "
	     << "displaying the \t   sum of elements of each column of Array_1 , "
	     << "displaying the sum of \t\t   both diagonal elements of "
		 << "Array_1." << endl;
	cout << "\t6. Finally , determining whether or not Array_1 is a special "
	     << "array.\n" << endl;
	cout << "\t7. Repeating the above steps until the user terminates the "
	     << "program.\n\n\n" << endl;
    do
    {
		answer = ' '; //resets the answer the user gives on going again or not
		pass = true; //resets the choice they choice so it doesn't infinite loop

        arrayPopulation(Array_1, Array_2, SIZE_OF_ARRAY);
        displayArrays1_2(Array_1, Array_2, SIZE_OF_ARRAY);
        arrayAddition(Array_1, Array_2, SIZE_OF_ARRAY);
        arrayMultiplication(Array_1, Array_2, SIZE_OF_ARRAY);
        arrayTransposal(Array_1, SIZE_OF_ARRAY);
        arrayDeterminant(Array_1);
		rowSums(Array_1, SIZE_OF_ARRAY);
		columnSums(Array_1, SIZE_OF_ARRAY);
		diagonalSums(Array_1, SIZE_OF_ARRAY);
        specialArray(Array_1, SIZE_OF_ARRAY);

        while(pass) //double nested loops. outer loop to redue functions
        {           //inner loop to validate the users input
            cout << "Would you like to check another Array - Enter y or Y for yes "
                 << "or n | N for no: ";
            cin >> answer;

           switch(answer)
           {
               case 'y':
                   break;
               case 'Y':
                   break;
               case 'N':
                   break;
               case 'n':
                   break;
               default:
                   cout << "Error *** Invalid choice  - Must enter y | Y | n | N" << endl;
           }
           if(answer=='Y' || answer=='y' || answer=='N' || answer=='n')
               pass = false;
           else
               pass = true;
        }
    }while(answer == 'Y' || answer == 'y');
    cout << "\n" << endl;

    cout << "This algorithm is implemented by Trenton Hohle\n\n"; //closing remark
}


void arrayPopulation(int array1 [3][3] , int array2 [3][3], int size)
{
    srand(time(NULL));  //initialize random seed
    bool checkRepeat1 = true; //sentinel to make sure there's no repeats
    bool checkRepeat2 = true; //sentinel to make sure there's no repeats
    int tempArray1[size*size];//initializes temp array
    int tempArray2[size*size];//initializes temp array
    int tempRandNum; //place holder for temp num until its validated and added to array
    for(int i = 0; i< (size*size); i++)
    { //outer loop to move section by section across the arrays
    	do
    	{ //inner loop repeats until new number isn't a repeat
    		tempRandNum = (rand()%12)+1;
    	    checkRepeat1 = true;
            for(int j = 0; j < i; j++)
            {
                if(tempRandNum == tempArray1[j])
                    checkRepeat1 = false;
		    }
        }while(!checkRepeat1);

        tempArray1[i] = tempRandNum; //adds num to array 1

        do
    	{ //inner loop repeats until new number isn't a repeat
    		tempRandNum = (rand()%12)+1;
    	    checkRepeat2 = true;
            for(int j = 0; j < i; j++)
            {
                if(tempRandNum == tempArray2[j])
                    checkRepeat2 = false;
		    }
        }while(!checkRepeat2);


        tempArray2[i] = tempRandNum; //adds num to array 2
    }


    int arrayPlaceMarker = 0;
    for(int i = 0; i<size; i++)
    { //populates the numbers from the temp arrays into their final arrays
        for(int j =0; j<size; j++)
        {
            array1[i][j] = tempArray1[arrayPlaceMarker];
            array2[i][j] = tempArray2[arrayPlaceMarker++];
		}
	}
}


void displayArrays1_2(int array1 [3][3], int array2[3][3], int size)
{
    cout << "Array_1\t\t:\n\n" << endl;
    for(int j = 0; j<size; j++)
    { //nested array so it moves row by row and column by column to output the
        for(int i = 0; i < size; i++) //3D array
        {
            cout << array1[i][j] << "\t";
        }
        cout << "\n" << endl;
    }
    cout << "\n" << endl;
    cout << "Array_2\t\t:\n\n" << endl;
    for(int j = 0; j<size; j++)
    {
        for(int i = 0; i < size; i++)
        {
            cout << array2[i][j] << "\t";
        }
        cout << "\n" << endl;
    }
    cout << "\n" << endl;
}


void arrayAddition(int array1[3][3], int array2[3][3], int size)
{
	int array3[size][size];
	cout << "Sum of Array 1     and     Array  2\n\n" << endl;
	for(int i = 0 ; i < size; i++ )
	{
	    for(int j = 0; j < size; j++)
	    { //adds arrays 1 & 2 together into array 3
	        array3[i][j] = (array1[j][i] + array2[j][i]);
	        cout << array3[i][j] << "\t";
		}
		cout << "\n\n";
	}
	cout << "\n\n";
}


void arrayMultiplication(int array1[3][3], int array2[3][3], int size)
{
	int tempArray[size][size];
	int tempNum, tempNum2, tempSum;
	for(int z = 0; z < size; z++) //3 arrays to give 3 variables, to cycle the
	{//arrays to multiply properly, while defining the answer into the temp array
	    for(int i = 0; i < size; i++ )
	    { //inner two arrays to go spot by spot down one arrays columns
		    tempSum = 0;// against the other arrays rows, multiplying them
            for(int j = 0; j < size; j++)
            { //multiplies array1 row i to array 2 column j and sums them
                tempNum = array1[j][z]; //togther into tempSum so it doesn't
				tempNum2 = array2[i][j];//modify the original arrays
				tempSum += (tempNum * tempNum2);

		    }
		    tempArray[z][i] = tempSum; //define multiplication of arrays into a
	    }                              //a temp array as to not modify either
	}                                  //original array


	cout << "Product of Array 1     and     Array 2\n" << endl;
	for(int i = 0; i < size; i++) //output the array
	{
	   for(int j = 0; j < size; j++)
	   {
	       cout << tempArray[i][j] << "\t";
	   }
	   cout << "\n\n";
	}
	cout << "\n\n";
}


void arrayTransposal(int array1[3][3], int size)
{
	int tempArray[size][size];
	for(int i = 0; i < size; i++)
	{
	   for(int j = 0; j < size; j++)
	   {
	       tempArray[j][i] = array1[j][i]; //temp array to hold transposed
	   }                                   //"mirrored" array
	}


	cout << "Transpose of Array 1\n" << endl;
	for(int i = 0; i < size; i++) //output temp array
	{
	   for(int j = 0; j < size; j++)
	   {
	       cout << tempArray[i][j] << "\t";
	   }
	   cout << "\n\n";
	}
	cout << "\n\n";
}


void arrayDeterminant(int array1[3][3])
{
	int determinant = 0;
	int t1, t2, t3, t4, t5, t6, t7, t8, t9;
	t1 = array1[0][0];
	t2 = array1[0][1];
	t3 = array1[0][2]; //couldn't think of a way to use an array to define
	t4 = array1[1][0]; //these variables more efficiently for the determinant
	t5 = array1[1][1]; //formula
	t6 = array1[1][2];
	t7 = array1[2][0];
	t8 = array1[2][1];
	t9 = array1[2][2];

	determinant = (t1*((t5*t9)-(t6*t8)) - t2*((t4*t9)-(t6*t7)) + t3*((t4*t8)-(t5*t7)));

	cout << "Determinant   of Array 1      =   " << determinant << "\n\n" << endl;

}


void rowSums(int array1[3][3], int size)
{
	int sum1 = 0, sum2 = 0, sum3 = 0;
	for(int i = 0; i < size; i++)
	{
	    sum1 += array1[0][i]; //each sum sums across the line simultaneously
	    sum2 += array1[1][i];
	    sum3 += array1[2][i];
	}

	    cout << "Sum of numbers in Row      #   1 in Array 1   =     " << sum1 << endl;
	    cout << "Sum of numbers in Row      #   2 in Array 1   =     " << sum2 << endl;
	    cout << "Sum of numbers in Row      #   3 in Array 1   =     " << sum3 << endl;
	    cout << "\n\n"; //outputs the sums
}


void columnSums(int array1[3][3], int size)
{
	int sum1 = 0, sum2 = 0, sum3 = 0;
	for(int i = 0; i < size; i++)
	{
	    sum1 += array1[i][0]; //each sum sums across the columns simultaneously
	    sum2 += array1[i][1];
	    sum3 += array1[i][2];
	}

	    cout << "Sum of numbers in Column   #   1 in Array 1   =     " << sum1 << endl;
	    cout << "Sum of numbers in Column   #   2 in Array 1   =     " << sum2 << endl;
	    cout << "Sum of numbers in Column   #   3 in Array 1   =     " << sum3 << endl;
	    cout << "\n\n"; //outputs sums
}


void diagonalSums(int array1[3][3], int size)
{
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < size; i++)
	{
	    sum1 += array1[i][i]; //sums the left to right diagonal
	    sum2 += array1[2-i][i]; //sums the right to left diagonal
	}

	cout << "Sum of numbers in first diagonal     in Array 1 =   " << sum1 << endl;
	cout << "Sum of numbers in second diagonal    in Array 1 =   " << sum2 << endl;
	cout << "\n\n"; //outputs sums
}


void specialArray(int array1[3][3], int size)
{
	int row1 = 0, row2 = 0, row3 = 0;
	int column1 = 0, column2 = 0, column3 = 0;
	int diagonal1 = 0, diagonal2 = 0;

	int specialNum = (size*(size*size+1))/2;
	cout << "The special number is   " << specialNum << "\n" << endl;

	for(int i = 0; i < size; i++) //gets the sums of the rows since
	{                             //we can't use pointers
	    row1 += array1[0][i];
	    row2 += array1[1][i];
	    row3 += array1[2][i];
	}

	for(int i = 0; i < size; i++) //gets the sums of the columns since
	{                             //we can't use pointers
	    column1 += array1[i][0];
	    column2 += array1[i][1];
	    column3 += array1[i][2];
	}

	for(int i = 0; i < size; i++) //gets the sums of the diagonals since
	{                             //we can't use pointers
	    diagonal1 += array1[i][i];
	    diagonal2 += array1[2-i][i];
	}

	if(row1 == specialNum && row2 == specialNum && row3 == specialNum &&
	   column1 == specialNum && column2 == specialNum && column3 == specialNum &&
	   diagonal1 == specialNum && diagonal2 == specialNum) //compares each value
	    cout << "The above is a special Array\n\n" << endl;//with the special number
	else
	    cout << "The above is not a special Array\n\n" << endl;
}
