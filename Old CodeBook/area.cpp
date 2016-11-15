#include <cmath>

double area2(double x0,double y0,double x1,double y1,double x2,double y2){
	return x0*y1 + x1*y2 + x2*y0 - x0*y2 - x1*y0 - x2*y1;
}

int equalf(double a,double b){
	double eps = 1e-9;
	return fabs(a-b) < eps;
}