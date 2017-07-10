#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include <iostream>
#include <cstdlib>
#include <ctime>
enum CType { MAJ, MIN, DIM, AUG, SUS2, SUS4};

struct Chord
{
	int root;
	int type;	///can be major, minor, diminished, augmented, sus2, or sus4
	int extraTones;	///dictates the number of extra tones to choose which will be randomly generated we will limit this to four..
};

Chord genChord();
int printChord(Chord&);
int emitNote(Chord&);
int emitType(Chord&);
int emitTones(Chord&);

#endif
