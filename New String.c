#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct string
{
	int allocated;
	int count;
	int capacity;
	void *data;
} string;
void create_string(string *str, int allocate)
{
	if (allocate > 0)
	{
		str->allocated = allocate;
		str->capacity = 4;
		str->data = malloc(sizeof(allocate + 4));
		str->count = 0;
		printf("DEBUG: String created\n");
	}
	else
		printf("\nERROR: Bad memory allocation");
}
void reallocate_string(string* str, int reallocate)
{
	if (reallocate > 0)
	{
		void* tmp = malloc(reallocate);
		memcpy(tmp, str->data, str->count);
		free(str->data);
		str->data = tmp;
		str->allocated = reallocate;
		free(tmp);
		printf("DEBUG: String reallocated\n");
	}
	else
		printf("|ERROR: Bad memory reallocation");
}
void extend_string(string* str)
{
	reallocate_string(str, str->allocated + str->capacity);
	printf("DEBUG: String extended\n");
}
void cut_string(string* str)
{
	reallocate_string(str, str->allocated-1);
	printf("DEBUG: String cut\n");
}
void fill_string(string *str, char* new_element)
{
	if (str->allocated - str->count < 5)
		extend_string(str);
	memcpy(str->data + str->count, new_element, 1);
	str->count++;
	printf("DEBUG: Character filled in\n");
}
char* show_char(string *str, int position)
{
	return (char*)str->data + position;
}
void free_string(string *str)
{
	free(str->data);
	str->allocated = 0;
	str->count = 0;
	str->capacity = 0;
	free(str);
	printf("---String deleted---\n");
}
void swap_strings(string* a, string* b)
{
	string* tmp = a;
	a = b;
	b = tmp;
}
void initialise_string(string* str)
{
	int size, i;
	char element;
	char* p_element = &element;
	while (size <= 0)
	{
		printf("Enter size:  ");
		scanf("%d", &size);
		if (size <= 0)
			printf("ERROR: String can't have this size, try again\n");
	}
	create_string(str, size);
	printf("Enter element(s):\n");
	fflush(stdin);
	for(i=0; i<size; i++)
	{
		printf("%d", i+1); printf(":\t"); fflush(stdin);
		element = (char)getchar();
		fill_string(str, p_element);
	}
	getchar();
}
void write_string(string* str)
{
	int i;
	char element;
	char* p_element = &element;
	printf("\nCharacters entered:\n");
	for(i=0; i<str->count; i++)
	{
		p_element = show_char(str, i);
		printf("%c ", *p_element);
		fflush(stdin);
	}
	getchar();
}
void memory_data(string* str)
{
	printf("\nStructure size:  "); printf("%d", sizeof(*str) + str->count); printf(" byte(s)");
	printf("\nString size:     "); printf("%d", str->count); printf(" byte(s)");
	printf("\nOther size:      "); printf("%d", sizeof(str->count) + sizeof(str->allocated) + sizeof(str->capacity)); printf(" byte(s)");
	printf("\nMemory allocated:  "); printf("%d", str->allocated); printf(" byte(s)");
	getchar();
}

int main()
{
	string *str1 = (string*)malloc(sizeof(string));
	string *str2 = (string*)malloc(sizeof(string));
	printf("FIRST STRING\n");
	initialise_string(str1);
	write_string(str1);
	memory_data(str1);
	//printf("SECOND STRING");
	getchar();
	return 0;
}
