import pymysql
import dbconfig
import datetime
import os

#consider the four main database operations:
#CRUD: Create, Read, Update, Delete
#in this basic app we don't really need update
#but we do need the other three as methods
class DBHelper:

    #method for connecting to a database
    def connect(self, database="databasename"):
        return pymysql.connect(host='database_url',
                            user=dbconfig.db_user,
                            passwd=dbconfig.db_password,
                            db=database)

    #From CRUD: Read
    def get_all_inputs(self):
        connection = self.connect()
        try:
            query = "SELECT description FROM places;"
            with connection.cursor() as cursor: #the book mentioned thinking of our db cursor as a generator
                cursor.execute(query)
            return cursor.fetchall()
        finally:
            connection.close()

#   #From CRUD: Update
#   def add_input(self, data):
#       connection = self.connect()
#       try:
#           #the following introduces a deliberate security flaw
#           #see the section on SQL injection in nook
#           query = "INSERT INTO places (description) VALUES (%s);"
#           with connection.cursor() as cursor:
#               cursor.execute(query, data)
#               connection.commit()
#       finally:
#           connection.close()

    #From Crud: Delete
    def clear_all(self):
        connection = self.connect()
        try:
            query = "DELETE FROM places;"
            with connection.cursor() as cursor:
                cursor.execute(query)
                connection.commit()
        finally:
            connection.close()

    #now we can do mapping stuff to use our real place database
    def add_place(self, name, date, latitude, longitude, description):
        connection = self.connect()
        try:
            query = "INSERT INTO places (name, date, latitude, longitude, description) VALUES (%s, %s, %s, %s, %s);"
            with connection.cursor() as cursor:
                cursor.execute(query, (name, date, latitude, longitude, description))
                connection.commit()
        except Exception as e:
            print(e)
        finally:
            #create our places html file
            fp = open("/home/mehstruslehpy2/placeMarker/templates/places/" + name + ".html","a")
            fp.write("<html>\n<link rel=\"stylesheet\" type=\"text/css\" href=\"../../../static/css/style.css\">\n")

            #create page
            fp.write("<h1> Name: "+name+"</h1>\n")
            fp.write("<p> Date Entered: "+date+"</p>\n")
            print(date)
            print(type(date))
            fp.write("<p> Latitude: "+str(latitude)+"</p>\n")
            fp.write("<p> Longitude: "+str(longitude)+"</p>\n")
            fp.write("<p> Description: </p>\n<p>"+description+"</p>\n")
            fp.write("</html>\n")
            fp.close()
            #write to our index of files /home/mehstruslehpy2/placeMarker/static/html/places
            #fp = open("/home/mehstruslehpy2/placeMarker/templates/place_index.html","a")
            #fp.write("<a href=\"/templates/places/"+name+date".html\">"+name+date+"</a><br>\n" + os.getcwd())
            #fp.write("\n")
            #fp.close()
            connection.close()

    def get_all_places(self):
        connection = self.connect()
        try:
            query = "SELECT latitude, longitude, date, name, description FROM places;"
            with connection.cursor() as cursor:
                cursor.execute(query)
                named_places = []
                for place in cursor:
                    #when our sql db contains all 0's for date it returns None..
                    if place[2] == None:
                        named_place = {
                            'latitude': place[0],
                            'longitude': place[1],
                            'date': "0000-00-00",
                            'name': place[3],
                            'description': place[4]
                        }
                        named_places.append(named_place)
                    else:
                        named_place = {
                            'latitude': place[0],
                            'longitude': place[1],
                            'date': datetime.datetime.strftime(place[2], '%Y-%m-%d'),
                            'name': place[3],
                            'description': place[4]
                        }
                        named_places.append(named_place)
                return named_places
        finally:
            connection.close()
