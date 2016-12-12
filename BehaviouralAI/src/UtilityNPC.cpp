#include "UtilityNPC.h"

#include "UtilityScore.h"
#include "UtilityValue.h"
#include <iostream>
#include "World.h"

UtilityNPC::UtilityNPC(World* pWorld) : BaseNPC(pWorld)
{


    m_waterValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
    m_waterValue.setMinMaxValues(0, 20);
    m_waterValue.setValue((float)getWaterValue());

    m_foodvalue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
    m_foodvalue.setMinMaxValues(0, 20);
    m_foodvalue.setValue((float)getFoodValue());

    m_restedValue.setNormalizationType(UtilityValue::INVERSE_LINEAR);
    m_restedValue.setMinMaxValues(0, 20);
    m_restedValue.setValue((float)getRestValue());

    UtilityScore* pWaterScore = new UtilityScore();
    pWaterScore->addUtilityValue(&m_waterValue, 1.0f);

    UtilityScore* pFoodScore = new UtilityScore();
    pFoodScore->addUtilityValue(&m_foodvalue, 1.0f);

    UtilityScore* pRestedScore = new UtilityScore();
    pRestedScore->addUtilityValue(&m_restedValue, 1.0f);

    m_pUtilityScoreMap["collectWater"] = pWaterScore;
    m_pUtilityScoreMap["collectFood"] = pFoodScore;
    m_pUtilityScoreMap["rest"] = pRestedScore;
}

UtilityNPC::~UtilityNPC()
{

}

void UtilityNPC::selectAction(float a_fdeltaTime)
{
    m_waterValue.setValue((float)getWaterValue());
    m_foodvalue.setValue((float)getFoodValue());
    m_restedValue.setValue((float)getRestValue());

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
    }

    if (strBestAction == "collectWater")
    {
        collectWater(a_fdeltaTime);
    }
    else if (strBestAction == "collectFood")
    {
        collectFood(a_fdeltaTime);
    }
    else if (strBestAction == "rest")
    {
        rest(a_fdeltaTime);
    }
    else
    {
        //if (m_fLifeTime > 18.0f)
        //{
        breed(a_fdeltaTime);
        //}
    }

}

int UtilityNPC::setFood(int a_iMinFood, int a_iMaxFood)
{
    m_iMinFood = a_iMinFood;
    m_iMaxFood = a_iMaxFood;
    m_foodvalue.setMinMaxValues(m_iMinFood, m_iMaxFood);

    return 0;
}

int UtilityNPC::setWater(int a_iMinWater, int a_iMaxWater)
{
    m_iMinWater = a_iMinWater;
    m_iMaxWater = a_iMaxWater;
    m_waterValue.setMinMaxValues(m_iMinWater, m_iMaxWater);

    return 0;
}

int UtilityNPC::setRested(int a_iMinRested, int a_iMaxRested)
{
    m_iMinRested = a_iMinRested;
    m_iMaxRested = a_iMaxRested;
    m_restedValue.setMinMaxValues(m_iMinRested, m_iMaxRested);

    return 0;
}


