#include <iostream>
#include <fstream>
#include "tagremover.h"

using namespace std;

int main(){
  ifstream cin("test.html");
  TagRemover tr(cin); // read from cin
  tr.print(cout);     // print on cout
}
