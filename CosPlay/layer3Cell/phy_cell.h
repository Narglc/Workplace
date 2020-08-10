#ifndef PHY_CELL_H
#define PHY_CELL_H

#include "cos_common.h"
//#include "carrier_obj.h"

class carrier_obj;

class phy_cell
{
public:
	phy_cell(T_RnlcPhyCellCfgReq phy_cell_req):phyCellReq(phy_cell_req){};
	~phy_cell();

	inline void phycellshow(){std::cout << "carrier_id:" << phyCellReq.carrier_id << ", phy_cell_id: " << phyCellReq.phy_cell_id << std::endl; }
	carrier_obj* carr_info;

	T_RnlcPhyCellCfgReq phyCellReq;

};



#endif
