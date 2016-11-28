#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      long long int num,val=0,count=1,state=1;
      long long int rep[8100];
      memset(rep,0,sizeof(rep));

      scanf("%lld",&num);
      while(num>0)
	{
	  val+=pow((num%10),2);
	  num/=10;
	}
      num=val;
      rep[num]=1;
      val=0;
  
      while(num!=1)
	{
	  val=0;
	  while(num>0)
	    {
	      val+=pow((num%10),2);
	      num/=10;
	    }
	  count++;
	  num=val;
	  if(rep[num]!=1)
	    rep[num]=1;
	  else
	    {
	      state=0;
	      break;
	    }
	}

      if(state==0 && count!=1)
	printf("Unhappy Number\n");
      else
	printf("Happy Number!\n");
    }
  return 0;
}
    
    
  
  
  
  
