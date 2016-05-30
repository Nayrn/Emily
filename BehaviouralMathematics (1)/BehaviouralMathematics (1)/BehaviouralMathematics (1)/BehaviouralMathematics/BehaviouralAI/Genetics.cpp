#include "Genetics.h"
#include <iostream>
#include <algorithm>
#include <vector>


void Genetics::beginPopulation()
{
	std::cout << "calling" << std::endl;
	m_vGenomes.clear();
	
	for (int i = 0; i < m_popSize; i++)
	{		
		m_vGenomes.push_back(Genome(m_iChromosomeLen, iGeneLength));
	}
	
	m_iGen = 0;
}


Genetics::~Genetics()
{
}

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
	int selectedGenome;
	
	return m_vGenomes[selectedGenome];
}



//------------------------------------
// separate Genome from Genetics class
//------------------------------------

std::vector<int> Genome::Decode()
{
	return std::vector<int>();
}

Genome::Genome(const int a_iNumBits, const int a_iGeneSize)
{
	

	for (int i = 0; i < a_iNumBits; ++i)
	{		
	 m_vBits.push_back(rand() % 1);
	}
}
