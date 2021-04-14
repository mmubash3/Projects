from country import *
#setting CountryCatalogue class
class CountryCatalogue:
    #initializing the CountryCatalogue
    def __init__(self,filename):
        countryCat=[]
        DATA=open(filename,'r')
        DATA.readline()
        for line in DATA:
        #the if and else makes the code be able to handle empty lines
            if line != "":
                #each line is split and the method is used in order to make it into an object and add it to the list countryCat
                word = line.rstrip('\n').split('|')
                each_country = Country(word[0],word[2],word[3].rstrip('\n'),word[1])
                countryCat.append(each_country)
            else:
                pass
        self.countryCat = countryCat
    #setter methods
    #method to update the population
    def setPopulationOfCountry(self,country_p,new_population_of_country):
        #this makes it go through every country object
        for country in self.countryCat:
            #if the input exists as an object it is updated using a sutiable setter method
            if country.getName() == country_p:
                country.setPopulation(new_population_of_country)
    #method to update the area
    def setAreaOfCountry(self,country_a,area_of_country):
        for country in self.countryCat:
            #if the input exists as an object it is updated using a sutiable setter method
            if country.getName() == country_a:
                country.setArea(area_of_country)
    #method to update the continent
    def setContinentOfCountry(self,country_c,continent_of_country):
        for country in self.countryCat:
            #if the input exists as an object it is updated using a sutiable setter method
            if country.getName() == country_c:
                country.setArea(continent_of_country)
    #method to find if a country exists as an object
    def findCountry(self,country_f):
        found= False
        #if the input exists as an object it is returned
        for country in self.countryCat:
            if country.getName() == country_f:
                return country
        #if it doesn't exist None is returned
        if found == False:
            return None
    #method to add country
    def addCountry(self,countryName,population,area,continent):
        #if the country doesn't exist it appends the country as an object with given variables
        if self.findCountry(countryName)==None:
            new_country=Country(countryName,population,area,continent)
            self.countryCat.append(new_country)
            return True
        else:
            return False
    #method to print all objects and instance variables
    def printCountryCatalogue(self):
        for country in self.countryCat:
            print(country)
    #method to save all the objects in a new file
    def saveCountryCatalogue(self,fname):
        #file it will save the objects is fname
        data=open(fname,'w')
        data.write("Country|Continent|Population|Area\n")
        #list to save all objects
        new_countryCat=[]
        #count of objects being added
        number_of_countries=0
        #gets the name, population, area & continent and appends it to the list in sutiable format
        for country in self.countryCat:
            w = country.getName()
            x = country.getPopulation()
            y = country.getArea()
            z = country.getContinent()
            new_countryCat.append(w+'|'+z+'|'+str(x)+'|'+str(y))
            number_of_countries+=1
        #sorts the list filled with all the objects in alphebetical order
        new_countryCat.sort()
        #writes each of the 'objects'/ items from the list into the file
        for item in new_countryCat:
            data.write(item)
            data.write('\n')
        #if the count of the number of countries added is 0 then it'll return -1 and if it's one or more it'll return the number of countries added
        if number_of_countries<1:
            return -1
        else:
            return number_of_countries


