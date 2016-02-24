#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
  /* Read words from file to string*/
  string line;
  string output;
  ifstream wordFile ("/usr/share/dict/words");
  if (wordFile.is_open()) {
    while ( getline (wordFile,line) ) {
      /*Converts all words to lower case letters */
      for (auto& c : line) {
        c = tolower(c);
      }


      if (line.size() > 2) { //No words added if under 3 char long

        /*Appends the triagrams in alphabetical order */
        vector<string> sortedTrigs;
        for (unsigned int i = 0; i != line.size() - 2; ++i) {
          string triagram = line.substr(i, 3); //create triagram

          /*if (triagram.find('\'') == string::npos) { //if it finds '
            sortedTrigs.insert(triagram);
          } */

          sortedTrigs.push_back(triagram);
        }
        sort(sortedTrigs.begin(), sortedTrigs.end());

        output += line + " " + to_string(sortedTrigs.size()) + " ";
        for (string& it : sortedTrigs)  {
          output += it + " "; //adds the triagrams
        }
        output += "\n"; //newline preperation for next word
      }
    }
    wordFile.close();
  }
  else cout << "Unable to open file";

  /* Write words from string to txt file */
  ofstream outputFile ("words.txt");
  if (outputFile.is_open())
  {
    outputFile << output.substr(0, 200); // used to test
    //outputFile << output;
    outputFile.close();
  }
  else cout << "Unable to open file";
  return 0;
}
