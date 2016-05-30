#pragma once

#include <vector>

struct Genome
{

	std::vector<int> Decode();
	Genome(const int a_iNumBits, const int a_iGeneSize);
	std::vector<int> m_vBits;
	int m_iGeneLength;

};

class Genetics // genetic algorithm class
{
public:
	void beginPopulation();
	Genetics(double cross_rate, double mutation_rate, int a_iPopsize, int a_inumBits, int a_iGeneLength) : m_dCrossRate(cross_rate), m_dMutRate(mutation_rate), m_popSize(a_iPopsize), m_iChromosomeLen(a_inumBits), m_iGen(0), iGeneLength(a_iGeneLength) 
	{
		beginPopulation();
	}
	~Genetics();


	


	void crossOver();
	void Mutate();

	int m_iGen; // to keep track of how successful each gen is
	int m_popSize;
	int iGeneLength;
	double m_dCrossRate;
	double m_dMutRate;
	int m_iChromosomeLen;


	void mutate(std::vector<int> & vecBits);

	void CrossOver(const std::vector<int> &mother, const std::vector<int> &father, std::vector<int> &child);

	// need roulette selection to randomise genetics a bit 

	Genome& RouletteSelection();

	std::vector<Genome> m_vGenomes;
protected:

private:

};
