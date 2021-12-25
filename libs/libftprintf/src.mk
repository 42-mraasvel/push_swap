# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    src.mk                                             :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 11:59:28 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/13 11:59:28 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ifndef SRC_MK
SRC_MK = 1
SRC =	src/convert_n.c \
		src/flagsequence_utils.c \
		src/conversion_utils.c \
		src/convert_hex.c \
		src/ft_dtoa_e.c \
		src/ft_dtoa_f.c \
		src/convert_f.c \
		src/convert_digit.c \
		src/convert_e.c \
		src/convert_character.c \
		src/ft_printf.c \
		src/convert_pointer.c \
		src/flagsequence.c \
		src/convert_unsigned_digit.c \
		src/conversion.c \
		src/ft_round_f.c \
		src/convert_string.c
endif
