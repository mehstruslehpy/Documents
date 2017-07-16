#!/usr/bin/wish -f

#the main gui
proc screen {} {

	frame .top -borderwidth 10
	pack .top -fill x

	button .top.dump -text "Generate New Progression" -command { dumpChords }
	button .top.about -text "About" -command { aboutWindow }
	button .top.quit -text "Quit" -command { quitProg }
	pack .top.dump -side left
	pack .top.about -side left
	pack .top.quit -side left

	frame .bottom
  	pack .bottom -fill x
  	text .bottom.main -relief sunken -bd 2 -yscrollcommand ".bottom.scroll set"
  	scrollbar .bottom.scroll -command ".bottom.main yview"
  	pack .bottom.main -side left -fill y
  	pack .bottom.scroll -side right -fill y
}

proc dumpChords {} {
	
	#clear previous contents
	.bottom.main delete 0.0 end

	#print out new contents
	set f [ open "| ./randChord.o" r]
  	while {[gets $f x] >= 0} {
  		#gets $f x
  		puts "$x"
		.bottom.main insert end "$x\n"
  	}
  	catch {close $f}
}

proc quitProg {} {
	exit
}
proc aboutWindow {} {
	#the new window
	toplevel .about

	pack [label .about.ls1 -text "This program was written by mehstruslehpy."]
	pack [label .about.ls2 -text "The main idea is that it prints a random arrangement of chords"]
	pack [label .about.ls3 -text " "]
	pack [label .about.ls4 -text "each chord has a root note a basic type and some optional extra"]
	pack [label .about.ls5 -text "tones you can add. Just pick a key and experiment. "]
	pack [label .about.ls6 -text " "]
	pack [label .about.ls7 -text "Keep in mind the notes, types and extra tones are random... "]
	pack [label .about.ls8 -text "Which means you will probably have to experiment a bit 'til you"]
	pack [label .about.ls9 -text "find something you like"]
	pack [label .about.ls10 -text " "]
	pack [label .about.ls11 -text "Enjoy! :]"]


	#exit stuff
	pack [button .about.b -text "OK" -command {destroy .about}]
	bind .about <Return> {.about.b invoke}

	tkwait window .about


}

screen
