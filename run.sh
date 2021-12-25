# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    run.sh                                             :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 20:21:35 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/13 21:35:20 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# ./run.sh [NUMARGS] [random]

# Script of choice (bash or python) : python has more options
ARGS=$(python3 ./scripts/args.py $1 $2)
# ARGS=$(bash ./scripts/args.sh $1)

echo Arguments: $ARGS

# Push swap execution
./push_swap ${ARGS} > instructions.txt
echo Instruction count: $(cat instructions.txt | wc -l)

# Normal checker call
./checker ${ARGS} < instructions.txt

# Examples for running with bonus flags

# ./checker -f instructions.txt ${ARGS}
# ./checker -v -c -f instructions.txt ${ARGS}
# ./checker -mlx -f instructions.txt ${ARGS}
