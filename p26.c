#include <stdio.h>
#include <string.h>
char a[100005][25];
char temp[25],temp1[50],temp2[50];
void stringcopy(char a[],char b[])
{
  int i,j,l=strlen(b);
  for(i=0;i<l;i++)
    a[i]=b[i];
  a[l]='\0';
}
void swap(int i,int j)
{
  stringcopy(temp,a[i]);
  stringcopy(a[i],a[j]);
  stringcopy(a[j],temp);
} 

int comparer(int i,int j)
{
  int swapstate;
  stringcopy(temp1,a[i]);
  strcat(temp1,a[j]);
  stringcopy(temp2,a[j]);
  strcat(temp2,a[i]);
  swapstate=strcmp(temp1,temp2);
  if(swapstate<=0)
    return 0;
  else if(swapstate>0)
    return 1;
} 

void merge(int l,int r,int p,int q)
{
  char c[100005][25],k=0,x,y;
  int i=l,j=p;
  while(i<=r && j<=q)
    {
      if(comparer(i,j)==0)
	{
	  stringcopy(c[k++],a[i]);
	  i++;
	}
      else
	{
	  stringcopy(c[k++],a[j]);
	  j++;
	}
    }
  while(i<=r)
    {
      stringcopy(c[k++],a[i]);
      i++;
    }
  while(j<=q)
    {
      stringcopy(c[k++],a[j]);
      j++;
    }
  for(x=0,y=l;x<k,y<=q;x++,y++)
    {
      stringcopy(a[y],c[x]);
    }   
}

void mergesort(int low,int high)
{
  if(low<high)
    {
      int temp;
      int mid=low+(high-low)/2;
      mergesort(low,mid);
      mergesort(mid+1,high);
      merge(low,mid,mid+1,high);
    }
}

int main()
{
  int n,i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%s",a[i]);
  mergesort(0,n-1);
  for(i=n-1;i>=0;i--)
    printf("%s",a[i]);
  printf("\n");
  return 0;
}
