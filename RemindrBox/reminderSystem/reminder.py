#imports
#dbhelper is in the same directory as this file
from dbhelper import DBHelper
from flask import Flask
from flask import render_template
from flask import request
import datetime
#cookies
from flask import make_response
usr=False
app = Flask(__name__)

#this is being used to grab insert and delete data from the database
DB = DBHelper()

#remove a username
@app.route("/enduser", methods=["POST"])
def end_user():
    resp = make_response(render_template("enduser.html"))

    resp.set_cookie('usrname', expires=0)
    return resp


#default page
@app.route("/")
def home(usr=False, resp=None):
    try:
        strs = []
        data = DB.get_all_inputs()

        #converting the output tuple to string array
        i = 0
        lowBound = len(data)
        for i in range(0, lowBound):
            strs.append( str(data[i]))
            strs[i] = strs[i][2:-3] # string without first two and last three characters
        print(strs[2][1])
    except Exception as e:
        #print the exception
        print(e)
        data = None

    return render_template("home.html", strs=strs, usr=usr)

#add to info the database
@app.route("/add", methods=["POST"])
def add():

    try:
        #check and set cookies
        print("DEBUG")
        usrname = request.cookies.get("usrname")
        #print(request.cookies.get("usrname"))
        if not usrname:
            usrname = request.form.get('username')
            usr=True
        data1 = usrname
        data2 = request.form.get("userinput")
        DB.add_input(data1 + ": " + data2)
    except Exception as e:
        #print e
        print(e)
    expires = datetime.datetime.now() + datetime.timedelta(days=365)
    resp = make_response(render_template("add.html"))
    resp.set_cookie("usrname", usrname, expires=expires)
    print("AFTER SET")
    print(usrname)
    print(request.cookies.get("usrname"))
    #we want this to be a boolean value...
    return resp

#clear the database
@app.route("/clear")
def clear():
    try:
        DB.clear_all()
    except Exception as e:
        #print e
        print(e)
    return home()

if __name__ == '__main__':
    app.run()
