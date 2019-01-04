// https://open.kattis.com/problems/parsinghex

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

void convertAllLower(string& str) {
	for (int i = 0; i < str.length(); i++) {
		str[i] = tolower(str[i]);
	}
}

ull convertHexToDec(string hex) {
	ull answer = 0;
	int exponent = 0;
	for (int i = hex.length() - 1; i >= 2; i--) {
		ull currValue = 0;
		if (isdigit(hex[i]))
			currValue = hex[i] - '0';
		else
			currValue = 10 + (hex[i] - 'a');
		// cout << currValue << "x16^" << exponent << endl;
		ull finalValue = pow(16, exponent) * currValue;
		exponent++;
		answer += finalValue;
	}
	return answer;
}

int main() {
	string line;
	string hex = "";
	string oriHex = "";
	while (getline(cin, line)) {
		hex = "";
		oriHex = "";
		string oriLine = line;
		convertAllLower(line);
		for (int i = 1; i < line.length(); i++) {
			if (hex.length() == 10) {
				cout << oriHex << " " << convertHexToDec(hex) << endl;
				hex = "";
				oriHex = "";
				continue;
			}
			if (hex.length() == 0 && line[i] == 'x' && line[i - 1] == '0') {
				hex = "0x";
				oriHex = oriLine[i-1];
				oriHex += oriLine[i];
			}
			else if (hex.length() > 0 && line[i] >= '0' && line[i] <= '9') {
				hex += line[i];
				oriHex += oriLine[i];
			}
			else if (hex.length() > 0 && line[i] >= 'a' && line[i] <= 'f') {
				hex += line[i];
				oriHex += oriLine[i];
			}
			else if (hex.length() > 0) {
				cout << oriHex << " " << convertHexToDec(hex) << endl;
				hex = "";
				oriHex = "";
			}
		}
		if (hex.length() > 0) {
			cout << oriHex << " " << convertHexToDec(hex) << endl;
			hex = "";
			oriHex = "";
		}
	}
	return 0;
}
