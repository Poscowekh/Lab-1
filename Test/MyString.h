// MyString.h

#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>
#include <time.h>

typedef struct
{
	int count;
	int allocated;
	int capacity;
	void* data;
} String;

//Closed Functionality
void create_string(String*, int);
void reallocate_string(String*, int);
bool extend_check(String*);
void extend_string(String*);
bool cut_check(String*);
void cut_string(String*);
void free_string(String*);
char encrypt_char(char, int);

//Open Functionality
void create_string(String*, int);
void generate_string(String*, int);
void set_string(String*, int, char*);
void copy_string(String*, String*);
void fill_element(String*, char*);
void change_element(String*, int, char*);
char* get_element(String*, int);
int get_size(String*);

void print_string(String*);
void concate_strings(String*, String*, String*);
void get_substring(String*, int, int, String*);
void code_string(String*, int, String*);
void decode_string(String*, int, String*);

#endif // MYSTRING_H
