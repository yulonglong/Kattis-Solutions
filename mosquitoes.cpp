// https://open.kattis.com/problems/mosquitoes

#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 1e9
#define EPS 1e-7
#define PI acos(-1.0)

double DEG_to_RAD(double d) { return d*PI/180.0; }
double RAD_to_DEG(double r) { return r*180.0/PI; }

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
};

int insideCircle(point p, point c, double r) {
	double dx = p.x -c.x, dy = p.y - c.y;
	double Euc = dx * dx + dy*dy, rSq = r * r;
	return (rSq - Euc > -EPS) ? 1 : 0;
}

bool circle2PtsRad(point p1, point p2, double r, point &c) {
	double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
				(p1.y - p2.y) * (p1.y - p2.y);
	double det = r*r / d2 - 0.25;
	if (det<0.0) return false;
	double h = sqrt(det);
	c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) *h;
	c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) *h;
	return true;
}

int main() {
	int tc; scanf("%d",&tc);
	while (tc--){
		vector<point> mosquito;
		int n; double d;
		scanf("%d %lf",&n,&d);
		for(int z=0;z<n;z++){
			double a, b;
			scanf("%lf %lf",&a,&b);
			mosquito.push_back(point(a,b));
		}

		int maxAns = 1;

		for(int i=0;i<(int)mosquito.size();i++){
			for (int j=i+1;j<(int)mosquito.size();j++){
				point center1;
				point center2;
				bool valid1 = circle2PtsRad(mosquito[i],mosquito[j],d/2.0,center1);
				bool valid2 = circle2PtsRad(mosquito[j],mosquito[i],d/2.0,center2);
				int count1 = 0;
				int count2 = 0;
				for(int k=0;k<(int)mosquito.size();k++) {
					if (valid1 && insideCircle(mosquito[k],center1,d/2.0)) {
						count1++;
					}
					if (valid2 && insideCircle(mosquito[k],center2,d/2.0)) {
						count2++;
					}
				}
				maxAns = max(maxAns,count1);
				maxAns = max(maxAns,count2);
			}
		}
		printf("%d\n",maxAns);
	}
	// point p1;
	// point p2(0.0, -1.0);
	// point ans;
	// circle2PtsRad(p1,p2,2.0,ans);
	// printf("One of the center is (%.2lf, %.2lf)\n",ans.x, ans.y);
	// circle2PtsRad(p2,p1,2.0,ans);
	// printf("The other center is (%.2lf %.2lf)\n",ans.x,ans.y);
	return 0;
}
