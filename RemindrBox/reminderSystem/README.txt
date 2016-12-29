on mysql from the book:
	
	Keep in mind that neither our setup of MySQL nor the data we store
	in it is part of our Git repository. Be careful as any mistakes made at
	a database level, including misconfiguration or deleting data, will be
	harder to undo.

./db_setup.py:
	creates and sets up the database

./dbconfig.py:
	some plain simple database info like user and password

./crimemap.py:
	does the generic responding to http commands

./dbhelper.py:
	provides the dbhelper class that crime map uses to talk to the sql database 
	through
