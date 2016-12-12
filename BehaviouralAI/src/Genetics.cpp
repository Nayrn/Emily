#include "Genetics.h"
#include <iostream>
#include <algorithm>
#include <vector>

/*
void Genetics::beginPopulation()
{
    std::cout << "calling" << std::endl;
    m_vGenomes.clear();

    for (int i = 0; i < m_popSize; i++)
    {
        m_vGenomes.push_back(Genome(m_iChromosomeLen));
    }

    m_iGen = 0;
}


Genetics::~Genetics()
{
}

void Genetics::Breed(const std::vector<int>& mother, const std::vector<int>& father, std::vector<int>& child0, std::vector<int> &child1)
{
    int iRand = rand() % 1;
    (float)iRand;

    if (iRand > m_dCrossRate || (mother == father))
    {
        child0 = mother;
        child1 = father;
        return;
    }
    else
    {
        child0 = father;
        child1 = mother;
    }

    //
    int crossPoint = rand() % m_iChromosomeLen - 1;
    m_popSize++;
}

// will not need crossover
void Genetics::crossOver()
{
}

void Genetics::Mutate()
{
}

void Genetics::mutate(std::vector<int>& vecBits)
{
}

void Genetics::CrossOver(const std::vector<int>& mother, const std::vector<int>& father, std::vector<int>& child)
{
}

Genome & Genetics::RouletteSelection()
{
    int iSlice = rand() % 10 * m_iTotalFitness;   // grab a random value, multiply by agent fitness
    float ciTotal = 0.0f;
    int selectedGenome = 0;

    for (int i = 0; i < m_popSize; ++i)   // this for loop adding chromosome total to the fitness of genomes
    {
        ciTotal += m_vGenomes[i].m_iFitness;

        if (ciTotal > iSlice)
        {
            selectedGenome = i;  // this if statement checking if chromosome total is greater than multiplied fitness, if yes, selected genome added to agent genome
            break;
        }
    }

    return m_vGenomes[selectedGenome];
}

*/

Genome::Genome(const int a_iNumBits)
{
    for (int i = 0; i < a_iNumBits; ++i)
    {
        m_vGenes.push_back(rand() % 21 + 10);
    }
}

Genome* Genome::Clone() const
{
    Genome* pNewGenome = new Genome(m_vGenes.size());
    pNewGenome->m_vGenes = m_vGenes;

    return pNewGenome;
}
