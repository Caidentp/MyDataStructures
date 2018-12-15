from os import name, system

if name == 'nt':
    system(r'.\run_tests.bat')
else:
    system(r'.\run_tests.bash')
