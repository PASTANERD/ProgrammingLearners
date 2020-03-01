
//16917
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int A, B, C;
    int X, Y;
    
    cin >> A >> B >> C >> X >> Y;
    
    int ans;
    
    //case 1 : 양 x개, 후 y개 구매
    ans =  A*X + B*Y;
    
    //case 2 : 반반 max(2X, 2Y)개
    ans = min(ans,max(2*X,2*Y)*C);

    //case 3 : 반반 min(2X, 2Y)개 + 부족한 치킨 더
    int total = min(2*X,2*Y)*C;
    if(X > Y)
        total += A*(X-(min(2*X,2*Y)/2));
    else if(X < Y)
        total += B*(Y-(min(2*X,2*Y)/2));
    ans = min(ans,total);

    cout << ans;
}
