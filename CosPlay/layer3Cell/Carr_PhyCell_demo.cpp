#include<iostream>

using namespace std;

struct PhyReq
{
	int cell_id;
	int power;
	string aau_moid;
};

class Carrier
{
public:
	Carrier(PhyReq req):cell_req(req){};
	void add(){count++;}
	inline void printPower(){cout << cell_req.cell_id << "-" << cell_req.power << "- count:" << count << " aau_moid:" << cell_req.aau_moid << endl;}
	int count = 0;
	PhyReq cell_req;
};

int main()
{
	PhyReq req1 = { 0 };
	PhyReq req2 = {2,168,"prru-1"};
	Carrier carr1(req1);
	Carrier carr2(req2);

    cout << "carr1 addr:" << &carr1 << endl;
    cout << "carr2 addr:" << &carr2 << endl;
	
	carr1.add();
	carr1.printPower();

	carr1.add();
	carr2.printPower();
	return 0;
}
