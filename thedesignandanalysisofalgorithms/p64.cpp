//
//  p64.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/5/17.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution1{//递归
public:
    int fibonacci(int n){
        if(n==0||n==1) return n;
        return fibonacci(n-1)+fibonacci(n-2);
    }
};

class Solution2{//公式，涉及到精度
public:
    int fibonacci(int n){
        if(n==0||n==1) return n;
        double fai1=(1+sqrt(5))/2.0;
        double fai2=(1-sqrt(5))/2.0;
        double result=(pow(fai1,n)-pow(fai2,n))/sqrt(5);
        return result;
    }
};

class Solution3{
public:
    int fibonacci(int n){
        vector<vector<int>> matrix={{0,1},{1,1}};
        vector<vector<int>> result={{0,1},{1,0}};
        for(int i=0;i<n;++i)
            result=matrixmultiply(result, matrix);
        return result[0][1];
    }
private:
    vector<vector<int>> matrixmultiply(vector<vector<int>> &nums1,vector<vector<int>> &nums2){
        vector<vector<int>> result(nums1.size(),vector<int>(nums2[0].size(),0));
        int loop=nums2.size();
        for(int i=0;i<nums1.size();++i)
            for(int j=0;j<nums2[0].size();++j)
                for(int k=0;k<loop;++k)
                    result[i][j]+=nums1[i][k]*nums2[k][j];
        return result;
    }
};

int main(int argc,const char *argv[]){
    Solution2 s3;
    for(int i=0;i<10;++i) cout<<s3.fibonacci(i)<<" ";
    cout<<endl;
    return 0;
}
