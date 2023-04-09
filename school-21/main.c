//
//  main.c
//  school-21
//
//  Created by Антон Чушъялов on 01.04.2023.
//

#include <stdio.h>
#include "s21_math.h"
#include "s21_string.h"
#include <math.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char str1[] = "Quaksasdasd\0"; // Array of size 100
    char str2[] = "abcz\0"; // Array of size 5

    int s = strspn(str1, "Qukas");
   
    printf("%d\n", s);

    return 0;
}
