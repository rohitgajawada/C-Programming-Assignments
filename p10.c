#include <stdio.h>
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      long long int n,i,j,carry=0,prod=0,count=1;
      long long int numb[1000000]={0};
      numb[0]=1;
      scanf("%lld",&n);
      for(i=2;i<=n;i++)
	{
	  prod=0;
	  carry=0;
	  for(j=0;j<count;j++)
	    {
	      prod=carry;
	      prod+=numb[j]*i;
	      numb[j]=prod%10;
	      carry=prod/10;
	    }
	  if(carry>0)
	    {
	      while(carry>0)
		{
		  numb[count]=carry%10;
		  carry/=10;
		  count++;
		}
	    }
	}
      for(i=count-1;i>=0;i--)
	printf("%lld",numb[i]);
      printf("\n");
    }
  return 0;
}
	  
      
      
