#include <stdio.h>
long long int fibo[1000000];
int main()
{
  long long int t;
  scanf("%lld",&t);
  long long int i,j;
  fibo[0]=0,fibo[1]=1;
  for(i=2;i<=1000000;i++)
    {
      fibo[i]=(fibo[i-1]+fibo[i-2])%(1000000000+7);
    }
  
  while(t--)
    {
      long long int n;
      scanf("%lld",&n);
      printf("%lld\n",fibo[n]);
    }
  return 0;
}
      
      
      

   
