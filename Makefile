.PHONY: clean clean_objs fclean re r d
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ODIR = objs/
SDIR = srcs/
LDIR = libft/
IDIR = includes/
NAME = astadnik.filler
LIB = $(LDIR)libft.a
FILES = get_input.c main.c print_sol.c
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(addprefix $(ODIR), $(OBJS))
	@echo "\x1b[34m\nCompiling $@\x1b[0m"
	@$(CC) $(CFLAGS) -I$(IDIR) -o $@ $^

r: $(NAME)
	@echo "\x1b[32m\nRunning $(NAME)\n\x1b[0m"
	@echo "VM's output\n" > rez.txt
	@echo "Stderr\n" > log.txt
	@-./resources/filler_vm -f resources/maps/map00 -p1 resources/players/abanlin.filler -p2 ./$(NAME) -s 5467 -t 1 1>> rez.txt 2>> log.txt

rc: r
	@vim -O rez.txt log.txt filler.trace \


d: $(LIB)
	@$(CC) $(CFLAGS) -I$(IDIR) -g -o $(NAME) $(addprefix $(SDIR), $(FILES)) libft/objs/*.o
	@echo "\x1b[32m\nRunning $(NAME)\n\x1b[0m"
	@./$(NAME)

$(LIB):
	@echo "\x1b[35m\nCompiling $(notdir $@)\x1b[0m"
	@$(MAKE) -C $(dir $@) $(notdir $@)
	@echo "\x1b[35m\n$(notdir $@) compiled\x1b[0m"

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
