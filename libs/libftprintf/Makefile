# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/22 13:50:46 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/14 08:53:12 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# Directories
SDIR = src
ODIR = obj
IDIR = includes
LFTDIR = libft

# Files
include src.mk
OBJ = $(patsubst $(SDIR)/%.c,$(ODIR)/%.o,$(SRC))

# Libs
LFT = $(LFTDIR)/libft.a

# Compilation
CC = gcc
CFLAGS = -Wall -Werror -Wextra
IFLAGS = -I$(IDIR) -I.

.PHONY: all
all:
	$(MAKE) -C $(LFTDIR)
	$(MAKE) $(NAME)

$(NAME): $(LFT) $(SRC)
	$(MAKE) $(OBJ)
	cp $(LFT) $(NAME)
	ar rcs $(NAME) $(OBJ)
$(OBJ): $(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -o $@ -c $(CFLAGS) $< $(IFLAGS)
$(LFT):
	$(MAKE) -C $(LIBFTDIR)

.PHONY: clean fclean re
clean:
	$(MAKE) clean -C $(LFTDIR)
	rm -f $(OBJ)
	rm -rf $(ODIR)
fclean:
	$(MAKE) clean
	$(MAKE) fclean -C $(LFTDIR)
	rm -f $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all
