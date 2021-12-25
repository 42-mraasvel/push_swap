**REQUIREMENTS**

	LINUX LIBRARIES:

		sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev

**USAGE**

	Compilation:

		make (default push swap and checker)
		make bonus (for options: -v -c -f)
		make mlx (for -mlx option, to visualize the sort)

	Scripts: Generate random numbers

		run.sh

			Usage:
				./run.sh [NUMARGS]
				./run.sh [NUMARGS] [random]
				Will get the arguments from one of the scripts and run push_swap, then pipe it to checker

		args.py

		Requirement:

			python3 installed

		Usage:
			python3 args.py [NUMARGS] [range | random]
		Default:
			python3 args.py 5 range

		args.sh

		Usage / options:
			./args.sh [NUMARGS] [MAXNUM]
		Default:
			./args.sh 5 INTMAX

**OPTIONS**

	After compiling with _make bonus_ and _make mlx_

	-v

		Prints out the state for each operation to STDOUT

	-c

		Adds color to the entries affected by the last operation

	-f [FILE]

		Reads instructions from [FILE] instead of the default STDIN

	-mlx

		Use the MLX library to visualize the sorting
