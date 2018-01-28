


#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

//structure definition: Token and Frequency
struct TokenFreq
{
   string token;
   int freq;
};

//function declarations
vector<TokenFreq>getTokenFreq(string &s);
void selectionSort_v1(vector<TokenFreq> &tokFreqVector);
vector<TokenFreq> selectionSort_v2(vector<TokenFreq> tokFreqVector);



int main(int argc, char** argv) {

   // local variable declaration: input string
  string s ;

  //ask the user to type a sentence.
  cout << "Type a sentence and press the key Enter or just press the key Enter to use the default sentence." << endl;

  getline(cin,s);

  //if no sentence is entered use default sentence.
  if (s.length() == 0) {
   /* s = "And no, I'm not a walking C++ dictionary. I do not keep every detail in my head "
            " at all times. If I did that, I would be much poorer programmer. I do keep the main "
            "points straight in my head most of the time, and I do know where to find the "
            "details when I need them. by Bjarne Stroustrup"; */
    
    s = "Mary had a little Mary lamb, little Mary lamb, little Mary lamb,";
    cout << "Entered sentence :  " << endl;
    cout << s << endl;
  }
  
  
  vector<TokenFreq> tf1 = getTokenFreq(s); // get the frequency of each token
  cout << "  " << endl;
  cout << " Tokens and frequencies before calling selection sort  " << endl;
  for (int j=0; j < tf1.size(); j++)  {      
      cout << " Token and frequency :  " << tf1.at(j).token << " " <<  tf1.at(j).freq << endl;
  }
  
  //save this vector to use also with selection sort (version2))
  vector<TokenFreq> tf1_saved = tf1;
 
  
  //sort the tokens by frequency using the selection sort algorithm, passing the vector by reference.
  //version 1
  selectionSort_v1(tf1);
  
  cout << "  " << endl;
  cout << " Tokens and frequencies after calling selection sort (version 1) " << endl;
  for (int j=0; j < tf1.size(); j++)  {      
      cout << " Token and frequency :  " << tf1.at(j).token << " " <<  tf1.at(j).freq << endl;
  }
  
  //sort the tokens by frequency using the selection sort algorithm, returning the vector by reference.  
  //version 2 (pass as argument the saved copy of tf1, that is, tf1_saved)
  vector<TokenFreq> tf2 = selectionSort_v2(tf1_saved);
  
  cout << "  "  << endl;
  cout << " Tokens and frequencies after calling selection sort (version 2) " << endl;
  for (int j=0; j < tf2.size(); j++)  {      
      cout << " Token and frequency :  " << tf2.at(j).token << " " <<  tf2.at(j).freq << endl;
   }
  
  return(0);
}

//finds the token frequency
vector<TokenFreq>getTokenFreq(string &s){

   
   int iBeg = 0;
   int iEnd;
   char aDelimiter = ' ';
   int wordCount = 0;
   string newWord[100]; // define array of tokens (by word here we mean token)
   
    // loop through all the characters of string s
    for (int i = 0; i <= s.length(); i++){

      if  (s[i] == aDelimiter) {
         iEnd = i;         
         //cout << s.substr(iBeg,iEnd-iBeg) << endl;  // testing with cout      
         newWord[wordCount] = s.substr(iBeg,iEnd-iBeg);
         wordCount += 1;
         iBeg = i+1;
      }

    }
    // get the last token
    //cout << s.substr(iBeg,s.length()-iBeg) << endl;  //testing with cout
    newWord[wordCount] = s.substr(iBeg,s.length()-iBeg);
    wordCount += 1;
    
    vector<TokenFreq> tf; // declare vector tf
   
    
    //use vectors to hold the token and the freq
    vector<string> tempToken;
    vector<int> tempFreq;     

    tempToken.push_back(newWord[0]); // add new word
    tempFreq.push_back(1); // set frequency = 1
   
    
    for (int i = 1; i < wordCount; i++){
        bool foundWord = false;
        for (int j=0; j < tempToken.size(); j++)  {
           if (tempToken.at(j) == newWord[i]){ // if the token equals an existing word, increase the frequency by 1 
               tempFreq.at(j) += 1;
               foundWord = true;
               }
        }
           if (!foundWord) {  //if a new token is found, start counting it.
               tempToken.push_back(newWord[i]);
               tempFreq.push_back(1);
           }
       
    } 
    
    
    for (int j=0; j < tempToken.size(); j++)  {
     //copy the tempToken and tempFreq to the TokenFreq vector
      tf.push_back(TokenFreq()); //push back new TokenFreq with default constructor     
      tf[j].token = tempToken.at(j); // add new token
      tf[j].freq = tempFreq.at(j); // add new frequency    
     
    }    

    
    return tf;
}

//selection sort passing by reference
void selectionSort_v1(vector<TokenFreq> &tokFreqVector){
    
    int n = tokFreqVector.size();
    int i, j,  tmp, minIndx;    
    for (i = 0; i < n - 1; i++) {
            minIndx = i;
            for (j = i + 1; j < n; j++)
                  if (tokFreqVector.at(j).freq < tokFreqVector.at(minIndx).freq)
                        minIndx = j;
            if (minIndx != i) {
                  int tmp_freq = tokFreqVector.at(i).freq;
                  string tmp_token = tokFreqVector.at(i).token;
                  tokFreqVector.at(i).freq = tokFreqVector.at(minIndx).freq;
                  tokFreqVector.at(i).token = tokFreqVector.at(minIndx).token;
                  tokFreqVector.at(minIndx).freq = tmp_freq;
                  tokFreqVector.at(minIndx).token = tmp_token;
                  
            }
      }
    
   // for (int j=0; j < tokFreqVector.size(); j++)  {
   //   cout << " word " << tokFreqVector.at(j).token  << " freq " << tokFreqVector.at(j).freq << endl;
   // } 
    
}

//selection sort returning by reference
vector<TokenFreq> selectionSort_v2(vector<TokenFreq> tokFreqVector2){
    
    int n = tokFreqVector2.size();
    int i, j,  tmp, minIndx;    
    for (i = 0; i < n - 1; i++) {
            minIndx = i;
            for (j = i + 1; j < n; j++)
                  if (tokFreqVector2.at(j).freq < tokFreqVector2.at(minIndx).freq)
                        minIndx = j;
            if (minIndx != i) {
                  int tmp_freq = tokFreqVector2.at(i).freq;
                  string tmp_token = tokFreqVector2.at(i).token;
                  tokFreqVector2.at(i).freq = tokFreqVector2.at(minIndx).freq;
                  tokFreqVector2.at(i).token = tokFreqVector2.at(minIndx).token;
                  tokFreqVector2.at(minIndx).freq = tmp_freq;
                  tokFreqVector2.at(minIndx).token = tmp_token;
                  
            }
      }
    
  
    
    return tokFreqVector2;
}








