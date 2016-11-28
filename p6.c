#include <stdio.h>
long long int twomods[100];

long long int fastmod(long long int a,long long int b,long long int c)
{
  twomods[0]=a%c;
  long long int i=1,t=0;
  long long int q=b,sum=1,count=0;
  while(i<=31)
    {
      twomods[i]=(twomods[i-1]*twomods[i-1])%c;
      i++;
    }
  while(q>0)
    {
      t=q%2;
      if(t==1)
	sum=(sum*(twomods[count]))%c;
      count++;
      q/=2;
    }
  return sum;
}           
  
int main()
{
  long long int t,i;
  scanf("%lld",&t);
  while(t--)
    {
      long long int a,b,c,ans;
      scanf("%lld%lld%lld",&a,&b,&c);
      ans=fastmod(a,b,c);
      printf("%lld\n",(ans%c));
      for(i=0;i<32;i++)
	twomods[i]=0;
    }
  return 0;
}
