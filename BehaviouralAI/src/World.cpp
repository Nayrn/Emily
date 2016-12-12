#include "World.h"
#include "Gizmos.h"

#include "gl_core_4_4.h"
#include <GLFW\glfw3.h>

#include <iostream>

#include "UtilityNPC.h"
#include "RandNPC.h"
#include "GeneticsNPC.h"
#include <algorithm>



World::World()
{
    
    //m_houseLocation = glm::vec3(10, 0, -10);
    //m_treeLocation = glm::vec3(-10, 0, -10);

    m_foodLocation = glm::vec3(10, 0, 10);
    m_waterLocation = glm::vec3(0, 0, 10);
    m_restedLocation = glm::vec3(-10, 0, 10);
    m_breedLocation = glm::vec3(0, 0, 0);

    m_uiHouseCurrentLogs = 4;
    m_uiHouseLogsRequired = 10;



    m_fBreedTime = 10.0f;
    m_fHouseInteractTime = 3.0;
    m_fTreeInteractTime = 1.0f;
    m_fBreedInteractTime = 5.0f;
	m_iAgentGen = 0;


    m_fLastHouseInteractTime = 0.0f;
    m_fLastTreeInteractTime = 0.0f;
    m_fLastBreedInteractTime = 0.0f;
    m_pNPC = new BaseNPC(this);
    for (int i = 0; i < 20; i++)
    {
        BaseNPC* pNPC = new GeneticsNPC(this, new Genome(6));
        pNPC->SetColour(glm::vec4(i / 10.0f, 0, i/10.0f, 1));
	
        m_npcs.push_back(pNPC);


    }


}

World::~World()
{

}

void World::update(float dt)
{

    m_breedNPC.clear();

	for (auto it = m_npcs.begin(); it != m_npcs.end(); it++)
	{

		(*it)->update(dt);
		if ((*it)->isAlive() == false)
		{
			delete *it;
			it = m_npcs.erase(it);
			if (it == m_npcs.end()) break;
			
		}

    }


    HandleBreeding();


}

void World::render()
{
    Gizmos::addSphere(m_foodLocation, 1, 8, 8, glm::vec4(1, 0, 0, 1));
    Gizmos::addSphere(m_waterLocation, 1, 8, 8, glm::vec4(0, 0, 1, 1));
    Gizmos::addSphere(m_restedLocation, 1, 8, 8, glm::vec4(0, 1, 1, 1));


    float m_fHouseHeight = 3 * ((float)m_uiHouseCurrentLogs / m_uiHouseLogsRequired);
    glm::vec4 houseColor = (m_uiHouseCurrentLogs >= m_uiHouseLogsRequired) ? glm::vec4(0, 1, 0, 1) : glm::vec4(1, 1, 0, 1);

    //Gizmos::addAABBFilled(m_houseLocation + glm::vec3(0, m_fHouseHeight, 0), glm::vec3(3, m_fHouseHeight, 2), houseColor);

    //Gizmos::addCylinderFilled(m_treeLocation, 1, 2, 8, glm::vec4(0, 1, 0, 1));

    auto it = m_npcs.begin();
    while (it != m_npcs.end())
    {
        if ((*it)->isAlive())
        {
            (*it)->render();
            it++;
        }
        else
        {
            delete *it;
            it = m_npcs.erase(it);
        }
    }
}

void World::addLogToHouse()
{
    if (m_uiHouseCurrentLogs < m_uiHouseLogsRequired)
        m_uiHouseCurrentLogs++;
}



bool World::interactWithOther()
{
    float fCurrentTime = (float)glfwGetTime();
    if (fCurrentTime >= m_fLastOtherInteractTime + m_fOtherInteractTime)
    {
        m_fLastOtherInteractTime = fCurrentTime;
        return true;
    }
    return false;

}

bool World::interactWithTree()
{
    float fCurrentTime = (float)glfwGetTime();
    if (fCurrentTime >= m_fLastTreeInteractTime + m_fTreeInteractTime)
    {
        m_fLastTreeInteractTime = fCurrentTime;
        return true;
    }
    return false;
}

bool World::interactWithHouse()
{
    float fCurrentTime = (float)glfwGetTime();
    if (fCurrentTime >= m_fLastHouseInteractTime + m_fHouseInteractTime)
    {
        m_fLastHouseInteractTime = fCurrentTime;
        return true;
    }
    return false;
}

bool World::interactWithBreedLocation(class BaseNPC* agent)
{
    m_breedNPC.push_back(agent);
    return true;


}

