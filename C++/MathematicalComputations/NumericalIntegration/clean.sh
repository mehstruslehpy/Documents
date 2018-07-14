#!/bin/sh
astyle -r "*.cpp"
astyle -r "*.h"
rm -rf *.o *.orig main
