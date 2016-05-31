#ifndef UTILITY_NPC_H_
#define UTILITY_NPC_H_

#include "BaseNPC.h"

#include <vector>
#include <map>
#include <string>

#include "UtilityScore.h"
#include "UtilityValue.h"

using namespace UtilitySystem;

class UtilityNPC : public BaseNPC
{
public:
	UtilityNPC(World* pWorld);
	~UtilityNPC();

protected:
	void selectAction(float a_fdeltaTime) override;
	UtilityValue getFood() { return m_foodvalue; }
	int setFood(int a_iMinFood, int a_iMaxFood);
	UtilityValue getWater() {return m_waterValue; }
	int setWater(int a_iMinWater, int a_iMaxWater);
	UtilityValue getRested() {return m_restedValue; }
	int setRested(int a_iMinRested, int a_iMaxRested);

private:
	UtilityValue m_waterValue;
	UtilityValue m_foodvalue;
	UtilityValue m_restedValue;

	int m_iMinFood, m_iMaxFood;
	int m_iMinWater, m_iMaxWater;
	int m_iMinRested, m_iMaxRested;

	std::map<std::string, UtilityScore*> m_pUtilityScoreMap;
};

#endif