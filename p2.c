#include <stdio.h>
#include <math.h>
int main()
{
  long long int t;
  scanf("%lld",&t);
  while(t--)
    {
      double x,y,z,s,a;
      scanf("%lf%lf%lf",&x,&y,&z);
      s=(x+y+z)/2;
      a=s*(s-x)*(s-y)*(s-z);
      if(a>0)
	printf("%.2lf\n",sqrt(a));
      else
	printf("0\n");
    }
  return 0;
}
  
