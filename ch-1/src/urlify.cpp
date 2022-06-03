/*
 * solution for interview question 1.3 page 90
 */
#include <iostream>

using namespace std;
/*
 * "Jaux meis!  " -> "Jaux%20meis!"
 */
void url_efy(char *input_string, int its_true_lenth){
  // its_true_lenth;
  // int padded_length contains 2 more per each space
  int pads = 0;
  for(int i = its_true_lenth - 1 ; i >= 0 ;--i){
    // cout << "cursor is: " << i << " ..."<< input_string[i] << endl;
    if(input_string[i] == ' '){
      pads++;
    }
  }
  cout << "pads: " << pads << endl;
  int full_length = its_true_lenth + 2 * pads;
  cout << "full_length " << full_length << " ..." << endl;
  // i is the last read char position !
  int last_filled_char_pos = full_length;
  for(int i = its_true_lenth - 1; i >= 0 ;i--){
    // cout << "i: " <<  i << " input is: "<< input_string[i] << endl;
    if(input_string[i] != ' '){
      // move the char to the end
      last_filled_char_pos--;
      input_string[last_filled_char_pos] = input_string[i];
      //cout << "fill pointer is: " <<  last_filled_char_pos << endl;
    } else { // space !' '
      // send to back '%20
      //cout << "space !" << endl;
      //cout << "fill pointer is: " <<  last_filled_char_pos << endl;
      last_filled_char_pos--;
      input_string[last_filled_char_pos] = '0';
      //cout << "===>>" << input_string << endl;
      //cout << "fill pointer is: " <<  last_filled_char_pos << endl;
      last_filled_char_pos--;
      input_string[last_filled_char_pos] = '2';
      //cout << "===>>" << input_string << endl;
      //cout << "fill pointer is: " <<  last_filled_char_pos << endl;
      last_filled_char_pos--;
      input_string[last_filled_char_pos] = '%';
      //cout << "===>>" << input_string << endl;
      //cout << "fill pointer is: " <<  last_filled_char_pos << endl;
    }
    cout << "===>>" << input_string << endl;

  }
}
//Jaux%20meis!%20Jaux%20meis!
// Jaux meis! Jaux meis!
// Jaux meis! Jaux meis!
int main(){
  char input[28] = {"Jaux meis! Jaux meis!      "};
  url_efy(input,21);
  // char input[13] = {"Jaux meis!  "};
  // char input[13] = {'J','a','u','x',' ', 'm','e','i','s','!',' ', ' '};
  cout << "size of is: "<< sizeof(input) << endl;
  // url_efy(input,10);
  cout << input << endl;
}
