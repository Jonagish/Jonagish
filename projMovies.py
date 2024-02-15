# Jonas Genao Abreu
# Assignment: Programming project Design
# Due Date 10/27/2023

# Program Title: Moives Data Project

# Program Description:
# --------------------
# This program will read a file containing movie data from 2006 to 2016.
# The program will ask the user to choose from different 7 options.
# The first choice is find movies by specified director; Second, find the highest grossing film in specified year;
# Third, find all fils made in a given year range in a speficied genre;
# Fourth, search film by title; Find the average runtime of films with revenue higher than specified revenue;
# Sort all the lists by revenue and write the results to a new file.
# and finally, exit the program.


# This function will open the file and return the file object
# Parameter: None
# Return: dataFile
def openFile():
    Ok = False
    while Ok == False:
        try:
            fileName = input("Please enter a file name: ")
            dataFile = open(fileName, "r")
            Ok = True
        except IOError:
            print("Invalid file name try again ...")
    return dataFile



# This function will read the file and return the data in six lists
# Parameter: None
# Return: (str)titleList, (str)genreList, (str)directorList, (int)yearList, (int)runtimeList, (float)revenueList
def getData():
    titleList = []
    genreList = []
    directorList = []
    yearList = []
    runtimeList = []
    revenueList = []
    dataFile = openFile()

    # Read the file
    # Split the data into lists
    for line in dataFile:
        line = line.strip()
        title, genre, director, year, runtime, revenue = line.split(",")
        titleList.append(title)
        genreList.append(genre)
        directorList.append(director)
        yearList.append(year)
        runtimeList.append(runtime)
        revenueList.append(revenue)
    dataFile.close()
    # Remove the header
    del titleList[0], genreList[0], directorList[0], yearList[0], runtimeList[0], revenueList[0]

    # Convert the lists to the correct data type
    yearList = [int(i) for i in yearList]
    runtimeList = [int(i) for i in runtimeList]
    revenueList = [float(i) for i in revenueList]

    return titleList, genreList, directorList, yearList, runtimeList, revenueList


# This function will find all films by a specified director and display the information
# Parameter: (str)titleList, (str)genreList, (str)directorList, (int)yearList, (int)runtimeList, (float)revenueList, (str)directorName
# Return: str(movies), str(genres), str(directors), int(years), int(runtimes), float(revenues) 
def findFilmByDirector(titleList, genreList, directorList, yearList, runtimeList, revenueList, directorName):
    indeces = []
    movies = []
    genres = []
    directors = []
    years = []
    runtimes = []
    revenues = []
    
    # Find the indeces of the films that meet the criteria
    for i in range(len(directorList)):
        if directorName == directorList[i]:
            indeces.append(i)

    for i in indeces:
        movies.append(titleList[i])
        genres.append(genreList[i])
        directors.append(directorList[i])
        years.append(yearList[i])
        runtimes.append(runtimeList[i])
        revenues.append(revenueList[i])
    

    return movies, genres, directors, years, runtimes, revenues


# This function will find the highest grossing film in a specified year and return the information
# Parameter: titleList, genreList, directorList, yearList, runtimeList, revenueList, year 
# Return: str(movie1), str(genre1), str(director1), int(year1), int(runtime1), float(revenue1)
def findHiGrossFilmByYear(titleList, genreList, directorList, yearList, runtimeList, revenueList, year):
    movies = []
    genres = []
    directors = []
    years = []
    runtimes = []
    revenues = []

    # Find the films that meet the criteria
    for i in range(len(yearList)):
        if year == yearList[i]:
            movies.append(titleList[i])
            genres.append(genreList[i])
            directors.append(directorList[i])
            years.append(yearList[i])
            runtimes.append(runtimeList[i])
            revenues.append(revenueList[i])
    

    maxRev = max(revenues)
    # This is for the case where there is more than one
    movie1 = []
    genre1 = []
    director1 = []
    year1 = []
    runtime1 = []
    revenue1 = []

    for i in range(len(revenues)):
        if maxRev == revenues[i]:
            movie1.append(movies[i])
            genre1.append(genres[i])
            director1.append(directors[i])
            year1.append(years[i])
            runtime1.append(runtimes[i])
            revenue1.append(revenues[i])

    return movie1, genre1, director1, year1, runtime1, revenue1


# This function will find all films made in a given year range in a specified genre
# Parameter: titleList, genreList, directorList, yearList, runtimeList, revenueList, year1, year2, genre
# Return: str(movies), str(genres), str(directors), int(years), int(runtimes), float(revenues)
def filmByYearsGenre(titleList, genreList, directorList, yearList, runtimeList, revenueList, year1, year2, genre):
    movies = []
    genres = []
    directors = []
    years = []
    runtimes = []
    revenues = []

    # Convert the genreList to a 2D list
    newGenreLsit = []
    for i in range(len(genreList)):
        newGenreLsit.append(genreList[i].split(";"))
    
    # Find the films that meet the criteria
    for i in range(len(yearList)):
        # Check if the year is between the range
        if year1 <= yearList[i] <= year2:
            # Check if the genre is in the list
            for j in range(len(newGenreLsit[i])):
                # If the genre is in the list, add the film to the list
                if genre == newGenreLsit[i][j]:
                    movies.append(titleList[i])
                    genres.append(genreList[i])
                    directors.append(directorList[i])
                    years.append(yearList[i])
                    runtimes.append(runtimeList[i])
                    revenues.append(revenueList[i])
            

    return movies, genres, directors, years, runtimes, revenues

