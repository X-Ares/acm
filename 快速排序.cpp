#include<iostream>
#include<time.h> 
using namespace std; 
int a[1000];
int quicksort(int v[], int left, int right){
        if(left < right){
                int key = v[left];
                int low = left;
                int high = right;
                while(low < high){
                        while(low < high && v[high] > key){
                                high--;
                        }
                        v[low] = v[high];
                        while(low < high && v[low] < key){
                                low++;
                        }
                        v[high] = v[low];
                }
                v[low] = key;
                quicksort(v,left,low-1);
                quicksort(v,low+1,right);
        }
}
int main()
{
	int n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		//partition(a,0,n-1);
		 quicksort(a,0,n-1);
		for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		printf("\n程序运行了%.2lf秒\n",(double)clock()/CLOCKS_PER_SEC);
	}
}
