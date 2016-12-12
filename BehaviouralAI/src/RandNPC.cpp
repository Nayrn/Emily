#include "RandNPC.h"


RandNPC::RandNPC(World * m_pWorld) : UtilityNPC(m_pWorld)
{
	setFood(rand() % 10, rand() % 41 + 10);
	setWater(rand() % 10, rand() % 41 + 10);
	setRested(rand() % 10, rand() % 41 + 10);
}

RandNPC::~RandNPC()
{
}
