#pragma once
#include "UtilityNPC.h"
class GeneticsNPC : public UtilityNPC
{
public:
	GeneticsNPC() = delete;
	GeneticsNPC(World* m_pWorld);
	~GeneticsNPC();

	void selectAction();
protected:
private:

};