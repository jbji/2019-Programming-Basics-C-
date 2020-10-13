#include <iostream>

using namespace std;

int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int difference_NORMAL(int,int,int,int);
int difference_CROSSYEAR(int,int,int,int);
int isIncluded(int,int,int,int);
int main() {
    int T,m1,d1,m2,d2,x;
//    cout << difference_NORMAL(1,0,1,1);

    cin >> T;
    char CASE='?'; //R P ?
    for(int i=0;i<T;i++){
        cin >> m1 >> d1 >> m2 >> d2 >> x;

        int an,ac;
        an=difference_NORMAL(m1,d1,m2,d2);
        ac=difference_CROSSYEAR(m1,d1,m2,d2);
        int key=isIncluded(m1,d1,m2,d2);
//        cout <<key<<' ' << an << ' ' <<ac << endl;
        if(m1>2){

        }else{
            if(an==-1||ac==-1){
                CASE='R';
            }
            if(abs(an-x)<=1){
                if(key){
                    if(x==an){
                        CASE = 'P';
                    }else{
                        CASE = 'R';
                    }
                }
            }else if(abs(ac-x)<=1){
                if(key){
                    if(x==ac){
                        CASE = 'P';
                    }else{
                        CASE = 'R';
                    }
                }
            }
        }

        cout << CASE <<endl;
    }
    return 0;
}
int difference_NORMAL(int m1,int d1,int m2,int d2){
    if(m1==2&&d1==29||m2==2&&d2==29){
        return -1;
    }else{
        int sum=0;
        for(int i=m1;i<m2-1;i++){
            sum+=days[i];
        }
        if(m1<m2){
            return days[m1-1]-d1+sum+d2;
        }else if(m1==m2){
            return -d1+d2;
        }else{
            return -2;
        }
    }
}
int difference_CROSSYEAR(int m1,int d1,int m2,int d2){
    if(m1==2&&d1==29||m2==2&&d2==29){
        return -1;
    }else{
        return difference_NORMAL(m1,d1,12,31)+difference_NORMAL(1,0,m2,d2);
    }
}

int isIncluded(int m1,int d1,int m2,int d2){
    if(m1<=2&&d1<=29&&m2>=m1){
        return 1;
    }
    if(m1<=2&&d1<=29&&m2==2&&d2==29){
        return 1;
    }
    if(m2<=m1&&(m2==2&&d2==29||m2>2)){
        return 1;
    }
    if(m2<=m1&&(m1==2&&d1<=29||m1<2)){
        return 1;
    }
    return 0;
}