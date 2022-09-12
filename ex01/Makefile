CC	=				c++
CFLAGS =			-Wall -Werror -Wextra -std=c++98
RM =				rm -rf

NAME=				Form_up_maggots
HEADERS =			.

SRCS_DIR = 			srcs
OBJS_DIR =			objs
LIBFT_DIR =			libs/libft

SRCS =				$(wildcard *.cpp)
OBJS =				$(addprefix $(OBJS_DIR)/,$(SRCS:.cpp=.o))

all:				$(NAME)

$(NAME):			$(OBJS)
						@$(CC) $(CFLAGS) -o $(NAME) -I $(HEADERS) $(OBJS)
						@echo "$(NAME) mandatory successfully compiled!"

$(OBJS_DIR)/%.o:	%.cpp
						@mkdir -p $(dir $@)
						@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

clean:
						@$(RM) $(OBJS_DIR)
						@echo "Successfuly cleaned all object files of $(NAME)!"

fclean:				clean
						@$(RM) $(NAME)
						@echo "Successfuly cleaned all executable files of $(NAME)!"

re:					fclean	all

rebonus:			fclean	bonus

.PHONY:				all	clean	fclean	re

