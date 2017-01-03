#I also don't use this pythonanywhere comes with a wsgi file that I modified
import sys
sys.path.insert(0, "/srv/http/FlaskPython/placeMarker")
from placemarker import app as application
