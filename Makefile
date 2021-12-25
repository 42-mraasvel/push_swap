# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mraasvel <mraasvel@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/13 13:07:29 by mraasvel      #+#    #+#                  #
#    Updated: 2021/05/14 15:42:49 by mraasvel      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ./mk_files/settings.mk
include ./mk_files/push_swap.mk
include ./mk_files/checker.mk

# CH = checker
NAME = $(PW) $(CH)
OBJ = $(PW_OBJ) $(CH_OBJ)
DEP = $(PW_DEP) $(CH_DEP)

.PHONY: all
all:
	$(MAKE) $(NAME)

# Libraries
$(LDIR)/%.a:
	$(MAKE) $*.a -C $(LDIR)
$(LDIR)/%.dylib:
	$(MAKE) $*.dylib -C $(LDIR)
	cp $@ .

# Cleaning up
.PHONY: clean fclean re
clean:
	$(RM) -r $(CH_ODIR)
	$(RM) -r $(PW_ODIR)
	$(RM) -r $(CH_DDIR)
	$(RM) -r $(PW_DDIR)
	$(MAKE) clean -C $(LDIR)
fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LDIR)
re: fclean
	$(MAKE) all

# Push Swap
$(PW): $(PW_OBJ) $(PW_LIBS) $(PW_HDF)
	$(CC) -o $@ $(PW_OBJ) $(PW_LFLAGS) $(CFLAGS)
$(PW_OBJ): $(PW_ODIR)/%.o: $(PW_SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS) $(PW_IFLAGS)
$(PW_DEP): $(PW_DDIR)/%.d: $(PW_SDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $< -MM -MF $@ -MT $(PW_ODIR)/$*.o $(PW_IFLAGS)

-include $(PW_DEP)

# Checker compilation
$(CH): $(CH_OBJ) $(CH_LIBS) $(CH_HDF)
	$(CC) -o $@ $(CH_OBJ) $(CH_LFLAGS) $(CFLAGS)
$(CH_OBJ): $(CH_ODIR)/%.o: $(CH_SDIR)/%.c
	@mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS) $(CH_IFLAGS)
$(CH_DEP): $(CH_DDIR)/%.d: $(CH_SDIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $< -MM -MF $@ -MT $(CH_ODIR)/$*.o $(CH_IFLAGS)

-include $(CH_DEP)

# Bonus / MLX

.PHONY: bonus mlx
bonus:
	$(MAKE) all WITH_BONUS=1
mlx:
	$(MAKE) all WITH_BONUS=1 WITH_MLX=1
