#ifndef BASE_NPC_H_
#define BASE_NPC_H_

#include <glm/glm.hpp>

class World;

class BaseNPC
{
public:
    //Don't want any base constructor
    BaseNPC() = delete;

    BaseNPC(World* a_pWorld);
    ~BaseNPC();

    void update(float a_fdeltaTime);
    void render();

    void SetColour(glm::vec4& colour) { m_renderColour = colour; }
	glm::vec4 getColour() { return m_renderColour; }
	//void GetColour(glm::vec4 colour);
    bool isAlive() { return m_bAlive; }
    //This will just output the NPC's vitals and information to the console
    void reportStatus();

    unsigned int getWaterValue() const { return m_uiWater; }
    unsigned int getFoodValue() const { return m_uiFood; }
    unsigned int getRestValue() const { return m_uiRested; }
    unsigned int getNumberOfLogs() const { return m_uiNumberOfLogs; }

    glm::vec3	 getPosition() const { return m_vPosition; }
    World*			m_pWorld;
    float			m_fLifeTime;
	bool			isIntroverted;
protected:
    //Called every frame by update - should call one of the behaviour functions below.
    virtual void selectAction(float a_fdeltaTime) { collectWater(a_fdeltaTime); }

    //Different behaviours that our AI can run - these will move the AI towards the required location
    //and then do the task.
    void collectWater(float a_fdeltaTime);
    void collectFood(float a_fdeltaTime);
    void rest(float a_fdeltaTime);
    void breed(float a_fdeltaTime);

    void chopTree(float a_fdeltaTime);
    void buildHouse(float a_fdeltaTime);
    void updateLifeTime(float a_fdeltaTime);


private:
    bool travelTo(glm::vec3 a_vLoc, float a_fDeltaTime);

    void checkAlive();
    void calculateStatusChange();
    glm::vec3		m_vPosition;

    unsigned int	m_uiFood;
    unsigned int	m_uiWater;
    unsigned int	m_uiRested;

    unsigned int	m_uiNumberOfLogs;
	int				m_iIntrovert;
	int				m_iBreedCost;
	float			m_fBreedTime;
    float			m_fMoveSpeed;

    bool			m_bAlive;
	
    float			m_fLastReportTime;
    float			m_fReportTime;


    float			m_fLastFoodReductionTime;
    float			m_fLastWaterReductionTime;
    float			m_fLastRestedReductionTime;

    float			m_fFoodReductionTime;
    float			m_fWaterReductionTime;
    float			m_fRestedReductionTime;

    float m_fFoodInteractTime;
    float m_fLastFoodInteractTime;

    float m_fLastWaterInteractTime;
    float m_fWaterInteractTime;

    float m_fLastRestedInteractTime;
    float m_fRestedInteractTime;

    glm::vec4		m_renderColour;
};

#endif