#include "UtilityNPC.h"

UtilityNPC::UtilityNPC(World * pWorld) : BaseNPC(pWorld)
{
	
	m_waterValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
	m_waterValue.setMinMaxValues(0, 20);
	m_waterValue.setValue(getWaterValue());



	UtilityScore* pWaterScore = new UtilityScore();
	pWaterScore->addUtilityValue(&m_waterValue, 1.0f);
	m_pUtilityScoreMap["collectWater"] = pWaterScore;


	m_foodValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
	m_foodValue.setMinMaxValues(0, 20);
	m_foodValue.setValue(getFoodValue());



	UtilityScore* pFoodScore = new UtilityScore();
	pFoodScore->addUtilityValue(&m_foodValue, 1.0f);
	m_pUtilityScoreMap["collectFood"] = pFoodScore;

}


UtilityNPC::~UtilityNPC()
{
}

void UtilityNPC::selectAction(float a_fdeltaTime)
{


	m_foodValue.setValue(getFoodValue());

	float fBestScore = 0.0f;
	std::string strBestAction;

	for (auto score : m_pUtilityScoreMap)
	{
		float fThisScore = score.second->getUtilityScore();
		if (fThisScore > fBestScore)
		{
			fBestScore = fThisScore;
			strBestAction = score.first;
		}

		if (strBestAction == "collectWater")
		{

			selectAction1(a_fdeltaTime);
		}


		if (strBestAction == "collectFood")
		{
			collectFood(a_fdeltaTime);
		}

	}
}

void UtilityNPC::selectAction1(float a_fdeltaTime)
{
	m_waterValue.setValue(getWaterValue());
	float fBestScore = 0.0f;
	std::string strBestAction;

	for (auto score : m_pUtilityScoreMap)
	{
		float fThisScore = score.second->getUtilityScore();
		if (fThisScore > fBestScore)
		{
			fBestScore = fThisScore;
			strBestAction = score.first;
		}

		if (strBestAction == "collectWater")
		{
			collectWater(a_fdeltaTime);

		}
	}

}

void UtilityNPC::selectAction2(float a_fdeltaTime)
{

	m_restValue.setValue(getRestValue());
	float fBestScore = 0.0f;
	std::string strBestAction;

	for (auto score : m_pUtilityScoreMap)
	{
		float fThisScore = score.second->getUtilityScore();
		if (fThisScore > fBestScore)
		{
			fBestScore = fThisScore;
			strBestAction = score.first;
		}

		if (strBestAction == "rest")
		{
			collectWater(a_fdeltaTime);

		}
	}
}

void UtilityNPC::selectAction3(float a_fdeltaTime)
{
	m_logValue.setValue(getNumberOfLogs());
	float fBestScore = 0.0f;
	std::string strBestAction;
	
	for (auto score : m_pUtilityScoreMap)
	{
		float fThisScore = score.second->getUtilityScore();
		if (fThisScore > fBestScore)
		{
			fBestScore = fThisScore;
			strBestAction = score.first;
			
		}

		if (strBestAction == "chopTree")
		{
			chopTree(a_fdeltaTime);
		}
	}
}

void UtilityNPC::selectAction4(float a_fdeltaTime)
{
}

void UtilityNPC::selectAction5(float a_fdeltaTime)
{

	
	float fBestScore = 0.0f;
	std::string strBestAction;

	for (auto score : m_pUtilityScoreMap)
	{
		float fThisScore = score.second->getUtilityScore();
		if (fThisScore > fBestScore)
		{
			fBestScore = fThisScore;
			strBestAction = score.first;

		}

		if (strBestAction == "reproduce")
		{
			reproduce(a_fdeltaTime);
		}
	}
}

void UtilityNPC::Update(float a_fdeltaTime)
{
	
}

void UtilityNPC::Render()
{
	
}

