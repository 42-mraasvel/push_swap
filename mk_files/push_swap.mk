# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    push_swap.mk                                       :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 14:02:30 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/13 20:44:47 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ifndef PUSH_SWAP_MK
PUSH_SWAP_MK = 1

PW = push_swap

# Directories
PW_DIR = ./src/push_swap
PW_SDIR = $(PW_DIR)/src
PW_IDIR = $(PW_DIR)/includes
PW_ODIR = $(PW_DIR)/obj
PW_DDIR = $(PW_DIR)/dep

# Files
include ./mk_files/push_swap_src.mk
PW_OBJ = $(patsubst $(PW_SDIR)/%.c,$(PW_ODIR)/%.o,$(PW_SRC))
PW_DEP = $(patsubst $(PW_SDIR)/%.c,$(PW_DDIR)/%.d,$(PW_SRC))

PW_LIBS = $(LFT) $(LPS)

# Flags
PW_LFLAGS = -L$(LDIR) -lps -L$(LDIR) -lft
PW_IFLAGS = -I$(PW_IDIR)

endif
