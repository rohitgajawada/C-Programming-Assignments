#include <stdio.h>
long long int partition(long long int psum[],long long int low,long long int up)
{
  long long int temp,i,j,pivot,mid;
  i=low+1;
  j=up;
  mid=(low+up)/2;
  if(psum[low]>psum[mid])
    {
      temp=psum[low];
      psum[low]=psum[mid];
      psum[mid]=temp;
    }
  if(psum[low]>psum[up])
    {
      temp=psum[low];
      psum[low]=psum[up];
      psum[up]=temp;
    }
  if(psum[mid]>psum[up])
    {
      temp=psum[mid];
      psum[mid]=psum[up];
      psum[up]=temp;
    }
  temp=psum[low];
  psum[low]=psum[mid];
  psum[mid]=temp;
  pivot=psum[low];
  while(i<=j)
    {
      while((psum[i]<pivot)&&(i<up))
	i++;
      while(psum[j]>pivot)
	j--;
      if(i<j)
	{
	  temp=psum[i];
	  psum[i]=psum[j];
	  psum[j]=temp;
	  i++;
	  j--;
	}
      else
	i++;
    }
  psum[low]=psum[j];
  psum[j]=pivot;
  return j;
}

void quick(long long int psum[],long long int low,long long int up)
{
  long long int pivlock;
  if(low>=up)
    return;
  pivlock=partition(psum,low,up);
  quick(psum,low,pivlock-1);
  quick(psum,pivlock+1,up);
}

int main()
{
  long long int n,i,j,k,q;
  scanf("%lld",&n);
  long long int a[100100];
  for(i=0;i<n;i++)
    scanf("%lld",&a[i]);
  scanf("%lld",&q);
  quick(a,0,n-1);
  while(q--)
    {
      long long int v,m=n,count=0;
      scanf("%lld",&v);
      
      i=0;
      for(j=i+1;j<m;j++)
	{
	  if((a[i]+a[j])>v)
	    {
	      m=j;
	      break;
	    }
	  else
	    count++;
	}
      if(m==n)
	m--;
      for(i=1;i<m;i++)
	{
	  for(j=m;j>i;j--)
	    {
	      if((a[i]+a[j])<=v)
		{
		  count+=j-i;
		  m=j;
		  break;
		}
	    }
	}
      printf("%lld\n",count);
    }
  return 0;
}
      
      
