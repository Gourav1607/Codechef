/*  Name : Gourav Siddhad
    Codechef - May Long Challenge 2018
    MAY18B-XORAGN (XOR Again)
 */

#include <iostream>
using namespace std;

int main() {
    int T;
    unsigned long int N, *A, *output;
    cin>>T;
    output = new unsigned long int[T];
    for(int i=0; i<T; i++) {
        cin>>N;
        A = new unsigned long int[N];
        unsigned long int result=0;
        for (int j=0; j<N; j++) {
            cin>>A[j];
            result = result^(2*A[j]);
        }
        output[i] = result;
        delete A;
    }
    for(int i=0; i<T; i++)
        cout<<output[i]<<endl;
    return 0;
}
