//
//  s21_math.c
//  school-21
//
//  Created by Антон Чушъялов on 01.04.2023.
//

#include "s21_math.h"
#include <stdio.h>

#define precision 0.0000001

#define S21_PI ((double)3.14159265358979323846)

int s21_abs(int x) {
    if (x >= 0) {
        return x;
    }
    return x * (-1);
}
long double factorial(int x) {
    if (x == 1) {
        return 1;
    }

    return x * factorial(x - 1);
}

//long double s21_acos(double x) {
//
//}
//
long double s21_asin(double x) {
    double result = 0;
    double it = 1;
    double term = 1;
    double pred_term = 1;
    
    while (term > precision) {
        result += term;
        pred_term *= (it / (it + 1));
        it+=2;
        term = pred_term * s21_pow(x, it) / it;
    }
    
    return result;
}

long double s21_atan(double x) {
    double result = 0;
    double it = 1;
    long double fact = 1;
    long double term = x;
    int sd = 1;
    
    while (s21_fabs(term) > precision) {
        result += term * sd;
        it += 2;
        fact = factorial(it);
        term = s21_pow(x, it) / fact;
        sd *= -1;
    }
    
    return result;
}

long double s21_ceil(double x) {
    int a = (int)x;
    return a + 1;
}


long double s21_cos(double x) {
    double result = 0;
    double it = 0;
    long double fact = 1;
    long double term = 1;
    int sd = 1;
    
    while (s21_fabs(term) > precision) {
        result += term * sd;
        it += 2.0;
        fact = factorial(it);
        term = s21_pow(x, it) / fact;
        sd *= -1;
    }
    
    return result;
}
long double s21_exp(double x) {
    double result = 0;
    double it = 1;
    double fact = 1;
    double term = 1;
    
    while (term > precision) {
        result += term;
        term = s21_pow(x, it) / fact;
        it++;
        fact *= it;
    }
    
    return result;
}
long double s21_fabs(double x) {
    if (x >= 0) {
        return x;
    }
    return x * (-1);
}
long double s21_floor(double x) {
    int a = (int)x;
    return a;
}
long double s21_fmod(double x, double y) {
    return x - y * s21_floor(x / y);
}
long double s21_log(double x) {
    double yn = 2; // random
    double yn1 = yn;
    
    do {
        yn = yn1;
        yn1 = yn + 2 * ((x - s21_exp(yn)) / (x + s21_exp(yn)));
    } while (s21_fabs(yn - yn1) > precision);
    
    return yn;
}
long double s21_pow(double x, double y) {
    double result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}
long double s21_sin(double x) {
    double result = 0;
    double it = 1;
    long double fact = 1;
    long double term = x;
    int sd = 1;
    
    while (s21_fabs(term) >= precision) {
        result += term * sd;
        it += 2;
        fact = factorial(it);
        term = s21_pow(x, it) / fact;
        sd *= -1;
    }
    
    return result;
}
long double s21_sqrt(double x) {
    double xn = 2; // random
    double xn1 = xn;
    
    do {
        xn = xn1;
        xn1 = xn - (s21_pow(xn, 2) - x) / (2 * xn);
    } while (s21_fabs(xn - xn1) > precision);
    
    return xn;
}
long double s21_tan(double x) {
    return s21_sin(x) / s21_cos(x);
}
