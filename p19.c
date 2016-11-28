#include <stdio.h>
#include <string.h>
#include <math.h>
int query[200];

int dist(int x,int y,int a,int b)
{
  int d;
  d=fabs(x-a)+fabs(y-b);
  return d;
}

int main()
{
  int n,m,q,count=0,r,i;
  scanf("%d%d%d",&n,&m,&q);
  while(q--)
    {
      int a1=-1,a2=-1,min=10000000;
      char word[20];
      int x,y;
      scanf("%s",word);
      scanf("%d%d",&x,&y);
      if((strcmp(word,"Add"))==0)
	{
	  query[count]=x;
	  query[count+1]=y;
	  count+=2;
	}
      else
	{
	  for(i=0;i<count;i+=2)
	    {
	      r=dist(x,y,query[i],query[i+1]);
	      if(r<=min)
		{
		  if((a1!=-1) && (a2!=-1) && (r==min))
		    {
		      if((query[i]<a1) || (query[i]==a1 && query[i+1]<a2))
			{
			  a1=query[i];
			  a2=query[i+1];
			}
		    }
		  else
		    {
		      a1=query[i];
		      a2=query[i+1];
		      min=r;
		    }
		}
	    }
	  printf("%d %d\n",a1,a2);
	}
    }
  return 0;
}
      
      
      
      
  
  
