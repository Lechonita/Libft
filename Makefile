# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 10:20:37 by jrouillo          #+#    #+#              #
#    Updated: 2022/11/24 15:19:31 by jrouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		*ft_memset.c \
		ft_bzero.c \
		*ft_memcpy.c \
		*ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		*ft_strchr.c \
		*ft_strrchr.c \
		ft_strncmp.c \
		*ft_memchr.c \
		ft_memcmp.c \
		*ft_strnstr.c \
		ft_atoi.c \
		*ft_calloc.c \
		*ft_strdup.c \
		*ft_substr.c \
		*ft_strjoin.c \
		*ft_strtrim.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		*ft_itoa.c \
		*ft_strmapi.c \
		ft_striteri.c \
		**ft_split.c

SRCSBONUS = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			*ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			*ft_lstmap.c

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${SRCSBONUS:.c=.o}

FLAGS = -Wall -Werror -Wextra

%.o: %.c libft.h
	gcc ${FLAGS} -I. -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) libft.h
	ar -rsc ${NAME} ${OBJS}

bonus: $(OBJS) $(OBJSBONUS) libft.h
	ar -rsc ${NAME} ${OBJS} ${OBJSBONUS}

clean:
	rm -f $(OBJS) ${OBJSBONUS}

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
