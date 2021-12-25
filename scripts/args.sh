# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    args.sh                                            :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 11:17:38 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/13 11:17:38 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Usage / options:
#	./args.sh [NUMARGS] [MAXNUM]
# Default:
#	./args.sh 5 INTMAX

if [ -z "$1" ];
then
	n=5
else
	n=$1
fi

if [ -z "$2" ];
then
	max=2147483647
else
	max=$2
fi

shuf -i 0-$max -n $n
