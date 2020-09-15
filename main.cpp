
#include <iostream>
#include <iostream>
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

string grabLast(string str)
{
    string last;
    int length = str.length();
    last += str[length-1];
    return last;
}

int main()
{




    string test = "Mississippi";
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








