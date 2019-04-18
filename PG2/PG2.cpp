//    Author: Trenton Hohle # 15
//    Due Date: 2/19/18
//    Programming Assignment 2
//    Spring 2018 - CS 3358 - 260
//
//    Instructor: Husain Gholoom
//
//    This program gathers assignment and test grades from the
//    user to then calculate the users grade in the class.
//    User can also delete various grades if miss entered.

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class MyGrades
{
    private:
        vector <int> assignments; //vector variables to hold grades
        vector <int> tests;
    public:
        void setAssignmentGrade();
        int getAssignmentGrades(int);
        void setTestGrade();
        int getTestGrades(int);
        double displayAssignmentGrades();
        double displayTestGrades();
        void displayOverallGrades();
        void deleteAssignmentGrade();
        void deleteTestGrade();
};



int main()
{
    int choice; //temp variable to hold menu choices
    MyGrades grades; //instance of class MyGrades

    cout << "Welcome to My Grades APP." << endl;

    do
    {
        choice = -1;
        cout << "\n   1. Set a Programming Assignment Grade" << endl;
        cout << "   2. Set A Test Grade" << endl;
        cout << "   3. Show All Programming Assignment Grades" << endl;
        cout << "   4. Show All Test Grades" << endl;
        cout << "   5. Show Overall Grades" << endl;
        cout << "   6. Delete A Programming Assignment Grade" << endl;
        cout << "   7. Delete A Test Grade" << endl;
        cout << "   9. Exit The Program\n" << endl;
        cout << "Enter your choice --->\t";
        cin >> choice;
        switch(choice)
        {
            case 1:
                grades.setAssignmentGrade();
                break;
            case 2:
                grades.setTestGrade();
                break;
            case 3:
                grades.displayAssignmentGrades();
                break;
            case 4:
                grades.displayTestGrades();
                break;
            case 5:
                grades.displayOverallGrades();
                break;
            case 6:
                grades.deleteAssignmentGrade();
                break;
            case 7:
                grades.deleteTestGrade();
                break;
            case 9:
                break;
            default:
                cout << "\nError *** You entered invalid choice\n" << endl;
                break;
        }
        if(cin.fail())
        {
            cin.clear(); //to catch if user input anything other than an int.
            cin.ignore(100, '\n');
        }

    }while(choice != 9); //repeats loop unless user inputs 9 to leave the program

    cout << "\n\nImplemented by Trenton Hohle \nFebruary - 2018" << endl; //closing remark
}

