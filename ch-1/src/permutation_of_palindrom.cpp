/*
 * solution for interview question 1.4 page 91
 * only works for lowercase letters of English alphabet
 * if a string is the permutation of a palindrpome:
 * - there is even number of each char
 * - one or zero characters number of which is odd:
 *       that is a center of a Palindrome
 * TODO:
 * - place letters into sorted array(hashtable)
 * - walk over hashtable and apply logic above
 */
#include <iostream>
//#include <cassert>

using namespace std;

// https://en.wikipedia.org/wiki/ASCII
// first letter of an ASCII table
char a = 'a';
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
  // "abcdfeabcdfe" is a permutation of the palindrome "abcdfeefdcba"
  // char a_str[] = "abcdfeabcdfe";
  // "abcdfe abcdfe" is a permutation of the palindrome "abcdfeefdcba"
  // char a_str[] = "abcdfe abcdfe";
  // "abc dfea bcdfe" is a permutation of the palindrome "abcdfeefdcba"
  // char a_str[] = "abc dfea bcdfe";
  // "abc idf ea bcdfe" is a permutation of the palindrome "abcdfeiefdcba"
  //char a_str[] = "abc idf iiea bcdfe";
  // "abc idf a bcdfe" is NOT a permutation of a palindrome
  char a_str[] = "abc idf a bcdfe";
  int letter_counts[26] = {0};
  for(size_t i = 0 ; i < sizeof(a_str) - 1;i++){
    if(a_str[i] != ' '){
      char a_char = a_str[i];
      cout << "for i " << i <<" a_char ==> " << a_char << endl;
      store_char(letter_counts, a_char);
    }
  }
  //
  int count_of_odds = 0;
  for(size_t i = 0 ; i < 26;i++){
     cout <<  letter_counts[i] << " ...."<< letter_counts[i] % 2 << "<<<" << endl;
  
    if( letter_counts[i] > 0 && letter_counts[i] % 2 > 0){
        count_of_odds++;
        cout << count_of_odds << "<<< count_of_odds" << endl;
        if(count_of_odds > 1){
          cout << a_str << " IS Not a Permutation of a palindrome! Exiting ..." << endl;
          exit(127); // False
        }
      }
  }
  cout << "The " << a_str << " is indeed  a permutation of a palindrome "<< endl;
}

