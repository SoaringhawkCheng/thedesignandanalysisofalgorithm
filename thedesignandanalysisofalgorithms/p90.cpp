//
//  p90.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/5/18.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <map>
using namespace std;

struct UndirectedGraphNode{
    map<UndirectedGraphNode *,int> neighbors;
};

class Solution{
public:
    vector<vector<int>> shortestcircuit(vector<UndirectedGraphNode> &graph){
        vector<int> nums={0,1,2,3};
        vector<vector<int>> result;
        int minpath=INT_MAX;
        do{
            int path=countpath(graph, nums);
            if(path<minpath){
                minpath=path;
                result.clear();
                result.push_back(nums);
            }
            else if(path==minpath)
                result.push_back(nums);
        }while (next_permutation(nums));
        return result;
    }
private:
    bool next_permutation(vector<int> &nums){
        auto pos=nums.rbegin();
        do{
            advance(pos, 1);
        }while(pos!=prev(nums.rend())&&*pos>=*prev(pos));
        if(pos==prev(nums.rend())) return false;
        auto change=find_if(nums.rbegin(), pos, bind1st(less<int>(),*pos));
        iter_swap(pos, change);
        reverse(nums.rbegin(), pos);
        return true;
    }
    int countpath(vector<UndirectedGraphNode> &graph,vector<int> &nums){
        int path=0;
        for(int i=0;i<nums.size();++i){
            path+=graph[nums[i]].neighbors[&graph[nums[(i+1)%nums.size()]]];
        }
        return path;
    }
};

int main(int argc,const char *argv[]){
    vector<UndirectedGraphNode> graph(4);
    graph[0].neighbors.insert(make_pair(&graph[1], 2));
    graph[0].neighbors.insert(make_pair(&graph[2], 5));
    graph[0].neighbors.insert(make_pair(&graph[3], 7));
    graph[1].neighbors.insert(make_pair(&graph[2], 8));
    graph[1].neighbors.insert(make_pair(&graph[3], 3));
    graph[2].neighbors.insert(make_pair(&graph[3], 1));
    graph[1].neighbors.insert(make_pair(&graph[0], 2));
    graph[2].neighbors.insert(make_pair(&graph[0], 5));
    graph[3].neighbors.insert(make_pair(&graph[0], 7));
    graph[2].neighbors.insert(make_pair(&graph[1], 8));
    graph[3].neighbors.insert(make_pair(&graph[1], 3));
    graph[3].neighbors.insert(make_pair(&graph[2], 1));
    
    Solution s;
    vector<vector<int>> result;
    result=s.shortestcircuit(graph);
    for(auto res:result){
        for(auto r:res)
            cout<<r<<" ";
        cout<<endl;
    }
    return 0;
}
