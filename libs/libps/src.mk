# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    src.mk                                             :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 12:19:27 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/13 12:19:28 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ifndef SRC_MK
SRC_MK = 1

SRC = src/btree.c \
src/dlist.c \
src/extra_wrappers.c \
src/ops_vect.c \
src/operations/pushswap.c \
src/operations/reverse_rotate.c \
src/operations/rotate.c \
src/operations/op_util.c \
src/operations/generic.c \
src/operations/operations.c \
src/stack.c \
src/parse_args.c \
src/parse_operations.c \
src/stack_utils.c \
src/sorted_indexing.c

HDF = includes/libft.h \
includes/libps.h

endif
