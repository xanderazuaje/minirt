NAME	:= libft.a
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -g3

HEADERS	:= -I ./include
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= $(patsubst ./src/%.c, obj/%.o, $(SRCS))

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

all: $(NAME)

obj/%.o: src/%.c
	@mkdir -p $(@D)
	@$(COMPILER) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@ar -r $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
