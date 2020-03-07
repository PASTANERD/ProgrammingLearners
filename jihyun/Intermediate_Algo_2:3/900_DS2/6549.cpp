
//6549
#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while(1){
        cin >> n;
        if(n==0)
            break;
        
        int rect[n];
        for(int i=0; i<n; i++)
            cin >> rect[i];
        
        long long MAX = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            
            //top보다 높이가 크거나 같으면 push
            if(st.empty() || rect[i] >= rect[st.top()]){
                st.push(i); continue;
            }
            
            while(!st.empty() && rect[i] < rect[st.top()]){
                int height = rect[st.top()]; st.pop();
                int weight;
                if(!st.empty())
                    weight = i - st.top() - 1;
                else
                    weight = i;
                
                if((long long)height*weight > MAX)
                    MAX = (long long)height*weight;
                
            }
            
            st.push(i);
        }
        
        int right = st.top();
        while(!st.empty()){
            int height = rect[st.top()]; st.pop();
            int weight;
            if(!st.empty())
                weight = right - st.top();
            else
                weight = right + 1;
            
            if((long long)height*weight > MAX)
                MAX = (long long)height*weight;
        }
        
        cout << MAX << '\n';
    }
}
