// Collin Li
// Data Structures
// 9/30/2020
// Classwork 8
/*
Write a program that accepts 5
integer values from the keyboard.
Store them in an array using a
pointer. Then print the array,
starting at the beginning of the array
and again starting at the end using
pointers.
*/

// Preprocessor directive
#include <iostream>
using namespace std;

int main() {
  int* arr = new int[5]; // the pointer

  cout << "Enter 5 numbers to be stored" << endl; // Asking for 5 numbers

  
  // Record the numbers
  for (int i = 0; i < 5; i++) {
    cin >> *(arr + i);
  }

  cout << "print from beginning to end" << endl;
  // print from beginning to end
  for (int i = 0; i < 5; i++) {
    cout  << *(arr + i) << " ";
  }

  cout << endl;

  cout << "print from end to beginning" << endl;
  // print from end to beginning
  for (int i = 4; i >=0; i--) {
    cout << *(arr + i) << " ";
  }
  cout << endl;

  delete[] arr; // delete pointer

  return 0;

}
