from os import name, system

if name == 'nt':
    system(r'./test_stack.bat')
else:
    system(r'./test_stack.bash')