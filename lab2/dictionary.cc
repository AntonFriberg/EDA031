#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {
	string line;
	ifstream wordFile ("words.txt");
	if (wordFile.is_open()) {
		while ( getline (wordFile,line) ) {
			vector<string> lineWords;
			string lineWord;
			istringstream iss(line);
			while (iss >> lineWord) {
				lineWords.push_back(lineWord);
			}
			string firstWord = lineWords[0];
			lineWords.erase(lineWords.begin()); //Only triagrams remain
			Word::word newWord(firstWord, lineWords);

		}
	}
}

bool Dictionary::contains(const string& word) const {
	/*for (auto& it : words) {
		if (it == word) {
			return true;
		}
	}
	return false;
	*/
	return Dictionary::words.count(word);
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	/*add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	*/
	return suggestions;
}
