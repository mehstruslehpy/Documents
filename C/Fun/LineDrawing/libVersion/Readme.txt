SUMMARY:
This library draws various equations and shapes via the ncurses library

Things to note:
	-The origin is centered at the top left
	-y values count from the orgin POSITIVELY downward

Model of the drawing coordinate plane:

     |
  ___|x________________________
    y|[(0,0)(1,0)(2,0)(3,0)]...
     |[(0,1)(1,1)(2,1)(3,1)]...
     |[(0,2)(1,2)(2,2)(3,2)]...
     |[(0,3)(1,3)(2,3)(3,3)]...
     |...
     |...
     |...

BUILDING AND USING:

The various functions are currently documented via comments in the Shapes.h file though I intend to add a more
permanent set of documentation in the future.

Shapes.c is an example program 

exampleProj is another example but this time via a static library

the outer makefile can be used either to build the Shapes.c program via running make or to build libShapes.a via
running: make library

running: make test will build the testing tools and programs inside of ./test

BUGS:
Because each (x,y) element in the plane needs to be a discrete integer there is a loss of 'resolution'
in certain lines. Essentially as the slope gets steeper more points are lost due to the nature of drawing with
discrete 'cells'

This effect can be noticed in Line Segments and also in Triangles

I have fixed it for perfectly vertical lines hence why Rectangles and Squares work fine


