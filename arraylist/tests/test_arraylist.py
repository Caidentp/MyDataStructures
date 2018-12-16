from os import name, system

if name == 'nt':
    system(r'.\test_arraylist.bat')
else:
    system(r'.\test_arraylist.bash')