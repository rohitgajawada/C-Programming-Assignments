#include <stdio.h>
long long int fact(long long int n)
{
  long long int i,ans=1;
  for(i=2;i<=n;i++)
    ans=ans*i;
  return ans;
}
long long int powerboy(long long int a,long long int b)
{
  long long int i,ans=1;
  for(i=1;i<=b;i++)
    ans=ans*a;
  return ans;
}
void fact2(long long int n,long long int m)
{
  long long int i,j,carry=0,prod=0,count=1,zees,state=0;
  long long int numb[1000000]={0};
  numb[0]=1;
  zees=n/5;
  if(m<=zees)
    {
      printf("0\n");
      return;
    }
  else
    {
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
      for(i=m-1;i>=0;i--)
	{
	  if(numb[i]==0 && state==0)
	    state=1;
	  else
	    {
	      state=1;
	      printf("%lld",numb[i]);
	    }
	}
      printf("\n");
    }
}

int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      long long int n,m,ans=0;
      scanf("%lld%lld",&n,&m);
      if(n>4)
	{
	  ans=0;
	  printf("0\n");
	}
      else
	{
	  if(n!=4)
	    {
	      ans=fact(n);
	      ans=fact(ans);
	      ans=ans%(powerboy(10,m));
	      printf("%lld\n",ans);
	    }
	  else if(n==4)
	    {
	      ans=fact(n);
	      fact2(ans,m);
	    }
	}
    }
  return 0;
}
