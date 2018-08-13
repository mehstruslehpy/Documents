#!/usr/bin/wish -f

#the main gui
proc screen {} {

	frame .top -borderwidth 10
	pack .top -fill x

	ttk::label .top.progLabel -text "Build An Argument: " -border 15
	pack .top.progLabel -side top

	#using ttk::buttons will make my buttons have a uniform width
	#also later I can add styles
	ttk::button .top.quit -text "Quit" -command { quitProg }
	pack .top.quit -side bottom

	ttk::button .top.genArg2 -text "Generate First Order Argument (Format 2)" -command [list exec -ignorestderr "./format2.sh"]
	pack .top.genArg2 -side bottom

	ttk::button .top.genArg1 -text "Generate First Order Argument (Format 1)" -command [list exec -ignorestderr "./format1.sh"]
	pack .top.genArg1 -side bottom

	ttk::button .top.genArg3 -text "       Generate Propositional Argument       " -command [list exec -ignorestderr "./format3.sh"]
	pack .top.genArg3 -side bottom
}
proc quitProg {} {
	exit
}

screen
