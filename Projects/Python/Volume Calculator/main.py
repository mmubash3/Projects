#must import the functions in order to use them in the code
from volume import cubevol
from volume import pyramidvol
from volume import ellipsoidvol
from summarize1 import summarize

print("Volume Calculator")

test_case_number= int(input('Please enter the number of tests: '))

for i in range(1, test_case_number+1):
    #the empty lists are provided so that we can store any values that are entered later in the program and is put in a loop so that the list is empty every time the loop runs
    CUBES=[]
    PYRAMIDS=[]
    ELLIPSOIDS=[]
    shape= input("Enter a shape you'd like to calculate the volume of: cube(c), pyramid(p), ellipsoid(e) or enter quit(q) to end program ")
    #this is done in order to remove any issues with input with extra spaces or caps
    shape=shape.upper().replace(" ",'').strip()

    while True:
      #done so that when shape is entered the second time it can format it properly
      shape=shape.upper().replace(" ",'').strip()

      #this part takes in the variable required for a cube and computes the value and stores it in the list after rounding it
      if shape == 'CUBE' or shape == 'C':
        side=int(input('please enter the length of the side of the cube '))
        volume_of_cube= cubevol(side)
        volume_of_cube=round(volume_of_cube,2)
        CUBES.append(volume_of_cube)
        shape= input("Enter a shape you'd like to calculate the volume of: cube(c), pyramid(p), ellipsoid(e) or enter quit(q) to end program ")

      #this part takes in the variables required for a pyramid and computes the value and stores it in the list after rounding it
      elif shape == 'PYRAMID' or shape== 'P':
        base_length=int(input('please enter the base length of the side of the pyramid '))
        height=int(input('please enter the height of the pyramid '))
        volume_of_pyramid= pyramidvol(base_length,height)
        volume_of_pyramid=round(volume_of_pyramid,2)
        PYRAMIDS.append(volume_of_pyramid)
        shape= input("Enter a shape you'd like to calculate the volume of: cube(c), pyramid(p), ellipsoid(e) or enter quit(q) to end program ")

      #this part takes in the variables required for an ellipsoid and computes the value and stores it in the list after rounding it
      elif shape == 'ELLIPSOID' or shape == 'E':
        radius1=int(input('please enter the first radius of the ellipsoid '))
        radius2=int(input('please enter the second radius of the ellipsoid '))
        radius3=int(input('please enter the third radius of the ellipsoid '))
        volume_of_ellipsoid= ellipsoidvol(radius1,radius2,radius3)
        volume_of_ellipsoid= round(volume_of_ellipsoid,2)
        ELLIPSOIDS.append(volume_of_ellipsoid)
        shape= input("Enter a shape you'd like to calculate the volume of: cube(c), pyramid(p), ellipsoid(e) or enter quit(q) to end program ")

      #this part of the code is for when the use wants to quit
      #the first part is for when all the lists are empty and no values are inputted
      elif shape == 'Q' or shape== 'QUIT':
        if len(CUBES)==0 and len(PYRAMIDS)==0 and len(ELLIPSOIDS)==0:
          print('You have reached the end of the session.')
          print('You did not perform any volume calculations.')
          #if no values are in the lists it'll break and stop the loop and the program
          break
        else:
          print('You have reached the end of your session.')
          print('The volume caluclated for each shape are:')
          #this is for when only the CUBES list is empty
          if len(CUBES)==0:
            print('Cube: No shapes entered')
          #this part is to sort and out put the CUBES list when it has values
          else:
            CUBES.sort()
            print('Cube: ',CUBES)
          #this is for when only the PYRAMIDS list is empty
          if len(PYRAMIDS)==0:
            print('Pyramid: No shapes entered')
          #this part is to sort and output the PYRAMIDS list when it has values
          else:
            PYRAMIDS.sort()
            print('Pyramid: ',PYRAMIDS)
          #this is for when only the ELLIPSOIDS list is empty
          if len(ELLIPSOIDS)==0:
            print('Ellipsoid: No shapes entered')
          #this part is to sort and output the ELLIPSOIDS list when it has values
          else:
            ELLIPSOIDS.sort()
            print('Ellipsoid: ',ELLIPSOIDS)
          #this is to create a file with the summarized values of all 3 lists in it
          summarize(CUBES,PYRAMIDS,ELLIPSOIDS,i)
        #the break is done so that the lists are only printed a single time
        break
      #this is for when a wrong or invalid shape is entered so that the program may ask for a value again
      else:
        print('Please enter a valid item shape')
        shape= input("Enter a shape you'd like to calculate the volume of: cube(c), pyramid(p), ellipsoid(e) or enter quit(q) to end program ")
        shape=shape.upper().replace(" ",'').strip()

