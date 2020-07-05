
import matplotlib.pyplot as plt
import numpy as np
import os
import json
from pprint import pprint

folder = os.path.join(os.path.dirname(__file__), "data")

files = list(reversed(sorted([os.path.join(folder, fn) for fn in os.listdir(folder) if fn.endswith(".json")])))


each_size = {
    
}
functions = set()
for fn in files:
    with open(fn) as f:
        data =json.load(f)
        if data["total_size"] not in each_size:
            each_size[data["total_size"]] = {v: k for k, v in zip(data["means"], data["functions"])}
            functions = functions.union(set(data["functions"]))
pprint(each_size)
pprint(functions)

for function in functions:
    #if function.startswith("divide") and "naive" in function and not (function.endswith("r2") or function.endswith("r3")):
    #   continue
    #if not function.startswith("divide_and_conquer_naive"):
    #    continue
    if function.startswith("block_wise"):
        continue
    x = []
    y = []
    for size in sorted(each_size.keys()):
        values = each_size[size]
        if function in values:
            x.append(pow(size, 1.))
            y.append(float(values[function]) / 1000.)
    print(x, y)
    plt.plot(x, y, label=function)

from matplotlib import rc

plt.legend()
plt.xscale("log")
plt.grid()
plt.xlim((1e10, 5.3e11))
plt.ylim((0, 160))
plt.savefig("test.pdf")
plt.xlabel("n * p * m")
plt.ylabel("seconds")
plt.show()
exit(0)
a = [

[1e6, '0.000', '0.000', '0.000', '0.300', '0.200', '0.250', '0.000', '0.000'],
[5e6, '0.200', '0.100', '0.200', '2.000', '1.800', '4.300', '0.200', '3.400'],
[1e7, '1.400', '1.350', '1.500', '4.000', '3.500', '4.750', '0.600', '7.750'],
[5e7, '7.450', '6.700', '8.100', '13.900', '11.950', '37.550', '2.350', '38.200'],
[1e8, '13.900', '13.150', '13.600', '15.300', '13.600', '100.200', '2.900', '75.300'],
[5e8, '81.100', '76.600', '74.350', '82.200', '75.150', '385.000', '14.600', '377.600'],
[1e9, '172.500', '166.250', '163.900', '127.100', '117.100', '686.450', '35.100', '808.800'],
[5e9, '1228.550', '1208.650', '1048.350', '532.850', '508.050', '2317.350', '127.750', '3998.350'],
[1e10,'2577.050', '2533.500', '2415.700', '922.000', '892.750', '3702.750', '298.550', '8060.550'],
[5e10, '15281.650', '15105.350', '12339.050', '4593.650', '4418.700', '16350.150', '1266.350', '40414.250'],
[1e11, '32127.000', '31768.100', '24630.650', '8223.350', '8152.700', '32005.850', '2425.700', '81039.750'],
[5e11, '249427.000', '248249.333', '124935.833', '39844.500', '39466.167', '138008.000', '11864.500', '402842.250']

]

def get_i(x):
    return np.array([(i[0], float(i[x + 1])) for i in a if len(i) > x  + 1])

[1e9,          '172.500',         '166.250',           '163.900',        '127.100',                   '117.100',                   '686.450',                     '35.100', '808.800'],
functions =  ["block_wise_256_f", "block_wise_256_f2", "boost_axpy_mul", "divide_and_conquer_block1", "divide_and_conquer_block2", "divide_and_conquer_naive_r3", "blas",   "naive_reordered"]

for i, f in list(enumerate(functions)):
    xy = get_i(i)
    plt.plot(xy[:,0], xy[:,1] / 1000., label=f)
    print(xy)
plt.legend()
plt.xscale("log")
plt.xlim((5e9, 1e12))
plt.show()


for i, f in list(enumerate(functions)):
    xy = get_i(i)
    xy_l = get_i(len(functions) - 1)
    plt.plot(xy[:,0], xy[:,1] / xy[:, 1], label=f)
    print(xy)
plt.legend()
plt.xscale("log")
plt.xlim((5e9, 1e12))
plt.show()