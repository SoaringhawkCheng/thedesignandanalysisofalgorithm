//
//  p145.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/6/2.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

//#include <iostream>
//#include <iterator>
//#include <string>
//using namespace std;
//
////class Solution{//书上的大整数相乘分治法
////public:
////    string largeNumberMultiplication(string lhs,string rhs){
////        
////    }
////};
//
//class Solution{//网上的大整数加法和乘法
//public:
//    string largeNumberAdd1(string lhs,string rhs){
//        if(lhs.empty()) return rhs;
//        if(rhs.empty()) return lhs;
//        string result;
//        bool carrybit=false;
//        while(!lhs.empty()&&!rhs.empty()){
//            int lnum=lhs.back()-'0';
//            int rnum=rhs.back()-'0';
//            lhs.pop_back();
//            rhs.pop_back();
//            result.push_back('0'+(lnum+rnum+carrybit)%10);
//            carrybit=(lnum+rnum+carrybit)/10;
//        }
//        while(!lhs.empty()){
//            int num=lhs.back()-'0';
//            lhs.pop_back();
//            result.push_back('0'+(num+carrybit)%10);
//            carrybit=(num+carrybit)/10;
//        }
//        while(!rhs.empty()){
//            int num=rhs.back()-'0';
//            rhs.pop_back();
//            result.push_back('0'+(num+carrybit)%10);
//            carrybit=(num+carrybit)/10;
//        }
//        if(carrybit) result.push_back('1');
//        reverse(result.begin(),result.end());
//        return result;
//    }
//    string largerNumberAdd2(string lhs,string rhs){
//        if(lhs.empty()) return rhs;
//        if(rhs.empty()) return lhs;
//        string result;
//        bool carrybit=false;
//        int i;
//        reverse(lhs.begin(), lhs.end());
//        reverse(rhs.begin(), rhs.end());
//        for(i=0;i<lhs.size()&&i<rhs.size();++i){
//            int lnum=lhs[i]-'0';
//            int rnum=rhs[i]-'0';
//            result.push_back('0'+(lnum+rnum+carrybit)%10);
//            carrybit=(lnum+rnum+carrybit)/10;
//        }
//        while(i<lhs.size()){
//            int lnum=lhs[i]-'0';
//            result.push_back('0'+(lnum+carrybit)%10);
//            carrybit=(lnum+carrybit)/10;
//        }
//        while(i<rhs.size()){
//            int rnum=rhs[i]-'0';
//            result.push_back('0'+(rnum+carrybit)%10);
//            carrybit=(rnum+carrybit)/10;
//        }
//        if(carrybit) result.push_back('1');
//        reverse(result.begin(), result.end());
//        return result;
//    }
//    string largeNumberMultiply(string lhs,string rhs){
//        string result;
//        if(lhs.empty()||rhs.empty()) return result;
//        reverse(lhs.begin(), lhs.end());
//        reverse(rhs.begin(), rhs.end());
//        result=string(lhs.size()+rhs.size(),'0');
//        for(int i=0;i<rhs.size();++i){
//            int carrybit=0;
//            for(int j=0;j<lhs.size();++j){
//                int lnum=lhs[j]-'0';
//                int rnum=rhs[i]-'0';
//                int base=result[i+j]-'0';
//                int tmp=base+lnum*rnum+carrybit;
//                carrybit=tmp/10;
//                result[i+j]='0'+tmp%10;
//            }
//        }
//        while(result.back()=='0') result.pop_back();
//        reverse(result.begin(), result.end());
//        return result;
//    }
//};
//
//int main(int argc,const char *argv[]){
//    string lhs,rhs;
//    lhs="12345";
//    rhs="54321";
//    Solution s;
//    cout<<s.largeNumberAdd1(lhs, rhs)<<endl;
////    cout<<lhs<<" "<<rhs<<endl;
//    cout<<s.largerNumberAdd2(lhs, rhs)<<endl;
////    cout<<lhs<<" "<<rhs<<endl;
//    cout<<s.largeNumberMultiply(lhs, rhs)<<endl;
////    cout<<lhs<<" "<<rhs<<endl;
//    return 0;
//}
