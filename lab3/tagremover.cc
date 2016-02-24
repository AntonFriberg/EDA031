#include "tagremover.h"
#include <iostream>
#include <string>

using namespace std;

TagRemover::TagRemover(std::istream& cin){
  string word;
  bool append=true;
  while(getline(cin,word)){
    for(auto& c:word){
      if(c=='<' || c=='&'){
        append=false;
      }
      if(append){
        input+=c;
      }
      if(c=='>' || c==';'){
        append=true;
      }
    }
      input+="\n";
  }
  input.erase(input.size()-1,1);
}

void TagRemover::print(std::ostream& cout){
    cout<<input<<endl;
}
