/*
 Gabriel Equitz - CSC 340 - student id: 915254839  - 
 * 
 */

#include <cstdlib>
#include <iostream>


using namespace std;

//function declarations
char getMostFreqLetter(string aString);
void StringToTokens(string aString);

/*
 * 
 */
int main(int argc, char** argv) {
 // local variable declaration
  string s ;

  //ask the user to type a sentence.
  cout << "Type a sentence and press the key Enter or just press the key Enter to use the default sentence." << endl;

  getline(cin,s);

  //if no sentence is entered use default sentence.
  if (s.length() == 0) {
    s = "Always remember that you are unique. Just like everyone else.";
    cout << s << endl;
  }

  cout << endl;



  // calling function to get the most frequent letter
   char cMost = getMostFreqLetter(s);
   cout << "The most frequent character is: " << cMost << endl;
  // calling the function to display the tokens
    cout << endl;
    cout << "The tokens are : " << endl;
    StringToTokens(s);

    return 0;
}
//returns the most frequent letter
char getMostFreqLetter(string aString)
{

  int maxN = 0;
  int countN ;
  char maxC ;

  //loop through all the letters of the alphabet
  for (char c = 'a'; c <= 'z'; c++){

    countN = 0;
    // loop through all the characters of aString
    for (int i = 0; i < aString.length(); i++){

       if (aString[i] == c || aString[i] == toupper(c))
          countN = countN + 1;

    }

    if (countN > maxN) {
      maxN = countN;
      maxC = c;

    }

  }


  return  maxC;

}
//function that splits string into tokens
void StringToTokens(string aString) {

   int iBeg = 0;
   int iEnd;
   char aDelimiter = ' ';
    // loop through all the characters of aString
    for (int i = 0; i <= aString.length(); i++){

      if  (aString[i] == aDelimiter) {
         iEnd = i;
         //substring(start index, span)
         cout << aString.substr(iBeg,iEnd-iBeg) << endl;
         iBeg = i+1;

      }

    }
    // displays the last token
    cout << aString.substr(iBeg,aString.length()-iBeg) << endl;


}



