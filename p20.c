#include <stdio.h>

int lis(int a[],int n)
{
  int i,j,max=1,test;
  int seq[1000];
  for(i=0;i<n;i++)
    seq[i]=1;
  for(i=1;i<n;i++)
    {
      for(j=i-1;j>=0;j--)
	{
	  if(a[i]>=a[j])
	    {
	      if(seq[i]<seq[j]+1)
		seq[i]=seq[j]+1;
	    }
	}
    }	  
    
  for(i=0;i<n;i++)
    {
      if(seq[i]>max)
	{
	    max=seq[i];
	}
    }
  //printf("max is %d\n",max);
  return max;
}
  
  
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      int n,m,i,j,ans;
      int val[1000]={0};
      double pos[1000]={0};
      scanf("%d%d",&n,&m);
      for(i=0;i<n;i++)
	scanf("%lf%d",&pos[i],&val[i]);
      ans=lis(val,n);
      printf("%d\n",n-ans);
    }
  return 0;
}
      
      
