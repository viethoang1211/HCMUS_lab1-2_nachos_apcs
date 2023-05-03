#include "syscall.h"

int main()
{
	int i;	
	for(i =0; i< 100000; i++)
	{
		Write("B",2,1);   
	}
}