# This function will get the first year from the user
# parameter: None
# Return: (int)year1
def getFirstYear():
    ok = False
    while ok == False:
        try:
            year1 = int(input("Year1: "))
            if year1 < 2006 or year1 > 2016:
                print("Year out of range, must be between 2006 and 2016")
            else:
                ok = True
        except ValueError:
            print("Invalid entry - Try again")
    return year1

# This function will get the second year from the user
# parameter: None
# Return: (int)year2
def getSecondYear():
    ok2 = False
    while ok2 == False:
        try:
            year2 = int(input("Year2: "))
            if  year2 > 2016:
                print("Year out of range, must be between 2006 and 2016")
            else:
                ok2 = True
        except ValueError:
            print("Invalid entry - Try again")
    return year2


# This function will find a film by title and return the information
# Parameter: titleList, genreList, directorList, yearList, runtimeList, revenueList, title
# Return: str(movies), str(genres), str(directors), int(years), int(runtimes), float(revenues)
def findFilmByTitle(titleList, genreList, directorList, yearList, runtimeList, revenueList, title):
    movies = []
    genres = []
    directors = []
    years = []
    runtimes = []
    revenues = []
    i = titleList.index(title)
    movies.append(titleList[i])
    genres.append(genreList[i])
    directors.append(directorList[i])
    years.append(yearList[i])
    runtimes.append(runtimeList[i])
    revenues.append(revenueList[i])

    return movies, genres, directors, years, runtimes, revenues

# This function will find the average runtime of films with revenue higher than specified value
# Parameter: (int)runtimeList, (float)revenueList, (float)revenue
# Return: (float)avgRuntime
def findAvgRuntime(runtimeList, revenueList, revenue):
    totalRuntime = 0
    avgRunTime = 0
    newRuntimeList = []

    # Find the films that meet the criteria
    for i in range(len(revenueList)):
        if revenueList[i] > revenue:
            newRuntimeList.append(runtimeList[i])

    # Add all the runtimes
    for i in range(len(newRuntimeList)):
        totalRuntime += newRuntimeList[i]
    
    # Find the average
    avgRuntime = totalRuntime / len(newRuntimeList)

    return avgRuntime

# This function will sort the lists by revenue and return the indices
# Parameter: theList
# Return: list of indices
# This is a bubble sort algorithm
# It will sort the list in ascending order
def sortList(theList):
    n = len(theList)
    indices = list(range(len(theList)))

    # Bubble sort
    for i in range(n-1):
        for j in range(0,n - i - 1):
            if theList[j] > theList[j+1]:
                theList[j], theList[j+1] = theList[j+1], theList[j]
                indices[j], indices[j+1] = indices[j+1], indices[j]
    
    return indices
    
# This function will write the sorted data to a file called movies-sorted-rev.csv
# Parameter: titleList, genreList, directorList, yearList, runtimeList, revenueList, sortedLists
# Return: None
def writeToFile(titleList, genreList, directorList, yearList, runtimeList, revenueList, sortedLists):

    outFile = open("movies-sorted-rev.csv", "w")
    for i in range(len(sortedLists)):
        index = sortedLists[i]
        outFile.write(titleList[index] + "," + genreList[index] + "," + directorList[index] + "," + str(yearList[index]) + "," + str(runtimeList[index]) + "," + str(revenueList[i]) + "\n")
    
    outFile.close()
    print("Sorted data has been written to the file: movies-sorted-rev.csv.")
    return 

# This function will display the results
# Parameter: movies, genres, directors, years, runtimes, revenues
# Return: None
def displayResults(movies, genres, directors, years, runtimes, revenues):

    print("TITLE".ljust(45), "GENRE".ljust(35), "DIRECTOR".ljust(24), "YEAR".ljust(8), "RUNTIME".ljust(8), "REVENUE(mil)".rjust(12))
    for i in range(len(movies)):
        print(movies[i].ljust(45), genres[i].ljust(35), directors[i].ljust(24), str(years[i]).ljust(8), str(runtimes[i]).ljust(8), ("$"+str(revenues[i])).rjust(12))
    return


