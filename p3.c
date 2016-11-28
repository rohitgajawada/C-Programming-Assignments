#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846
int main()
{
  long long int x;
  scanf("%lld",&x);
  while(x--)
    {
      double x1,y1,r,x2,y2,R,area=0,d,ch;
      scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r,&x2,&y2,&R);
  
      d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
  
      ch=R-r;
      //printf("%lf\n",ch);
      if(ch<0)
	ch=ch*(-1);
  
      //printf("%lf %lf\n",ch,d);
      if(d<=ch)
	{
	  if(r<R)
	    area=PI*r*r;
	  else
	    area=PI*R*R;
	  //printf("hi\n");
	}
      else if(d>=(r+R))
	area=0.00;
      else
	{  
	  area=(r*r)*(acos((d*d+r*r-R*R)/(2.0*d*r)));
	  area+= (R*R)*(acos((d*d+R*R-r*r)/(2.0*d*R)));
	  area+=(-1.0)*(sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R)))/(2.0);
	  //printf("hi\n");
	}
  
      printf("Area of intersection is %.2lf sq. units\n",area);
    }
  
return 0;
}
  
