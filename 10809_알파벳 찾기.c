#include <stdio.h>

int main(void) {

	int i;
	char num; 
	int ch[100] = { 0, }; 

	while (1)
	{

		scanf(" %c", &num); 
		if (num < 'a' || num > 'z') break; 
		ch[num - 'a']++;
	}

	
	for (i = 0; i <= 26; i++) {
		if (ch[i] > num) {
			printf("%c", ch[i]);
		}

			printf("%c\n", 'a' + i);
	}
	return 0;
