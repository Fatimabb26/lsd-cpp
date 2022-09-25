#include <stdio.h>
#include <stdlib.h>



////Prototypes

void check_msb(int n);
void print_bits(unsigned char c);
void print_nth_byte ( int n , int m) ;







///Exercice 1
void check_msb(int n)
{
	int c == n >> 31;
	if (c==0)
		printf(" msb is not a set");
	else 
		printf(" msb is a set");



}


///Exercice 2

void print_bits(unsigned char s)
{
	for(int i = 0 ; i < 8; i++)
	{
		if((s >> 8-i-1) & 1 == 1)
			printf("1");
		else 
			printf("0");
			
	}
	printf("\n");   
	return ;
	
}

// Exercice 4

void print_nth_byte(int n , int m)
{
	int d = m*8;
	for(int j =0; j < 8; j++)
	{
		if(((n>>d-j-1)&1) ==1)
			printf("1");
		else 
			printf("0");
	}
	printf("\n");
	return;
}