void World::Breed( Genome& p1, Genome& p2, Genome& c1, Genome& c2)
{
	


	/*Get a random number between 0 and number of genes in Genome (swapPoint)*/
	/*At swapPoint, swap all of p1's genes with p2's, and vice versa*/
	/*Store results in child 1 and child2*/
	/*For each gene in child1 and child2, do mutation if required*/

	int swapPoint = rand() % p1.GetGenes().size();


	for (int i = 0; i < p1.GetGenes().size(); ++i)
	{
		if (i <= swapPoint)
		{
			c1.GetGenes()[i] = p1.GetGenes()[i];
			c2.GetGenes()[i] = p2.GetGenes()[i];
		}
		else
		{
			c1.GetGenes()[i] = p2.GetGenes()[i];
			c2.GetGenes()[i] = p1.GetGenes()[i];
		}
	}


	int mutationRate = 5;
	int mutationAmount = 3;
	for (int i = 0; i < p1.GetGenes().size(); ++i)
	{
		int r = rand() % 100;
		if (r <= mutationRate)
		{
			c1.GetGenes()[i] += rand() % (mutationRate * 2) - mutationRate;
		}
		r = rand() % 100;
		if (r <= mutationRate)
		{
			c2.GetGenes()[i] += rand() % (mutationRate * 2) - mutationRate;
		}
	}

}

void World::HandleBreeding()
{
    float fCurrentTime = (float)glfwGetTime();
    if (fCurrentTime >= m_fLastBreedInteractTime + m_fBreedInteractTime)
    {
        std::cout << "Breeding with " << m_breedNPC.size() << " agents!" << std::endl;
        m_fLastBreedInteractTime = fCurrentTime;
        std::random_shuffle(m_breedNPC.begin(), m_breedNPC.end());

		bool bDidBreeding = false;
        while (m_breedNPC.size() >= 2 &&  m_npcs.size() <= 20)
        {
            GeneticsNPC* npc1 = (GeneticsNPC*)*(m_breedNPC.end() - 1);
            m_breedNPC.pop_back();

            GeneticsNPC* npc2 = (GeneticsNPC*)*(m_breedNPC.end() - 1);
            m_breedNPC.pop_back();


            //Breeding goes here!
            GeneticsNPC* pChild1 = new GeneticsNPC(this, new Genome(6));
            GeneticsNPC* pChild2 = new GeneticsNPC(this, new Genome(6));

            Breed(*npc1->GetGenome(), *npc2->GetGenome(), *pChild1->GetGenome(), *pChild2->GetGenome());
            pChild1->UpdateGenome();
            pChild2->UpdateGenome();

			if (m_npcs.size() <= 20)
			{
				m_npcs.push_back(pChild1);
				m_npcs.push_back(pChild2);

				glm::vec4 parentColour = npc1->getColour() * npc2->getColour();

				pChild1->SetColour(glm::vec4(parentColour.x, parentColour.y, parentColour.z, 1));
				pChild2->SetColour(glm::vec4(parentColour.x, parentColour.y, parentColour.z, 1));

				bDidBreeding = true;
			}
			else		
				bDidBreeding = false;
			
			
		
        }

		if (bDidBreeding)
		{
			m_iAgentGen++;
			std::cout << "Generation number:   " << m_iAgentGen << std::endl;
			if (m_iAgentGen > 1000)
			{
				system("pause");
			}

			GeneticsNPC* pOldest = nullptr;
			std::vector<int> averageValue; averageValue.resize(6);
			for (auto it = m_npcs.begin(); it != m_npcs.end(); ++it)
			{
				if (!pOldest || pOldest->m_fLifeTime < (*it)->m_fLifeTime)
				{
					pOldest = (GeneticsNPC*)(*it);
				}

				for (int i = 0; i < 6; i++)
				{
					averageValue[i] = ((GeneticsNPC*)(*it))->GetGenome()->GetGenes()[i];
				}
			}

			for (int i = 0; i < 6; i++)
			{
				averageValue[i] / m_npcs.size();
			}

			if (pOldest)
			{
				Genome* pG = pOldest->GetGenome();
				std::vector<int>& genes = pG->GetGenes();
				std::cout << "Oldest living: " << genes[0] << " "
					<< genes[1] << " "
					<< genes[2] << " "
					<< genes[3] << " "
					<< genes[4] << " "
					<< genes[5] << std::endl;

				std::cout << "Average living: " << genes[0] << " "
					<< averageValue[1] << " "
					<< averageValue[2] << " "
					<< averageValue[3] << " "
					<< averageValue[4] << " "
					<< averageValue[5] << std::endl;
			}
		}
		

        while (m_npcs.size() < 10)
        {
            BaseNPC* pNPC = new GeneticsNPC(this, new Genome(6));
            pNPC->SetColour(glm::vec4(m_npcs.size() / 20.0f, m_npcs.size() / 10.0f, 0, 1));

            m_npcs.push_back(pNPC);
        }
    }

}

glm::vec3 World::getRestedLocation() const
{
    return m_restedLocation;
}

glm::vec3 World::getBreedLocation() const
{
    return m_breedLocation;
}



glm::vec3 World::getFoodLocation() const
{
    return m_foodLocation;
}

glm::vec3 World::getWaterLocation() const
{
    return m_waterLocation;
}

glm::vec3 World::getTreeLocation() const
{
    return m_treeLocation;
}

int World::CalcFitness()
{
    BaseNPC* pNPC = new BaseNPC(this);

    return (int)pNPC->m_fLifeTime;

}

glm::vec3 World::getHouseLocation() const
{
    return m_houseLocation;
}
