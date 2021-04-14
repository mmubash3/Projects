from catalogue import *
open('output.txt','w')
#function to output a updated file named output.txt
#the function takes in two file names the country file and the update file
def processUpdates(cntryFileName,updateFileName):
    validity_of_cntryFileName = False
    #a while loop is run so that it keeps running until the person enters the right file or quits the program
    while validity_of_cntryFileName == False:
        #if the country file is valid it'll just return true
        try:
            a = CountryCatalogue(cntryFileName)
            validity_of_cntryFileName=True
        #if the country file isn't valid
        except FileNotFoundError:
            #it asks to continue or exit
            print("The country file you have entered doesn't exist")
            retry= input('Would you like to quit? Enter N to continue, enter Y or anything else to quit')
            #if they want to exit it will run this and end the function and return a False from the function but the validity becomes true quitting the function
            if retry != 'N':
                validity_of_cntryFileName = True
                end_of_task_file= open('output.txt','w')
                end_of_task_file.write("Update Unsuccessful\n")
                return False
            #if they don't want to exit they will be asked for the correct file until they put in a correct file
            elif retry == 'N':
                cntryFileName= input("Please enter the file name:")
    validity_of_updateFileName=False
    #a while loop is run so that it keeps running until the person enters the right file or quits the program
    while validity_of_updateFileName == False:
        #if the update file is valid it'll just return true
        try:
            with open(updateFileName) as f:
                updates = f.read().splitlines()
            validity_of_updateFileName = True
        #if the country file isn't valid
        except FileNotFoundError:
            #it asks to continue or exit
            print("The update file you have entered doesn't exist")
            retry= input('Would you like to quit? Enter N to continue, enter Y or anything else to quit')
            #if they want to exit it will run this and end the function and return a False from the function but the validity becomes true quitting the function
            if retry != 'N':
                validity_of_cntryFileName = True
                end_of_task_file= open('output.txt','w')
                end_of_task_file.write("Update Unsuccessful\n")
                return False
            #if they don't want to exit they will be asked for the correct file until they put in a correct file
            elif retry == 'N':
                updateFileName = input("Please enter the file name:")
    #initiates the CountryCatalogue class so the methods in it can be used
    data = CountryCatalogue(cntryFileName)
    updatefile = open(updateFileName,'r')
    for line in updatefile:
        x=line.split(';')
        name_of_country = x[0]
        no_of_updates = len(x)
        #allows us to know if a country object has to be added or updated
        new_country = data.findCountry(name_of_country)
        #if the country doesn't exist use .addCountry to add it to the file
        if new_country == None:
            #if there is only 1 value
            if no_of_updates == 2:
                #the update is split using the '=' sign so P=45 becomes two objects in a list P & 45
                v_to_use = x[1].split('=')
                #it is stripped to aviod errors
                if v_to_use[0].strip() == 'P':
                    #if population value exists the second value in the new list is the new variable population
                    population = v_to_use[1].strip()
                #if P doesn't exist population is set to ''
                else:
                    population = ''
                if v_to_use[0].strip() == 'A':
                    #if area value exists the second value in the new list is the new variable area
                    area=v_to_use[1].strip()
                #if A doesn't exist area is set to ''
                else:
                    area=''
                if v_to_use[0].strip() == 'C':
                    #if continent value exists the second value in the new list is the new variable continent
                    continent = v_to_use[1].strip()
                #if C doesn't exist continent is set to ''
                else:
                    continent = ''
                #the instance variables are added to the object
                data.addCountry(name_of_country,population,area,continent)

            #similarly the same thing has been done for when there are only two or three values as it was done for one value, although
            #this accounts for a second or third value in the list
            #the program keeps track of how many values there are by using the length of the list (line.split)
            #depending on how many values there are the program will run accordingly
            #if there are 2 values
            elif no_of_updates == 3:
                #first update & second update variables
                v_to_use = x[1].split('=')
                v2_to_use = x[2].split('=')
                if v_to_use[0].strip() == 'P':
                    population = v_to_use[1].strip()
                elif v2_to_use[0].strip() == 'P':
                    population = v2_to_use[1].strip()
                else:
                    population = ''

                if v_to_use[0].strip() == 'A':
                    area = v_to_use[1].strip()
                elif v2_to_use[0].strip() == 'A':
                    area = v2_to_use[1].strip()
                else:
                    area = ''

                if v_to_use[0].strip() == 'C':
                    continent = v_to_use[1].strip()
                elif v2_to_use[0].strip() == 'C':
                    continent = v2_to_use[1].strip()
                else:
                    continent = ''
                data.addCountry(name_of_country,population,area,continent)

            #if there are 3 values
            elif no_of_updates==4:
                #first, second and third update variables
                v_to_use = x[1].split('=')
                v2_to_use = x[2].split('=')
                v3_to_use = x[3].split('=')

                if v_to_use[0].strip() == 'P':
                    population = v_to_use[1].strip()
                elif v2_to_use[0].strip() == 'P':
                    population = v2_to_use[1].strip()
                elif v3_to_use[0].strip() == 'P':
                    population = v3_to_use[1].strip()
                else:
                    population = ''

                if v_to_use[0].strip() == 'A':
                    area = v_to_use[1].strip()
                elif v2_to_use[0].strip() == 'A':
                    area = v2_to_use[1].strip()
                elif v3_to_use[0].strip() == 'A':
                    area = v3_to_use[1].strip()
                else:
                    area = ''

                if v_to_use[0].strip() == 'C':
                    continent = v_to_use[1].strip()
                elif v2_to_use[0].strip() == 'C':
                    continent = v2_to_use[1].strip()
                elif v3_to_use[0].strip() == 'C':
                    continent = v3_to_use[1].strip()
                else:
                    continent = ''
                data.addCountry(name_of_country,population,area,continent)
        #if the country does exist and needs to be updated
        else:
            #since country exists use update function
            #goes through each update in the list
            for each_update_entry in x:
                #skips the first item in the list as it is the country
                if x.index(each_update_entry) == 0:
                    continue
                #depending on the first letter of each update it will use a sutiable setter method and update to the new value
                else:
                    v_to_use = each_update_entry.split('=')
                    #updates to the population value
                    if v_to_use[0].strip() == 'P':
                        data.setPopulationOfCountry(name_of_country,v_to_use[1].strip())
                    #updates to the area value
                    if v_to_use[0].strip() == 'A':
                        data.setAreaOfCountry(name_of_country,v_to_use[1].strip())
                    #updates to the continent value
                    if v_to_use[0].strip() == 'C':
                        data.setContinentOfCountry(name_of_country,v_to_use[1].strip())
    #saves all the values to output.txt using the save method
    data.saveCountryCatalogue('output.txt')
    #returns true to the function if everything works out
    return True

