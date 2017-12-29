while True:
    str = input()
    if str == "DONE":
        break
  
    str = str.lower()
    str = str.replace("!", "")
    str = str.replace(" ", "")
    str = str.replace(",", "")
    str = str.replace(".", "")
    str = str.replace("?", "")
  
    if (str == str[::-1]):
        print("You won't be eaten!")
    else:
        print('Uh oh..')
  
