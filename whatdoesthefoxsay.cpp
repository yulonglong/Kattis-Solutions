// https://open.kattis.com/problems/whatdoesthefoxsay

#include <bits/stdc++.h>
using namespace std;

int main() {
	string line;
	getline(cin, line);
	int n = atoi(line.c_str());
	int count = 0;
	vector<string> foxVoices;
	set<string> animalVoices;
	string originalVoices;

	while (getline(cin, line)) {
		if (count == 0) {
			originalVoices = line;
			foxVoices.clear();
			animalVoices.clear();
			count++;
			continue;
		}

		if (line == "what does the fox say?") {
			istringstream istream(originalVoices);
			string tempVoice;
			while (istream >> tempVoice)
			{
				if (animalVoices.find(tempVoice) == animalVoices.end())
				{
					foxVoices.push_back(tempVoice);
				}
			}
			cout << foxVoices[0];
			for (int i = 1; i < foxVoices.size(); i++) {
				cout << " " << foxVoices[i];
			}
			cout << endl;
			count = 0;
			continue;
		}
		else {
			istringstream istream(line);
			string singleSound;
			istream >> singleSound;
			istream >> singleSound;
			istream >> singleSound;
			animalVoices.insert(singleSound);
			count++;
		}
	}

	return 0;
}
