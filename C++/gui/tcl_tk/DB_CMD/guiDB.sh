#!/usr/bin/wish -f

#you can change to the working directory fairly easily
cd /home/sleepy/Documents/Programming/C++/gui/tcl_tk/DB_CMD

#the main gui
proc screen {} {

	#from here: #http://www.tldp.org/HOWTO/Scripting-GUI-TclTk/advanced.html
	frame .top -borderwidth 10
	pack .top -fill x

#	button .dump -text "Dump Entries" -command { puts "\nHello World" }
#	pack .dump
	button .top.dump -text "Dump" -command { dumpEntry }
	pack .top.dump -side left
	button .top.app -text  "Append" -command { appendEntry }
	pack .top.app -side left
	button .top.find -text "Find" -command { findEntry }
	pack .top.find -side left
	button .top.sort -text "Sort" -command { sortDb }
	pack .top.sort -side left
	button .top.back -text "Backup" -command { backupDb }
	pack .top.back -side left
	button .top.inter -text "About" -command { aboutWindow}
	pack .top.inter -side left
	button .top.quit -text "Quit" -command { quitProg }
	pack .top.quit -side left

	frame .bottom
  pack .bottom -fill x
  text .bottom.main -relief sunken -bd 2 -yscrollcommand ".bottom.scroll set"
  scrollbar .bottom.scroll -command ".bottom.main yview"
  pack .bottom.main -side left -fill y
  pack .bottom.scroll -side right -fill y
}

proc dumpEntry {} {

	#global variables to contain the strings
	global dfile "-empty-"

	#the new window
	toplevel .t

	#entries and labels for the input text
	pack [label .t.lname -text "Choose a DB File:"]
	pack [entry .t.ename -textvariable dfile]

	#exit stuff
	pack [button .t.b -text "OK" -command {destroy .t}]
	bind .t <Return> {.t.b invoke}
	focus .t.ename
	tkwait window .t

	#debug stuff
	puts "DEBUG (name): $dfile"

	#clear out the output window	
	.bottom.main delete 0.0 end

	#clear out the output window	
	.bottom.main delete 0.0 end

	#print out the contents
	set f [ open "| ./db.o -d $dfile" r]
  	while {[gets $f x] >= 0} {
  		#gets $f x
  		puts "$x"
		.bottom.main insert end "$x\n"
  	}
  	catch {close $f}
}

proc appendEntry {} {
	#global variables to contain the strings
	global name "-empty-"
	global age "-empty-"
	global pid "-empty-"
	global rating "-empty-"
	global phone "-empty-"
	global addr "-empty-"
	global notes "-empty-"
	global file "-empty-"

	#the new window
	toplevel .t

	#entries and labels for the input text
	pack [label .t.lname -text "Name:"]
	pack [entry .t.ename -textvariable name]

	pack [label .t.lage -text "Age:"]
	pack [entry .t.eage -textvariable age]

	pack [label .t.lpid -text "Person ID:"]
	pack [entry .t.epid -textvariable pid]

	pack [label .t.lrating -text "Rating:"]
	pack [entry .t.erating -textvariable rating]

	pack [label .t.lphone -text "Phone:"]
	pack [entry .t.ephone -textvariable phone]
	
	pack [label .t.laddr -text "Address:"]
	pack [entry .t.eaddr -textvariable addr]

	pack [label .t.lnotes -text "Notes:"]
	pack [entry .t.enotes -textvariable notes]

	pack [label .t.lfile -text "DB File to Append:"]
	pack [entry .t.efile -textvariable file]

	#exit stuff
	pack [button .t.b -text "OK" -command {destroy .t}]
	bind .t <Return> {.t.b invoke}
	focus .t.ename
	tkwait window .t

	#debug stuff
	puts "DEBUG (name): $name"
	puts "DEBUG (age): $age"
	puts "DEBUG (pid): $pid"
	puts "DEBUG (rating): $rating"
	puts "DEBUG (phone): $phone"
	puts "DEBUG (addr): $addr"
	puts "DEBUG (notes): $notes"
	puts "DEBUG (file): $file"

	#clear out the output window	
	.bottom.main delete 0.0 end

	#build and execute the append command
  	set f [ open "| ./db.o -a -name $name -age $age -pid $pid -rating $rating -phone $phone -addr $addr -notes $notes -file $file" r]
 	while {[gets $f x] >= 0} {
    	.bottom.main insert end "$x\n"
  	}
  	catch {close $f}
}

