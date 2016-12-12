#ifndef WORLD_H_
#define WORLD_H_

#include "glm/glm.hpp"
#include <vector>
#include "UtilityNPC.h"
#include "Genetics.h"


class World
{
public:
    World();
    ~World();
    Genetics* m_genetics;
    BaseNPC* m_pNPC;
    void update(float dt);
    void render();

    void addLogToHouse();
    unsigned int getHouseLogsRequired() const { return m_uiHouseLogsRequired; }
    unsigned int getCurrentHouseLogs() const { return m_uiHouseCurrentLogs; }
    bool isHouseBuilt() { return m_uiHouseCurrentLogs == m_uiHouseLogsRequired; }
    int CalcFitness();
    glm::vec3 getHouseLocation() const;
    glm::vec3 getTreeLocation() const;
    glm::vec3 getWaterLocation() const;
    glm::vec3 getFoodLocation() const;
    glm::vec3 getRestedLocation() const;
    glm::vec3 getBreedLocation() const;





    bool interactWithOther();
    bool interactWithTree();
    bool interactWithHouse();

    bool interactWithBreedLocation(class BaseNPC* agent);
private:
    void Breed(Genome& p1, Genome& p2, Genome& c1, Genome& c2);


    unsigned int m_uiHouseLogsRequired;
    unsigned int m_uiHouseCurrentLogs;

    glm::vec3 m_houseLocation;
    glm::vec3 m_treeLocation;


    glm::vec3 m_waterLocation;
    glm::vec3 m_foodLocation;
    glm::vec3 m_restedLocation;
    glm::vec3 m_breedLocation;

    float m_fHouseInteractTime;
    float m_fTreeInteractTime;


    float m_fOtherInteractTime;

    float m_fLastOtherInteractTime;
    float m_fLastHouseInteractTime;
    float m_fLastTreeInteractTime;


    float m_fBreedTime;
    float m_fBreedInteractTime;
    float m_fLastBreedInteractTime;
    std::vector<class BaseNPC*> m_npcs;
    std::vector<BaseNPC*> m_breedNPC;
	int m_iAgentGen;
    void HandleBreeding();

public:
};

#endif // !WORLD_H_
