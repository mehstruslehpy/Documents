#!/bin/sh
astyle -r "*.cpp"
astyle -r "*.h"
rm -rf *.o *.orig main
rm IO/*.o IO/*.orig IO/stub
rm Ram/*.o Ram/*.orig Ram/stub
rm RegBank/*.o RegBank/*.orig RegBank/stub
