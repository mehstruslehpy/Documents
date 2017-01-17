This is my best stab at implementing variables in my pretend bytecode...
You could also do this with lvalue rvalue style emitted bytecode if you 
change the code in the emitter and in the assignment/ID part of stmt()
but I like the idea of store and load instructions more than lvalue, rvalue
and assignment instructions

