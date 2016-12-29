REMINDRBOX:

is a simple webserver app to host reminders for yourself
this is not meant to be used seriously it is just a proof
of concept this app is not secure! I created it from a 
heavily modified version of an example from the book 
'flask by example'

on mysql from the book:
	
	Keep in mind that neither our setup of MySQL nor the data we store
	in it is part of our Git repository. Be careful as any mistakes made at
	a database level, including misconfiguration or deleting data, will be
	harder to undo.

./db_setup.py:
	creates and sets up the database

./dbconfig.py:
	some plain simple database info like user and password

./reminder.py:
	does the generic responding to http commands

./dbhelper.py:
	provides the dbhelper class that crime map uses to talk to the sql database 
	through
