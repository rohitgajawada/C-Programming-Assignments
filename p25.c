#include <stdio.h>
#include <string.h>
long long int dp[210][210];
long long int grouper(long long int n,long long int k)
{
  long long int i,j,total=1,temp;
  if(n<k)
    {
      return 0;
    }
  if(n==k)
    {
      return 1;
    }
  if(dp[n][k]!=-1)
    return dp[n][k];
  
  for(i=k;i<=n;i++)
    {
      temp=grouper(n-i,i);
      total+=temp;
    }
  dp[n][k]=total;
  return dp[n][k];
}

int main()
{
  long long int t;
  scanf("%d",&t);
  while(t--)
    {
      long long int n,k,ans;
      memset(dp,-1,sizeof(dp[0][0])*210*210);
      scanf("%lld%lld",&n,&k);
      ans=grouper(n,k);
      printf("%lld\n",ans);
    }
  return 0;
}
      
