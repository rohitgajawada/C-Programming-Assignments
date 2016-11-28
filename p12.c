#include <stdio.h>
#include <math.h>

long long int getsum(long long int n)
{
  long long int i,sum=0;
  while(n>0)
    {
      sum+=n%10;
      n/=10;
    }
  return sum;
}
      
  
int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      long long int c,i,j,k,u,l,ans=-1;
      scanf("%lld",&c);
      l=((long long int)sqrt(c))-81;
      if(l<0)
	l=0;
      u=(long long int)sqrt(81*81+c);
      for(i=l;i<=u;i++)
	{
	  k=getsum(i);
	  if((i*i+k*i-c)==0)
	    {
	      ans=i;
	      break;
	    }
	}
      printf("%lld\n",ans);
    }
  return 0;
}
	  
