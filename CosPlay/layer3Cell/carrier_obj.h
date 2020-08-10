#ifndef CARRIER_OBJ_H
#define CARRIER_OBJ_H

#include "cos_common.h"

class carrier_obj
{
public:
	carrier_obj(T_RnlcCarrierCfgReq carr_req):carrierReq(carr_req){};
	~carrier_obj();

	inline void cellshow(){std::cout << "cell_id:" << carrierReq.carrier_id << ", aau_type: " << carrierReq.aau_type << std::endl; }


	T_RnlcCarrierCfgReq carrierReq;

};



#endif