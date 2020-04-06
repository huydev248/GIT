#include <stdio.h>
#include <stdlib.h>

int main()
{
	char color[20];
	char PluralNoun[20];
	char celebrityF[20];
	char celebrityL[20];
	
	printf("Enter a color: ", color);
	scanf("%s", color);
	printf("Enter a PluralNoun: ", PluralNoun);
	scanf("%s", PluralNoun);
	printf("Enter a celebrity: ", celebrityF, celebrityL);
	scanf("%s%s", celebrityF, celebrityL);
	
	printf("Rose are %s\n", color);
	printf("%s are blue\n", PluralNoun);
	printf("I love %s %s\n", celebrityF, celebrityL);
	
	return 0;
}