NAME	:= minirt
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g3 -fsanitize=address,leak
LIBMLX	:= ./lib/mlx
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include -I $(LIBMLX)/include -I $(LIBFT)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= $(patsubst src/%.c, obj/%.o, $(SRCS))

all: libmlx libft $(NAME)

libmlx:
	@cmake -DDEBUG=1 $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	make -C $(LIBFT)

obj/%.o: src/%.c
	@mkdir -p $(@D)
	@mold -run $(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf obj/
	@rm -rf $(LIBMLX)/build
	@make -C $(LIBFT) clean

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, libft