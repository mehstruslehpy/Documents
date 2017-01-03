#imports
import pymysql
import dbconfig

#import dbconfig which we will populate with database credentials
#then we will create a connection to it
connection = pymysql.connect(host='localhost',
                            user=dbconfig.db_user,
                            passwd=dbconfig.db_password)

#we create a cursor to our database
#think of this like a cursor in a word processor
#this points to a place in a database where data will be
#deleted, editted, created, etc.

#we use a try block because the finally block for this try
#always executes whether or not the try block succeeds
#so the connection will always get closed and never be left
#open
try:
    with connection.cursor() as cursor:
            sql = "CREATE DATABASE IF NOT EXISTS placemap"
            cursor.execute(sql)
            sql = """CREATE TABLE IF NOT EXISTS placemap.places (
id int NOT NULL AUTO_INCREMENT,
latitude FLOAT(10,6),
longitude FLOAT(10,6),
date DATETIME,
name VARCHAR(50),
description VARCHAR(1000),
updated_at TIMESTAMP,
PRIMARY KEY (id) /*this is a primary key for indexing purposes*/
)"""
            cursor.execute(sql); #executing the previous line
            connection.commit()  #committing the previous line
finally:
            connection.close()

#summary:
#id: unique num for every place
#lat&lon: obvious, each one can be up to 10 digits and max of six after the decimal point
#date: time and date of the place
#name: will be used for predefined name to classify the places
#description: a field for descriptions
#updated_at: date of last change
