#!/usr/bin/wish -f

#the main gui
proc screen {} {

	frame .top -borderwidth 10
	pack .top -fill x

	#using ttk::buttons will make my buttons have a uniform width
	#also later I can add styles
	ttk::button .top.quit -text "Quit" -command { quitProg }
	pack .top.quit -side bottom

	#the file containing binary paths
	set inBinFile [ open "ProgramBinary.txt" r ]
	#the file containing program names
	set inNameFile [ open "ProgramName.txt" r ]
	set number 0

	#read and populate the menu
	while { [gets $inBinFile cmdName; gets $inNameFile buttonName  ] >= 0 } {
	
		if {[string index $cmdName 0] != "/"} then {
			puts "Error: must specify a path from root to the intended binary." 
			puts [string index $cmdName 0] 
			quitProg
		}

		#you can filter certain commands
		#check for the binary illegal
		#if {[string first "illegal" $cmdName 0] != -1} {
		#	puts "Error: illegal pattern 1" 
		#	quitProg
		#}

		ttk::button .top.$buttonName -text $buttonName -command [list exec -ignorestderr $cmdName] 
		pack .top.$buttonName -side bottom

		incr number
	}

	close $inBinFile
	close $inNameFile
}
proc quitProg {} {
	exit
}

screen
