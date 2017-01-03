#imports
#dbhelper and mockdbhelper are in the same directory as this file
from flask import Flask
from flask import render_template
from flask import request
#conditionally import dbhelper or mockdbhelper
import dbconfig
if dbconfig.test:
    from mockdbhelper import  MockDBHelper as DBHelper
else:
    from dbhelper import DBHelper
import json

app = Flask(__name__)

#this is being used to grab insert and delete data from the database
DB = DBHelper()

#this has been replaced by the following function..
#probably might want to modify the exception handler back in though..
#default page
#@app.route("/")
#def home():
#    try:
#        data = DB.get_all_inputs()
#    except Exception as e:
#        #print e
#        print(e)
#        data = None
#    return render_template("home.html", data=data)
@app.route("/place_index")
def place_index():
    places = DB.get_all_places()
    placeLen = len(places)
    return render_template("place_index.html", places=places, placeLen=placeLen)

#default page
@app.route("/")
def home():
    places = DB.get_all_places()
    places = json.dumps(places)

    return render_template("home.html", places=places)

#add to info the database
@app.route("/add", methods=["POST"])
def add():
    try:
        data = request.form.get("userinput")
        DB.add_input(data)
    except Exception as e:
        #print e
        print(e)
    return home()

#clear the database
@app.route("/clear")
def clear():
    try:
        DB.clear_all()
    except Exception as e:
        #print e
        print(e)
    return home()

#submitplace uses http requests to grab our relevant data and then pushes that to our sql database
@app.route("/submitplace", methods=['POST'])
def submitplace():
    name = request.form.get("name")
    date = request.form.get("date")
    latitude = float(request.form.get("latitude"))
    longitude = float(request.form.get("longitude"))
    description = request.form.get("description")
    DB.add_place(name, date, latitude, longitude, description)
    return home()

if __name__ == '__main__':
#    app.run(port=5000, debug=True)
    app.run()
