//  Authors: Matt Windham 51 & Kevin Kim
//  Due date: 4/12/2017
//  Progamming Assignment 6
//  Spring 2017 - CS 3358 - Section Number 2
//
//  Instructor:  Husain Gholoom
//
//

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void populateArray(int*, int, int);
void displayArray(int*, int, int);
void tableOfSquares(int, int);
int powerFunction(int, int);
int sumOfSquares(int, int);
int minMaxNumber(int*, int);
void bubbleSort(int*, int);
bool isMember(int*, int, int);
bool notMember(int*, int, int);
void isItPrime(int, int);

int main()
{
    char option;        // Char input for menu switch
    int arrSize;        // Input for size of array
    int *array;         // Array to hold values
    int value;          // Values used in array
    bool menuSwitch = true;     // Boolean for menu switch
                                // T = run again, F = terminate program
    srand(time(NULL));

    
    cout << "Thinking Recursively" << endl << endl;
    cout << "The function of this program is to" << endl
    << "use recursion to :-" << endl << endl;
    cout << "\t1.  Display squares of integers in ascending" << endl
    << "\t    order from 1 to the last element in the array" << endl;
    cout << "\t2.  Raise the first number to a power 2" << endl;
    cout << "\t3.  Return the sums of squares of the numbers" << endl
    << "\t    from 0 to the fifth element in the array" << endl;
    cout << "\t4.  Search the array for the array's min and max values" << endl;
    cout << "\t5.  Sort the array in ascending order" << endl;
    cout << "\t6.  Search the array for the first value in the array" << endl;
    cout << "\t7.  Search the array for the number 600" << endl;
    cout << "\t8.  Determine if a number is prime (processes all array values)" << endl;
    
    do
    {
        cout << "Select from the following menu" << endl;
        cout << "\tA.  Enter Array Size that is > 4." << endl;
        cout << "\tX.  Terminate The Program. ";
        
        cin >> option;
        switch(option)
        {
            case 'A':
                cout << "Enter Array Size: ";
                cin >> arrSize;
                cout << endl;
                
                if (arrSize <= 4)
                {
                    cin.clear();
                    cin.ignore();
                    cout << "*** Invalid Array Size Value ***" << endl;
                    cout << "Enter Array Size That is > 4: ";
                    cin >> arrSize;
                    cout << endl << endl;
                    
                    if (!(cin >> arrSize))
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "*** Invalid Array Size Value ***" << endl;
                        cout << "Enter an integer not a char: ";
                        cin >> arrSize;
                    }
                }
                
                array = new int [arrSize];
                populateArray(array, arrSize, 0);
                
                cout << "The generated array is: ";
                displayArray(array, arrSize, 0);
                cout << endl << endl;
                
                value = array[arrSize-1];
                cout << "Table of square values 1 - " << value << endl
                << endl << "N" << "\tN Squared" << endl;
                tableOfSquares(value, 1);
                
                value = array[0];
                cout << endl << "Power Function:" << endl;
                cout << value << " raised to the 2nd power is: "
                << powerFunction(value, 2) << endl << endl;
                
                value = array[arrSize-2];
                cout << "Sum of squares between 0 and " << value
                << " is: " << sumOfSquares(value, 0) << endl << endl;
                
                cout << "Sorted array" << endl;
                bubbleSort(array, arrSize);
                displayArray(array, arrSize, 0);
                cout << endl << endl;
                
                value = array[3];
                cout << "Member Functions:" << endl << "Does the array: ";
                displayArray(array, arrSize, 0);
                cout << " have the number \t" << value << "?";
                
                if(isMember(array, arrSize, value))
                    cout << "  YES" << endl;
                else
                    cout << "  NO" << endl;
                
                cout << endl << "Does the array: ";
                displayArray(array, arrSize, 0);
                cout << " have the number \t 600?";
                
                if(isMember(array, arrSize, 600))
                    cout << "  YES" << endl;
                else
                    cout << "  NO" << endl;
                
                cout << endl << "Is it prime:" << endl;
                for(int i = 0; i < arrSize; i++)
                {
                cout << "The number " << array[i] << " is ";
                isItPrime(array[i], array[i] - 1);
                cout << "Prime" << endl;
                }
                
                delete [] array;
                
                break;
                
            case 'X':
                cout << endl << "Matt Windham & Kevin Kim - " <<
                "Tweak Development Directors" << endl <<
                "April 2017" << endl << endl;
                
                return 0;
                break;
                
            default:
                cout << endl << "***  Invalid Option ***"
                << endl << endl << endl;
                
        }
        
    }while(menuSwitch);
    
    return 0;
}

void populateArray (int *arr, int size, int index)
{
    if(index >= size)
        return;
    
    arr[index] = rand() % (476 + 25);
    
    populateArray(arr, size, index + 1);
}

void displayArray (int *arr, int size, int index)
{
    if(index >= size)
        return;
    
    cout << arr[index] << " ";
    
    displayArray(arr, size, index + 1);
}

void tableOfSquares(int last, int index)
{
    if(index > last)
        return;
    
    cout << index << "\t" << (index * index) << endl;
    tableOfSquares(last, index + 1);
}

int powerFunction(int num, int power)
{
    if(power == 0)
        return 1;
    
    else if (power == 1)
        return num;
    
    else
        return (num * powerFunction(num, power - 1));
}

int sumOfSquares(int num, int index)
{
    if(index > num)
        return 0;
    else
        return((index * index) + sumOfSquares(num, index + 1));
}

/*int minMaxNumber(int *arr, int size)
{
    
} */

void bubbleSort(int *arr, int size)
{
    if(size == 1)
        return;
    
    for(int i = 0; i < (size-1); i++)
        
        if(arr[i] < arr[i+1])
            swap(arr[i], arr[i + 1]);
    
    bubbleSort(arr, size-1);
}

bool isMember(int *arr, int size, int target)
{
    if(size <= 0)
        return false;
    
    else if (arr[size-1] == target)
        return true;
        
    else
        return isMember(arr, size-1, target);
}

void isItPrime(int num, int holder)
{
    if(holder <= 1)
        return;
    
    else if(num % holder == 0)
        cout << "NOT ";
    
    else
        isItPrime(num, holder - 1);
}