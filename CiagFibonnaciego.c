#include<stdio.h>
int main()

{
	printf("\nWitam policzymy elementy Ciagu Fibonacciego\n");
	puts(" xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
	printf("Ktory element ciagu obliczyc ?\n");
	int n;
	scanf("%d" ,&n);

	if (n==0)
	printf("0 element Ciagu Fibonacciego rowna sie 0\n");
	else if(n<=2)
	printf("%d elementem Ciagu Fibonacciego = 1\n" ,n);
	else

	{

	int f1=1; //wartosc pierwszego elementu
	int f2=1; //wartosc drugiego elementu
	int temp; //zmienna pomocnicza
	for(int i=3; i<=n; i++)

		{

		temp=f1+f2;
		f1=f2;
		f2=temp;
		/*dwa przykladowe obiegi petli:
		temp=1+1=2;
		f1=f2=1;
		f2=temp=2;
		temp=1+2=3;
		f1=f2=2;
		f2=temp=3;
		*/

		}

	printf("%d element Ciagu Fibonacciego = %d\n" ,n, f2);

	}

	return 0;
} 
