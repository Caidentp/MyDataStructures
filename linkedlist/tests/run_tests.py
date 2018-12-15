from os import version
from subprocess import call

if version == 'nt':
    call(['./run_script.bat'])
else:
    call(['./run_script.bash'])
