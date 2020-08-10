#include<iostream>
#include "cos_common.h"
#include "carrier_obj.h"
#include "phy_cell.h"

using namespace std;


int main()
{
	T_RnlcCarrierCfgReq carr_req = { 1, 328};
	carrier_obj* obj = new carrier_obj(carr_req);

	T_RnlcPhyCellCfgReq phy_cell_req = { 1, 0x100};
	phy_cell* phyCell = new phy_cell(phy_cell_req);

	phyCell->carr_info = obj;

	obj->carrierReq.phy_cell_list.push_back(phyCell);

	obj->cellshow();
	phyCell->phycellshow();
	phyCell->carr_info->cellshow();
	obj->carrierReq.phy_cell_list[0]->phycellshow();


	return 0;
}