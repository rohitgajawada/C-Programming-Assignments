#include <stdio.h>
long long int supergcd(long long int a,long long int b)
{
  if(a==0)
    return b;
  return supergcd(b%a,a);
}
int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      long long int a,b,k,i,j,p,q,r,ans,temp1,temp2,tem;
      scanf("%lld%lld%lld",&a,&b,&k);
      long long int arr[1000005];
      p=a,q=b,i=0;
      temp1=supergcd(a,b);
      temp2=(a*b)/(temp1);
      while(p<temp2 || q<temp2)
	{
	  if(p<q)
	    {
	      arr[i++]=p;
	      p=p+a;
	    }
	  else if(p>q)
	    {
	      arr[i++]=q;
	      q=q+b;
	    }
	}
      arr[i++]=p;
      r=(k-1)%i;
      ans=((k-1)/i)*p+arr[r];
      printf("%lld\n",ans);
    }
  return 0;
}
	  
	  
	  
      
      
      
