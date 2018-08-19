# WHAT THIS IS:
	-This is a TTP emulator
		-TTP stands for "Taks Toy Processor" it is a processor design used for a class I took
# TIPS AND USAGE:
	-For a first time run of the emulator try: ./main Progams/PascalFinal.ram
	-running ./main <yourbinary> will run your binary on the processor emulator and print output
		-output consists of the next instruction to run as read in from ram, a dump of the registers
			and a dump of the contents of ram
	-running ./main <yourbinary> | grep "NEXT-INSTRUCTION" can work as a crude disassembler in a pinch
	-I wrote several one liner tools for debugging along these lines under the DebugUtils directory
	-To use my debugging one liners do ./DebugUtils/<debugtool> <yourbinary>
	-The above tips coupled with io redirection: > and >> operators provide a good way to watch and sort
		through the output of the emulator
	-For lower level debugging of a binary consider running the emulator in gdb and breaking on the function
		that implements the instruction you would like to analyze or break on a particular value of the program
		counter register
	-The method CompSim::ExecInstr is useful for stepping one ttp instruction at a time in gdb
	-you probably want to adjust your screen and font to fit the ram dump nicely into your screen ideally you want it 
		to look like a big rectangle
	-the program should exit with the pc one less than what it would be in logisim otherwise the state of the registers
		and ram should be identical (if not you found a bug)
# TODO:
	-clean up the source code and make it look pretty
	-doxygen docs?
	-Instruction docs?
	-IO hardware?
	-breakpoint mechanism?
	-write more tools
	-test more instructions
	-add more hardware
	-add more instructions
	-get clarification on how the flags are supposed to work
	-add user level interface for running different variations of the hardware, mainly ram size but register mods might be cool too
	-consider making it possible for a user to install/augment the instruction set

# DEMO:
![link to demo gif goes here](https://raw.githubusercontent.com/mehstruslehpy/Documents/master/C%2B%2B/TTPSim/TTPSimAndAsmDemo.gif)
