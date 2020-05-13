def abbreviation(line):   #defining the abbreviation function
  abbr=line.split(" ")    # split the line at space
  abbr_format=''
  for word in abbr:
    abbr_format+=word[0]
  return abbr_format.upper()  # to return the upper case of abbreviation.


while(True):  # infinite loop
  file_path=input("Enter file name along with its path\n") # take input from user 
  try:
    with open(file_path) as file:
      for line in file.read().split('\n'):   # every is terminated on '\n'
         print(line)
         print("Abbrevation of line : ",abbreviation(line))
      file.close()
      break       # break the loop
  except FileNotFoundError:       # if give path is not valid path of file
    print('File does not exist')
