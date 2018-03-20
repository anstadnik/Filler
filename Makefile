.PHONY: clean clean_objs fclean re r d v
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ODIR = objs/
SDIR = srcs/
LDIR = libft/
IDIR = includes/
NAME = astadnik.filler
VIS = vis
LIB = $(LDIR)libft.a
FFILES = get_input.c main.c print_sol.c
VFILES = visual_inp.c visualize.c
FOBJS = $(FFILES:.c=.o)
VOBJS = $(VFILES:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(addprefix $(ODIR), $(FOBJS))
	@echo "\x1b[34m\nCompiling $@\x1b[0m"
	@$(CC) $(CFLAGS) -I$(IDIR) -o $@ $^

$(VIS): $(LIB) $(addprefix $(ODIR), $(VOBJS))
	@echo "\x1b[34m\nCompiling $@\x1b[0m"
	@$(CC) $(CFLAGS) -I$(IDIR) -I /usr/local/include -o $@ $^ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

v: $(NAME) $(VIS)
	@-for i in ./resources/players/*.filler; do (./resources/filler_vm -f ./resources/maps/map01 -p1 $$i -p2 ./astadnik.filler | ./vis &); done

r: $(NAME)
	@echo "\x1b[32m\nRunning $(NAME)\n\x1b[0m"
	@echo "VM's output\n" > rez.txt
	@echo "Stderr\n" > log.txt
	@-./resources/filler_vm -f resources/maps/map01 -p1 resources/players/carli.filler -p2 ./astadnik.filler 

rc: r
	@vim -O rez.txt log.txt filler.trace

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
	@echo "\x1b[31mRemoving the object files of $(NAME) and $(VIS)\x1b[0m"
	@rm -f $(addprefix $(ODIR), $(FOBJS)) $(addprefix $(ODIR), $(VOBJS))

fclean: clean_objs
	@$(MAKE) -C $(LDIR) fclean
	@echo "\x1b[31mRemoving the $(NAME) and $(VIS)\x1b[0m"
	@rm -rf $(NAME) $(VIS)

re: 
	@$(MAKE) fclean
	@$(MAKE) 
