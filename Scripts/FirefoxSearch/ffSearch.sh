#!/usr/bin/wish -f

#the main gui
proc screen {} {

	global sterm "-empty-"
	frame .top -borderwidth 10
	pack .top -fill x

	button .top.quit -text "Quit" -command { quitProg }
	global sterm "-empty-"

	SearchTerm
	quitProg
}

proc SearchTerm {} {
	global sterm "-empty-"
	
	toplevel .search

	pack [label .search.lfile -text "Search the internet:"]
	pack [entry .search.efile -textvariable sterm]

	pack [button .search.b -text "OK" -command {destroy .search}]
	bind .search <Return> {.search.b invoke}
	focus .search.efile
	tkwait window .search

	#puts "DEBUG (bupfile): $sterm"

	if {$sterm eq "-empty-"} then {
		quitProg
	} elseif {$sterm eq ""} then {
		quitProg
	} else {}

	#build and execute the.Search command
  	set f [ open "| firefox --search $sterm " r]
}

proc quitProg {} {
	exit
}

screen
