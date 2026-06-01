#include"file2.c"
extern int x;
void display()
{
	printf("\n value of x=%d",x);
	x=x+10;
	printf("\n value of x=%d",x);
}