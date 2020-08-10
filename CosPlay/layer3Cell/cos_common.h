#ifndef COS_COMMON_H
#define COS_COMMON_H

#include<iostream>
#include<vector>

struct T_RnlcPhyCellCfgReq
{
	int carrier_id;
	int phy_cell_id;
};

class phy_cell;

struct T_RnlcCarrierCfgReq
{
	int carrier_id;
	int aau_type;

	std::vector<phy_cell*> phy_cell_list;
};

#endif