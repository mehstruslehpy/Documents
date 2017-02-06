I created this by simply editting how our translator outputs numbers by creating my own number output function in the parser.
really those should probably be moved to the emitter file, they just travers down to the individual digits of the input number 
and convert the number into the appropriate roman numeral representation

as a bonus expressions get translated to postfix though this could be removed
