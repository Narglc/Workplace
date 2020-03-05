//
//  UnionFind.h
//  AlgorithmVideo
//
//  Created by Narglc on 2020/3/5.
//  Copyright © 2020 Narglc. All rights reserved.
//

#ifndef UnionFind_h
#define UnionFind_h
#include <cassert>

class UnionFind{

private:
    int *id;
    int count;
    
public:
    UnionFind(int n)
    {
        count = n;
        id = new int[n];
        for(int i = 0; i < n; i++)
            id[i] = i;
    }
    
    ~UnionFind()
    {
        delete [] id;
    }
    
    int find(int p)
    {
        assert(p >= 0 && p < count)
        return id[p];
    }

    bool isConnected(int p, int q)
    {
        return find[p] == find[q]
    }

    void unionElement(int p, int q)
    {
        int pId = find(p);
        int qId = find(q);
        if(pId == qId)
            return;
        else
            id[p] = qId;
    }
};



#endif /* UnionFind_h */
