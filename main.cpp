
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//left shift used to encode strings
string shiftLeft(string str)
{
    string shifted;
    //loop takes a new string and copies, str starting from index 1
    for (int i = 1; i < str.size(); ++i)
    {
        shifted += str[i];
    }
    //adds the old index 0 to the last index
    shifted += str[0];
    return shifted;
}

//function to grab the last letter of a string
string grabLast(string str)
{
    string last;
    int length = str.length();
    last += str[length-1];
    return last;
}

void InsertionSort(string *pointer, int length)
{
    string temp;
    int i;
    for(i = 1; i<length; i++)
    {
        temp = *(pointer+i);
        int j;

        for(j = i - 1; j >= 0 && (*(pointer+j)).compare(temp)>0 ; j--)
        {
            pointer[j+1] = *(pointer+j);
        }
        pointer[j+1] = temp;
    }
}

int main()
{

    string test = "ADBCabcd";
    int rows = test.length();
    string array[rows];
    string shiftedarray = test;
    array[0] = test;

    //use the shiftleft func to shift each string and place into array.
    for(int i = 1; i< rows; i++)
    {
        shiftedarray = shiftLeft(shiftedarray);
        array[i] = string(shiftedarray);
    }
    //array[1] = *(array+2);

    //cout<< *(array +1)<<endl;
    InsertionSort(array, rows);



    //grab each last character from, cycled strings
    string last[rows];
    for(int i = 0; i< rows;i++)
    {
        last[i] = grabLast(array[i]);
    }

    for(int i = 0; i< rows;i++)
    {
        std::cout << array[i] << std::endl;
    }

}