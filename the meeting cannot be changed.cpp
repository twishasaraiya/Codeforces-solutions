
PROBLEM:http://codeforces.com/contest/782/problem/B
#include<stdio.h>
#include<string.h>
#define maxn 60000+10
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
int n,i;
int a[maxn],b[maxn];
int canmeet(double time)
{
  double left,right,le,ri;
  for(i=0;i<n;i++)
  {
    if(i==0)
    {
    left=a[i]-b[i]*time;
    right=a[i]+b[i]*time;
    }
    else
    {
      le=a[i]-b[i]*time;
      ri=a[i]+b[i]*time;
      if(le>right||ri<left)
      return 0;
      left=max(left,le);
      right=min(ri,right);
    }
  }
  return 1;
}
int main()
{
  scanf("%d",&n);
  for(i=0;i<n;i++)
  scanf("%ld",&a[i]);
  for(i=0;i<n;i++)
  scanf("%ld",&b[i]);
  double mid,l=0,r=1e9;
  while(r-l>1e-6)
  {
    mid=(l+r)/2;
    if(canmeet(mid))
    r=mid;
    else
    l=mid;
  }
  printf("%.12lf\n",r);
  return 0;
}