# This function will display the option menu and get the user's choice
# Parameter: None
# Return: choice
def getChoice():
    print("\nPlease choose one of the following options:")
    print("1 -- Find all films made by a specified director")
    print("2 -- Find the highest grossing film made in a specific year")
    print("3 -- Find all films made in a given year range in a specified genre")
    print("4 -- Search for a film by title")
    print("5 -- Find average runtime of films with higher revenue than specified value")
    print("6 -- Sort all lists by revenue and write the results to a new file")
    print("7 -- Quit")

    ok = False
    while ok == False:
        try:
            choice = int(input("Choice ==> "))
            if choice < 1 or choice > 7:
                print("Choice must be between 1 and 7")
            else:
                ok = True
        except ValueError:
            print("Invalid entry - Try again")
    return choice


# This function will call the other functions
# Parameter: None
# Return: None

def main():
    titleList, genreList, directorList, yearList, runtimeList, revenueList = getData()
    choice = getChoice()
    stop = False

    # This loop will run until the user chooses to exit the program
    while stop == False:
        print("")
        # Option 1
        # This option will find all films by a specified director
        # ------------------------------------------------------
        if choice == 1:
            ok = False
            while ok == False:
                directorName = input("Enter director: ")
                if directorName in directorList:
                    movies, genres, directors, years, runtimes, revenues = findFilmByDirector(titleList, genreList, directorList, yearList, runtimeList, revenueList, directorName)
                    print("\nThe films that meet your criteria are:\n")
                    displayResults(movies, genres, directors, years, runtimes, revenues)
                    ok = True
                    choice = getChoice()

                else:
                    print("Invalid entry - Try again")
            

        #Option 2 
        # This option will find the highest grossing film in a specified year
        # ------------------------------------------------------------------
        elif choice == 2:
            ok = False
            while ok == False:
                try:
                    year = int(input("Enter year: "))
                    if year in yearList:
                        ok = True
                        movies, genres, directors, years, runtimes, revenues = findHiGrossFilmByYear(titleList, genreList, directorList, yearList, runtimeList, revenueList, year)
                        print("\nThe film that meets your criteria is:\n")
                        displayResults(movies, genres, directors, years, runtimes, revenues)
                        choice = getChoice()

                    elif year < 2006 or year > 2016:
                        print("Year out of range, must be between 2006 and 2016")

                except ValueError:
                    print("Invalid entry - Try again")

        # Option 3
        # This option will find all films made in a given year range in a specified genre
        # -------------------------------------------------------------------------------
        elif choice == 3:
            print("Enter year range to search (oldest year first)")
            ok = False
            # Gets the first and second year and checks if the second year is after the first year
            while ok == False:
               year1 = getFirstYear()
               year2 = getSecondYear()
               if year1 > year2:
                    print("Second year should be after first year - try again")
               else:
                    ok = True
            # Genre
            ok2 = False
            while ok2 == False:
                genre = input("Enter genre: ")
                if genre in genreList:
                    ok2 = True
                    movies, genres, directors, years, runtimes, revenues = filmByYearsGenre(titleList, genreList, directorList, yearList, runtimeList, revenueList, year1, year2, genre)
                    print("\nThe films that meet your criteria are:\n")
                    displayResults(movies, genres, directors, years, runtimes, revenues)
                    choice = getChoice()
                else:
                    print("Invalid entry - Try again")

        # Option 4
        # This option will search for a film by title
        # -------------------------------------------
        elif choice == 4:
            title = input("Enter title: ")
            if title in titleList:
                movies, genres, directors, years, runtimes, revenues = findFilmByTitle(titleList, genreList, directorList, yearList, runtimeList, revenueList, title)
                print("\nThe film that meets your criteria is:\n")
                displayResults(movies, genres, directors, years, runtimes, revenues)
                choice = getChoice()
            else:
                print("\nNo such film exists.")
                choice = getChoice()

        # Option 5
        # This option will find the average runtime of films with revenue higher than specified value
        # ------------------------------------------------------------------------------------------
        elif choice == 5:

            ok = False
            while ok == False:
                try:
                    revenue = float(input("Enter revenue limit (millions): $"))
                    if revenue < 0:
                        print("Invalid entry - Try again")
                        
                    elif revenue > max(revenueList):
                        print("No films have revenue higher than $ ", "{:.2f}".format(revenue), " million.")
                        ok = True
                        choice = getChoice()
                        
                    else:
                        ok = True
                        avgRuntime = findAvgRuntime(runtimeList, revenueList, revenue)
                        print("The average runtime for films with revenue higher than $", "{:.2f}".format(revenue), "million is", "{:.2f}".format(avgRuntime), "minutes.")
                        choice = getChoice()

                except ValueError:
                    print("Invalid entry - Try again")

        # Option 6
        # This option will sort all the lists by revenue and write the results to a new file
        # ---------------------------------------------------------------------------------
        elif choice == 6:
            sortedList = sortList(revenueList)
            writeToFile(titleList, genreList, directorList, yearList, runtimeList, revenueList, sortedList)
            choice = getChoice()
        
        # Option 7
        # This option will exit the program
        # ----------------------------------
        else:
            print("Good-bye")
            stop = True


print(main())