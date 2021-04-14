#the math file is imported so that the pi value can be used
import math

#this will create a function that calculates the value of the cube
def cubevol (side):
  return side*side*side

#this will create a function that calculates the value of the pyramid
def pyramidvol (base_length, height):
  return (1/3)* (base_length**2)* height

#this will create a function that calculates the value of the ellipsoid
def ellipsoidvol (radius1,radius2,radius3):
  return 4/3* radius1*radius2*radius3* math.pi
