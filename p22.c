#include <stdio.h>
#include <string.h>

void findmax(char str[],int n)
{
  int i,j,k,max=0,dynprog[1010][1010]={0};
  for(i=1,j=1;j<=n;j++)
    dynprog[i][j]=1;
  for(i=1;i<=n;i++)
    {
      for(j=i;j<=n;j++)
	{
	  if((str[i-1]==str[j-1]) && (j!=i))
	    {
	      dynprog[i][j]=1+dynprog[i-1][j-1]; //taking each suffix and checking
	      if(dynprog[i][j]>max)
		max=dynprog[i][j];
	    }
	  else
	    dynprog[i][j]=0; //no repeated suffix
	}
    }
  printf("%d\n",max);
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      char str[1010];
      scanf("%s",str);
      int n=strlen(str);
      findmax(str,n);
    }
  return 0;
}
