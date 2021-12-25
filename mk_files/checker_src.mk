# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    checker_src.mk                                     :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 16:31:37 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/13 20:52:29 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ifndef CHECKER_SRC_MK
CHECKER_SRC_MK = 1

# Files that are present in all 3 checker versions

CH_SRC =	./src/checker/src/main.c
CH_HDF =	./src/checker/includes/checker.h \
			./src/checker/includes/libft.h \
			./src/checker/includes/libps.h \

ifdef WITH_BONUS
# Add regular bonus files

CH_SRC +=	./src/checker/src/getops/get_ops_bonus.c \
			./src/checker/src/viz/color_bonus.c \
			./src/checker/src/viz/color_bonus2.c \
			./src/checker/src/viz/print_bonus.c

CH_HDF +=	./src/checker/includes/checker_bonus.h \
			./src/checker/includes/libftprintf.h

	ifdef WITH_MLX
# Add MLX files

CH_SRC +=	./src/checker/src/mlx/execute_mlx.c \
			./src/checker/src/mlx/draw.c \
			./src/checker/src/mlx/color_utils.c \
			./src/checker/src/mlx/end_mlx.c \
			./src/checker/src/mlx/init_mlx.c \
			./src/checker/src/mlx/execute_ops.c \
			./src/checker/src/mlx/calculate_values.c \
			./src/checker/src/mlx/mlx_wrapper.c \
			./src/checker/src/mlx/getlines.c \
			./src/checker/src/mlx/render.c \
			./src/checker/src/mlx/hooks.c \
			./src/checker/src/viz/visualize_mlx.c \
			./src/checker/src/args/args_mlx.c \
			./src/checker/src/args/flags_mlx.c

CH_HDF +=	./src/checker/includes/mlx_keys.h \
			./src/checker/includes/mlx_bonus.h \
			./src/checker/includes/x_events.h

	else

CH_SRC +=	./src/checker/src/viz/visualize_bonus.c \
			./src/checker/src/args/flags_bonus.c \
			./src/checker/src/args/args_bonus.c

	endif

else

# Add mandatory files
CH_SRC +=	./src/checker/src/args/args.c \
			./src/checker/src/getops/get_ops.c \
			./src/checker/src/viz/visualize.c

endif

endif
