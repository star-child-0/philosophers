# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anvannin <anvannin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 18:36:34 by anvannin          #+#    #+#              #
#    Updated: 2023/07/03 16:04:36 by anvannin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config ---------------------------------------------------------------------->

NAME		:= philo
SRCS		:=	main.c \
			utils.c \
			threads.c \
			time.c \
			table.c \
			philo.c \
			philo_routine.c \
			philo_status.c \
			waiter.c \
			menu.c \

SRC_DIR     := src
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
BUILD_DIR   := .build
OBJS        := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS        := $(OBJS:.o=.d)
INCS        := ./include
CC          := gcc
CFLAGS      := -g -Wall -Wextra -Werror
PTHREAD	:= -pthread
CPPFLAGS    := $(addprefix -I,$(INCS)) -MMD -MP
RM          := rm -rf
DIR_DUP     = mkdir -p $(@D)

.PHONY: all clean fclean re
.SILENT:

# Rules ----------------------------------------------------------------------->

define total_files
$(shell echo "$(SRCS)" | wc -w)
endef

define obj_files
$(shell bash -c 'shopt -s nullglob && echo .build/*.o | wc -w')
endef

define percent
$(shell echo $$(($(obj_files) * 100 / $(total_files))))
endef

all: banner $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(PTHREAD)
	${info ${BOLD}[100%]	  Done!   ->  ${GREEN}$(NAME)${NO_COLOR}}

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	${info ${BOLD}[$(percent)%]	Compiling -> ${YELLOW}$@${NO_COLOR}}

-include $(DEPS)

clean:
	$(RM) $(BUILD_DIR)
	${info }
	${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}}

fclean: clean
	$(RM) $(NAME) $(NAME_CLIENT)

re:
	$(MAKE) fclean
	$(MAKE) all

# Style ----------------------------------------------------------------------->

RED		:= ${shell tput setaf 1}
GREEN		:= ${shell tput setaf 2}
YELLOW	:= ${shell tput setaf 3}
BLUE		:= ${shell tput setaf 4}
MAGENTA	:= ${shell tput setaf 5}
NO_COLOR	:= ${shell tput sgr0}
BOLD		:= ${shell tput bold}
UNDERLINE	:= ${shell tput smul}
ITALIC	:= ${shell tput sitm}

banner:

${info ${RED}}
${info  ██▓███   ██░ ██  ██▓ ██▓     ▒█████    ██████  ▒█████   ██▓███   ██░ ██ ▓█████  ██▀███    ██████  }
${info ▓██░  ██▒▓██░ ██▒▓██▒▓██▒    ▒██▒  ██▒▒██    ▒ ▒██▒  ██▒▓██░  ██▒▓██░ ██▒▓█   ▀ ▓██ ▒ ██▒▒██    ▒  }
${info ▓██░ ██▓▒▒██▀▀██░▒██▒▒██░    ▒██░  ██▒░ ▓██▄   ▒██░  ██▒▓██░ ██▓▒▒██▀▀██░▒███   ▓██ ░▄█ ▒░ ▓██▄    }
${info ▒██▄█▓▒ ▒░▓█ ░██ ░██░▒██░    ▒██   ██░  ▒   ██▒▒██   ██░▒██▄█▓▒ ▒░▓█ ░██ ▒▓█  ▄ ▒██▀▀█▄    ▒   ██▒ }
${info ▒██▒ ░  ░░▓█▒░██▓░██░░██████▒░ ████▓▒░▒██████▒▒░ ████▓▒░▒██▒ ░  ░░▓█▒░██▓░▒████▒░██▓ ▒██▒▒██████▒▒ }
${info ▒▓▒░ ░  ░ ▒ ░░▒░▒░▓  ░ ▒░▓  ░░ ▒░▒░▒░ ▒ ▒▓▒ ▒ ░░ ▒░▒░▒░ ▒▓▒░ ░  ░ ▒ ░░▒░▒░░ ▒░ ░░ ▒▓ ░▒▓░▒ ▒▓▒ ▒ ░ }
${info ░▒ ░      ▒ ░▒░ ░ ▒ ░░ ░ ▒  ░  ░ ▒ ▒░ ░ ░▒  ░ ░  ░ ▒ ▒░ ░▒ ░      ▒ ░▒░ ░ ░ ░  ░  ░▒ ░ ▒░░ ░▒  ░ ░ }
${info ░░        ░  ░░ ░ ▒ ░  ░ ░   ░ ░ ░ ▒  ░  ░  ░  ░ ░ ░ ▒  ░░        ░  ░░ ░   ░     ░░   ░ ░  ░  ░   }
${info           ░  ░  ░ ░      ░  ░    ░ ░        ░      ░ ░            ░  ░  ░   ░  ░   ░           ░   }
${info }
${info ${BOLD}${ITALIC}${YELLOW}                        🍝 I never thought philosophy would be so deadly 🍝}
${info ${NO_COLOR}}

# ------------------------------------------------------------------------------
