# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 13:00:32 by mraasvel      #+#    #+#                  #
#    Updated: 2021/12/25 15:57:42 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LFTDIR = libft
LPFDIR = libftprintf
LPSDIR = libps
LMLXDIR = libmlx

OS = $(shell uname)

LFT = libft.a
LPF = libftprintf.a
LPS = libps.a

ifeq ($(OS),Linux)
LMLX = libmlx.a
else
LMLX = libmlx.dylib
endif

.PHONY: all
all: $(LFT)

%.a:
	$(MAKE) -C $*
	cp $*/$@ .
%.dylib:
	$(MAKE) -C $*
	cp $*/$@ .

.PHONY: clean fclean re
clean:
	@$(MAKE) clean -C $(LFTDIR)
	@$(MAKE) clean -C $(LPFDIR)
	@$(MAKE) clean -C $(LPSDIR)
fclean:
	@$(RM) $(LFTDIR)/$(LFT) $(LFT)
	@$(RM) $(LPFDIR)/$(LPF) $(LPF)
	@$(RM) $(LPSDIR)/$(LPS) $(LPS)
	@$(MAKE) fclean -C $(LFTDIR)
	@$(MAKE) fclean -C $(LPFDIR)
	@$(MAKE) fclean -C $(LPSDIR)
re: fclean
	$(MAKE) all
