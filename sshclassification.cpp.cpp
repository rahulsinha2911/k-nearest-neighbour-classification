#include<bits/stdc++.h>
using namespace std;
int k;
struct clus
{
	vector<vector<double> >v;	
	clus *left,*right,*par;
	double ssh;
	vector<double>far1;
	vector<double>far2;
};

vector<clus*>leaf;

int countleaf(vector<clus*>leaf)
{
	int cc=0;
	for(int i=0;i<leaf.size();i++)
	{
		if(leaf[i]->left==NULL && leaf[i]->right==NULL)
		cc++;
	}
	return cc;
}



clus *getnode()
{
	    clus *root=new clus();
	    cout<<"type the dimension of point and no of cluster u want\n";
		int n;
		cin>>n>>k;
		cout<<"here we are taking point randomly no need to enter manually\n";
		
		cout<<"type total number point u want to take\n";
		int z;
		cin>>z;
		for(int i=0;i<z;i++)
		{
			vector<double>vc;
			vc.clear();
			for(int j=0;j<n;j++)
			{
			//	srand(10);
				int h=rand()%300;
				//cout<<h<<" ";
				vc.push_back(h);
			}
		//	cout<<"\n";
			root->v.push_back(vc);
		}
		//cout<<"\n\n";
		for(int j=0;j<root->v.size();j++)
			{
				for(int k=0;k<root->v[0].size();k++)
				{
				//	cout<<root->v[j][k]<<" ";
				}
			//	cout<<"\n";
			}
		//	cout<<"\n";
		
		
		root->left=NULL;
		root->right=NULL;
		root->par=NULL;
		return root;
}
 
 
double getssh(vector<double>v1,vector<vector<double> >v2)
{
	
	double d;
	for(int i=0;i<v2.size();i++)
	{
		for(int j=0;j<v2[0].size();j++)
		{
			d+=(v1[j]-v2[i][j])*(v1[j]-v2[i][j]);
		}
	}
	d=sqrt(d);
//	cout<<"sshd== "<<d<<"\n\n\n";
	return d;
}

vector<double> getfar(vector<double>v1,vector<vector<double> >v2)
{
	
	cout<<"here in getfar function "<<v1.size()<<" "<<v2.size()<<" "<<" with dimension "<<v2[0].size()<<"\n";
	double d,r=-35352324;
	vector<double>ans,rr;
	for(int i=0;i<v2.size();i++)
	{
		d=0;
		ans.clear();
		for(int j=0;j<v2[0].size();j++)
		{
			d+=(v1[j]-v2[i][j])*(v1[j]-v2[i][j]);
			ans.push_back(v2[i][j]);
		}
		
			//	cout<<"ffr "<<i<<"th = "<<d<<"\n";
			if(d>r)
			{
				 r=d;
				rr=ans;
			}
		
	}
	cout<<"\n\n\n";
	
	return rr;
}

struct clus *create(vector<double>f,clus *p,vector<vector<double> >v2)
{
	clus *n=new clus();
	n->left=NULL;
	n->right=NULL;
	n->par=p;
	n->v=v2;
	n->ssh=getssh(f,v2);
	
	n->far1=getfar(f,v2);
	n->far2=getfar(n->far1,v2);
	
	return n;
}

