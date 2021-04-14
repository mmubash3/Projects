#setting country class
class Country:
    #initializing a method
    def __init__(self,name,population,area,continent):
        self.name=name
        self.population=population
        self.area=area
        self.continent=continent
    #represent
    #using representation method
    def __repr__(self):
        return(self.name + " (pop: " + str(self.population) + ", size: " + str(self.area) + ") in " + self.continent)

    #getter methods
    def getName(self):
        return self.name
    def getPopulation(self):
        return self.population
    def getArea(self):
        return self.area
    def getContinent(self):
        return self.continent

    #setter methods
    def setPopulation(self,population):
        self.population=population
    def setArea(self,area):
        self.area=area
    def setContinent(self,continent):
        self.continent=continent
