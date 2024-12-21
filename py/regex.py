import re
sen = "My name is python, +919473581564 i am Pythonista 5354 Bapi 454435345345345 is also a python everyone is python of different version"

pat = re.sub(r"[\+91]\d",'#',sen)

print(pat)
