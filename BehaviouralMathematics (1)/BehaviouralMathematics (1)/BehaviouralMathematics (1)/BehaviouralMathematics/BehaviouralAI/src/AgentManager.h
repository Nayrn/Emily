#pragma once
#include "Genetics.h"
#include "BaseNPC.h"
#include "UtilityNPC.h"
#include "World.h"
class AgentManager
{
public:
	Genetics* m_genetics;
	BaseNPC* m_pNPC;
	void managePopulation();
	void findOther();
	BaseNPC* m_pNPCOther;
	World* m_pWorld;
	AgentManager();
	~AgentManager();

};
