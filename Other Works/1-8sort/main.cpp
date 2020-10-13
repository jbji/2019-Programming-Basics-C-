#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct student{
    int score;
    string name;
}a[100];
int n;
int score_cmp(const student & a, const student & b){
    if(a.score>b.score) return 1;
    if(a.score<b.score) return 0;
    if(a.name<b.name) return 1;
    return 0;
}
int main() {
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i].name;
        cin>>a[i].score;
    }
    sort(a+0,a+n,score_cmp);
    for(int i=0;i<n;i++){
        cout<<a[i].name<<' '<<a[i].score<<endl;
    }
    return 0;
}