void addnode(clus* node1,vector<double>far1,vector<double>far2)
{
	clus *node=node1;
	//cout<<"ok1\n";
	vector<vector<double> >nl;
	vector<vector<double> >nr;
	
	vector<double>m1=node->far1;
	vector<double>m2=node->far2;
	
//	cout<<"ok2\n";
	
	for(int i=0;i<node->v.size();i++)
	{
	//	cout<<"ok3\n";
		double d1,d2;
		vector<double>ans;
		ans.clear();
		//cout<<m1.size()<<" "<<node->v.size()<<"\n";
		for(int j=0;j< node->v[0].size();j++)
		{
			ans.push_back(node->v[i][j]);
			
			d1+=(m1[j]- node->v[i][j])*(m1[j]- node->v[i][j]);
		    
		//	cout<<node->v[i][j]<<"ok10\n";
			
			d2+=(m2[j]- node->v[i][j])*(m2[j]- node->v[i][j]);
		}
	//	cout<<"ok4\n";
		if(d1<=d2)
		{
			nl.push_back(ans);
		}
		else
		nr.push_back(ans);
	}
     	cout<<"node sizes = "<<node->v.size()<<" "<<node->v[0].size()<<" ";
     	
	cout<<"nl child sizes = "<<nl.size()<<" "<<nl[0].size()<<" ";
	
	cout<<"nr child sizes = "<<nr.size()<<" "<<nr[0].size()<<"\n";
	//cout<<"ok5\n";
	//cout<<"filled\n";
	node->right=create(node->far2,node,nr);
	if(node->right==NULL)
	cout<<"chaku NULL right here\n\n\n";
	
	node->left=create(node->far1,node,nl);
	if(node->left==NULL)
	cout<<"chaku NULL here\n\n\n";
	
	
	leaf.push_back(node->left);
	leaf.push_back(node->right);
	
}

clus *root=NULL;
vector<int>cou;
int main()
{
	  	if(root==NULL)
		{
			root=getnode();                      //line 25
			leaf.push_back(root);
		}
		cout<<"k= "<<k<<"\n";
		/*
		for(int j=0;j<root->v.size();j++)
			{
				for(int k=0;k<root->v[0].size();k++)
				{
					cout<<root->v[j][k]<<" ";
				}
			    cout<<"\n";
			}
		cout<<"gdg\n";
			*/
			
			
	    int temp=1;
	    //cout<<"iniallise root\n";
	    vector<double>mean;
	    for(int j=0;j<root->v[0].size();j++)
	    {
	    	double sum=0;
	    	for(int i=0;i<root->v.size();i++)
	    	{
	    		sum+=root->v[i][j]*1.0;
			}
			mean.push_back(sum/root->v.size());
		}
		
		/*for(int i=0;i<mean.size();i++)
		cout<<mean[i]<<" ";
		cout<"\n\n\n";
	    //cout<<"iniallise mean\n";
	    */
	    
	    
		root->ssh=getssh(mean,root->v);  //line 68
		//	cout<<"ok";
	
		vector<double>f1=getfar(mean,root->v);   //line 84
		
		vector<double>f2=getfar(f1,root->v);
		
		root->far1=f1;
		root->far2=f2;
	//	cout<<"ff1 ff2\n";
		
		clus *node=root,*chaku=NULL;
		int gh=0;
    	while(countleaf(leaf) < k)
		{
				double ratio=-646352.0;
				double ratiopr=-3533343;
			cout<<countleaf<<" "<<leaf.size()<<"\n";
		//	cout<<temp<<"rgddd\n";
			addnode(node,f1,f2);        //line 128
			temp++;
			int z=leaf.size(),j=-1;
			for(int i=0;i<z;i++)
			{
				//cout<<i<<"\n";
				struct clus *sam=leaf[i];
			   if(sam->left==NULL && sam->right==NULL)
			   {
			   		if( chaku==NULL)
				chaku=sam;
				else if(chaku==sam)
				{
					cout<<"chaku rocks \n\n\n";
				}
			
			     // 	sam->left=new clus();
			   		if((sam->par->ssh/sam->ssh) > ratio)    // considering high ratio
			   		{
			   			if(find(cou.begin(),cou.end(),i)==cou.end())
			   			{
			   			ratio=(sam->par->ssh/sam->ssh);
			   			node=sam;
			   			j=i;
			   			gh=i;
			   			}
					}
			   }	
			}
			cou.push_back(gh);
			ratiopr=ratio;
		//	leaf[j]=root;
		}
		
		
		cout<<"point in required number of cluster are as follows\n";
		for(int i=0;i<leaf.size();i++)
		{
			struct clus *n=leaf[i];
			if(n->left==NULL && n->right==NULL)
			{
				for(int j=0;j<n->v.size();j++)
				{
					for(int k=0;k<n->v[j].size();k++)
					{
						cout<<n->v[j][k]<<" ";
					}
					cout<<"\n";
				}
				cout<<"\n\n\n\n";
			}
		}
}
