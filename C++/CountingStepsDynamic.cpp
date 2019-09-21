#include<stdio.h>
#include<limits.h>
#define min(a,b) a<b?a:b
int cs[10000];
int S[10000];

void printS(int n)
{

	if(S[n]!=0)
	{
		if(S[n]==1)
		{
			printf("Minus 1\n");
			printS(n-1);
		}
		else
		{
			printf("Divide by %d\n",S[n]);
			printS(n/S[n]);
		}
	}
}

int CountTheStepsD(int n)
{
	if(cs[n]!=-1) return cs[n];
	cs[n]=INT_MAX;
	if(n>1) 
	{
		int temp=1+CountTheStepsD(n-1);
		if(temp<cs[n])
		{
			cs[n]=temp;
			S[n]=1;
		}
	}
	if(n%2==0) 
	{
		int temp=1+CountTheStepsD(n/2);
		if(temp<cs[n])
		{
			cs[n]=temp;
			S[n]=2;
		}
	}
	if(n%3==0) 
	{
		int temp=1+CountTheStepsD(n/3);
		if(temp<cs[n])
		{
			cs[n]=temp;
			S[n]=3;
		}
	}
	return cs[n];


}

int CountTheSteps(int n)
{
	int qmin=INT_MAX;
	if (n<=1)return 0;
	if(n>1) qmin=min(qmin,1+CountTheSteps(n-1));
	if(n%2==0) qmin=min(qmin,1+CountTheSteps(n/2));
	if(n%3==0) qmin=min(qmin,1+CountTheSteps(n/3));
	return qmin;
}
int main()
{
	for(int i=0;i<10000;i++)cs[i]=-1;
	cs[0]=0;
	cs[1]=0;
	int amount=41;
	printf("Number of Steps for %d: %d\n",amount,CountTheStepsD(amount));
	printS(amount);
	return 0;
}