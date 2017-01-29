#include <iostream>

#include <memory>
#include "header.hpp"








using std::unique_ptr;
using std::cout;





int main()
{

    //std::cout << SIZE;

    char originalArray[SIZE];
    originalArray [0] = 'a';
    originalArray [1] = 'b';
    originalArray [2] = 'b';
    originalArray [3] = 'c';
    originalArray [4] = 'a';
    originalArray [5] = 'c';
    originalArray [6] = 'a';
    originalArray [7] = 'c';
    originalArray [8] = 'b';
    originalArray [9] = 'c';

//Declare unique pointer
auto noRepeats = unique_ptr<char[]>{ new char[SIZE] };

cout << "Original array: ";
dispArray(originalArray);


//Set unique pointer to unique pointer returned by the function
noRepeats = deleteRepeats(originalArray);

//Integer for counting the characters deleted
int charCount = 0;

//Loop to display characters and count the ones deleted
cout << "Array with repeats deleted: ";
for(int x = 0; x < SIZE; x++)
    {
    cout << noRepeats[x];
    if(noRepeats[x] != ' ')
        charCount += 1;
    }
    cout << std::endl << "# of Characters deleted: " << (SIZE - charCount) << std::endl;













    return 0;
}
