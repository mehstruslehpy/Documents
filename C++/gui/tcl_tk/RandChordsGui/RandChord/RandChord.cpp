#include "definitions.h"

using namespace std;

int main()
{
	srand(time(0));
	int amount = 0;
	Chord myChord;

	//not too many and not 0
	amount = (rand() % 16) + 1;
	cout << "Printing: " << amount << " chords\n";

	do
	{
		myChord = genChord();
		printChord(myChord);

		amount--;	//I should probably just do this in a for loop
	} while (amount != 0);
	cout << endl;
	return 0;
}
