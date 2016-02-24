#include <string>
#include <vector>
#include <algorithm>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) {
	Word::word = w;
	Word::triagrams = t;
	sort(triagrams.begin(),triagrams.end());
}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int nbrOfMatches = 0;
	vector<string> v = Word::triagrams; //copy our triagram

	/*locates matches, if match is found the previous words
		can be deleted from next search since they are in alphabetical
		order. */
	for (auto& it : t) {
		int pos = 1;
		for (auto& iv : v) {
			if ( it == iv ) {
				v.erase(v.begin(), v.begin() + pos);
				++nbrOfMatches;
				break;
			}
			++pos;
		}
	}
	return nbrOfMatches;
}
