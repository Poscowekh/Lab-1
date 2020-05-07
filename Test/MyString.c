// MyString.c

#include "MyString.h"

void create_string(String* str, int size)
{
    if(size > 0)
    {
        str->allocated = size;
        str->capacity = 4;
        str->data = malloc(size);
        str->count = 0;
    }
    /*else
        printf("Size of string is less than 1");*/
}

void generate_string(String* str, int size)
{
    srand(time(NULL));
    create_string(str, size);
    for(size_t i = 0; i < size; i++)
    {
        char tmp = ' ' + (rand() % 95);
        fill_element(str, &tmp);
    }
}

void set_string(String* str, int size, char* element)
{
    create_string(str, size);
    for(size_t i = 0; i < size; i++)
        fill_element(str, element);
}

void reallocate_string(String* str, int reallocate)
{
    if(reallocate > 0)
    {
        void* tmp = malloc(reallocate);
        if(str->count != 0)
        {
            memcpy(tmp, str->data, str->count);
            free(str->data);
        }
        str->data = tmp;
        str->allocated = reallocate;
    }
    /*else
        printf("String reallocated to 0 bytes or less");*/
}

bool extend_check(String* str)
{
    if(str->allocated - str->count < str->capacity)
        return true;
    else
        return false;

}

void extend_string(String* str)
{
    reallocate_string(str, str->allocated + str->capacity);
}

bool cut_check(String* str)
{
    if(str->allocated - str->count > str->capacity)
        return true;
    else
        return false;

}

void cut_string(String* str)
{
    reallocate_string(str, str->count + str->capacity);
}

void fill_element(String* str, char* element)
{
    if(extend_check(str))
        extend_string(str);
    memcpy(str->data + str->count, element, 1);
    str->count++;
}

char* get_element(String *str, int position)
{
	return (char*)str->data + position;
}

void change_element(String *str, int position, char* element)
{
    extend_check(str);
    memcpy(str->data + position, element, 1);
}

void free_string(String *str)
{
	free(str->data);
	str->allocated = 0;
	str->count = 0;
	str->capacity = 0;
	free(str);
}

int get_size(String* str)
{
	return str->count;
}

void print_string(String* str)
{
    if(get_size(str) != 0)
    {
        char element;
        printf("\nIndex: ");
        for(size_t i = 0; i < str->count; i++)
        {
            printf("%d", i);
            printf(" ");
        };
        printf("\nValue: ");
        for(size_t i = 0; i < str->count; i++)
        {
            element = *get_element(str, i);
            printf("%c", element);
            printf(" ");
        }
        printf("\n");
    } else {
        printf("\nString has no elements!\n");
    }
}

void concate_strings(String* dest, String* string_1, String* string_2)
{
    if(string_1->count + string_2-> count + string_1->capacity < 65535)
    {
        if(dest->allocated < string_1->count + string_2->count + dest->capacity)
            reallocate_string(dest, string_1->count + string_2->count + dest->capacity);
        if(dest != string_1 && dest != string_2)
        {
            memcpy(dest->data + dest->count, string_1->data, string_1->count);
            dest->count = dest->count + string_1->count;
            memcpy(dest->data + dest->count, string_2->data, string_2->count);
            dest->count = dest->count + string_2->count;
        } else {
            if (dest == string_1)
            {
                memcpy(dest->data + dest->count, string_2->data, string_2->count);
                dest->count = dest->count + string_2->count;
            }
            else
            {
                memcpy(dest->data + dest->count, string_1->data, string_1->count);
                dest->count = string_1->count + string_2->count;
            }
        }
        if(cut_check(dest))
            cut_string(dest);
    }
    else
        printf("Strings are too long and cannot be concated");
}

void get_substring(String* str, int from, int to, String* dest)
{
    if(dest != str)
        create_string(dest, to - from + 1);
    memcpy(dest->data, str->data + from, to - from + 1);
    dest->count = to - from + 1;
    if(extend_check(dest))
        extend_string(dest);
}

void code_string(String* str, int key, String* dest)
{
    if(dest != str)
    {
        create_string(dest, str->count);
        for(size_t i = 0; i < str->count; i++)
        {
            char tmp = *get_element(str, i);
            tmp = encrypt_char(tmp, key);
            fill_element(dest, &tmp);
        }
    }
    else
    {
        String* tmp_string = malloc(sizeof(String));
        copy_string(str, tmp_string);
        for(size_t i = 0; i < tmp_string->count; i++)
        {
            char tmp = *get_element(tmp_string, i);
            tmp = encrypt_char(tmp, key);
            fill_element(tmp_string, &tmp);
        }
        create_string(dest, tmp_string->count);
        copy_string(tmp_string, dest);
    }
}

void decode_string(String* str, int key, String* dest)
{
    code_string(str, -key, dest);
}

char encrypt_char(char element, int key) //encrypts a symbol using key
{
    if(key > 0)
    {
        if(element + (key % 95) <= '~')
        {
            element = element + (key % 95);
            return element;
        }
        else
        {
            int tmp = '~' - element + 1;
            element = ' ' + (key % 95) - tmp;
            return element;
        }
    }
    else
    {
        if(element + (key % 95) >= ' ')
        {
            element = element + (key % 95);
            return element;
        }
        else
        {
            int tmp = element - ' ' + 1;
            element = '~' + (key % 95) + tmp;
            return element;
        }
    }
}

void copy_string(String* str, String* dest)
{
    create_string(dest, str->count);
    for(size_t i = 0; i < dest->count; i++)
    {
        char tmp = *get_element(str, i);
        fill_element(dest, &tmp);
    }
}
