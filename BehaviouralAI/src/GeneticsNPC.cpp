#include "GeneticsNPC.h"
#include <iostream>
#include "Genetics.h"

GeneticsNPC::GeneticsNPC(World* m_pWorld, GeneticsNPC* pParent) : UtilityNPC(m_pWorld)
{
    SetGenome(pParent->GetGenome()->Clone());
}

GeneticsNPC::GeneticsNPC(World* m_pWorld, Genome* pGenome) : UtilityNPC(m_pWorld)
{
    assert(pGenome != nullptr && "Genome can't be null!");
    SetGenome(pGenome);
}

GeneticsNPC::~GeneticsNPC()
{
}

void GeneticsNPC::SetGenome(Genome* pGenome)
{
    m_genome = pGenome;

    UpdateGenome();
}

Genome* GeneticsNPC::GetGenome()
{
    return m_genome;
}

void GeneticsNPC::UpdateGenome()
{
    if (m_genome != nullptr)
    {
        std::vector<int> genes = m_genome->GetGenes();
        setFood(genes[0], genes[1]);
        setWater(genes[2], genes[3]);
        setRested(genes[4], genes[5]);
    }
}
