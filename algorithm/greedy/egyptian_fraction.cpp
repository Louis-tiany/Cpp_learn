#include<iostream>


using namespace std;

void printEgyptian(int nr,int dr)
{
	if(nr==0||dr==0)
		return;
	if(dr%nr==0)
	{
		cout<<"1/"<<dr/nr;
		return;
	}
	if(nr%dr==0)
	{
		cout<<nr/dr;
		return;
	}
	if(nr>dr)
	{
		cout<<nr/dr<<"+";
		printEgyptian(nr%dr,dr);
		return;
	}
	int n=dr/nr+1;
	cout<<"1/"<<n<<"+";
	printEgyptian(nr*n-dr,dr*n);
}


int main()
{
	int nr=6;
	int dr=14;
	cout<<"egypitan fractian representation:"<<nr<<"/"<<dr<<"\n";
	printEgyptian(nr,dr);
	cout<<"\n";
	return 0;
}
