#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int t;
  scanf("%d",&t);
  while(t--)
    {
      char str[10010];
      memset(str,0,sizeof(str[0])*10010);
      int counts[10][2]={0};
      memset(counts,0,sizeof(counts[0][0])*10*2);
      char poss[10][10010]={0};
      memset(poss,0,sizeof(poss[10][10010])*10*10010);
      int k,i,j,x,y,z,temp;
      int p,q,r,pt,cost,min=1000001,minind=-1;
      int allcosts[10];
      memset(allcosts,0,sizeof(allcosts[0])*10);
      int ans[10][10]={0};
      memset(ans,0,sizeof(ans[0][0])*10*10);
      scanf("%d",&k);
      scanf("%s",str);
      int l=strlen(str);
      for(i=0;i<l;i++)
	{
	  counts[str[i]-'0'][1]++;
	}
      for(i=0;i<10;i++)
	{
	  cost=0;
	  pt=k-counts[i][1];
	  p=i,q=i;
	  while(pt>0)
	    {
	      q++;
	      if(q<10 && pt>0)
		{
		  pt-=counts[q][1];
		  if(pt>=0)
		    {
		      temp=(q-i)*counts[q][1];
		      cost+=temp;
		      if(temp>0)
			ans[i][q]+=counts[q][1];
		    }		
		  else
		    {
		      cost+=(pt+counts[q][1])*(q-i);
		      ans[i][q]+=pt+counts[q][1];
		    }
		  //printf("i:%d q:%d cost:%d\n",i,q,cost);
		}
	      p--;
	      if(p>=0 && pt>0)
		{
		  pt-=counts[p][1];
		  if(pt>=0)
		    {
		      temp=(i-p)*counts[p][1];
		      cost+=temp;
		      if(temp>0)
			ans[i][p]+=counts[p][1];
		    }
		  else
		    {
		      cost+=(pt+counts[p][1])*(i-p);
		      ans[i][p]+=pt+counts[p][1];
		    }
		  //printf("i:%d p:%d cost:%d\n",i,p,cost);
		}
	    }
	  allcosts[i]=cost;
	  if(cost<min)
	    {
	      min=cost;
	      minind=i;
	    }
	}
      // printf("min %d minind i=%d\n",min,minind);
      //for(i=0;i<10;i++)
      //printf("ans of %d for 1 is %d\n",i,ans[1][i]);
      for(i=0;i<10;i++)
	{
	  for(j=0;j<l;j++)
	    {
	      if(str[j]-'0' > i && ans[i][str[j]-'0']>0)
		{
		  ans[i][str[j]-'0']--;
		  poss[i][j]=i+'0';
		}
	      else
		poss[i][j]=str[j];
	    }
	  for(j=l-1;j>=0;j--)
	    {
	      if(str[j]-'0' < i && ans[i][str[j]-'0']>0)
		{
		  ans[i][str[j]-'0']--;
		  poss[i][j]=i+'0';
		}
	    }
	}
      //for(i=0;i<10;i++)
      //{
      //  printf("%s\n",poss[i]);
      //}
      //till here correct
      // printf("-----\n");
      char output[10000];
      memset(output,0,sizeof(output[0])*10000);
      for(z=0;z<10;z++)
	{
	  if(allcosts[z]==min)
	    {
	      strcpy(output,poss[z]);
	      break;
	    }
	}
      for(i=z;i<10;i++)
	{
	  if(allcosts[i]==min)
	    {
	      //printf("%s\n",poss[i]); 
	      x=strcmp(poss[i],output);
	      if(x<0)
		strcpy(output,poss[i]);
	    }
	}
      // printf("-.-.-.-.-.-\n");
      printf("%d %s\n",min,output);

    }
  return 0;
}
	      
	  
	  
	  
      
      
	  
	  
      
      
      
