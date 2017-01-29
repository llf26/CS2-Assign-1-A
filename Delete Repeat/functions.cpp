#include <iostream>

#include <memory>
#include "header.hpp"


using std::cout;

using std::unique_ptr;







//Display original array

void dispArray(char array[])
{
    for(int x = 0; x < SIZE; x++)
        cout << array[x];
    cout << std::endl;
}


unique_ptr<char[]> deleteRepeats(char array[])
{
    int count = 0;
    for(int x = 0; x < SIZE; x++)
    {
        //Store current character
        char temp = array[x];

        //Set any matching characters after the current one to a space
            for(int y = x + 1; y < SIZE; y++)
            {
                if(temp == array[y])
                    {
                    array[y] = ' ';
                    count++;
                    }
            }


    }

    //Eliminate any leftover spaces
    for(int z = 0; z < count; z++)
    for(int x = 0; x < SIZE - 1; x++)
        if((array[x] == ' ') || (array[x] == array[x - 1]))
        array[x] = array[x + 1];

    //Create a unique pointer to return
        auto ptr = unique_ptr<char[]>{ new char[SIZE] };

    //Set the elements of the character array to the elements
    //of the unique pointer
        for(int x = 0; x < SIZE; x++)
            ptr[x] = array[x];

        return ptr;

}


