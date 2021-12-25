# Executable
NAME := libps.a


# Directories
SDIR := src
ODIR := obj/
DDIR := dep/
IDIR := includes

# Files
include src.mk
OBJ := $(patsubst $(SDIR)/%.c,$(ODIR)%.o,$(SRC))
DEP := $(patsubst $(SDIR)/%.c,$(DDIR)%.d,$(SRC))

# Compilation
CC = gcc
IFLAGS = -I$(IDIR)
LFLAGS =
CFLAGS = -Wall -Wextra -Werror

RM = /bin/rm -f

# Rules
.PHONY: all
all:
	$(MAKE) -j4 $(NAME)

# Compilation
$(NAME): $(SRC) $(HDF)
	@echo Compiling $@
	@$(MAKE) $(OBJ)
	@ar -rcc $@ $(OBJ)
$(OBJ): $(ODIR)%.o: $(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS) $(IFLAGS)
$(DDIR)%.d: $(SDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $< -MM -MF $@ -MT $(ODIR)$*.o $(IFLAGS)

# Cleanup
.PHONY: clean fclean re cleanall
clean:
	$(RM) $(OBJ)
	$(RM) $(DEP)
	$(RM) -r $(ODIR)
	$(RM) -r $(DDIR)
fclean: clean
	$(RM) $(NAME)
cleanall: fclean
	$(RM) -r $(DDIR)
	$(RM) -r $(ODIR)
re: fclean
	$(MAKE) all

-include $(DEP)
