#include <iostream>
#include "ufo_functions.hpp"
void greet(){
  using namespace std;
  string msg ;
  msg += "=============\n" ;
  msg += "UFO: The Game\n";
  msg += "=============\n";
  msg += "Instructions: save your friend from alien abduction by guessing the" "letters in the codeword.\n";
  cout << msg;
}


int main() {
  using namespace std;
  string codeword = "codecademy";
  string answer = string(codeword.size(), '_');
  int misses = 0;
  vector<char> incorrect;
  bool guess = false;
  char letter;


  while (answer != codeword && misses < 7){

    display_misses(misses);
    display_status(incorrect, answer);
    cout << "Please enter your guess: ";
    cin >> letter;
    cout << "\n";

    for (int i=0; i < codeword.size(); i++){
      if (codeword[i] == letter){
        answer[i] = letter;
        guess = true;
      }
    }
    if (guess){
      cout << "Correct!\n";      
    }
    else{
      cout << "Incorrect! The tractor beam pulls the person in further.\n";
      incorrect.push_back(letter);
      misses++;
    }
  guess = false;
    
  }

  end_game(answer, codeword);

}




