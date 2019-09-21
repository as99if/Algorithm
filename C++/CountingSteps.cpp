#include<stdio.h>
#include<limits.h>
#define min(a,b) a<b?a:b
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
	printf("%d \n",CountTheSteps(50));
	return 0;
}