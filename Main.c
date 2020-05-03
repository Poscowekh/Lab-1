// Main.c

#include "MyString.h"

int main()
{
	String *str1 = (String*)malloc(sizeof(String));
	String *str2 = (String*)malloc(sizeof(String));
	String *str3 = (String*)malloc(sizeof(String));
	printf("FIRST STRING\n");
	Initialise_String(str1);
	printf("SECOND STRING\n");
	Initialise_String(str2);
	Concate_Strings(str1, str1, str2);
	Get_Substring(str1, 2, 5, str3);
	//Code_String(str1, 2);
	Print_String(str1);
	Print_String(str2);
	Print_String(str3);
	//memory_data(str1);
	//memory_data(str2);
	getchar();
	return 0;
}