proc backupDb {} {
	global bupfile "-empty-"
	
	#the new window
	toplevel .t

	pack [label .t.lfile -text "DB File to Backup:"]
	pack [entry .t.efile -textvariable bupfile]

	#exit stuff
	pack [button .t.b -text "OK" -command {destroy .t}]
	bind .t <Return> {.t.b invoke}
	focus .t.efile
	tkwait window .t

	#clear out the output window	
	.bottom.main delete 0.0 end

	puts "DEBUG (bupfile): $bupfile"

	#build and execute the backup command
  	set f [ open "| ./db.o -b $bupfile " r]
 	while {[gets $f x] >= 0} {
    	.bottom.main insert end "$x\n"
  	}
  	catch {close $f}
}

proc sortDb {} {

	global sfile "-empty-"
	global sortmode "-empty-"
	#the new window
	toplevel .t

	pack [label .t.lfile -text "Enter the DB filename you want to Sort:"]
	pack [entry .t.efile -textvariable sfile]

	pack [label .t.ls1 -text "Sort Modes:"]
	pack [label .t.ls2 -text "by name   (0)"]
	pack [label .t.ls3 -text "by age    (1)"]
	pack [label .t.ls4 -text "by ID     (2)"]
	pack [label .t.ls5 -text "by rating (3)"]
	pack [label .t.ls6 -text "by phone  (4)"]
	pack [label .t.ls7 -text "by address(5)"]
	pack [label .t.ls8 -text "by info   (6)"]

	pack [label .t.lmode -text "Enter your choice of sort mode:"]
	pack [entry .t.emode -textvariable sortmode]
	
	#exit stuff
	pack [button .t.b -text "OK" -command {destroy .t}]
	bind .t <Return> {.t.b invoke}
	focus .t.efile
	tkwait window .t

	#clear out the output window	
	.bottom.main delete 0.0 end

	puts "DEBUG (sfile): $sfile"
	puts "DEBUG (sortmode): $sortmode"

	#build and execute the backup command
  	set f [ open "| ./db.o -s $sfile $sortmode " r]
 	while {[gets $f x] >= 0} {
    	.bottom.main insert end "$x\n"
  	}
  	catch {close $f}
}

proc findEntry {} {
	global ffile "-empty-"
	global findmode "-empty-"
	global findterm
	#the new window
	toplevel .t

	pack [label .t.lfile -text "Enter the DB filename you want to Sort:"]
	pack [entry .t.efile -textvariable ffile]

	pack [label .t.ls1 -text "Find Modes:"]
	pack [label .t.ls2 -text "by name   (0)"]
	pack [label .t.ls3 -text "by age    (1)"]
	pack [label .t.ls4 -text "by ID     (2)"]
	pack [label .t.ls5 -text "by rating (3)"]
	pack [label .t.ls6 -text "by phone  (4)"]
	pack [label .t.ls7 -text "by address(5)"]
	pack [label .t.ls8 -text "by info   (6)"]

	pack [label .t.lfmode -text "Enter your choice of search mode:"]
	pack [entry .t.efmode -textvariable findmode]
	
	pack [label .t.lterm -text "Enter search term:"]
	pack [entry .t.eterm -textvariable findterm]
	#exit stuff
	pack [button .t.b -text "OK" -command {destroy .t}]
	bind .t <Return> {.t.b invoke}
	focus .t.efile
	tkwait window .t

	#clear out the output window	
	.bottom.main delete 0.0 end

	puts "DEBUG (ffile): $ffile"
	puts "DEBUG (findmode): $findmode"
	puts "DEBUG (findterm): $findterm"

	#build and execute the backup command
  	set f [ open "| ./db.o -f $ffile $findmode $findterm " r]
 	while {[gets $f x] >= 0} {
    	.bottom.main insert end "$x\n"
  	}
  	catch {close $f}
}
proc aboutWindow {} {
	#the new window
	toplevel .t

	pack [label .t.ls1 -text "This program was written by mehstruslehpy."]
	pack [label .t.ls2 -text "First Build Completed On: 27 May 2017"]
	pack [label .t.ls3 -text "I hope you like it! :]"]


	#exit stuff
	pack [button .t.b -text "OK" -command {destroy .t}]
	bind .t <Return> {.t.b invoke}

	tkwait window .t


}
proc quitProg {} {
	set answer [tk_messageBox -message "Really quit?" -type yesno -icon question]
  switch -- $answer {
    yes exit
    no {puts "DEBUG: no quit"}
  }
}

screen
