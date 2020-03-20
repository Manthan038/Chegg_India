#include<iostream>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;
void readdata()  // this is function for reading data form Mobile_info.txt file
{
	fstream fi;
	string line;
	fi.open("Mobile_info.txt", ios::in);
	while (fi) { 
  
        // Read a Line from File 
        getline(fi, line); 
  
        // Print line in Console 
        cout << line << endl; 
        } 
  
    // Close the file 
    fi.close(); 
}
int main()
{
time_t now = time(0);
struct tm *ltm = localtime(&now);
fstream new_file; 
new_file.open("Mobile_info.txt",ios::app);  //Stream class to both read and write from/to files.
new_file.seekg(ios::end); // set the curser at the last so that new data should added at end of the file
int Mobile,Avarage,Highest=INT_MIN,Lowest=INT_MAX;
new_file<<"Date: "<<ltm->tm_mday<<"/"<<1 + ltm->tm_mon<<"/"<<1900 + ltm->tm_year<<endl;  // this is for system date 
new_file<<"Enter Number of Mobile Sold ";  //new_file is used for printing data into the file
cout<<"Enter Number of Mobile Sold \n";
cin>>Mobile;
new_file<<Mobile<<endl;
new_file<<"Enter the prices: ";
int *mprice =(int*)malloc(Mobile*sizeof(int)); // Dynamic memmory allocation
for (int i=0;i<Mobile;i++)
{
	cin>>mprice[i];
	new_file<<mprice[i]<<" ";
	Avarage+=mprice[i];
	Highest=max(Highest,mprice[i]);   // take out the highest price
	Lowest=min(Lowest,mprice[i]);   // for lowest price
}
new_file<<endl;
new_file<<"Highest Cost is: "<<Highest<<endl;
new_file<<"Lowest Cost is: "<<Lowest<<endl;
new_file<<"Avarage Cost is:"<<(float)Avarage/(float)Mobile<<endl;
new_file<<endl;
new_file<<endl;
new_file.close(); //  Closing file
cout<<"Done..../n ";
int n;
cout<<"Press 1 for read the file ";
cin>>n;
if (n==1)
readdata();
}


