#include <bits/stdc++.h>
using namespace std;

map<string,double> tz;

void init() {
	tz["UTC"] = 0;
	tz["GMT"] = 0;
	tz["BST"] = 1;
	tz["IST"] = 1;
	tz["WET"] = 0;
	tz["WEST"] = 1;
	tz["CET"] = 1;
	tz["CEST"] = 2;
	tz["EET"] = 2;
	tz["EEST"] = 3;
	tz["MSK"] = 3;
	tz["MSD"] = 4;
	tz["AST"] = -4;
	tz["ADT"] = -3;
	tz["NST"] = -3.5;
	tz["NDT"] = -2.5;
	tz["EST"] = -5;
	tz["EDT"] = -4;
	tz["CST"] = -6;
	tz["CDT"] = -5;
	tz["MST"] = -7;
	tz["MDT"] = -6;
	tz["PST"] = -8;
	tz["PDT"] = -7;
	tz["HST"] = -10;
	tz["AKST"] = -9;
	tz["AKDT"] = -8;
	tz["AEST"] = 10;
	tz["AEDT"] = 11;
	tz["ACST"] = 9.5;
	tz["ACDT"] = 10.5;
	tz["AWST"] = 8;
}

string convertTime(string t, string ampm, string from, string to) {
	int minutes = 0;
	if (t == "noon") minutes = 12*60;
	else if (t == "midnight") minutes = 0;
	else {
		istringstream istream(t);
		string first;
		getline(istream, first, ':');
		string second;
		getline(istream, second);
		// cout << first << " : " << second << endl;
		int currHours = atoi(first.c_str());
		int currMinutes = atoi(second.c_str());
		minutes = currHours*60 + currMinutes;
		if (currHours == 12 && ampm == "a.m.") {
			minutes = currMinutes;
		}
		else if (currHours < 12 && ampm == "p.m.") {
			minutes += 12*60;
		}
	}
	int tzDiff = (tz[to] - tz[from]) * 60.0;
	// cout << tzDiff << endl;
	minutes += tzDiff;
	minutes = (minutes + 24*60) % (24*60);

	if (minutes == 0) return "midnight\n";
	else if (minutes == 12*60) return "noon\n";
	else {
		int currHours = minutes / 60;
		int currMinutes = minutes % 60;
		// cout << currHours << ":" << currMinutes << endl;
		// if 12 am
		if (currHours == 0) {
			currHours = 12;
			ampm = "a.m.";
		}
		else if (currHours < 12) {
			ampm = "a.m.";
		}
		else if (currHours == 12) {
			ampm = "p.m.";
		}
		else {
			currHours -= 12;
			ampm = "p.m.";
		}
		ostringstream ostream;
		if (currMinutes >= 10) {
			ostream << currHours << ":" << currMinutes << " " << ampm << endl;
		}
		else {
			ostream << currHours << ":0" << currMinutes << " " << ampm << endl;
		}
		return ostream.str();
	}

}

int main() {
	init();
	int n; cin >> n;
	while (n--) {
		string t; cin >> t;
		string ampm = "a.m.";
		if (t != "noon" && t != "midnight") 
			cin >> ampm;
		string from, to; cin >> from >> to;
		cout << convertTime(t,ampm,from,to);
	}

	return 0;
}