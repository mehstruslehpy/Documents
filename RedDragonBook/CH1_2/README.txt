Various compilers and translators from the first chapter of the book, I could not work out generating real x86 assembly so I settled for a mockup
things like div mod and mul are treated all wrong, actual x86 uses even further extended registers (the real name escapes me) like this eax:edx
after performing its various forms of multiply and divide. 

I also don't have any real comparison operators 

The latest complete iteration is the variables2 directory, it can do assign variables and load their values via abstracted store, load, rvalue
lvalue and assign commands. I initially tried doing this by watching stack push and pops and calculating an offset to the variable via the ebp
but this proved too difficult for me. I may still try and do that because I have seen that sort of thing is done extensively in the book
'Reversing: Secrets of Reverse Engineering' but for now I will settle for abstraction. I like that method on a conceptual level because it is
closer to the bare metal than my current implementation

the latest iteration also supports if expr then stmt type statements

and

while expr do statement type statements

I have not currently implemented pascal style begin ... end statements and I probably won't because it seems to work just fine without them..

Throughout the chapter I also created various infix to postfix translators and a decimal infix to roman numeral expression translator they are
fairly neat.
