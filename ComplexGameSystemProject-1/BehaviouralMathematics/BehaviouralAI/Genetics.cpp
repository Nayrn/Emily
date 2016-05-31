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

void Genetics::Breed(Genome(&mother), Genome(&father))
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
	int iSlice = rand() % 10 * m_iTotalFitness; 
	float ciTotal = 0.0f;
	int selectedGenome = 0;

	for (int i = 0; i < m_popSize; ++i)
	{
		ciTotal += m_vGenomes[i].m_iFitness;

		if (ciTotal > iSlice)
		{
			selectedGenome = i;
			break;
		}
	}

	return m_vGenomes[selectedGenome];
}



//------------------------------------
// separate Genome from Genetics class
//------------------------------------

std::vector<int> Genome::Decode()
{
	std::vector<int> decoded;

	// going through chromosomes a gene at a time
	for (int gene = 0; gene < m_vBits.size(); gene += m_iGeneLength)
	{
		std::vector<int> thisGene;
		for (int bit = 0; bit < m_iGeneLength; ++bit)
		{
			thisGene.push_back(m_vBits[gene + bit]);			
		}

		//converts to int and adds to list of decoded genes
		decoded.push_back(BitToInt(thisGene));
	}
	return std::vector<int>();
}

Genome::Genome(const int a_iNumBits, const int a_iGeneSize)
{


	for (int i = 0; i < a_iNumBits; ++i)
	{
		m_vBits.push_back(rand() % 1);
	}
}

int Genome::BitToInt(const std::vector<int>& vec)
{
	int value = 0;
	int multiplier = 1;

	for (int chromBit = vec.size(); chromBit > 0; chromBit--)
	{
		value += vec[chromBit - 1] * multiplier;
		multiplier *= 2;
	}
	return value;
}
