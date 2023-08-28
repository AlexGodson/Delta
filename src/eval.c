#include <stdio.h>
#include <math.h>

#include "../include/eval.h"

double _add(double a, double b) {
	return a + b;
}

double _sub(double a, double b) {
	return a - b;
}

double _mul(double a, double b) {
	return a * b;
}

double _div(double a, double b) {
	return b / a;
}

double _mod(double a, double b) {
	return modf(a, &b);
}

double _pow(double a, double b) {
	return pow(a, b);
}
