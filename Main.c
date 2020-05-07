// Main.c

#include "MyString.h"

int main()
{
    String* string_1 = (String*)malloc(sizeof(String));
    String* string_2 = (String*)malloc(sizeof(String));
    String* string_3 = (String*)malloc(sizeof(String));
    String* string_4 = (String*)malloc(sizeof(String));

    printf("FIRST STRING");                         //Some string
    generate_string(string_1, 6);
    print_string(string_1);

    printf("\nSECOND STRING");                      //Some string
    sleep(1);
    generate_string(string_2, 3);
    /*create_string(string_2, 2);
    char a = '~';
    char b = ' ';
    fill_element(string_2, &a);
    fill_element(string_2, &b);*/
    print_string(string_2);

    printf("\nCONCATENATION RESULT");
    concate_strings(string_3, string_2, string_1);  //Concates string_2 and string_1 to string_3
    print_string(string_3);

    printf("\nSUBSTRING FROM FIRST STRING");
    get_substring(string_1, 2, 4, string_4);        //Substring 2->4 from string_1 to string_4
    print_string(string_4);

    printf("\nRESULT OF CODING SECOND STRING");
    code_string(string_2, -100, string_3);          //Codes using key = -100
    print_string(string_3);

    printf("\nRESULT OF DECODING SECOND STRING");
    decode_string(string_3, -100, string_4);
    print_string(string_4);

    printf("\n");
	return 0;
}
