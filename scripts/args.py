# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    args.py                                            :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 11:17:39 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/13 11:17:39 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

import random
import time
import sys

# Usage:
#	python3 args.py [NUMARGS] [range | random]
# Default:
#	python3 args.py 5 range

INTMAX = 2147483647
INTMIN = -2147483648

# Just a set of n random numbers between INTMIN and INTMAX
def random_args(n):
	random.seed(time.time())
	args = set()
	count = 0
	for i in range(1, n + 1):
		num = random.randint(INTMIN, INTMAX)
		if num in args:
			continue
		if i == n:
			count += 1
			print(num)
		else:
			count += 1
			print(num, end = " ")
		args.add(num)

# Range(5) = (0, 1, 2, 3, 4)
def range_args(size):
	nums = list(range(0, size))
	random.shuffle(nums)
	print(*nums)

# python3 args.py [NUMARGS] [random]
#	NUMARGS: number of arguments
#	random: gives random number of arguments between INTMIN and INTMAX instead of the default range option
if __name__ == '__main__':
	n = 5
	if len(sys.argv) > 1:
		n = int(sys.argv[1])
	if len(sys.argv) > 2 and sys.argv[2] == 'random':
		random_args(n)
	else:
		range_args(n)
