//
//  main.c
//  school-21
//
//  Created by Антон Чушъялов on 01.04.2023.
//

#include <stdio.h>
#include "s21_math.h"
#include <math.h>

int main(int argc, const char * argv[]) {
    printf("%Lf\n", s21_sin(90 * M_PI / 180));
    printf("%f\n", sin(90 * M_PI / 180));
   
    return 0;
}
