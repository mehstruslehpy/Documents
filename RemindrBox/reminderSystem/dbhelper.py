import pymysql
import dbconfig

#consider the four main database operations:
#CRUD: Create, Read, Update, Delete
#in this basic app we don't really need update
#but we do need the other three as methods
class DBHelper:

    #method for connecting to a database
    def connect(self, database="remind"):
        return pymysql.connect(host='localhost',
                            user=dbconfig.db_user,
                            passwd=dbconfig.db_password,
                            db=database)

    #From CRUD: Read
    def get_all_inputs(self):
        connection = self.connect()
        try:
            query = "SELECT description FROM entries;"
            with connection.cursor() as cursor: #the book mentioned thinking of our db cursor as a generator
                cursor.execute(query)
            return cursor.fetchall()
        finally:
            connection.close()

    #From CRUD: Update
    def add_input(self, data):
        connection = self.connect()
        try:
            #the following introduces a deliberate security flaw
            #see the section on SQL injection in nook
            query = "INSERT INTO entries (description) VALUES ('{}');".format(data)
            with connection.cursor() as cursor:
                cursor.execute(query)
                connection.commit()
        finally:
            connection.close()

    #From Crud: Delete
    def clear_all(self):
        connection = self.connect()
        try:
            query = "DELETE FROM entries;"
            with connection.cursor() as cursor:
                cursor.execute(query)
                connection.commit()
        finally:
            connection.close()
