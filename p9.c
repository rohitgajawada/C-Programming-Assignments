#include <stdio.h>

double min(double a,double b)
{
  if(a<b)
    return a;
  else
    return b;
}
double max(double a,double b)
{
  if(a>b)
    return a;
  else
    return b;
}

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      double x1,y1,x2,y2,x3,y3,x4,y4;
      scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
      double m,state=1,l1,l2,l3,l4;
      if((x1==x2)&&(x2==x3)&&(x3==x4)) //all same x-coord 
	{
	  if(min(y1,y2)<min(y3,y4))
	    {
	      if(max(y1,y2)<min(y3,y4))
		state=0;
	    }
	  else if(min(y3,y4)<min(y1,y2))
	    {
	      if(max(y3,y4)<min(y3,y4))
		state=0;
	    }
	}
      else if((y1==y2)&&(y2==y3)&&(y3==y4)) //all same y-coord
	{
	  if(min(x1,x2)<min(x3,x4))
	    {
	      if(max(x1,x2)<min(x3,x4))
		state=0;
	    }
	  else if(min(x3,x4)<min(x1,x2))
	    {
	      if(max(y3,y4)<min(y3,y4))
		state=0;
	    }
	}
		
      else
	{
	  if(x1!=x2) //normal
	    {
	      l1=(y3-y1)-((y2-y1)*(x3-x1))/(x2-x1);
	      l2=(y4-y1)-((y2-y1)*(x4-x1))/(x2-x1);
	    }
	  else
	    {
	      l1=x3-x1;
	      l2=x4-x1;
	    }
	  if(x3!=x4) //normal
	    {
	      l3=(y1-y3)-((y4-y3)*(x1-x3))/(x4-x3);
	      l4=(y2-y3)-((y4-y3)*(x2-x3))/(x4-x3);
	    }
	  else //slope is infinity
	    {
	      l3=x1-x3;
	      l4=x2-x3;
	    }
	  if(((x1==x2)&&(y1==y2))&&((x3==x4)&&(y3==y4))) //lines are points
	    {
	      if((x2!=x3)&&(y2!=y3))
		state=0;
	    }	 
	  else if((l1*l2>0) || (l3*l4>0)) //pts on same side of line
	    {
	      state=0;
	    }
	  else if((l1*l2==0) || (l3*l4==0))
	    {
	      if((max(x3,x4)>max(x1,x2))&&(max(y3,y4)>max(y1,y2)))
		{
		  if((max(x1,x2)<min(x3,x4))||(max(y1,y2)<min(y3,y4)))
		    state=0;
		}
	      else if((max(x1,x2)>max(x3,x4))&&(max(y1,y2)>max(y3,y4)))
		{
		  if((max(x3,x4)<min(x1,x2))||(max(y3,y4)<min(y1,y2)))
		    state=0;
		}
	    }
	}
      if(state==1)
	printf("YES\n");
      else if(state==0)
	printf("NO\n");
    }
  return 0;
}
	    
	  
	  
	  
      
	     
	 
	
	  
      
      
hey lo
