#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll minvalue(ll , ll );
int main()
{
	cout<<"type the no of input cordinate\n";
	ll n;
	cin>>n;
	ll v[n][3];
	srand(3);
	for(int i=0;i<n;i++)
	{
		ll x,y;
		x=rand()%1000;
		y=rand()%1000;
		cout<<i<<" input sample taken as randon is ("<<x<<","<<y<<")\n";
		v[i][0]=x;
		v[i][1]=y;
	}
	cout<<"type the no of cluster probability\n";
	ll z,p,q,k1x,k1y,k2x,k2y;
	cin>>z;
	ll temp1,temp2;
	p=rand()%n;
	q=rand()%n;
	k1x=v[p][0];
	k1y=v[p][1];
	k2x=v[q][0];
	k2y=v[q][1];
	cout<<"centroid intially taken for cluster 1 is ("<<v[p][0]<<","<<v[p][1]<<")\n";
    cout<<"centroid intially taken for cluster 2 is ("<<v[q][0]<<","<<v[q][1]<<")\n";
    
    cout<<"calculation for eucledian distance\n";
    for(int i=0;i<n;i++)
    {
      ll d1,d2,temp;
	  d1=sqrt((v[i][0]-k1x)*(v[i][0]-k1x) + ((v[i][1]-k1y)*(v[i][1]-k1y)));
	  
	   d2=sqrt((v[i][0]-k2x)*(v[i][0]-k2x) + ((v[i][1]-k2y)*(v[i][1]-k2y)));
	   temp=minvalue(d1,d2);
	   if(temp==1)
	   {
	    v[i][2]=1;
	    k1x=(k1x+v[i][0])/2;
	    k1y=(k1y+v[i][1])/2;
	   }
	   else if(temp==2)
	    {
	    	 v[i][2]=2;
	    k2x=(k2x+v[i][0])/2;
	    k2y=(k2y+v[i][1])/2;
		}
	   else
	   {
	   	v[i][2]=0;
	   	k2x=(k2x+v[i][0])/2;
	    k2y=(k2y+v[i][1])/2;
	    
	    k1x=(k1x+v[i][0])/2;
	    k1y=(k1y+v[i][1])/2;
	   }
  
	  cout<<d1<<"\n";	
	}
	cout<<"\npoints of cluster 1 are\n";
	int temp=0;
	for(int i=0;i<n;i++)
	{
		if(v[i][2]==1)
		{
		 cout<<"("<<v[i][0]<<","<<v[i][1]<<")\n";
		 temp++;
	   }	 
	}
	
	if(temp==0)
	cout<"no point lie in cluster 1 according to intial point given\n";
	
	cout<<"\npoints of cluster 2 are\n";
	temp=0;
	for(int i=0;i<n;i++)
	{
		if(v[i][2]==2)
		{
		 cout<<"("<<v[i][0]<<","<<v[i][1]<<")\n";
		 temp++;
	   }
	}
	
	if(temp==0)
	cout<"no point lie in cluster 2 according to intial point given\n";
	
	cout<<"\npoints of both cluster 1 and 2 are\n";
	 temp=0;
	for(int i=0;i<n;i++)
	{
		if(v[i][2]==0)
		{
		 cout<<"("<<v[i][0]<<","<<v[i][1]<<")\n";
		 temp++;
	    }   
	}
	if(temp==0)
	cout<<"no point are common to both cluster\n";
}
ll minvalue(ll d1,ll d2)
{
	long long r,s;
	r=d1;
	s=d2;
    if(r<s)
    {
    	return 1;
	}
	else if(r>s)
	{
		return 2;
	}
	else
	{
		return 0;
	}
}
