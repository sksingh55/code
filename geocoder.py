from pygeocoder import Geocoder
from geopy.geocoders import GoogleV3




geolocator = GoogleV3("AIzaSyBMvHYtdZZs1KivmIxu5woOxLtNdSjb3zg")
location = geolocator.reverse("23.1801, 80.0269")
print(location[1])

