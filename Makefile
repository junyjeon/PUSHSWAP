# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junyojeo <junyojeo@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/12 21:52:21 by junyojeo          #+#    #+#              #
#    Updated: 2023/02/03 22:56:14 by junyojeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Define the complier and flags

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -MMD -O3

# Define the directories

SRC_DIR			=	sources
BUILD_DIR		=	build
INC_DIR			=	-I includes

# Define the source files

SRC_CORE		=	$(addprefix core/, check_duplicate_and_sort.c hard_coding.c \
parsing_stack_and_array.c print_error.c push_pop.c quick_sort.c ranked.c stack_init.c)
SRC_COMMAND		=	$(addprefix command/, push.c reverse_rotate.c rotate.c swap.c)
SRC_UTIL		=	$(addprefix util/, ft_atoi_ll.c ft_lstnew.c ft_memcpy.c ft_split.c \
ft_strdup.c ft_strjoin.c ft_strlen.c ft_strncmp.c ft_substr.c)

PUSHSWAP_SRCS	=	$(addprefix $(SRC_DIR)/, main.c $(SRC_CORE) $(SRC_COMMAND) $(SRC_UTIL))
PUSHSWAP_OBJS	=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(PUSHSWAP_SRCS))
PUSHSWAP_DEPS	=	$(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.d, $(PUSHSWAP_SRCS))

PUSHSWAP		=	push_swap

all:
	@$(MAKE) -j $(PUSHSWAP)

# Define the target and dependencies

$(PUSHSWAP): $(PUSHSWAP_OBJS)
	@$(CC) $(CFLAGS) $^ -o $@
	@printf "${GREEN}> success 🎉${END}"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | dir_guard
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@
	@printf "$(YELLOW)[PUSHSWAP] [%02d/%02d] ( %3d %%) Compiling $<\r$(END)"

dir_guard:
	@mkdir -p $(addprefix $(BUILD_DIR)/, core)
	@mkdir -p $(addprefix $(BUILD_DIR)/, command)
	@mkdir -p $(addprefix $(BUILD_DIR)/, util)

clean:
	@$(RM) -r $(BUILD_DIR)
	@echo "${YELLOW}> All objects files of the push_swap have been deleted.❌${END}"

fclean:
	@$(RM) -r $(PUSHSWAP) $(BUILD_DIR) push_swap
	@echo "${YELLOW}> Cleaning of the push_swap has been done.❌${END}"

re: fclean
	@$(MAKE) all
	@printf "$(GREEN)Cleaned and rebuilt everything for pushswap!${END}"

.PHONY:	all clean fclean re dir_guard

#Colors

END				=	$'\x1b[0m
BOLD			=	$'\x1b[1m
UNDER			=	$'\x1b[4m
REV				=	$'\x1b[7m
GREY			=	$'\x1b[30m
RED				=	$'\x1b[31m
GREEN			=	$'\x1b[32m
YELLOW			=	$'\x1b[33m
BLUE			=	$'\x1b[34m
PURPLE			=	$'\x1b[35m
CYAN			=	$'\x1b[36m
WHITE			=	$'\x1b[37m

-include $(PUSHSWAP_DEPS)
