# Creating SLL of different types and testing debug functions

# First we have to set the sys.path as sll files are one drirectory above

import os
import sys

sys.path.append(os.path.join(sys.path[0], ".."))

from sllCreate import *
from sllDebug import *

sll1 = makeSLL_string("1 2 3 4 5")
simpleDebug(sll1)
advancedDebug(sll1)

sll2 = makeSLL_string("1 2 3 4 5 6", int)
simpleDebug(sll2)
advancedDebug(sll2)

sll3 = makeSLL_string("1 2 3 4 5 8", float)
simpleDebug(sll3)
advancedDebug(sll3)

try:
    sll4 = makeSLL_string("1 2 3 4 jai", int)
except Exception as exp:
    print(exp)

sll5 = makeSLL_list([1, 2, 3, 4, 5])
simpleDebug(sll5)
advancedDebug(sll5)

sll6 = makeSLL_list([1, 2, 3.0, 553.007, [1, 2, 3, 4, 5], (1, 2, 3, 4, 5), {"name":"jaidheer", "favCar":"challenger", "favJet":"su35"}])
simpleDebug(sll6)
advancedDebug(sll6)
