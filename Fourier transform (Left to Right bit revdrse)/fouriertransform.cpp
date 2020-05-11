#include <bits/stdc++.h>
using namespace std;
void reversBit(vector<int>&v,int N)
{  
   int size;
	while(N>1)
	{  
	  
	  size=v.size();
	  for(int i=0;i<size;i++)
	    {
	        
         v.push_back(N/2+v[i]); 	  
		}
		N/=2;	
	}
}
int main()
{
	int N=16;
	vector <int> rLbit;
	rLbit.push_back(0);
	reversBit(rLbit,N);
	for(int i=0;i<rLbit.size();i++)
	    {
          cout<<rLbit[i]<<" ";	  	
		}
		cout<<"Done";
}
