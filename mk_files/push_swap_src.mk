# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    push_swap_src.mk                                   :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 18:09:03 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/13 18:12:01 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ifndef PUSH_SWAP_SRC_MK
PUSH_SWAP_SRC_MK = 1

PW_SRC =	./src/push_swap/src/bigsort/segment_util.c \
			./src/push_swap/src/bigsort/sort_min.c \
			./src/push_swap/src/bigsort/bigsort_util.c \
			./src/push_swap/src/bigsort/bigsort.c \
			./src/push_swap/src/bigsort/segment_split.c \
			./src/push_swap/src/smallsort/queue.c \
			./src/push_swap/src/smallsort/saves.c \
			./src/push_swap/src/smallsort/operations/pushswap.c \
			./src/push_swap/src/smallsort/operations/reverse_rotate.c \
			./src/push_swap/src/smallsort/operations/rotate.c \
			./src/push_swap/src/smallsort/state_ops.c \
			./src/push_swap/src/smallsort/smallsort.c \
			./src/push_swap/src/smallsort/state.c \
			./src/push_swap/src/main.c

PW_HDF =	./src/push_swap/includes/struct.h \
			./src/push_swap/includes/libft.h \
			./src/push_swap/includes/libps.h \
			./src/push_swap/includes/smallsort.h \
			./src/push_swap/includes/proto.h

endif
