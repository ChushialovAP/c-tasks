#include "s21_string.h"
#include <stddef.h>
#include <stdlib.h>
// // memmove -  Сравнивает первые n байтов str1 и str2
// int memcmp(const void *str1, const void *str2, size_t n){
//  size_t i;
//  for ( i = 0; i != n; i++){

//  }

// }

// memmove - копирует n символов из src в dest
// dest — это указатель на целевой массив, в который следует скопировать содержимое
// src — это указатель на источник копируемых данных
// n — это количество копируемых байтов.
void *s21_memmove(void *dest, const void *src, size_t n) {
    char *pDest = (char *)dest;
    char *pSrc = (char *)src;

    char *tmp = (char *)malloc(n * sizeof(char));

    for(size_t i = 0; i < n; i++) {
        *(tmp + i) = *(pSrc + i);
    }
    for(size_t i = 0; i < n; i++) {
        *(pDest + i) = *(tmp + i);
    }
    free(tmp);
    return dest;
}
// memset - копирует символ c  в первые n символов строки, на которую указывает аргумент str.
// str — это указатель на блок памяти для заполнения.
// c — это значение, которое нужно установить. Значение передается как int,
// но функция заполняет блок памяти, используя беззнаковое преобразование этого значения в char.
// n — это количество байтов, которое должно быть установлено в значение.
// Эта функция возвращает указатель на область памяти str.
void *s21_memset(void *str, int c, size_t n) {
    char *pStr = (char*)str;

    for (size_t i = 0; i != n; i++){
        *(pStr + i) = (char) c;
    }
    return str;
}

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, size_t n) {
    char *pStr = (char*)str;
    void *res = NULL;

    for (int i = 0; i < n; i++) {
        if (*(pStr + i) == (char)c) {
            res = pStr + i;
            break;
        }
    }

    return res;
}

// Сравнивает первые n байтов str1 и str2.
int s21_memcmp(const void *str1, const void *str2, size_t n) {
    char *pStr1 = (char*)str1;
    char *pStr2 = (char*)str2;
    int res = 0;

    for (int i = 0; i < n; i++) {
        if (*(pStr1) != *(pStr2)) {
            res = *(pStr1) - *(pStr2);
        }
        pStr1++;
        pStr2++;
    }

    return res;
}

// Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, size_t n) {
    char *pDest = (char *)dest;
    char *pSrc = (char *)src;

    for(size_t i = 0; i < n; i++) {
        *(pDest + i) = *(pSrc + i);
    }
    return dest;
}

// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest.
char *s21_strcat(char *dest, const char *src) {
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';

    return dest;
}

// Добавляет строку, на которую указывает src, в конец строки, на которую указывает dest, длиной до n символов.
char *s21_strncat(char *dest, const char *src, size_t n) {
    while (*dest != '\0') {
        dest++;
    }

    while (*src != '\0' && n-- > 0) {
        *dest++ = *src++;
    }
    *dest = '\0';

    return dest;
}

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
char *s21_strchr(const char *str, int c) {
    char *pStr = (char *)str;
    void *res = NULL;

    while (*pStr != '\0'){
        if (*pStr == (char)c) {
            res = pStr;
            break;
        }
        pStr++;
    }

    return res;
}

// Сравнивает строку, на которую указывает str1, со строкой, на которую указывает str2.
int s21_strcmp(const char *str1, const char *str2) {
    int res = 1;

    while (*str1 == *str2) {
        if (*str1 == '\0') {
            res = 0;
            break;
        }
        str1++;
        str2++;
    }

    if (res != 0) {
        res = *str1 - *str2;
    }

    return res;
}

// Сравнивает не более первых n байтов str1 и str2.
int s21_strncmp(const char *str1, const char *str2, size_t n) {
    int res = 1;

    while (*str1 == *str2 && n-- > 0) {
        if (*str1 == '\0') {
            res = 0;
            break;
        }
        str1++;
        str2++;
    }

    if (res != 0) {
        res = *str1 - *str2;
    }

    return res;
}

// Копирует строку, на которую указывает src, в dest.
char *s21_strcpy(char *dest, const char *src) {
    //while (*(pDest++) = *(src++));
    while (*(src) != '\0') {
        *(dest++) = *(src++);
    }

    *dest = '\0';

    return dest;
}

// Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, size_t n) {
    while (*(src) != '\0' && n-- > 0) {
        *(dest++) = *(src++);
    }

    *dest = '\0';

    return dest;
}

// Вычисляет длину начального сегмента str1, который полностью состоит из символов, не входящих в str2.
size_t s21_strcspn(const char *str1, const char *str2) {
    size_t res = 0;

    while(*str1 != '\0' && !s21_strchr(str2, *(str1 + res))) res++;

    return res;
}

// Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает указатель на строку с сообщением об ошибке. 
// Нужно объявить макросы, содержащие массивы сообщений об ошибке для операционных систем mac и linux. 
// Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС осуществляется с помощью директив.
// char *strerror(int errnum) {
    
// }

// Вычисляет длину строки str, не включая завершающий нулевой символ.
size_t s21_strlen(const char *str) {
    size_t res = 0;

    while(*(str + res) != '\0') res++;

    return res;
}

// Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2) {
    char * res = NULL;

    while (*(str2) != '\0') {
        res = s21_strchr(str1, *str2);
        if (res) {
            break;
        }
        str2++;
    }

    return res;
}

// Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
char *s21_strrchr(const char *str, int c) {
    int len = s21_strlen(str);
    char *pStr = (char *)(str + len);
    void *res = NULL;

    while (len-- >= 0){
        if (*pStr == (char)c) {
            res = pStr;
            break;
        }
        pStr--;
    }

    return res;
}

// Вычисляет длину начального сегмента str1, который полностью состоит из символов str2.
size_t s21_strspn(const char *str1, const char *str2) {
    size_t res = 0;

    while(*str1 != '\0' && s21_strchr(str2, *(str1 + res))) res++;

    return res;
}