#include "Ranking.h"
void main() {
	RankingBoard rank;
	srand((unsigned)time(NULL));
	
	rank.load("ranking.txt");
	rank.print();
	printf("\n");

	for (int i = 0; i < 5; i++) {
		rank.add(rand() % 500, (rand() % 1000) * 0.1);
	}
		
	rank.store("ranking.txt");
}