//Given a list of tickets, find itinerary in order using the given list.
#include<iostream>
#include<string>
#include<map>

using namespace std;

void printItinerary(map<string,string> dataSet)
{

	map<string,string> reversemap;
	map<string,string>::iterator iter;
	string start;
	for(iter=dataSet.begin();iter!=dataSet.end();iter++)
		reversemap[iter->second]=iter->first;
	//find start of itinerary
	for(iter=dataSet.begin();iter!=dataSet.end();iter++)
	{
		if(reversemap.find(iter->first)==reversemap.end())
		{
			start=iter->first;
			break;
		}
	}
	if(start.empty())
	{
		cout<<"Invalid Input\n";
		return;
	}
	iter=dataSet.find(start);
	while(iter!=dataSet.end())
	{
		cout<<iter->first<<"----"<<iter->second<<endl;
		iter=dataSet.find(iter->second);
	}
}


int main()
{
    map<string, string> dataSet; 
    dataSet["Chennai"] = "Banglore"; 
    dataSet["Bombay"] = "Delhi"; 
    dataSet["Goa"] = "Chennai"; 
    dataSet["Delhi"] = "Goa"; 
  
    printItinerary(dataSet); 
    return 0;
}
