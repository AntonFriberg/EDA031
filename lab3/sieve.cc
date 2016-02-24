#include <string>
#include <iostream>
using namespace std;

int main(){
  string primes(100000,'p');
  primes.replace(0,2,"cc");
  int i=0;
  for(auto& c : primes){
    if(c=='p'){
      int number=i+i;
      while(number<100001){
        primes[number]='c';
        number=number+i;
      }
    }
    i++;
  }
  string result;
  for(int i=0;i!=201;i++){
    if(primes[i]=='p'){
      result+=to_string(i);
      result+="\n";
    }
  }
  cout<<result;
  cout<<primes.find_last_of("p")<<endl;


}
