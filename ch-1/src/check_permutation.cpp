/*
 * solution for interview question 1.2 page 90
 * only works for lowercase letters of English alphabet
 * if one string is the permutation of the other:
 * - both has the same lengh
 * - both has same letters
 * TODO:
 * - compare lenght
 * - place letters into sorted array(hashtable)
 * - compare number of letters: must be the same
 */
#include <iostream>
//#include <cassert>

using namespace std;

// https://en.wikipedia.org/wiki/ASCII
// first letter of an ASCII table
char a = 'a';

// allocate array for letters of ASCII table
// the ASCII table the sorted `a` to `z`
// used to store a number of the characters seen,
// int letter_counts[26] = {0};

// use shift = 97 to place count of `a` at index 0 of an array after taking ASCII code of a letter
const int shift = (int) a;

/*
  increments the number of seen characters of [a..z]
  return new value of counter incremented
*/
int store_char(int *storage, char a_char){
  const int ascii_of_a_char = (int) a_char;
  const int i = ascii_of_a_char - shift; 
  storage[i]++;
  return storage[i];
}

int main(){
  // a and b strings are permutations
  char a_str[] = "abcdfef";
  int a_letter_counts[26] = {0};
  char b_str[] = "bfadefc";
  int b_letter_counts[26] = {0};
  if (sizeof(a_str) != sizeof(b_str) ){
    cout << "Strings lenght are not equal sizes! Exiting ..." << endl;
    exit(127);
  } else {
    cout << "Equal sizes ... keep going" << endl;
    for(size_t i = 0 ; i < sizeof(a_str) - 1;i++){
      char a_char = a_str[i];
      char b_char = b_str[i];
      cout << "for i " << i <<" a_char ==> " << a_char << endl;
      cout << "for i " << i <<" b_char ==> " << b_char << endl;
      store_char(a_letter_counts, a_char); // allow duplicates
      store_char(b_letter_counts, b_char); // allow duplicates
      // TODO uncomment to disable duplicate
      /*
        if (store_char(a_letter_counts, a_char) > 1 || store_char(b_letter_counts, b_char) > 1 ){
        cout << "DUPLICATE! Exiting ..." << endl;
        exit(127); // False
      } else {
        cout << "still going ..." << endl;
      }
      */
    }
    for(size_t i = 0 ; i < 26;i++){
      if(a_letter_counts[i] != b_letter_counts[i]){
        cout << "Not Permutation! Exiting ..." << endl;
        exit(127); // False
      }
    }
    cout << "The " << a_str << " is indeed  a permutation of "<< b_str << endl;
  }
}
