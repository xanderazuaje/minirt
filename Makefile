NAME	:= minirt
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3 -fsanitize=address,leak
LIBMLX	:= ./lib/mlx
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= $(patsubst src/%.c, obj/%.o, $(SRCS))

USE_MOLD ?= 0

ifdef USE_MOLD
	ifeq ($(USE_MOLD), 1)
		COMPILER := mold -run $(CC)
	else
		COMPILER := $(CC)
	endif
else
		COMPILER := $(CC)
endif

all: libmlx libft $(NAME)

libmlx:
	@cmake -DDEBUG=1 $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@echo compiling libft...
	@make -C $(LIBFT) USE_MOLD=$(USE_MOLD)
	@echo libft done!

obj/%.o: src/%.c
	@mkdir -p $(@D)
	@$(COMPILER) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(COMPILER) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf obj/
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft