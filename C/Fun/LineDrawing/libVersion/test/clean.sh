#!/bin/sh
cd test
astyle testSources/*.c
rm testObjects/*.o testObjects/*.out testScripts/*.out testSources/*.orig
cd ..
