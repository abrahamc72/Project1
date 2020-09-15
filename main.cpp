#include <iostream>
#include <iostream>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string shiftLeft(string s)
{
    string result;
    for (int i = 1; i < s.size(); ++i) {
        result += s[i];
    }
    result += s[0];
    return result;
}


int main()
{
    string test = "Mississippi";
    int rows = sizeof(test);
    string array[rows];
    string shiftedarray;

    shiftedarray = shiftLeft(test);



    std::cout << shiftedarray << std::endl;


}







