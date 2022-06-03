/*
 * solution for interview question 1.1 page 90
 * only works for lowercase letters of English alphabet
 */
#include <iostream>
// #include <cassert>

using namespace std;

// https://en.wikipedia.org/wiki/ASCII
// declare first letter of our ASCII table
char a = 'a';

// allocate array for letters of ASCII table
// used to store a number of the characters seen,
int letter_counts[26] = {0};

// use shift = 97 to place count of `a` at index 0 of an array after taking ASCII code of a letter
const int shift = (int) a;

/*
 increments the number of seen characters of [a..z]
 return new value of counter incremented
*/
int store_char(char a_char){
  const int ascii_of_a_char = (int) a_char;
  const int i = ascii_of_a_char - shift; 
  letter_counts[i]++;
  return letter_counts[i];
}

int main(){
  // unique string
  // char a_str[] = "abcfert";
  // non unique string
  char a_str[] = "klsjdfaslcvjnzxcvmnzxcbhmaiufrgh";
  for(size_t i = 0 ; i < sizeof(a_str) - 1;i++){
    char a_char = a_str[i];
    cout << "for i " << i <<" ==> " << a_char << endl;
    if (store_char(a_char) > 1 ){
      cout << "DUPLICATE! Exiting ..." << endl;
      exit(127); // False
    } else {
      cout << "still unique ... keep going" << endl;
    }
  }
}
