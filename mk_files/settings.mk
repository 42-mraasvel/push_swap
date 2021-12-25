# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    settings.mk                                        :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 14:07:41 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/13 21:30:00 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ifndef SETTINGS_MK
SETTINGS_MK = 1

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
LDIR = libs
OS = $(shell uname)

# Libraries
LFT = $(LDIR)/libft.a
LPS = $(LDIR)/libps.a
LPF = $(LDIR)/libftprintf.a

ifeq ($(OS),Linux)
	LMLX = $(LDIR)/libmlx.a
else
	LMLX = $(LDIR)/libmlx.dylib
endif

# Other
RM = rm -f

endif
