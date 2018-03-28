.PHONY: clean clean_objs fclean re r g
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ODIR = objs/
SDIR = srcs/
LDIR = libft/
IDIR = includes/
NAME = fdf
LIB = $(LDIR)libft.a
DLIB = $(LDIR)dlibft.a
FILES = main.c parse.c parse2.c hooks.c draw.c draw_line.c
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(addprefix $(ODIR), $(OBJS))
	@echo "\x1b[34m\nCompiling $@\x1b[0m"
	@$(CC) $(CFLAGS) -I$(IDIR) -I /usr/local/include -o $@ $^ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

$(LIB):
	@echo "\x1b[35m\nCompiling $(notdir $@)\x1b[0m"
	@$(MAKE) -C $(dir $@) $(notdir $@)
	@echo "\x1b[35m\n$(notdir $@) compiled\x1b[0m"

r: g
	@echo "\x1b[32m\nRunning $(NAME)\n\x1b[0m"
	@-for i in ./test_maps/*; do (./fdf $$i & ); done

$(DLIB):
	@echo "\x1b[35mCompiling libft with g flag\x1b[0m"
	@$(MAKE) -C $(LDIR) g

g: $(DLIB)
	@echo "\x1b[34mCompiling $(NAME) with g flag\x1b[0m"
	@$(CC) $(CFLAGS) -I$(IDIR) -I /usr/local/include -g -o $(NAME) $(addprefix $(SDIR), $(FILES)) $(LDIR)dlibft.a -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

$(addprefix $(ODIR), %.o): $(addprefix $(SDIR), %.c)
	@printf "."
	@$(CC) $(CFLAGS) -I$(IDIR) -c -o $@ $<

clean: clean_objs
	@$(MAKE) -C $(LDIR) clean

clean_objs:
	@echo "\x1b[31mRemoving the object files of $(NAME)\x1b[0m"
	@rm -f $(addprefix $(ODIR), $(OBJS))

fclean: clean_objs
	@$(MAKE) -C $(LDIR) fclean
	@echo "\x1b[31mRemoving the $(NAME)\x1b[0m"
	@rm -rf $(NAME) $(NAME).dSYM

re: 
	@$(MAKE) fclean
	@$(MAKE) 
