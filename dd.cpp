#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("homework.in");
	ofstream fout("homework.out");
	int n;
	fin>>n;
	double note[n]; 
	double pro[n];
	for(int i=0; i<n; i++){
		int a;
		fin>>a;
		note[i]=a;
	}
	double cont=note[n-1];
	double cos=0;
	int j=1;
	double menor=min(note[n-1], note[n-2]);
	pro[n-1]=note[n-1];
	for(int i=n-2; i>=1; i--){
		if(note[i]<menor){
			menor=note[i];
		}
		cont+=note[i];
		cos=cont-menor;
		pro[i]=cos/j;
		j++;
		cout<<pro[i]<<endl;
	}
	double may=0;
	vector <double> res;
	for(int i=1; i<n-1; i++){
		if(pro[i]>may){
			may=pro[i];
		}
	}
	for(int i=1; i<n-1; i++){
		if(pro[i]==may){
			res.push_back(i);
		}
	}
	int t=res.size();
	for(int i=0; i<t; i++){
		fout<<res[i]<<endl;
	}
	return 0;
}
