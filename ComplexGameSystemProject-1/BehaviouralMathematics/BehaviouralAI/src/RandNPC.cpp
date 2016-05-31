#include "RandNPC.h"


RandNPC::RandNPC(World * m_pWorld) : UtilityNPC(m_pWorld)
{
	setFood(rand() % 5, rand() % 21 + 10);
	setWater(rand() % 5, rand() % 21 + 10);
	setRested(rand() % 5, rand() % 21 + 10);
}

RandNPC::~RandNPC()
{
}
