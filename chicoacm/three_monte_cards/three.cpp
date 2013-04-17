#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int NUM_TRIALS = 32;

char ThreeCardMonte(string swaps) {
  string pos = "JAJ";
  for(int i = 0; i < swaps.length(); ++i) {
    if (swaps[i] == 'R') {
      swap(pos[1], pos[2]);
    } else if (swaps[i] == 'L') {
      swap(pos[0], pos[1]);
    } else if (swaps[i] == 'E') {
      swap(pos[0], pos[2]);
    }
  }
  if(pos[0] == 'A') {
    return 'L';
  } else if (pos[1] == 'A') {
    return 'M';
  } else {
    return 'R';
  }
}

int main(){
  int totalPassed = 0;
  int totalFailed = 0;
  string input[NUM_TRIALS]  = {"L","REL","RFRFR","","FLRELFLRELLFRLFEELFLRFLELRFLRFREFRFLLRFERLFLREFRFL","LLLRLLRERLFFEELFLRRFEFEFLFELFFLFFLRLREEFL","LEFLRERERFREREELFFFLFRLRLEFREEEEFEFRRLLFFFFLELL","LFLLLLFEFEREFEERERFFRLEEELRREEREEFLRLLFFLEFEER","RLEFLFFLFLLLRRELREERREERLFELERLFLLRREFEFFEFLR","LLLFFLELELRRFRLFFFRFLLRFEERRFRRLLELFERLFR","FEFERRRFLFFLELFFLFLLREFLEEEFEEFLFFERRLEEFLLFLF","LFELELFRLFRFLREFLFLRLLEELLEERRLRFEFFLRLEL","LREEFEFEEFLEFEFLELLRERRRLLLRFRLLLRFREERLREEELEEF","REFFFERREERLRELLELLLRRREFREEELELLLLLERFRLLEEFF","RELLRFFEEFEEERFRRLLRLFRRLFFRLFLLLLRFLRFLEEFR","RLFRRFFRERLRFEFFEFRLELRFELELRERRRLEELRLREFLLLFL","LELERFFEEFFELEFFRLFFLFEEFRFLRFLREEFEFLFFFRFR","LRRRRERFLLFRREFRFRRLRFFELLFELFLLFRLRFLFRREE","LRFERRFEFEFFERLFEREREEFELLEEFFRRLRELRELRFL","LLLRLLRERLFFEELFLRRFEFEFLFELFFL","FLRLREEFLELEFLRERERFREREELFFFLFRLRLEFREEEEFEFRRL","LLLRLLRERLFFEELFLRRFEFEFLFELFFL","LLLRLLRERLFFEELFLRRFEFEFLFELFFL","FLRLREEFLELEFLRERERFREREELFFFLFRLRLEFREEEEFEFRRL","E","LE","LRELRELRELRELRELREEEEEEEEEEEEEEEEEEEEEEEEEE","LL",'L',"LR","RL"};
  char output[NUM_TRIALS] = {'L','M','R','M','L','R','R','R','M','R','M','R','L','M','M','M','L','R','L','M','M','M','M','M','M','R','M','M','L','L','R','M'};

  for(int i = 0; i < NUM_TRIALS; ++i) {
    if(ThreeCardMonte(input[i]) == output[i]){
      cout << "Passed test "<< i << endl;
      totalPassed++;
    } else {
      cout << "Failed test " << i << " Input:\"" << input[i] 
          << "\" Your Output:\"" << ThreeCardMonte(input[i])
          <<"\" Correct Output:\"" << output[i] << "\"\n";
      totalFailed++;
    }
  }
  cout << endl << "You passsed " << totalPassed << " of " << NUM_TRIALS << " tests"
  << endl << "You failed  " << totalFailed << " of " << NUM_TRIALS << " tests" << endl;

  return 0;
}