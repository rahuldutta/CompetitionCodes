
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <math.h>
using namespace std;

string cignore[50];
string titles[200];
string sorth[3000];
int sort_corres[3000];

int partition(string arr[], int arr1[],int left, int right)

{
      int i = left, j = right;
      string tmp;
      string pivot = arr[(left + right) / 2];
      int pivot1=arr1[(left + right) / 2];
      while (i <= j) {

            while ((arr[i].compare(pivot) < 0)||(arr[i].compare(pivot) == 0&&arr1[i]<pivot1))
                  i++;
            while ((arr[j].compare(pivot) > 0)||(arr[j].compare(pivot) == 0&&arr1[j]>pivot1))
                  j--;
            if (i <= j) {
            //if(arr[i].compare(arr[j])!=0||(arr[i].compare(arr[j])==0&&arr1[i]>=arr1[j]))
            {
            	  	tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			int tmp1=arr1[i];
			arr1[i]=arr1[j];
			arr1[j]=tmp1;
		}  
		i++;
		j--;
		  
            }
      }

     

      return i;

}

 

void quickSort(string arr[], int arr1[], int left, int right) {

      int index = partition(arr, arr1,left, right);
      if (left < index - 1)
            quickSort(arr, arr1, left, index - 1);
      if (index < right)
            quickSort(arr, arr1, index, right);

}




int main()
{

	string temp;
	int ig_cnt=0;
	int titles_cnt=0;
	int word_cnt=0;
	getline(cin,temp);
	while(temp.compare("::")!=0)
	{
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		cignore[ig_cnt++]=temp;
		getline(cin,temp);
		//temp=temp1;
	}
	while(getline(cin,temp))
	{
		//temp=temp1;
		transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		titles[titles_cnt++]=temp;
		istringstream iss(temp);
		//cout<<temp<<endl;
		string sub;
		while(iss>>sub)
		{
			
			
			int flag=0;
			for(int i=0;i<ig_cnt;i++)
			{
				if(sub.compare(cignore[i])==0)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				//cout<<sub<<endl;
				sorth[word_cnt]=sub;
				sort_corres[word_cnt]=titles_cnt;
				word_cnt++;
			}
		}
	}
	quickSort(sorth,sort_corres, 0,word_cnt-1);
	/*for(int k =0;k<word_cnt;k++)
	{
		cout<<sorth[k]<<" "<<sort_corres[k]<<endl;
	}*/
	int flag=0;
	//cout<<word_cnt;
	for(int j=0;j<word_cnt;j++)
	{
		int f=0;
		istringstream iss(titles[sort_corres[j]-1]);
		string sub;
		while(iss>>sub)
		{

			if(sub.compare(sorth[j])==0 )
			{
				if(f==flag)
				{
					transform(sub.begin(), sub.end(), sub.begin(), ::toupper);
				}
				cout<<sub;
				f++;
			}
			else
			{
				cout<<sub;
			}
			if(!iss.eof())
			cout<<" ";
			else
			cout<<"\n";
		}
		if(j!=word_cnt-1&&sorth[j].compare(sorth[j+1])==0&&sort_corres[j]==sort_corres[j+1])
		{
			flag++;
		}
		else
		{
		flag=0;
		}

	}
	return 0;
}
