# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnagy <lnagy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/23 12:31:27 by lnagy             #+#    #+#              #
#*   Updated: 2016/10/18 17:40:03 by lnagy            ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

PSH    = push_swap
CHK    = checker
CFLG   = -Wextra -Wall -Werror -g
FILES  = stackfunc.c utils.c ops.c
PSHF   = push_swap.c tree_func.c $(FILES)
CHKF   = checker.c $(FILES)
SRCD   = srcs/
OBJD   = objs/
GITLIB = 'https://github.com/lnagy42/libft.git'
LIBS   = -Llibft -lft
PSHS   = $(addprefix $(SRCD),$(PSHF))
PSHO   = $(addprefix $(OBJD),$(PSHF:.c=.o))
CHKS   = $(addprefix $(SRCD),$(CHKF))
CHKO   = $(addprefix $(OBJD),$(CHKF:.c=.o))
HEAD   = includes/push_swap.h
INC    = -Iincludes -Ilibft

.PHONY: lib all clean re fclean

all : $(CHK) $(PSH)

$(OBJD)%.o: $(SRCD)%.c ${HEAD}
	@mkdir -p objs
	gcc $(CFLG) $(INC) -c -o $@ $<

$(PSH): $(PSHO)
		gcc $(CFLG) -o $(PSH) $(PSHO) $(LIBS)

$(CHK): $(CHKO)
		gcc $(CFLG) -o $(CHK) $(CHKO) $(LIBS)

clean:
		@rm -f $(CHKO)
		@rm -f $(PSHO)
		@echo "Objects cleaned."

fclean: clean
		@rm -f $(CHK)
		@rm -f $(PSH)
		@echo "Binaries cleaned."

re: fclean all
