#include <stdio.h>
long long int psum[1000000]={0};

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
      //swap(psum[low],psum[mid]);
    }
  if(psum[low]>psum[up])
    {
      temp=psum[low];
      psum[low]=psum[up];
      psum[up]=temp;
      //swap(psum[low],psum[up]);
    }
  if(psum[mid]>psum[up])
    {
      temp=psum[mid];
      psum[mid]=psum[up];
      psum[up]=temp;
      //swap(psum[mid],psum[up]);
    }
  temp=psum[low];
  psum[low]=psum[mid];
  psum[mid]=temp;
  //swap(psum[low],psum[mid]);
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

long long int powerset(long long int tiny[],long long int s)
{
  long long int i,j,k,m,l=1,temp;
  for(i=1;i<=s;i++)
    l*=3;
  for(i=0;i<l;i++)
    {
      m=i;
      for(j=0;j<s;j++)
	{
	  temp=m%3;
	  if(temp==1)
	    psum[i]+=tiny[j];
	  else if(temp==2)
	    psum[i]+=(-1)*tiny[j];
	  m=m/3;
	}
      //printf("%lld\n",psum[i]);
    }
  return l;
}

long long int binsear(long long int tiny[],long long int k,long long int l,long long int r)
{
  long long int mid;
  mid=l+(r-l)/2;
  if(l>r)
    return 0;
  else
    {
      if(tiny[mid]==k)
	return 1;
      else if(tiny[mid]>k)
	binsear(tiny,k,l,mid-1);
      else if(tiny[mid]<k)
	binsear(tiny,k,mid+1,r);
    }
}
       
int main()
{
  long long int n,k,t,i,z,out;
  scanf("%lld",&n);
  long long int tiny[n];
  for(i=0;i<n;i++)
    scanf("%lld",&tiny[i]);
  z=powerset(tiny,n); 
  quick(psum,0,z-1);
  //for(i=0;i<z;i++)
  //printf("%lld\n",psum[i]);
  scanf("%lld",&t);
  while(t--)
    {
      scanf("%lld",&k);
      out=binsear(psum,k,0,z-1);
      if(out==1)
	printf("YES\n");
      else if(out==0)
	printf("NO\n");
    }
  return 0;
}




