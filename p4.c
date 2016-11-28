#include <stdio.h>
long long int cubes[10]={0,1,8,27,64,125,216,343,512,729};
long long int armstrongs[10]={0};
int main()
{
  long long int x;
  scanf("%lld",&x);
  long long int i,count=0,sum,t;
  for(i=1;i<=100000;i++)
    {
      sum=0;
      t=i;
      while(t>0)
	{
	  sum+=cubes[t%10];
	  t/=10;
	  // printf("%lld\n",sum);
	}
      //printf("%lld\n",i);
      if(sum==i)
	{
	  armstrongs[count]=i;
	  count++;
	  // printf("%lld\n",i);
	}
    }

  while(x--)
    {
      long long int l,r,j=0,c=0;
      scanf("%lld%lld",&l,&r);
      for(i=l;i<=r;i++)
	{
	  if(i>armstrongs[count-1])
	    break;
	  for(j=0;j<count;j++)
	    {
	      if(i==armstrongs[j])
		c++;
	    }
	}
      printf("%lld\n",c);
    }
  return 0;
}
  
		
	  
	  
      
    	
      
