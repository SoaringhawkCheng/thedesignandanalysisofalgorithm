//
//  p3.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/5/16.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

class Solution1{//递归实现
public:
    int euclid(int m,int n){
        if(n==0) return m;
        return euclid(n,m%n);
    }
};

class Solution2{//非递归实现
public:
    int euclid(int m,int n){
        while(n){
            int tmp=m%n;
            m=n;
            n=tmp;
        }
        return m;
    }
};

int main(int argc,const char *argv[]){
    Solution1 s1;
    Solution2 s2;
    cout<<s1.euclid(24, 60)<<endl;
    cout<<s2.euclid(24, 60)<<endl;
}
