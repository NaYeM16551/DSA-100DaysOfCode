#include <iostream>

int main() {
    std::cout << "This is line " << __LINE__ << ".\n"; // Display the current line number --output (This is line 4.)
    #line 100 "new_file.cpp"  // Change the line number and file name for the preprocessor
    std::cout << "Now the line number is " << __LINE__ << " in the file " << __FILE__ << ".\n";//o/p--Now the line number is 100 in the file new_file.cpp.
    return 0;
}
