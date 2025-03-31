x = 0
try:
  x+=1
  raise ValueError
except NameError:
  x+=1
except ValueError:
  x+=1
else:
  x+=1
finally:
  x+=1
  print(x)