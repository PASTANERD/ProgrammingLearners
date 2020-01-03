#include <iostream>
#include <algorithm>

using namespace std;

int findNext(int *a, int n){
    int next=0;
    for(int i=1; i<n; i++){
        if(a[i-1] < a[i])
            next = i;
    }
    return next;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int *a = new int[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

   int next = findNext(a, n);

    if(next == 0){
        next = -1;
        cout << next << "\n";
        return 0;
    }

    int j=next;
    for(int i=next; i<n; i++){
        if(a[next-1] < a[i])
            j = (a[i] < a[j]) ? i : j;
    }
    swap(a[next-1], a[j]);


    /*for(int i=n-1; i>next; i--){
        for(int k=next; k<=i; k++)
            if(a[k] > a[k+1])
                swap(a[k],a[k+1]);
    }*/
    sort(a+next, a+n);

    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << "\n";

    return 0;
}

/**
 * 1 2 3 4
 * 1 2 4 3
 * 1 3 2 4
 * 
 * 4 3 2 1
 * */