NAME	:= libft.a
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -g3

HEADERS	:= -I ./include
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= $(patsubst ./src/%.c, obj/%.o, $(SRCS))

all: $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(@D)
	@mold -run $(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
