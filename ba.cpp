#include <bits/stdc++.h>
using namespace std;
vector<int> elsy;
int binarysearch(int ini, int fin, int medio, int x){
	if(ini==fin){
		return 0;
	}
	if(elsy[medio]==x){
		return 1;
	}
	if(x>elsy[medio]){
		int r=binarysearch(medio+1, fin, (ini+fin)/2, x);
		return r;
	}
	else{
		int r=binarysearch(ini, medio-1, (ini+fin)/2, x);
		return r;
    }

}	
	int main(){
	ifstream fin("highcard.in");
	ofstream fout("highcard.out");
	int n;
	fin>>n;
	int bessy[n];
	for(int i=0; i<n; i++){
		int a;
		fin>>a;
		elsy.push_back(a);
	}
	int j=0;
	for(int i=1; i<=n*2; i++){
		if(elsy[j]!=i){
			bessy[i-1]=i;
		}
		else{
			j++;
		}
	}
	int cont=0;
	for(int i=0; i<n; i++){
		int medio=n/2;
		int ini=0;
		int fin=n-1;
		int h=1;
		int u=0;
		bool ok=false;
		while(bessy[i]-h>1 && ok==false){
		     u+=binarysearch(ini, fin, medio, bessy[i]-1);
		     if(u==1){
				 ok=true;
			}
	    }
		cont+=u;
	}
	fout<<cont;
	
	return 0;
}
