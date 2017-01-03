#this will need fixed..
#this was actually straight out of the book

#this is a mock dbhelper class
#basically it does nothing
#we use this to test everything but the
#code dealing with the database
class MockDBHelper:

    def connect(self, database="crimemap"):
        pass

    def get_all_inputs(self):
        #return ["('DEBUG: return string')"]
        return []

    def add_input(self, data):
        pass

    def clear_all(self):
        pass

    def add_crime(self, name, date, latitude, longitude, description):
        pass

    def get_all_crimes(self):
        return [{
            'latitude': 38.57869718259962,
            'longitude': -121.48372650146484,
            'date': "2001-01-01",
            'name': "mugging",
            'description': "mock description"
        }]
