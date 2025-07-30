

GREEN = \033[32m
BLUE = \033[34m
RESET = \033[0m

NAME = phonebook
CC = c++
CFLAGS =  -std=c++98
CFLAGS += -Wall -Wextra -Werror
CFILES = main.cpp Contact.cpp PhoneBook.cpp ArrayContact.cpp
OBJS_DIR = ./objs/
SRC_DIR = ./src/
OBJS = ${addprefix ${OBJS_DIR}, ${CFILES:.cpp=.o}}
VPATH = ${SRC_DIR}

all: ${NAME}

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o $@
	@echo "${GREEN} ${NAME} compiled ${RESET}"

${OBJS_DIR}:
	@mkdir objs

${OBJS}: | ${OBJS_DIR}

${OBJS_DIR}%.o: %.cpp
	@${CC} ${CFLAGS} -c $^ -o $@

clean:
	@rm -rf ${OBJS_DIR}
	@echo "${BLUE} objects deleted ${RESET}"

fclean: clean
	@rm -rf ${NAME}
	@echo "${BLUE} ${NAME} deleted ${RESET}"

re: fclean all

.PHONY: re clean fclean all