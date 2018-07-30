// Example program
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct AnalysisWords
{
    string words;
    vector<int> countWord;
    vector<int> lengthWord;
    vector<int> lengthWordAnalysis;
};

void analysis(AnalysisWords* data)
{

  vector<string> array;

  //split
  istringstream is(data->words);
  string s;
  while (getline(is, s, ' '))
  {
    array.push_back(s);

    data->lengthWord.push_back(s.length());

  }

  int len = 1;


  auto result = max_element(data->lengthWord.begin(), data->lengthWord.end());


  for(int &s : data->lengthWord)
  {
      cout << s<< endl;
  }


  cout << "MAX = " <<  *result<< endl;

  cout << "========================" << endl;


  bool flag = false;

  do
  {
      for(int i=0; i < data->lengthWord.size();i++)
      {
          if(data->lengthWord[i] == len)
          {
              if(flag == false)
              {
                data->countWord.push_back(1);
                data->lengthWordAnalysis.push_back(len);

                flag = true;
              }
              else
              {
                  data->countWord.back() +=1;
              }


          }

      }
      flag = false;
      len++;

  }while( len <= *result);

  cout << "END " << endl;

  for(int i=0; i < data->countWord.size();i++)
  {
     cout << "Word Lenght: " << data->lengthWordAnalysis[i] << " | Count: " << data->countWord[i] << endl;
  }

  cout << "==============" << endl;

}


int main()
{
  AnalysisWords* analysisWords = new AnalysisWords();

  string words;
  cout << "Write words:  " <<endl;
  getline (std::cin, words);

  analysisWords->words = words;
  analysis(analysisWords);


}
