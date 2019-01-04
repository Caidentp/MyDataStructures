from os import name, system

if name == 'nt':
    system(r'./test_heap.bat')
else:
    system(r'./test_heap.bash')
