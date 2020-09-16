#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

//left shift used to encode strings
string shiftLeft(string str)
{
    string shifted;
    //loop takes a new string and copies, str starting from index 1
    for (int i = 1; i < str.length(); ++i)
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

//insertion sort that alphabetizes
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

int main(int argc, char* argv[])
{
    //cycle keeps track of how many lines are being taken in.
    int cycle = 0;
    string test;
    while(true)
    {

        if(cycle==0) {
            getline(std::cin, test);
        }
        //if the getline is empty, the while loop will be broken and the program will end
        if(cycle>0 && test.empty())
        {
            break;
        }
        //remove line seperator
        test.pop_back();

        //variable initialization
        cycle++;
        int rows = test.length();
        string array[rows];
        string shiftedarray = test;
        array[0] = test;
        string original = test;
        int originalindex = 0;

        //use the shiftleft func to shift each string and place into array.
        for (int i = 1; i < rows; i++) {
            shiftedarray = shiftLeft(shiftedarray);
            array[i] = string(shiftedarray);
        }
        //call insert sort
        InsertionSort(array,rows);

        //takes index of where original string is found
        for (int i = 0; i < rows; i++) {
            if (original.compare(array[i]) == 0) {
                originalindex = i;
            }
        }


        //grab each last character from cycled+sorted strings
        string last[rows];
        for (int i = 0; i < rows; i++) {
            last[i] = grabLast(array[i]);
        }


        string output;

        //checks for count of each letter in last. adds it to a final output string.
        for (int i = 0; i < rows; i++)
        {
            if (i > 0) {
                output += " ";
            }

            string letter = last[i];
            int count = 1;
            int searched = 0;
            char check[1];
            check[0] = letter[0];

            //cluster detection
            if (i < rows - 1 && letter.compare(last[i + 1]) == 0) {
                count++;
                i++;
            }
            //removes any seperators
            if( *check != 10 && *check!=13) {
                output += std::to_string(count);
                output += " ";
                output += letter;


            }

        }
        test ="";
        getline(std::cin, test);

        if(!test.empty())
        {
            std::cout << originalindex << endl;
            std::cout << output << endl;

        }
        else{
            std::cout << originalindex << endl;
            std::cout << output;
            break;
        }
    }
    return 0;
}