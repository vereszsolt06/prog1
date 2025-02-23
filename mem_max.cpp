#include <iostream>
#include <vector>

using namespace::std;

int main(){
    vector<int*> mem_blocks;
    while(true){
        int* i=new int;
        mem_blocks.emplace_back(i);
    }
    return 0;
}
