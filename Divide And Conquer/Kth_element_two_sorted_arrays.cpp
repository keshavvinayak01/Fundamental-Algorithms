/*
    Input : 2 Sorted arrays
    Output : Kth smallest element in the combined sorted array.

    Approach : Using Divide and Conquer, we can solve this problem in 
               O(logn + logm) time, where n and m are array sizes.

*/
#include<bits/stdc++.h>
using namespace std;

int KthSmallest(int* arr1, int* arr2, int start1, int end1, int start2, int end2, int k) {
    if(start1 == end1) return arr2[k];
    if(start2 == end2) return arr1[k];

    int mid1 = (start1 + end1)/2;
    int mid2 = (start2 + end2)/2;
    if(mid1 + mid2 < k) {
        if(arr1[mid1] > arr2[mid2]) 
            return KthSmallest(arr1, arr2, start1, end1, mid2 + 1, end2, k - mid2 - 1);
        
        else 
            return KthSmallest(arr1, arr2, mid1 + 1, end1, start2, end2, k - mid1 - 1);
    }
    else {
        if(arr1[mid1] > arr2[mid2]) 
            return KthSmallest(arr1, arr2, start1, mid1, start2, end2, k);
        
        else 
            return KthSmallest(arr1, arr2, start1, end1, start2, mid2, k); 
    }
}

int main() {
    int t, n, m, k;
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        int* arr1 = new int[n];
        int* arr2 = new int[m];
        for(int i = 0 ; i < n ; i++) cin >> arr1[i];
        for(int i = 0 ; i < m ; i++) cin >> arr2[i];
        cout << KthSmallest(arr1, arr2, 0, n-1, 0, m-1, k-1) << endl;
        delete[] arr1;
        delete[] arr2;
    }
}