#include <stdio.h>
#define PI 3.14159
int main()
{
  long long int n;
  scanf("%lld",&n);
  while(n--)
    {
      double a,ans;
      scanf("%lf",&a);
      ans=2*a/(3*(4-PI));
      printf("%.2lf %.2lf\n",ans,ans);
    }
  return 0;
}
      
