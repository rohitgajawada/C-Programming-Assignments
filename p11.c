#include <stdio.h>
#include <string.h>


int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      char num[1000000];
      long long int k,l,m,i,j,ans=0;
      scanf("%s",num);
      scanf("%lld",&k);
      l=strlen(num);
      for(i=0;i<l;i++)
	{
	  if(num[i]=='0' || num[i]=='5')
	    {
	      ans=(ans+((power(2,i))%(1000000007))*((power(2,k*l)-1)%(1000000007))*((power((power(2,l)-1),m-2))%(1000000007)))%(1000000007);
	    } 
      printf("%lld\n",ans);
    }
  return 0;
}
	  
      
      
      
      
