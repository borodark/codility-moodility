#include <iostream>
#include <cassert>

using namespace std;

char a = 'a';

int letter_counts[26] = {0};

const int shift = (int) a;
// increment the number of seen characters of [a..z]
// return new value of counter incremented
int store_char(char a_char){
  const int ascii_of_a_char = (int) a_char;
  const int i = ascii_of_a_char - shift; 
  letter_counts[i]++;
  return letter_counts[i];
}

int main(){

  //char a_str[] = "abcfert";
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
  //

//char unique_str[]

  /*
  cout << endl;
  cout << "pushing z ...." << endl;
  int zZ = store_char(z);
  cout << endl;
  cout << "zZ = " << zZ << endl;
  cout << "pushing b ...." << endl;
  int bZ = store_char(b);
  cout << endl;
  cout << "bZ = " << bZ << endl;
  cout << "pushing z ...." << endl;
  zZ = store_char(z);
  cout << endl;
  cout << "zZ = " << zZ << endl;
  */
}

