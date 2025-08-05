# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/24 18:04:01 by inazaria          #+#    #+#              #
#    Updated: 2025/08/05 18:36:25 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<><><><><><><> Files <><><><><><><><><><><><><><><><><><><>
SRC_DIR 	= ./src/

BUILD_DIR 	= ./build/

INC_DIR 	= ./includes/

LIBFT_DIR 	= ./libft/

# .c files for source code SRC_FILES_NAMES = main.c
SRC_FILES_NAMES = main.c

SRC_FILES_NAMES += parser/parser.c

SRC_FILES_NAMES += packet/packet_utils.c

SRC_FILES_NAMES += utils/print_utils.c
SRC_FILES_NAMES += utils/error.c
SRC_FILES_NAMES += utils/utils.c


# Full path to .c files
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC_FILES_NAMES))

# .o files for compilation
OBJ_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.o, $(SRC_FILES))

# .d files for header dependency
DEP_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.d, $(SRC_FILES))


#<><><><><><><> Variables <><><><><><><><><><><><><><><><><>

NAME 	:= ft_ping
CC 	:= cc
CFLAGS 	:= -gdwarf-4 -Wall -Wextra -Werror -I $(INC_DIR) -MMD -MP
LFLAGS 	:= libft/libft.a
MKDIR 	:= mkdir -p
RM_RF 	:= rm -rf
ECHO  	:= echo -e

PROJECT_VERSION := $(shell git describe --tags --always || echo "0.1")

BLUE	:= $(shell echo -e "\033[34m") 
BROWN	:= $(shell echo -e "\033[33m")
GREEN	:= $(shell echo -e "\033[32m")
RED	:= $(shell echo -e "\033[31m")
NC	:= $(shell echo -e "\033[0m")

#<><><><><><><> Recipes <><><><><><><><><><><><><><><><><><>

# Modifying Implicit conversion rules to build in custom directory
$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	@$(MKDIR) $(dir $@)
	@$(ECHO) "\033[34m[CMP] Compiling $<...$(NC)"
	@$(CC) -c $(CFLAGS) $< -o $@ 


# This is to add the .d files as dependencies for linking
-include $(DEP_FILES)

re : fclean all

$(NAME) : $(OBJ_FILES)
	@$(ECHO) "$(BROWN)[BLD] Building libft static library...$(NC)"
	@$(MAKE) --no-print-directory -s -C $(LIBFT_DIR) all
	@$(ECHO) "$(GREEN)[BLD] successfully built libft.$(NC)"	

	@$(ECHO) "$(BROWN)[BLD] Building $(NAME) executable...$(NC)"
	@$(CC) $^ -o $(NAME) $(LFLAGS)
	@$(ECHO) "$(GREEN)[BLD] Executable built successfully.$(NC)"

all : $(NAME) 

clean : 
	@$(ECHO) "$(BROWN)[CLN] Cleaning object and dependency files...$(NC)"
	@$(RM) $(DEP_FILES) $(OBJ_FILES)
	@$(ECHO) "$(GREEN)[CLN] Clean complete.$(NC)"

fclean : 
	@$(ECHO) "$(BROWN)[CLN] Cleaning Libft object and dependency files...$(NC)"
	@$(MAKE) --no-print-directory -s -C $(LIBFT_DIR) fclean > /dev/null
	@$(ECHO) "$(GREEN)[CLN] Libft Clean complete.$(NC)"
	@$(ECHO) "$(BROWN)[CLN] Cleaning object, dependency files, and executable...$(NC)"
	@$(RM_RF) $(BUILD_DIR) $(NAME)
	@$(ECHO) "$(GREEN)[CLN] Clean complete.$(NC)"


.DEFAULT_GOAL := all
.PHONY : all clean fclean re
