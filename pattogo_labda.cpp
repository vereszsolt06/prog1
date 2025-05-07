#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    int x=1,y=1,dx=1,dy=1;
    int w=30,h=20;
    for(;;){
        system("cls");
        for(int i=0;i<=h;i++) {
            for(int j=0;j<=w;j++)
                if(i==y && j==x) cout<<'O';
                else if(i==0 || i==h)
                    cout<<'-';
                else if(j==0 || j==w)
                    cout<<'|';
                else cout<<' ';
            cout << '\n';
        }
        x+=dx;
        y+=dy;
        if(x==1 || x==w) dx*=-1;
        if(y==1 || y==h) dy*=-1;
        this_thread::sleep_for(chrono::milliseconds(40));
    }
    return 0;
}
