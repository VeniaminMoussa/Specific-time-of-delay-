#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define SIZE 5
#define SEC 2
void delay_sec1(int sec);
void delay_sec2(double sec);
void count1_to(int x);
void count2_to(int x);
void count3_to(int x);
int main(void)
{
	int i, n=1;

	srand(time(NULL));

	while(n)
	{
		printf("Select a way of counting between [1,3] or 0 for exit: ");
		scanf("%d",&n);

		while((n<0)||(n>4))
		{
			printf("Try again between [1,3] or 0 for exit: ");
			scanf("%d",&n);
		}

		switch(n)
		{
			case 1:
			{
				system("clear");

				printf("Counting to %d with %d seconds delay: ",SIZE, SEC);

				count1_to(SIZE);
			}
			break;
			case 2:
			{
				system("clear");

				printf("Counting to %d with %d seconds delay: ",SIZE, SEC);

				count2_to(SIZE);
			}
			break;
			case 3:
			{
				system("clear");

				printf("Counting to %d with %d seconds delay: ",SIZE, SEC);

				count3_to(SIZE);
			}
			break;
		}
	}

	printf("Exited programm.\n");

	return 0;
}
void delay_sec1(int  sec)//Chosing only in second as 2 sec 
{
	double a=time(NULL);
	
	while((time(NULL)-a)<sec)
	{
		printf("%c",'\0');
	}
}
void delay_sec2(double sec)//Chosing even in nanosecond as 0.2 sec 
{
	double a=time(NULL), b;
	
	sec*=35;

	for(b=time(NULL);(b-a)<sec;b+=0.000001)
	{
		printf("%c",'\0');
	}
}
void count1_to(int x)
{
	int i;

	printf("\n");

	for(i=0;i<x;i++)
	{
		delay_sec(SEC);

		printf("%d\n",i+1);
	}
}
void count2_to(int x)
{
	int i;

	for(i=0;i<x;i++)
	{
		delay_sec(SEC);

		if(i>0)
			printf("\b, ");

		printf(" %d.",i+1);
	}

	printf("\n");
}
void count3_to(int x)
{
	int i;

	printf(" ");

	for(i=1;i<=x;i++)
	{
		delay_sec(SEC);

		if(i>1000)
			printf("\b\b\b\b");
		else if(i>100)
			printf("\b\b\b");
		else if(i>10)
			printf("\b\b");
		else if(i>0)
			printf("\b");

		printf("%d",i);
	}

	printf("\n");
}
