#include <iostream>

using namespace std;

int main() {
    int h;
    cin >> h;
    for(int line=0;line<h;line++){
        //第line行，需要输出h-line-1个横杠，1个左斜边，line个空格；
        //line个空格；1个右斜边；h-line-1个横杠，
        for(int i=0;i<h-line-1;i++){
            cout << '-';
        }
        cout << '/';
        if(line!=h-1){
            for(int i=0;i<2*line;i++){
                cout <<' ';
            }
        }else{
            for(int i=0;i<2*line;i++){
                cout <<'_';
            }
        }

        cout << '\\';
        for(int i=0;i<h-line-1;i++){
            cout << '-';
        }
        cout << endl;
    }
    return 0;
}