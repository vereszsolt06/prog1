#include <iostream>
#include <vector>
#include <thread>

using namespace::std;

void cpu_heavy(){
    while(true){
        unsigned long long int l=1;
        for(int i=1;i<INT_MAX;i++){
            l^=(i*41246747)%2145325121;
        }
    }
}

int main(){
    unsigned int t_count=thread::hardware_concurrency();
    vector<thread> ts;
    for(unsigned int i=0;i<t_count;i++){
        ts.emplace_back(cpu_heavy);
        ts.back().detach();
    }
    while(true)
        this_thread::sleep_for(chrono::seconds(1));
    return 0;
}
