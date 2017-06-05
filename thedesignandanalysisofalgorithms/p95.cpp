//
//  p95.cpp
//  thedesignandanalysisofalgorithms
//
//  Created by 追寻梦之碎片 on 2017/6/1.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <vector>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution{
public:
    vector<int> dfs(UndirectedGraphNode *node){
        
    }
    
};

int main(int argc,const char *argv[]){
    vector<UndirectedGraphNode> graph;
    for(int i=0;i<10;++i)
        graph.push_back(UndirectedGraphNode('a'+i));
    graph[0].neighbors={&graph[2],&graph[3]};
    graph[1].neighbors={&graph[4],&graph[5]};
    graph[2].neighbors={&graph[0],&graph[3]};
    graph[3].neighbors={&graph[0],&graph[2]};
    graph[4].neighbors={&graph[1],&graph[5]};
    graph[5].neighbors={&graph[1],&graph[4]};
    graph[6].neighbors={&graph[7],&graph[9]};
    graph[7].neighbors={&graph[6],&graph[8]};
    graph[8].neighbors={&graph[7],&graph[9]};
    graph[9].neighbors={&graph[6],&graph[8]};
    
    return 0;
}



