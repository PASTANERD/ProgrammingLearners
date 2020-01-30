#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Member{
    int age;
    string name;
    int join;
};

bool compare(const Member& a, const Member& b){
    if(a.age == b.age)
        return a.join < b.join;
    return a.age < b.age;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n;
    cin >> n;

    Member *member = new Member[n];
    for(int i=0; i<n; i++){
        cin >> member[i].age >> member[i].name;
        member[i].join = i;
    }

    sort(member, member+n, compare);

    for(int i=0; i<n; i++)
        cout << member[i].age << " "<< member[i].name << "\n";

    return 0;
}