#include "definitions.h"

using namespace std;

Chord genChord()
{
    //cout << endl;
    Chord outChord;
    outChord.root = ( rand() % ( 0  - 8 + 1 ) );
    //cout << "Root note: "<< outChord.root << endl;
    outChord.type = ( rand() % ( 0  - 10 + 1 ) );
    //cout << "Type: "<< outChord.type << endl;
    outChord.extraTones = rand() % 3;
    //cout << "Extra tones: "<< outChord.extraTones << endl;
    //cout << endl;
    return outChord;
}

int printChord(Chord& inChord)
{
    cout << endl << "---------------------------------------" << endl;
    emitNote(inChord);
    emitType(inChord);
    emitTones(inChord);
	cout << endl;
	return 0;
}

int emitNote(Chord& inChord)
{
    int sharpFlat = 0;
    sharpFlat = rand() % 3;

    switch (inChord.root)
    {
    case 0:
        cout << "A ";
        break;
    case 1:
        cout << "B ";
        break;
    case 2:
        cout << "C ";
        break;
    case 3:
        cout << "D ";
        break;
    case 4:
        cout << "E ";
        break;
    case 5:
        cout << "F ";
        break;
    case 6:
        cout << "G ";
        break;
    default:
        cout << "OOPS ";
    }

    if (sharpFlat == 1)
    {
        cout << "Flat ";
    }
    else if (sharpFlat == 2)
    {
        cout << "Sharp ";
    }

    return 0;
}
int emitType(Chord& inChord)
{
    switch (inChord.type)
    {
    case 0:
        cout << "Maj: ";
        break;
    case 1:
        cout << "Min: ";
        break;
    case 2:
        cout << "Dim: ";
        break;
    case 3:
        cout << "Aug: ";
        break;
    case 4:
        cout << "Sus2: ";
        break;
    case 5:
        cout << "Sus4: ";
        break;
    case 6:
		cout << "Dom7: ";
        break;
    case 7:
		cout << "Half Dim: ";
        break;
    case 8:
		cout << "With Extra Tones: ";
		break;
    default:
        cout << "OOPS OOPS ";
    }
	return 0;
}

int emitTones(Chord& inChord)
{
    int sharpFlat = 0;
    int curTone = ( rand() % ( 2 - 13 + 1 ) );

    for (int i = inChord.extraTones; i != 0; i--)
    {
        sharpFlat = rand() % 3;
        curTone = (rand() % 7) + 2;

        if (sharpFlat == 1)
        {
            cout << "flat ";
        }
        else if (sharpFlat == 2)
        {
            cout << "sharp ";
        }
		else
		{
			cout << "natural ";
		}
		cout << curTone << " ";
    }
	return 0;
}
