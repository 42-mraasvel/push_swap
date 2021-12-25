# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    checker.mk                                         :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 16:27:28 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/13 21:32:43 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

ifndef CHECKER_MK
CHECKER_MK = 1

CH = checker

# Directories
CH_DIR = ./src/checker
CH_SDIR = $(CH_DIR)/src
CH_IDIR = $(CH_DIR)/includes
CH_ODIR = $(CH_DIR)/obj
CH_DDIR = $(CH_DIR)/dep

# Files
include ./mk_files/checker_src.mk
CH_OBJ = $(patsubst $(CH_SDIR)/%.c,$(CH_ODIR)/%.o,$(CH_SRC))
CH_DEP = $(patsubst $(CH_SDIR)/%.c,$(CH_DDIR)/%.d,$(CH_SRC))

CH_LIBS = $(LFT) $(LPS)

ifdef WITH_BONUS
	CH_LIBS += $(LPF)
	ifdef WITH_MLX
		CH_LIBS += $(LMLX)
	endif
endif

# Flags
CH_LFLAGS = -L$(LDIR) -lps -L$(LDIR) -lft
CH_IFLAGS = -I$(CH_IDIR)

ifdef WITH_BONUS
	CH_LFLAGS += -L$(LDIR) -lftprintf
	ifdef WITH_MLX
		CH_LFLAGS += -lm -pthread
		CH_IFLAGS += -I$(LDIR)/libmlx
		ifeq ($(OS),Linux)
			CH_LFLAGS += -L$(LDIR) -lmlx -lXext -lX11
		else
			CH_LFLAGS += -L. -lmlx -framework OpenGL -framework AppKit
		endif
	endif

endif

endif
