NAME	= pipex

UTILS_SRC = utils/ft_error_msg.c		utils/ft_find_path.c  \
			utils/ft_free_arr.c			utils/ft_putstr_fd.c  \
			utils/ft_split.c			utils/ft_strchr.c \
			utils/ft_strlen.c			utils/ft_strjoin.c  \
			utils/ft_substr.c			utils/ft_strncmp.c  \
			utils/ft_strdup.c			utils/ft_array_len.c \
			utils/close_fds.c

SRCS		=	mandatory/main.c	mandatory/ft_fork.c		mandatory/execution.c

SRCS_BNS	=   bonus/main_bonus.c	bonus/ft_multi_pipe_bonus.c		bonus/execution_bonus.c 	bonus/here_doc_bonus.c	bonus/free_exec_res.c

gnl			=	bonus/gnl/get_next_line_bonus.c	bonus/gnl/get_next_line_utils_bonus.c

OBJS	=	${SRCS:.c=.o}	${UTILS_SRC:.c=.o}

OBJS_BNS	=	${SRCS_BNS:.c=.o}	${UTILS_SRC:.c=.o}	${gnl:.c=.o}

CC		= cc

CFLAGS	= -Wall -Wextra -Werror 

all: $(NAME)

%_bonus.o:%_bonus.c  utils/utils.h  bonus/pipex_bonus.h   bonus/gnl/get_next_line_bonus.h
	@$(CC) ${CFLAGS} -c $< -o $@

%.o:%.c  mandatory/pipex.h  utils/utils.h
	@$(CC) ${CFLAGS} -c $< -o $@

$(NAME): 		${OBJS}
	@$(CC) ${OBJS} -o ${NAME}
	@echo "finish compilation"

bonus:		${OBJS_BNS}
	@$(CC) ${OBJS_BNS} -o ${NAME}
	@echo "finish compilation"

clean:
	@rm -f ${OBJS} ${OBJS_BNS}
	@echo "remove object files"

fclean: 	clean
	@rm -f $(NAME)
	@echo "remove " ${NAME}

re:		fclean all

.PHONY: all clean fclean re