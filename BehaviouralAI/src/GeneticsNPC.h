#pragma once
#include "UtilityNPC.h"
#include <list>

class GeneticsNPC : public UtilityNPC
{
public:
    GeneticsNPC() = delete;
    GeneticsNPC(World* m_pWorld, class Genome* pGenome);
    GeneticsNPC(World* m_pWorld, GeneticsNPC* pParent);
    ~GeneticsNPC();

    void SetGenome(class Genome* pGenome);
    Genome* GetGenome();

    void UpdateGenome();
	std::list<Genome> m_genomes;
protected:
private:
    class Genome* m_genome;

};