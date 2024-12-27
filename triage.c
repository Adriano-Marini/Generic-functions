#include "library.h"

int main(){
	int tab[10]={12,11,2,3,5,7,8,6,9,7};
	for(int i=0; i<10;i++)
		printf("tab[%i]: %i\n", i, tab[i]);
	generic_tri(tab, 10, sizeof(int), &equals_int);
	printf("After the triage\n");
	for(int i=0; i<10;i++)
		printf("tab[%i]: %i\n", i, tab[i]);

	return 0;
}
