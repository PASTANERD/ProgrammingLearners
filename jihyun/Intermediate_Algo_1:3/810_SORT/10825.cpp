
//10825
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class student{
    public :
        string name;
        int x, y, z;    //국 영 수
    
    student(string _name, int _x, int _y, int _z){
        name = _name;
        x = _x;
        y = _y;
        z = _z;
    }
};

bool compare(student a, student b){
    if(a.x == b.x){
        if(a.y == b.y){
            if(a.z == b.z){
                return a.name < b.name;
            }
            return a.z > b.z;
        }
        return a.y < b.y;
    }
    return a.x > b.x;
}

int main(){
    int n;
    cin >> n;
    vector<student> v;
    
    for(int i=0; i<n; i++){
        int x, y, z;
        string name;
        cin >> name >> x >> y >> z;
        v.push_back(student(name,x,y,z));
    }

    sort(v.begin(),v.end(),compare);
    
    for(auto p : v)
        cout << p.name << '\n';
}
