#pragma once
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include "UtilityScore.h"
#include "UtilityValue.h"
#include "BaseNPC.h"

using namespace UtilitySystem;

class UtilityNPC : public BaseNPC
{
public:

	UtilityNPC(World* pWorld);
	
	~UtilityNPC();
	void selectAction(float a_fdeltaTime) override;
	void selectAction1(float a_fdeltaTime) override;
	void selectAction2(float a_fdeltaTime) override;
	void selectAction3(float a_fdeltaTime) override;
	void selectAction4(float a_fdeltaTime) override;
	void selectAction5(float a_fdeltaTime) override;

	void Update(float a_fdeltaTime);
	void Render(); 
	
protected:


private:
	UtilityValue m_waterValue;
	UtilityValue m_foodValue;
	std::map<std::string, UtilityScore*>m_pUtilityScoreMap;
	UtilityValue m_restValue;
	UtilityValue m_logValue;
	UtilityValue m_breedValue;
	

};
