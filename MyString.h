// MyString.h

#ifndef MYSTRING_H
#define MYSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <stdbool.h>

typedef struct 
{
	int count;
	int allocated;
	int capacity;
	void* data;
} String;

//Closed Functionality
void Create_String(String*, int);
void Reallocate_String(String*, int);
void Extend_String(String*);
void Cut_String(String*, int);
void Free_String(String*);
void Cut_Check(String*);

//Open Functionality
void Initialise_String(String*);
void Fill_Element(String*, char*);
char* Get_Element(String*, int);
void Put_Element(String*, int, char*);
int Get_Size(String*);
void Print_String(String*);
void Memory_Data(String*);
bool Concate_Strings(String*, String*, String*);
void Get_Substring(String*, int, int, String*);
void Code_String(String*, int);
void Decode_String(String*, int);
	
#endif // MYSTRING_H
