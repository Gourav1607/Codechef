/*  Name : Gourav Siddhad
    Codechef - May Long Challenge 2018
    MAY18B-MTYFRI (Mighty Friend)
 */

#include <iostream>
using namespace std;

bool mtyfri(int[], int, int);
void insertionsortasc(int[], int);
void insertionsortdesc(int[], int);

int main() {
    int T, N, K, *A;
    bool *output;
    cin>>T;
    output = new bool[T];
    for(int i=0; i<T; i++) {
        cin>>N>>K;
        A = new int[N];
        for (int j=0; j<N; j++)
            cin>>A[j];

        output[i] = mtyfri(A, N, K);

        delete A;
    }

    for(int i=0; i<T; i++)
        if(output[i])
            cout<<"YES\n";
        else
            cout<<"NO\n";

    return 0;
}

bool mtyfri(int A[], int N, int K) {
    long int mscore=0, tscore=0;
    for(int i=0; i<N; i++)
        if(i%2==0)
            mscore += A[i];
        else
            tscore += A[i];

    if(tscore>mscore) {
        return true;
    } else if (K>0){
        int Nm, Nt, *Am, *At;
        Nm=Nt=N/2;
        if(N%2!=0)
            Nm++;
        Am = new int[Nm];
        At = new int[Nt];
        Nm = Nt = 0;
        for(int i=0; i<N; i++) {
            if(i%2==0)
                Am[Nm++] = A[i];
            else
                At[Nt++] = A[i];
        }

        insertionsortdesc(Am, Nm);  // Max to Min
        insertionsortasc(At, Nt);   // Min to Max

        int count=0, cm=0, ct=0;
        while(count<K && cm<Nm && ct<Nt) {
            if(Am[cm]>At[ct]) {
                mscore = mscore + At[ct] - Am[cm];
                tscore = tscore + Am[cm] - At[ct];
                if(tscore>mscore) {
                    return true;
                }
                count++;
                cm++;   ct++;
            } else {
                return false;
            }
        }
        return false;
    }
    return false;
}

void insertionsortasc(int data[], int n) {
	int key=0;
	for(int i=1; i<n; i++) {
		key = data[i];
		int j=i-1;
		while(j>=0 && key<data[j]) {
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=key;
	}
}

void insertionsortdesc(int data[], int n) {
	int key=0;
	for(int i=1; i<n; i++) {
		key = data[i];
		int j=i-1;
		while(j>=0 && key>data[j]) {
			data[j+1]=data[j];
			j--;
		}
		data[j+1]=key;
	}
}
