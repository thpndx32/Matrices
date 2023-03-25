#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

ofstream mult("Mult.txt");

void mult_mat_1(int m1, int m2, int** mat1, int n1, int n2,
			int** mat2)
{
	int x, i, j;
	int res[m1][n2];
	for (i = 0; i < m1; i++) {
		for (j = 0; j < n2; j++) {
			res[i][j] = 0;
			for (x = 0; x < m2; x++) {
				*(*(res + i) + j) += *(*(mat1 + i) + x)
									* *(*(mat2 + x) + j);
			}
		}
	}
	for (i = 0; i < m1; i++) {
		for (j = 0; j < n2; j++) {
			mult << *(*(res + i) + j) << " ";
		}
		mult << "\n";
	}
    mult.close();
}

void mult_mat_2(int m1, int m2, int** mat1, int n1, int n2,
			int** mat2, int bSz)
{
	int x, i, j;
	int res[m1][n2];
    if(m1%bSz||m2%bSz||n1%bSz||n2%bSz) return;
    for (i = 0; i < m1; i++) {
		for (j = 0; j < n2; j++) {
			res[i][j] = 0;
		}
	}
    int a=m1/bSz,b=n2/bSz,c=m2/bSz;
    for(int ii = 0; ii<bSz; ii++){
        for(int jj = 0; jj<bSz;jj++){
            for(int kk = 0; kk<bSz;kk++){
                for (i = ii*a; i < (ii+1)*a; i++) {
                    for (j = jj*b; j < (jj+1)*b; j++) {
                        for (x = kk*c; x < (kk+1)*c; x++) {
                            *(*(res + i) + j) += *(*(mat1 + i) + x)
                                                * *(*(mat2 + x) + j);
                        }
                    }
                }
            }
        }
    }
	for (i = 0; i < m1; i++) {
		for (j = 0; j < n2; j++) {
			mult << *(*(res + i) + j) << " ";
		}
		mult << "\n";
	}
    mult.close();
}

void inf_mat(ifstream& in,string name, int& x, int& y){
    in.open(name);
    string s;
    vector<string> v_s;
    int c=0;
    while(getline(in,s)){
        v_s.push_back(s);
        //cout<<s<<endl;
    }
    x = v_s.size();
    stringstream ss(s);
    string temp;
    while ( ss >> temp )
    {
        c++;
    }
    y = c;
    in.close();
}

int** mat_gene(ifstream& in,string name, int x, int y){
    int **a;
    a = new int *[x];
    for(int i=0; i<x; i++){
        a[i]  = new int[y];
    }
    in.open(name);
    string s;
    int i=0;
    //cout << "i"<<endl;
    while(getline(in,s)){
        int j = 0;
        //cout << "i"<<endl;
        stringstream ss(s);
        string temp;
        while(ss >> temp){
            //cout<<temp<<" ";
            a[i][j]=stoi(temp);
            j++;
        }
        //cout<<endl;
        i++;
    }
    in.close();
    return a;
}
