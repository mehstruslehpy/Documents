#include "definitions.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1)  ///if they only specify the executable
    {
        interactiveMode();
    }
    else
    {
        commandLineMode(argc, argv);
    }
    return 0;
}
