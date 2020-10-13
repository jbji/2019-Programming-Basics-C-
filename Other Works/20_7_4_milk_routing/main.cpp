#include <iostream>

using namespace std;

int main() {
    int N,M,X,I,J;
    double L,C;
    cin >> N >> M >> X;
    int node[N+1][N+1];
    double delay[N+1][N+1];
    //将节点全部填充为1（走不通）
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            node[i][j]=1;
        }
    }
    //读入并标记
    for(int i=0;i<M;i++){
        cin >> I >> J >> L >> C;
        node[I][J] = node[J][I] = 0;
        delay[I][J] = delay[J][I] = L+X/C;
    }


    return 0;
}
