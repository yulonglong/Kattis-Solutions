// https://open.kattis.com/problems/wertyu

#include <bits/stdc++.h>
using namespace std;
typedef pair<char,int> ci;

map<char, int> dict;
map<char, int>::iterator iter;
vector<char> reverseDict;

int main() {
	int idx = 0;
	// Special Case, corner, on the left
	idx++; dict.insert(ci('`', idx++)); reverseDict.push_back('`'); reverseDict.push_back('`');
	dict.insert(ci('1', idx++)); reverseDict.push_back('1');
	dict.insert(ci('2', idx++)); reverseDict.push_back('2');
	dict.insert(ci('3', idx++)); reverseDict.push_back('3');
	dict.insert(ci('4', idx++)); reverseDict.push_back('4');
	dict.insert(ci('5', idx++)); reverseDict.push_back('5');
	dict.insert(ci('6', idx++)); reverseDict.push_back('6');
	dict.insert(ci('7', idx++)); reverseDict.push_back('7');
	dict.insert(ci('8', idx++)); reverseDict.push_back('8');
	dict.insert(ci('9', idx++)); reverseDict.push_back('9');
	dict.insert(ci('0', idx++)); reverseDict.push_back('0');
	dict.insert(ci('-', idx++)); reverseDict.push_back('-');
	dict.insert(ci('=', idx++)); reverseDict.push_back('=');

	// Special Case, corner, on the left
	idx++; dict.insert(ci('Q', idx++)); reverseDict.push_back('Q'); reverseDict.push_back('Q');
	dict.insert(ci('W', idx++)); reverseDict.push_back('W');
	dict.insert(ci('E', idx++)); reverseDict.push_back('E');
	dict.insert(ci('R', idx++)); reverseDict.push_back('R');
	dict.insert(ci('T', idx++)); reverseDict.push_back('T');
	dict.insert(ci('Y', idx++)); reverseDict.push_back('Y');
	dict.insert(ci('U', idx++)); reverseDict.push_back('U');
	dict.insert(ci('I', idx++)); reverseDict.push_back('I');
	dict.insert(ci('O', idx++)); reverseDict.push_back('O');
	dict.insert(ci('P', idx++)); reverseDict.push_back('P');
	dict.insert(ci('[', idx++)); reverseDict.push_back('[');
	dict.insert(ci(']', idx++)); reverseDict.push_back(']');
	dict.insert(ci('\\', idx++)); reverseDict.push_back('\\');

	// Special Case, corner, on the left
	idx++; dict.insert(ci('A', idx++)); reverseDict.push_back('A'); reverseDict.push_back('A');
	dict.insert(ci('S', idx++)); reverseDict.push_back('S');
	dict.insert(ci('D', idx++)); reverseDict.push_back('D');
	dict.insert(ci('F', idx++)); reverseDict.push_back('F');
	dict.insert(ci('G', idx++)); reverseDict.push_back('G');
	dict.insert(ci('H', idx++)); reverseDict.push_back('H');
	dict.insert(ci('J', idx++)); reverseDict.push_back('J');
	dict.insert(ci('K', idx++)); reverseDict.push_back('K');
	dict.insert(ci('L', idx++)); reverseDict.push_back('L');
	dict.insert(ci(';', idx++)); reverseDict.push_back(';');
	dict.insert(ci('\'', idx++)); reverseDict.push_back('\'');

	// Special Case, corner, on the left
	idx++; dict.insert(ci('Z', idx++)); reverseDict.push_back('Z'); reverseDict.push_back('Z');
	dict.insert(ci('X', idx++)); reverseDict.push_back('X');
	dict.insert(ci('C', idx++)); reverseDict.push_back('C');
	dict.insert(ci('V', idx++)); reverseDict.push_back('V');
	dict.insert(ci('B', idx++)); reverseDict.push_back('B');
	dict.insert(ci('N', idx++)); reverseDict.push_back('N');
	dict.insert(ci('M', idx++)); reverseDict.push_back('M');
	dict.insert(ci(',', idx++)); reverseDict.push_back(',');
	dict.insert(ci('.', idx++)); reverseDict.push_back('.');
	dict.insert(ci('/', idx++)); reverseDict.push_back('/');

	string line;
	while (getline(cin,line)) {
		ostringstream oss;
		for (int i=0;i<line.length();i++){
			if (line[i] == ' ') oss << " ";
			else {
				int idx = -1;
				iter = dict.find(line[i]);
				if (iter != dict.end()) {
					idx = iter->second;
				}
				oss  << reverseDict[idx-1];
			}
		}
		cout << oss.str() << endl;
	}
	return 0;
}
