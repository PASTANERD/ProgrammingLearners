/*
*   Baekjoon Online Judge
*   https://www.acmicpc.net/problem/16947
*   
*   Solved by chaeeon lim
*   pastanerd0416@gmail.com
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
bool *visit, check;
int *d;
vector<int> stack;

void print(vector<int> v, string name){
    cout << name <<": {";
    for(vector<int>::iterator itr = v.begin() ; itr != v.end()-1 ; itr++) cout << *itr << ", ";
    cout << v.back() << "}\n";
}

// void dfs(int v, vector<int> *e, int distance){
//     visit[v] = true;
//     d[v] = min(d[v], distance);
//     for(vector<int>::iterator next = e[v].begin() ; next != e[v].end() ; next++){
//         if(d[*next] != 0 && !visit[*next]) dfs(*next, e, distance+1);
//     }
// }

bool cycle_finder(int v, int start, vector<int> *e){
    // if(v == start && check){
    //     print(stack, "stack");
    //     return true;
    // }
    // if(visit[v]) return false;
    if(visit[v]){
        if(v == start) return true;
        else return false;
    }
    stack.push_back(v);
    print(stack, "stack");
    visit[v] = true;
    for(vector<int>::iterator next = e[v].begin() ; next != e[v].end() ; next++){
        if(!visit[*next]) cycle_finder(*next, start, e);
        // if(cycle_finder(*next, start, e)) return true;
    }
    // stack.pop_back();
    return false;
}
// bool cycle_finder(int v, int start, vector<int> *e, vector<int> stack){
//     if() return true;
//     if() return false;
//     cout << "visit: " << v <<'\n';
//     stack.push_back(v);
//     printstack(stack, "stack");  
//     visit[v] = true;   

//     for(vector<int>::iterator next = e[v].begin() ; next != e[v].end() ; next++){
//         if(!visit[*next]){
//             // stack.push_back(*next);
//             // searching_count++;
//             if(cycle_finder(*next, e, stack)) return true;
//         }
//     }

//     return false;
//     // if(){}
//         // reach to start node
//     // if(searching_count == N){
//     //     cout << "searching finished" << '\n';
//     //     for(vector<int>::iterator itr = stack.begin() ; itr != stack.end() ; itr++){
//     //         for(vector<int>::iterator jtr = itr + 2 ; jtr != stack.end() ; jtr++){
//     //             for(vector<int>::iterator edge = e[*itr].begin() ; edge != e[*itr].end() ; edge++){
//     //                 if(*edge == *jtr){
//     //                     vector<int> result(itr, jtr+1);
//     //                     printstack(result, "result");
//     //                     return;
//     //                 }
//     //             }
//     //         }
//     //     }
//     // }
//     // else{
//     //     visit[v] = true;
//     //     for(vector<int>::iterator next = e[v].begin() ; next != e[v].end() ; next++){
//     //         if(!visit[*next]){
//     //             stack.push_back(*next);
//     //             // searching_count++;
//     //             cycle_finder(*next, e, stack);
//     //             stack.pop_back();
//     //         }
//     //     }
//     // }
    
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> adj[N+1];
    // vector<int> temp; 
    for(int i = 0 ; i < N ; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    visit = new bool[N+1];
    fill_n(visit, N+1, false);

    cout << "?\nfinding cycle\n";
    for(int i = 1 ; i <= N ; i++){
        check = false;
        if(cycle_finder(i, i, adj)) break;
    }
    // temp.push_back(1);
    // cycle_finder(1, adj, temp);
    // vector<int> cycle(cycle_finder(1, 1, adj, temp));


    // d = new int[N+1];
    // fill_n(d, N+1, 3000);
    // fill_n(visit, N+1, false);
    // for(vector<int>::iterator itr = cycle.begin() ; itr != cycle.end() ; itr++){
    //     dfs(*itr, adj, 0);
    // }

    // for(int i = 1 ; i <= N ; i++) cout << d[i] << ' ';

    return 0;
}
