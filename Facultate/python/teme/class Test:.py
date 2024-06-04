file = open("filename.txt", "r")
for i in range(21):
  print(file.read(4))
file.close()