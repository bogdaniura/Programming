#include<stdio.h>
main ()
{
int i,n,fact=1;
printf("Enter the number: ");
scanf("%d",&n); //inputing the number
for(i=1;i<=n;i++) /* finding factorial */
{
fact = fact*i;
}
printf("Factorial=%d\n",fact);
}