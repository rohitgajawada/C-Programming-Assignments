#include <stdio.h>
void merge(long long int a[],long long int l,long long int r,long long int p,long long int q)
{
  long long int c[2000],k=0,x,y;
  long long int i=l,j=p;
  while(i<=r && j<=q)
    {
      if(a[i]<a[j])
	{
	  c[k++]=a[i];
	  i++;
	}
      else
	{
	  c[k++]=a[j];
	  j++;
	}
    }
  while(i<=r)
    {
      c[k++]=a[i];
      i++;
    }
  while(j<=q)
    {
      c[k++]=a[j];
      j++;
    }
  for(x=0,y=l;x<k,y<=q;x++,y++)
    {
      a[y]=c[x];
    }   
}

void mergesort(long long int a[],long long int low,long long int high)
{
  if(low<high)
    {
      long long int temp;
      long long int mid=low+(high-low)/2;
      if(high==low+1)
	{
	  if(a[low]>a[high])
	    {
	      temp=a[low];
	      a[low]=a[high];
	      a[high]=temp;
	    }
	  return;
	}
      mergesort(a,low,mid);
      mergesort(a,mid+1,high);
      merge(a,low,mid,mid+1,high);
    }
}

int main()
{
  while(1)
    {
      long long int i,j,k,n,a[10000],total=0;
      scanf("%lld",&n);
      if(n==0)
	break;
      for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
      mergesort(a,0,n-1);
      for(i=0;i<n;i++)
	{
	  k=i+2;
  	  for(j=i+1;j<n;j++)
	    {
	      while(k<n && a[k]<=(a[i]+a[j]))
		{
		  k++;
		}
	      if(a[k]>(a[i]+a[j]))
		total+=n-k;
	    }
	}
      printf("%lld\n",total);
    }
  return 0;
}
		
		      
		  
      
      
  
