#include <stdio.h>
int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      double x1,y1,x2,y2,ansx=0,ansy=0;
      char op;
      scanf("%lf %lf %lf %lf %c",&x1,&y1,&x2,&y2,&op);
      if(op=='A')
	{
	  ansx=x1+x2;
	  ansy=y1+y2;
	}
      else if(op=='S')
	{
	  ansx=x1-x2;
	  ansy=y1-y2;
	}
      else if(op=='M')
	{
	  ansx=((x1*x2)-(y1*y2));
	  ansy=((x1*y2)+(x2*y1));
	}
      else if(op=='D')
	{
	  ansx=((x1*x2)+(y1*y2))/((x2*x2)+(y2*y2));
	  ansy=((x2*y1)-(x1*y2))/((x2*x2)+(y2*y2));
	}
      printf("%.2lf %.2lf\n",ansx,ansy);
    }
  return 0;
}
    
