#include <iostream>
using namespace std;
int n, m, count,k;
int a[100], s[100];
void PrintSolution() {
	int i;
	count++;
	cout<<"The subset #" <<count<<": ";
	for (i=1 ; i<= m ;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void MSet(){
	k = 1; s[k] = 1;
	while(k>0){
		while(s[k] <= n-m+k){
			a[k] = s[k];
			s[k] += 1;
			if (k==m) PrintSolution();
			else{k++; s[k] = a[k-1] + 1;}
		}
		k--;
	}
}
int main(){
	cin >> n >> m;
	a[0] = 0;
	count = 0;
	MSet();
	cout << "Number of " << m << "-elements subsets of set " << n << " elements = " << count << endl;
	return 0;
}