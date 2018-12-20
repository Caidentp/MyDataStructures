from os import name, system

if name == 'nt':
    system(r'.\test.bat')
else:
    system(r'.\test.bash')
