/*  Name : Gourav Siddhad
    Codechef - May Long Challenge 2018
    MAY18B-RD19 (Minimum Deletions)
 */

#include <iostream>
using namespace std;

int findGCD(unsigned int[], int);
int mindel(unsigned int[], int);
int deleteelement(unsigned int[], int&, int);

int main() {
    int T, N, *output;
    unsigned int *A;
    cin>>T;
    output = new int[T];
    for(int i=0; i<T; i++) {
        cin>>N;
        A = new unsigned int[N];
        for (int j=0; j<N; j++)
            cin>>A[j];
        output[i] = mindel(A, N);
        delete A;
    }
    for(int i=0; i<T; i++)
        cout<<output[i]<<endl;
    return 0;
}

int mindel(unsigned int A[], int N) {
    int count = 0;
    here:
    int temp = findGCD(A, N);
    if (temp == 1) {
        return count;
    } else if (N==1) {
        return -1;
    } else {
        if(deleteelement(A, N, temp)) {
            count++;
            goto here;
        } else {
            return -1;
        }
    }
}

int deleteelement(unsigned int a[], int &n, int temp) {
    int i=0, flag=0;
    for (i=0; i<n; i++)
        if(temp == a[i]) {
            flag = 1;
            break;
        }
    while(i<n-1) {
        a[i] = a[i+1];
        i++;
    }
    n--;
    return flag;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int findGCD(unsigned int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++)
        result = gcd(arr[i], result);
    return result;
}
