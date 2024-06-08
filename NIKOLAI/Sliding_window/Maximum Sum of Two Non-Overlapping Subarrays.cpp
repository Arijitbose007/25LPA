#include <vector>
#include <algorithm>

using namespace std;

int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    return max(helper(A, L, M), helper(A, M, L));
}

int helper(vector<int>& A, int L, int M) {
    int n = A.size();
    vector<int> Lmax(n), Mmax(n);
    int Lsum = 0, Msum = 0;
    
    for (int i = 0; i < L; i++) Lsum += A[i];
    Lmax[L-1] = Lsum;
    for (int i = L; i < n; i++) {
        Lsum += A[i] - A[i-L];
        Lmax[i] = max(Lmax[i-1], Lsum);
    }
    
    for (int i = n-1; i >= n-M; i--) Msum += A[i];
    Mmax[n-M] = Msum;
    for (int i = n-M-1; i >= 0; i--) {
        Msum += A[i] - A[i+M];
        Mmax[i] = max(Mmax[i+1], Msum);
    }
    
    int result = 0;
    for (int i = L-1; i < n-M; i++) {
        result = max(result, Lmax[i] + Mmax[i+1]);
    }
    return result;
}
