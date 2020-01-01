#include <iostream>
#include <algorithm>

using namespace std;

char candy[50][50];

int check(int n){
    int answer = 1;
    for(int i=0; i<n; i++){
        int count = 1;
        for(int j=1; j<n; j++){
            if(candy[i][j] == candy[i][j-1])
                count++;
            else
                count = 1;
            if(answer < count)  answer = count;
        }
        count = 1;
        for(int j=1; j<n; j++){
            if(candy[j][i] == candy[j-1][i])
                count++;
            else
                count = 1;
            if(answer < count) answer = count;
        }
    }
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> candy[i][j];

    int answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j+1 < n){
                swap(candy[i][j], candy[i][j+1]);
                int temp = check(n);
                if(temp > answer)   answer = temp;
                swap(candy[i][j], candy[i][j+1]);
            }
            if(i+1 < n){
                swap(candy[i][j], candy[i+1][j]);
                int temp = check(n);
                if(temp > answer)   answer = temp;
                swap(candy[i][j], candy[i+1][j]);
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
