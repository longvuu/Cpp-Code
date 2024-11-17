#include <iostream>
using namespace std;
 
int n, k;
int arr[20];
void read ()
{
	cin>>n>>k;
	arr[0]=0;
	for (int i=1; i<=n; i++)
	{
		int tmp;
		cin>>tmp;
		arr[i]=arr[i-1]+tmp;
	}
}
 
int count=0;
int tim (int x, int bg, int ed, int K)
{
	if (bg > ed) return 0;
	if (K==1)
	{
		if (x==arr[ed]-arr[bg-1])
		{
			count++;
			return 1;
		}
		else return 0;
	}
	else if (K==0) return 0;
	else
	{
		int BG = bg;
		for (int i=bg; i<=ed; i++)
		{
			if (arr[i]-arr[BG-1]==x)
			{
				tim (x, i+1, ed, K-1);
			}
		}
	}
	return 0; 
}
 
int main ()
{
	read ();
	if (k==1)
	{
		count=1;
	}
	else
	{
		for (int i=1; i<=n; i++)
		{
			int label = arr[i];
			tim (label, i+1, n, k-1);
		}
	}
	cout<<count;
	return 0;
}