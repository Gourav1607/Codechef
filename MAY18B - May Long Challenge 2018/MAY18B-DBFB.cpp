/*  Name : Gourav Siddhad
    Codechef - May Long Challenge 2018
    MAY18B-DBFB (Dibs on Fibs)
 */

#include <iostream>
using namespace std;
#define MOD 1000000007

inline long long int mod(long long int a)
{
    return a >= MOD ? a % MOD : a;
}

long long int dbfb(long, long, long long int[], long long int[]);

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    long M, N;
    long long int *A, *B;
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        cin >> M >> N;
        A = new long long int[M];
        B = new long long int[M];
        long long int j = 0;
        for (j = 0; j < M; ++j)
            cin >> A[j];
        for (j = 0; j < M; ++j)
            cin >> B[j];

        cout << (long long int)dbfb(M, N, A, B) << endl;
        delete A;
        delete B;
    }
    return 0;
}

long long int dbfb(long M, long N, long long int A[], long long int B[])
{
    if (N < 2)
        N = 2;
    long long int result = 0, *fib;
    long i = 0;
    fib = new long long int[N];
    fib[0] = 0;
    fib[1] = 0;
    for (i = 0; i < M; ++i)
    {
        fib[0] = mod(fib[0] + (long long int)A[i]);
        fib[1] = mod(fib[1] + (long long int)B[i]);
    }

    for (i = 2; i < N; ++i)
        fib[i] = mod(fib[i - 1] + fib[i - 2]);

    // cout<<fib[0]<<","<<fib[1]<<" = "<<mod(fib[N-1]*mod(M))<<endl;
    result = mod(fib[N - 1] * (long long int)mod(M));
    return result;
}
