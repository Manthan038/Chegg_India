#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main()
{
               
        ifstream input;
		size_t pos,rpos,lpos;
        string line;
        string first_name,last_name;
        bool flagM;
        cout<<"Enter your first name and Last name separated by space\n";
        cin>>first_name>>last_name;  // enter your name for search 
        
		input.open("chegg_search.txt");   // this is file name in that you want to search 
		if(input.is_open())   // check if file is open or not
		{
			while(getline(input,line))       // this will run  untill there will any line in file or not
			{ 
			 pos = line.find(first_name+" "+last_name);  // check for first and last name together
			 rpos= line.find(first_name);             // check for only first name
			 
			 lpos= line.find(last_name);             // check for only last name 
			  if(pos!=string::npos) // string::npos is returned if string is not found
              {
                cout <<first_name<<" "<<last_name<<": \t together Found\n";   
                flagM=1;   // if flagM became true so that only first name and only last name also became true 
              }
               if(rpos!=string::npos or flagM==1)
              {
              	cout<<first_name<<" :\t\tFound\n";
			  }
			  if(lpos!=string::npos or flagM==1)
			  {
			  	cout<<last_name<<" :\t\tFound\n";
			  	if(flagM==1)break;                 // if first and last name is found together then break the loop
			  }
			}
		}


}
