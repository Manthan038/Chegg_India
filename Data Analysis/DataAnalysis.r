#assignment.raw <- read.csv(file ='assignment.csv')  # you can use the syntex for loading your data set 


  #  As assignment.csv is not proveided therefor i have to create it

Wind <- c(18,6,78,18, 57, 5, 18, 19, 30, 322, 11, 68,23)    # defining the rows for Wind columns
Heat <- c(10,41,19, 74, 67 ,5 ,10, 21, 36, 18, 80, 72,5)
Month <- c(12,5,6,3,5,6,2,6,5,8,9,6,5)
Day <- c(22,4,21,4,25,7,17,19,12,4,12,15,23)
assignment<- data.frame(Wind,Heat,Month,Day)   #Creating assignment data set 


assignment           # printing the data set that we have created



# A  show the column name of data frame

cat("columns name of data frame:::",names(assignment),"\n")

# B Extract the first 3 rows of the assignment data frame.

cat(" assignment 3 rows \n")
head(assignment,3)
#assignment[1:3,]  this aslo can be use to do so

# C  observations (i.e. rows), and variables are there in this data frame

str(assignment)  #data frame  examines
cat("\nShape of assignment:::",dim(assignment),"\n") # for checking the shape of our (data number of row and number of columns)



# D Extract the last 7 rows of the data frame.
cat("Extraction of last 7 rows\n")
tail(assignment,7)


# E Find the value of Wind in the (n)th row
# suppose n=8
cat(" 8th row value:\n")
assignment[8,]

# F   mean of the Carbon column but I have not made Carbon column so i will use Heat column

cat("Mean of Heat column: ",mean(assignment$Heat),"\n")


# G Subset the rows with Heat>31 and Wind> 30. What is the mean of Day in this subset

SubSet<-data.frame(assignment[assignment$Heat >31,])
SubSet<-data.frame(SubSet[SubSet$Wind >30,])

cat("\n\n SubSet......\n")
SubSet     # print the sub data set

cat("Mean of Day is:",mean(SubSet$Day))

# H What is the mean of "Heat" when "Month" is equal to 6

cat("When Heat  Month is 6 then Mean of Day is::", mean(assignment[assignment$Month==6,"Day"]),"\n")


#I maximum Heat value in the month of May

cat("Maximum Heat in the Month of May(5)::", max(assignment[assignment$Month==6,"Heat"]),"\n")


#J  Reorder your data frame based on Wind in descending order, print the first 10 observations and avarage of 10 Day volumn 

# sorting data frame as per Wind
cat("Sorting data as per Wind\n")
assignment<-assignment[
  order( -assignment[,"Wind"] ),
]

# Print first 10 10 observations

head(assignment,10)

cat("Avarage of 10 Day columns in new data ::",mean(assignment[1:10,"Day"])) 
