#ifndef GA_H_
#define GA_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <algorithm>
#include <functional>
#include "utils.h"

using namespace std;

class GA {
	class Population;
	class Chromosome;
public:
	GA(std::function< double(vector<double>)>  f, size_t numOfGenes): f(f) {
		size_t numOfChromo = 200;
		this->population = Population(numOfChromo, numOfGenes);
	}

	void evolve() {
		cout << fixed << showpoint;
		cout << setprecision(5);
		for(;;) {

			vector<Chromosome> chromoVec = population.getChromosomes();
			vector<Chromosome> topChromosomes(chromoVec.end() - 10, chromoVec.end());
			for(auto chromo: topChromosomes) {
				vector<double> genes = chromo.getGenes();
				for(int i = 0; i < genes.size(); ++i) {
					cout << genes[i] << "     ";
				}
				cout << "\033[1;31mER:" << chromo.calculateError(f) << "\033[0m\n";
				cout << '\n';
			}
			population.keepByPercentage(10);
			population.generateNewChromosomes();
			population.sortChromosomes(f);
		}
	}

private:

	class Population {
	public:
		Population(size_t numOfChromo, size_t numOfGenes): numOfChromo(numOfChromo) {
			for(size_t i = 0; i < numOfChromo; ++i) {
				chromoVector.push_back(Chromosome(numOfGenes, -30, 30));
			}

		}
		Population(): Population(0,0) {}

		Population(const vector<Chromosome> chromoVector): chromoVector(chromoVector) {}

		const vector<Chromosome> getChromosomes() {
			return chromoVector;
		}
		
		void sortChromosomes(std::function<double(vector<double>)> f) {
			std::sort(chromoVector.begin(), chromoVector.end(), [&](Chromosome &lhs, Chromosome &rhs) {
				return lhs.calculateError(f) > rhs.calculateError(f);
			});
		}

		void keepByPercentage(float n) {
			if(!(n >= 0 || n <= 100)) throw std::runtime_error("Invalid percentage.");
			size_t numOfElemToRemove = 100 - ((n / 100) * chromoVector.size());
			chromoVector.erase(chromoVector.begin(), chromoVector.begin() + numOfElemToRemove);
		}

		void generateNewChromosomes() {
			size_t currentNumOfChromosomes = this->chromoVector.size();
			size_t numOfChromoPerChromo = (numOfChromo / currentNumOfChromosomes - 1);

			for(auto chromo: chromoVector) {
				for(size_t j = 0; j < numOfChromoPerChromo; ++j) {
					auto tmp = chromo;
					tmp.mutate();
					chromoVector.push_back(tmp);
				}
			}
		}

	private:
		vector<Chromosome> chromoVector;
		size_t numOfChromo;
	};

	class Chromosome {
		public:
			Chromosome(size_t numOfGenes, double min, double max)
			{
				geneVector.reserve(numOfGenes);
				for(size_t i = 0; i < numOfGenes; ++i) {
					geneVector.push_back(randomDouble(min, max));
				}
			}
			
			Chromosome(vector<double> geneVector): geneVector(geneVector) {}

			const vector<double> getGenes() {
				return geneVector;
			}

			double calculateError(std::function< double(vector<double>) > f) {
				double result = f(geneVector);
				return result*result;
			}

			// Where all the magic happens.
			void mutate() {
				size_t n = randomInt(0, geneVector.size() - 1);
				geneVector[n] = geneVector[n] * randomDouble(-2, 2);
			}

		private:
			vector<double> geneVector;
	};
	Population population;
	std::function< double(vector<double>) > f;
	size_t numOfChromo;
};

#endif /* GA_H_ */
