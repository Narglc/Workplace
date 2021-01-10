#include<iostream>
#include<vector>

using namespace std;

class phyCell;

struct T_RnlcPhyCellReq{
    int carrier_id;
    int phy_cell_id;
};

class Carrier{
    int carrier_id;

    vector<phyCell*> phy_cell_list;
};

class phyCell{
    T_RnlcPhyCellReq cell_req;
    Carrier* carrier_info;

public:
    void print_info()
    {
        cout << "Carr[" << cell_req.carrier_id << "] PhyCell[" << cell_req.phy_cell_id << "]." << endl;
    }
};



int main()
{
    vector<phyCell*> phyCellVec;
    phyCell* phyCellObj;
    for(int i = 0; i < 5; i++)
    {
        phyCellObj = new phyCell();
        printf("[%d]---> addr:%p\n", i, phyCellObj);
        phyCellVec.push_back(phyCellObj);
    }

    cout << "===========分隔符===========" << endl;

    vector<phyCell*> phyCellVecCpy = phyCellVec;
    for(auto phyCellIter:phyCellVec)
    {
        printf("---> ADDR:%p ", phyCellIter);
        phyCellIter->print_info();
        delete phyCellIter;
    }
    //phyCellVec.clear();
    for(auto phyCellIter:phyCellVec)
    {
        printf("---> ADDR:%p ", phyCellIter);
        phyCellIter->print_info();
    }

    cout << "===========after delete===========" << endl;
    for(auto phyCellIter:phyCellVecCpy)
    {
        printf("---> ADDR:%p ", phyCellIter);
        phyCellIter->print_info();
        //delete phyCellIter;
    }

    cout << "===========结束符===========" << endl;
    return 0;
}