// https://open.kattis.com/problems/mountainbiking

#include <bits/stdc++.h>
using namespace std;
#define MAX 4
#define PI acos(-1.0)

int n;
double g;
double speed[MAX];

double degToRad(double deg) {
	return (deg / 180.0) * PI;
}

int main() {
	cin >> n >> g;
	memset(speed, 0, sizeof(speed));
	for (int i = 0; i < n; i++) {
		double dist, deg;
		cin >> dist >> deg;
		double acc = g * cos(degToRad(deg));
		// The unknowns are t and finalSpeed;
		// dist = (initialSpeed + finalSpeed)/2.0 * t;
		// t = (finalSpeed - initialSpeed)/ acc;
		// Combine equations above:
		// dist = ((initial + final)/2.0) * ((final-initial)/acc)
		// dist = (final^2 - initial^2)/(2*acc)
		// dist * 2 * acc = final^2 - initial^2
		// final^2 = (2*dist*acc) + initial^2
		// final = sqrt((2*dist*acc) + initial^2)
		for (int j = 0; j <= i; j++) {
			double initial = speed[j];
			double finalSpeed = sqrt((2.0 * dist * acc) + (initial * initial));
			speed[j] = finalSpeed;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%.6f\n", speed[i]);
	}
	return 0;
}