void MyGrades :: setAssignmentGrade()
{
    if(assignments.size()==6)
    { //validation to make sure max assignments aren't met
        cout << "\nAlready have 6 assignments\n" << endl;
    }
    else
    {
        int assignGrade; //temp variable to hold input grade
        do
        {
            do
            {
                cin.clear();
                cin.ignore(100, '\n'); //makes sure cin is clear in case of previous invalid input
                cout << "What grade did you get for your assignment: ";
                cin >> assignGrade; // gathers grade from user

                if((assignGrade < 0) || (assignGrade > 10)) //error for invalid input number
                    cout << "\nError *** invalid number input\n" << endl;
                if(cin.fail()) //error for invalid data type
                    cout << "\nError *** You entered a character / String\n" << endl;
            }while(!cin || (!cin.good()));
        }while((assignGrade < 0) || (assignGrade > 10)); //nested loops to make sure input is valid

        assignments.push_back(assignGrade); //adds input to vector
    }

}
int MyGrades :: getAssignmentGrades(int index)
{
    return assignments.at(index); //returns assignments at give index
}
void MyGrades :: setTestGrade()
{
    int testGrade; //temp variable to hold test grade

    if(tests.size() == 2)
    { //validation that too many tests haven't already been input

        cout << "Already have max number of tests\n" << endl;
    }
    if(tests.size() == 1)
        { //validation loops to make sure proper input for the
        do //second test if one is already in the vector
        {
            do
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "What grade did you get for your assignment: ";
                cin >> testGrade;
                if((testGrade < 0) || (testGrade > 25)) //checks if input value is valid
                    cout << "\nError *** invalid number input choices are 0-25\n" << endl;
                if(cin.fail())
                    cout << "\nError *** You entered a character / String\n" << endl;
            }while(!cin);
        }while((testGrade < 0) || (testGrade > 25));
        tests.push_back(testGrade);
    }
    if(tests.size() == 0)
    { //validation for the first test being entered into the vector
        do
        {
            do
            {
                cin.clear();
                cin.ignore(100, '\n');
                cout << "What grade did you get for your assignment: ";
                cin >> testGrade;
                if((testGrade < 0) || (testGrade > 20))
                    cout << "\nError *** invalid number input choices are 0-20\n" << endl;
                if(cin.fail())
                    cout << "\nError *** You entered a character / String\n" << endl;
            }while(!cin);
        }while((testGrade < 0) || (testGrade > 20));
        tests.push_back(testGrade);
    }
}
int MyGrades :: getTestGrades(int index)
{
    return tests.at(index); //returns test grade of given index
}
double MyGrades :: displayAssignmentGrades()
{
    double counter = 0; //temp to gather all assignment grade values
    double total = 0; //temp to hold and return calculated value of 20
    cout << "\nProgramming Assignment Grades Are As Follows" << endl;
    for(int i = 0; i < assignments.size(); i++)
    { //reads in all values and displays them
        cout << fixed << setprecision(2) << (double) assignments.at(i) << "   ";
        counter += assignments.at(i);
    }
    if(assignments.size() > 0)
    { //if there is more than 1 assignment calculates grade out of 20
        total = ((counter/(assignments.size()))*2);
         cout << "\nAverage Programming Assignments Grades is\t" << fixed
             << setprecision(2) << total << " Out of 20" << endl;
    }
    if(assignments.size() == 0) //if no assignment grades, gives error
        cout << "\nNo Assignments Grades are recorded" << endl;

    return total; //returns calculated assignment grade out of 20
}
double MyGrades :: displayTestGrades()
{
    double counter = 0; //temp to hold grouped up test grade(s)
    cout << "\nTest Grades Are As Follows" << endl;
    for(int i = 0; i < tests.size(); i++)
    { //loop to read all test grades and count them up
        cout << fixed << setprecision(2) << (double) tests.at(i) << "   ";
        counter += tests.at(i);
    }
    if(tests.size() == 0) //error message if no test grades logged
        cout << "\nNo Test Grades are recorded\n" << endl;
    if(tests.size() == 1)
    { //output if only 1 test is logged
         cout << "\nAverage Test Grade is\t" << fixed
             << setprecision(2) << counter << " Out of 20\n" << endl;
    }
    if(tests.size() == 2)
    { //output if 2 test grades are logged
         cout << "\nAverage Test Grades is\t" << fixed
             << setprecision(2) << counter << " Out of 45\n" << endl;
    }

    return counter; //returns the sum of test grades
}
void MyGrades :: displayOverallGrades()
{
    double assignment, test; //temps to store values of test and assignment grades
    cout << "\nShow Overall Grades.\n" << endl;
    cout << "My Overall Grades so far as as follows  :" << endl; //output fluff
    assignment = displayAssignmentGrades(); //assigns values to temp variables
    test = displayTestGrades(); //and displays current tests/assignments

    //outputs depending on the size of tests and assignments
    if(assignments.size() == 0 && tests.size() == 0)
        cout << "Overall Total  -- >   0 out of 0\n" << endl;
    if(assignments.size() > 0 && tests.size() == 0)
        cout << "Overall Total  -- >   " << assignment
             << " out of 20\n" << endl;
    if(assignments.size() > 0 && tests.size() == 1)
        cout << "Overall Total  -- >   " << (assignment + test)
             << " out of 40\n" << endl;
    if(assignments.size() > 0 && tests.size() == 2)
        cout << "Overall Total  -- >   " << (assignment + test)
             << " out of 65\n" << endl;
    if(assignments.size() == 0 && tests.size() == 1)
        cout << "Overall Total  -- >   " << test
             << " out of 20\n" << endl;
    if(assignments.size() == 0 && tests.size() == 2)
        cout << "Overall Total  -- >   " << test
             << " out of 45\n" << endl;

}
void MyGrades :: deleteAssignmentGrade()
{
    int assignmentToDelete; //temp to hold delete value
    bool found = false; //temp to check if value is even in vector

    do
    {
        if(assignments.size()==0)
        { //output error if size of assignments is already 0
            cout << "\nError *** No Assignments to Delete\n" << endl;
            found = true;
        }else
        {
            cin.clear(); //makes sure cin is clear of any previous errors
            cin.ignore(100, '\n');
            cout << "Enter An Assignment Grade to be Deleted:   ";
            cin >> assignmentToDelete;
            for(int i = 0; i < assignments.size() && !found; i++)
            { //checks vector for num to delete, if found, deletes num and leaves loop
                if(assignments.at(i) == assignmentToDelete)
                {
                    assignments.erase(assignments.begin()+i);
                    found = true;
                }
            }

            if(!cin) //verifies if input is an int
                cout << "\nError *** Invalid input, input an integer\n" << endl;
            else if(assignmentToDelete<0 || assignmentToDelete>10) //checks that input is a valid number
                cout << "\nError *** Input value is out of bounds, choices are 0-10\n" << endl;
            else if(!found) //checks if input was even found
                cout << "\nInput value " << assignmentToDelete << " wasn't found.\n" << endl;
        }

    }while(!cin || !found);
}
void MyGrades :: deleteTestGrade()
{
    int testToDelete; //temp variable to store value to delete
    bool found = false; //bool to check if value was found

    do
    {
        if(tests.size()==0)
        { //error for if test vector is already empty
            cout << "\nError *** No Tests to Delete\n" << endl;
            found = true;
        }else
        {
            cin.clear(); //makes sure cin is clear or previous errors
            cin.ignore(100, '\n');
            cout << "Enter An Test Grade to be Deleted:   ";
            cin >> testToDelete; //gathers input
            for(int i = 0; i < tests.size() && !found; i++)
            { //checks tests vector if test is even found
                if(tests.at(i) == testToDelete)
                { //deletes test if found, and then leaves the loop
                    tests.erase(tests.begin()+i);
                    found = true;
                }
            }

            if(!cin) //validation to make sure input is an int
                cout << "\nError *** Invalid input, input an integer\n" << endl;
            else if(testToDelete<0 || testToDelete>25) //validation to make sure input number is valid
                cout << "\nError *** Input value is out of bounds, choices are 0-25\n" << endl;
            else if(!found) //validation if input number was even found
                cout << "\nInput value " << testToDelete << " wasn't found.\n" << endl;
        }

    }while(!cin || !found);
}
