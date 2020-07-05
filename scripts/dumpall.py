#!/usr/bin/python
import os
import sys
import subprocess
for i in range(20):
    number = str(pow(i, 3))
    args = [os.path.join(os.path.dirname(__file__), "test.py"), number] + sys.argv[1:]
    print(" ".join(args))
    subprocess.check_call(args)