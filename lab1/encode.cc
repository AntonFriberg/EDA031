#include <iostream>
#include <fstream>
#include <string>
#include "coding.h"
/* Needed for ostringstream */
#include <sstream>
#include <cerrno>

using namespace std;

int main(int argc, char* argv[]) {
  string file = "./";
  for (int i=1; i<argc; i++)
    file += argv[i];
  ifstream input(file);
  ofstream output(file + ".enc");
  string line;

  /* Best way to read a file completely in C++.
     Source: http://insanecoding.blogspot.se */
  ostringstream contents;
  contents << input.rdbuf(); //read the file
  input.close();
  line = contents.str();

  string::iterator it;
  if (output.is_open()) {
    for (it = line.begin(); it < line.end(); ++it) {
      *it = Coding::encode(*it);
      output.put(*it);
    }
  }
  else cout << "Unable to open file";
  return 0;
}
