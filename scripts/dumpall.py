#!/usr/bin/python
import os
import sys
import subprocess
for e in range(8, 13):
    for p in [1, 5]:
        number = str(float(str(p) + "e" + str(e)))
        args = [os.path.join(os.path.dirname(__file__), "test.py"), number] + sys.argv[1:]
        print(" ".join(args))
        subprocess.check_call(args)