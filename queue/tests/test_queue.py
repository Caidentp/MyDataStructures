from os import name, system

if name == 'nt':
    system(r'./test_queue.bat')
else:
    system(r'./test_queue.bash')