This program draws plane y=mx+b lines

Because each (x,y) element in the plane needs to be a discrete integer there is a loss of 'resolution'
in certain lines. Essentially as the slope gets steeper more points are lost due to the nature of drawing with
discrete 'cells'

Things to note:
	-The origin is centered at the top left
	-y values count from the orgin POSITIVELY downward
	-when the program reaches the bottom of the window it continues onward horizontally 

Model of the drawing coordinates:
	 x
	y[(0,0)(1,0)(2,0)(3,0)]
	 [(0,1)(1,1)(2,1)(3,1)]
	 [(0,2)(1,2)(2,2)(3,2)]
	 [(0,3)(1,3)(2,3)(3,3)]

I will probably add in options to specify command line args in the future
