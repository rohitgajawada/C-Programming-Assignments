#include <stdio.h>
long long int primes[10000001]={0};
long long int sums[10000001]={0};
int main()
{
  long long int t;
  scanf("%lld",&t);
  long long int k,j=2,num;
  for(k=2;k<10000000;k++)
    {
      sums[k]=sums[k-1];
      if(primes[k]==0)
	{
	  sums[k]+=k;
	  for(j=2;(num=j*k)<10000000;j++)
	    {
	      primes[num]=-1;
	    }
	}
    }

  while(t--)
    {
      long long int l,r,i,sum=0;
      scanf("%lld%lld",&l,&r);
      sum=sums[r]-sums[l-1];
      printf("%lld\n",sum);
    }
  return 0;
}
