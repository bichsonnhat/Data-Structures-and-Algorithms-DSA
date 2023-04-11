#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point{
	float x, y;
};

double sqr(int u){
	return u * u;
}

double getDistance(Point u, Point v){
	return sqrt(sqr(u.x - v.x) + sqr(u.y - v.y));
}

int search(vector <Point> a, int n, Point p){
	double dis = 99999999999;
	int ret = 0;
	for (int i = 0; i < n; ++i){
		double cur_dis = getDistance(a[i], p);
		if (cur_dis < dis){
			dis = cur_dis;
			ret = i;
		}
	}
	return ret + 1;
}

int main(){
    int n; cin >> n;
    vector <Point> a(n);
    Point p;
    cin >> p.x >> p.y;
    for (int i = 0; i < n; ++i){
    	cin >> a[i].x >> a[i].y;
    }
    cout << search(a, n, p);
    return 0;
}