#include <stdio.h>
int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      double b,h,ans;
      scanf("%lf%lf",&b,&h);
      ans=(b*h*((b*b)+(12*h*h)))/48;
      printf("%lf\n",ans);
    }
  return 0;
}
