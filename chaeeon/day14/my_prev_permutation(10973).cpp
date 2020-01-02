
/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/10973
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <algorithm>
#define swap(a, b) temp = a; a = b; b = temp; 
using namespace std;

bool my_prev_perm(int *array, int n){
    int temp = 0;
    int i = n-1;
    while(i > 0 && array[i-1] <= array[i]) i -= 1; // check the two lsbs which are descendent order or not;
    if(i <= 0) return false; // the array has descendent order (ex. 5 4 3 2 1) so there is no next permutation
    else{   // if (i-1)_th number is not in order of descendent, then change it to next order of permuntation
        int j = n-1;
        while(array[j] >= array[i-1]) j-=1;
        swap(array[j], array[i-1])
        sort(array+i,array+n, greater<int>());          // 1 2 4 3 5 --> 1 2 3 5 4
        return true;
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int *arr = new int[N];
    for(int i = 0 ; i < N ; i++) cin >> arr[i];
    if(my_prev_perm(arr, N)) for(int i = 0 ; i < N ; i++) cout << arr[i] << " ";
    else cout << -1;
    return 0;
}