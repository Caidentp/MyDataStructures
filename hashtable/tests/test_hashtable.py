from os import name, system

if name == 'nt':
    system(r'./test_hashtable.bat')
else:
    system(r'./test_hashtable.bash')
