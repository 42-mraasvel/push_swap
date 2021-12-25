NAME = libmlx.a

OS = $(shell uname)

# OS check
ifeq (${OS},Linux)
MLXDIR = mlx_linux
MLX = $(MLXDIR)/$(NAME)
else
MLXDIR = mlx_mac
NAME = libmlx.dylib
MLX = $(MLXDIR)/$(NAME)
endif

HED = mlx.h

# Compilation
.PHONY: all
all: $(NAME)
$(NAME): $(MLX)
	cp $(MLX) .
$(MLX):
	$(MAKE) -C $(MLXDIR)

# Cleanup
.PHONY: clean fclean re
clean:
	$(MAKE) clean -C $(MLXDIR)
fclean: clean
	rm -f $(HED)
	rm -f $(NAME)
re: fclean
	$(MAKE) all
