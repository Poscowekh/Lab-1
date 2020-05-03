// MyString.c

#include "MyString.h"

void Create_String(String *str, int allocate)
{
	if (allocate > 0)
	{
		str->allocated = allocate;
		str->capacity = 4;
		str->data = malloc(sizeof(allocate + 4));
		str->count = 0;
	}
};
void Reallocate_String(String* str, int reallocate)
{
	if (reallocate > 0)
	{
		void* tmp = malloc(reallocate);
		memcpy(tmp, str->data, str->count);
		free(str->data);
		str->data = tmp;
		str->allocated = reallocate;
		free(tmp);
	}
};
void Extend_String(String* str)
{
	Reallocate_String(str, str->allocated + str->capacity);
}
void Cut_String(String* str, int size)
{
	Reallocate_String(str, str->allocated-size);
}
void Cut_Check(String* str)
{
	int size = str->allocated - str->count;
	if(size < 5)
		Cut_String(str, size);
}
void Fill_Element(String *str, char* new_element)
{
	Cut_Check(str);
	memcpy(str->data + str->count, new_element, 1);
	str->count++;
}
char* Get_Element(String *str, int position)
{
	return (char*)str->data + position;
}
void Put_Element(String *str, int position, char* element)
{
	 memcpy(str->data + position, element, 1);
}
void Free_String(String *str)
{
	free(str->data);
	str->allocated = 0;
	str->count = 0;
	str->capacity = 0;
	free(str);
}
int Get_Size(String* str)
{
	return str->count;
}
void Initialise_String(String* str)
{
	int size = 4;
	unsigned i;
	char element;
	Create_String(str, size);
	printf("Enter element(s):\n");
	for(i=0; i<size; i++)
	{
		printf("%d", i+1); 
		printf(": ");
		element = (char)getchar();
		fflush(stdin);
		Fill_Element(str, &element);
	};
}
void Print_String(String* str)
{
	unsigned i;
	char element;
	printf("String:\n");
	printf("Index: ");
	for(i=0; i<str->count; i++)
	{
		printf("%d", i);
		printf("  ");
	};
	printf("\nValue: ");
	for(i=0; i<str->count; i++)
	{
		element = *Get_Element(str, i);
		printf("%c", element);
		printf("  ");
	}
	printf("\n");
}
void Memory_Data(String* str)
{
	printf("\nStructure size:  "); printf("%d", sizeof(*str) + str->count); printf(" byte(s)");
	printf("\nString size:     "); printf("%d", str->count); printf(" byte(s)");
	printf("\nOther size:      "); printf("%d", sizeof(str->count) + sizeof(str->allocated) + sizeof(str->capacity)); printf(" byte(s)");
	printf("\nMemory allocated:  "); printf("%d", str->allocated); printf(" byte(s)");
}
bool Concate_Strings(String* dest, String* str1, String* str2)
{
	if(dest->allocated <= str1->count + str2->count)
		Reallocate_String(dest, str1->count + str2->count + dest->capacity);
	if (dest == str1)
	{
		memcpy(dest->data + dest->count, str2->data, str2->count);
		dest->count = str1->count + str2->count;
		Cut_Check(dest);
		return true;
	}
	else
	{
		memcpy(dest->data + dest->count, str1->data, str1->count);
		dest->count = str1->count + str2->count;
		Cut_Check(dest);
		return true;
	}
	Reallocate_String(dest, dest->count + str1->count + str2->count);
	memcpy(dest->data + dest->count, str1->data, str1->count);
	dest->count = dest->count + str1->count;
	memcpy(dest->data + dest->count, str2->data, str2->count);
	dest->count = dest->count + str2->count;
	Cut_Check(dest);
	return true;
}
void Get_Substring(String* str, int from, int to, String* dest)
{
	Free_String(dest);
	Create_String(dest, to - from + 1);
	memcpy(dest->data, str->data + from - 1, to - from + 1);
	dest->count = to - from + 1;
}
void Code_String(String* str, int value)
{
	unsigned i,j;
	char* tmp_char;
	for(i=0; i<str->count; i++)
	{
		tmp_char = Get_Element(str, i);
		for(j=0; j<value; j++)
		{
			if((*tmp_char) = '~')
				(*tmp_char) = ' ';
			(*tmp_char)++;
		};
		Put_Element(str, i, tmp_char);
	}
}
void Decode_String(String* str, int value)
{
	//Code_String(str, -value);
};
