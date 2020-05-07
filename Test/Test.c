#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <memory.h>
#include "MyString.h"
#include "Test.h"

void generate_function(size_t pos, int* val)
{
    *val = pos*pos;
}

size_t get_random_size()
{
    srand(time(NULL));
    return abs(100 + rand() % 10000);
}

Check test_create_string()
{
    String* string = malloc(sizeof(String));
    create_string(string, 0);
    if(string->allocated != 0)
        return ERROR;
    for(size_t i = 0; i < 5; i++)
    {
        size_t n = get_random_size();
        create_string(string, n);
        if(string->allocated != n)
            return ERROR;
    }
    free_string(string);
    return NO_ERROR;
}

Check test_reallocate_string()
{
    String* string = malloc(sizeof(String));
    size_t n = get_random_size();
    generate_string(string, n/2);
    reallocate_string(string, n);
    if(string->allocated != n)
        return ERROR;
    free_string(string);
    return NO_ERROR;
}

Check test_fill_get_change_string()
{
    String* string = malloc(sizeof(String));
    char a = 'A';
    int n = get_random_size();
    create_string(string, n);
    for(size_t i = 0; i < n; i++)
        fill_element(string, &a);
    if(string->count != n)
        return ERROR;
    for(size_t i = 0; i < n; i++)
        if(*get_element(string, i) != 'A')
            return ERROR;
    free_string(string);
    return NO_ERROR;
}

Check test_generate_string()
{
    String* string = malloc(sizeof(String));
    for(size_t i = 0; i < 10; i++)
    {
        size_t n = get_random_size();
        generate_string(string, n);
        if(string->count != n)
            return ERROR;
        for(size_t i = 0; i < n; i++)
            if(*get_element(string, i) > '~' || *get_element(string, i) < ' ')
                return ERROR;
    }
    free_string(string);
    return NO_ERROR;
}

Check test_fill_get_element()
{
    String* string = malloc(sizeof(String));
    size_t n = get_random_size();
    create_string(string, 95);
    for(size_t i = 0; i < 95; ++i){
        char tmp = ' ' + i;
        fill_element(string, &tmp);
    }
    for(size_t i = 0; i < 95; ++i){
        char tmp = ' ' + i;
        if(*get_element(string, i) != tmp)
            return ERROR;
    }
    free_string(string);
    return NO_ERROR;
}

Check test_set_string()
{
    String* string = malloc(sizeof(String));
    size_t n = get_random_size();
    char a = 'a';
    set_string(string, n, &a);
    if(string->count != n)
        return ERROR;
    for(size_t i = 0; i < n; i++)
        if(*get_element(string, i) != a)
            return ERROR;
    free_string(string);
    return NO_ERROR;
}

Check test_concate_strings()
{
    String* str1 = malloc(sizeof(String));
    size_t n = get_random_size();
    create_string(str1, n);
    String* str2 = malloc(sizeof(String));
    size_t k = get_random_size();
    create_string(str2, k);
    char a = 'a';
    char b = 'b';;
    set_string(str1, n, &a);
    set_string(str2, k, &b);
    concate_strings(str1, str2, str1);
    if(str1->count != n + k)
        return ERROR;
    for(size_t i = 0; i < n; ++i)
        if(*get_element(str1, i) != a)
            return ERROR;
    for(size_t i = n; i < n + k; ++i)
        if(*get_element(str1, i) != b)
            return ERROR;
    free_string(str1);
    free_string(str2);
    return NO_ERROR;
}

Check test_get_substring()
{
    String* str1 = malloc(sizeof(String));
    String* str2 = malloc(sizeof(String));
    for(size_t i = 0; i < 4; i++)
    {
        int n = get_random_size();
        srand(time(NULL));
        int from = rand() % n/2;
        int to = rand() % n/2 + n/2;
        generate_string(str1, n);
        get_substring(str1, from, to, str2);
        if(str2->count != to - from + 1)
            return ERROR;
        for(size_t j = from; j <= to; j++)
            if(*get_element(str2, j - from) != *get_element(str1, j))
                return ERROR;
    }
    return NO_ERROR;
}

Check test_code_decode_string()
{
    String* str1 = malloc(sizeof(String));
    String* str2 = malloc(sizeof(String));
    String* str3 = malloc(sizeof(String));
    int n = get_random_size();
    generate_string(str1, n);
    create_string(str2, str1->count);
    srand(time(NULL));
    int key = rand() % 1500 + 100;
    code_string(str1, key, str2);
    create_string(str3, str2->count);
    decode_string(str2, key, str3);
    if(str3->count != str1->count)
        return ERROR;
    for(size_t i = 0; i < n; i++)
        if(*get_element(str1, i) != *get_element(str3, i))
            return ERROR;
    return NO_ERROR;
}


int main()
{
    int errors = 0;
    Check result;

    printf("Test Create String: ");
    result = test_create_string();
    if(result == ERROR){
        errors ++;
        printf("ERROR");
    }
    else
    {
        printf("NO_ERROR");
    }
    printf("\n");

    printf("Test Reallocate String: ");
    result = test_reallocate_string();
    if(result == ERROR){
        errors ++;
        printf("ERROR");
    }
    else
    {
        printf("NO_ERROR");
    }
    printf("\n");

    printf("Test Fill Get Change String: ");
    result = test_fill_get_change_string();
    if(result == ERROR){
        errors ++;
        printf("ERROR");
    }
    else
    {
        printf("NO_ERROR");
    }
    printf("\n");

    printf("Test Fill Get Element: ");
    result = test_fill_get_element();
    if(result == ERROR){
        errors ++;
        printf("ERROR");
    }
    else
    {
        printf("NO_ERROR");
    }
    printf("\n");

    printf("Test Set String: ");
    result = test_set_string();
    if(result == ERROR){
        errors ++;
        printf("ERROR");
    }
    else
    {
        printf("NO_ERROR");
    }
    printf("\n");

    printf("Test Generate String: ");
    result = test_generate_string();
    if(result == ERROR){
        errors ++;
        printf("ERROR");
    }
    else
    {
        printf("NO_ERROR");
    }
    printf("\n");

    printf("Test Get Substring: ");
    result = test_get_substring();
    if(result == ERROR){
        errors ++;
        printf("ERROR");
    }
    else
    {
        printf("NO_ERROR");
    }
    printf("\n");

    printf("Test Concate Strings: ");
    result = test_concate_strings();
    if(result == ERROR){
        errors ++;
        printf("ERROR");
    }
    else
    {
        printf("NO_ERROR");
    }
    printf("\n");

    printf("Test Code Decode String: ");
    result = test_code_decode_string();
    if(result == ERROR){
        errors ++;
        printf("ERROR");
    }
    else
    {
        printf("NO_ERROR");
    }
    printf("\n");

    printf("%d", errors);
    printf(" errors\n");
    if(errors == 0)
        printf("Tests successful\n");
    return 0;
}

