def count(row):

    count = 0
    last = -1

    for i in range(len(row) - 1):

         if row[i] != row[i + 1]:
             count += (i-last) *(len(row) -i - 1)
             last = i

    return count

the_row_of_ashok = input().strip()
the_row_of_anand= input().strip()

if not all(tree in 'ML' for tree in the_row_of_ashok + the_row_of_anand):
      print("Invalid input", end="")
else:
      ashok = count(the_row_of_ashok)
      anand= count(the_row_of_anand)
     
      if ashok > anand:
         print("Ashok", end="")

      elif anand > ashok:
         print("Anand", end="")

      else:
         print("Draw", end="")

