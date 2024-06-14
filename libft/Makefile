# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntarik <ntarik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 15:51:05 by ntarik            #+#    #+#              #
#    Updated: 2024/06/12 20:05:30 by ntarik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

FILES := ft_atoi ft_bzero ft_calloc ft_isalnum \
ft_isalpha ft_isascii ft_isdigit ft_isprint  \
ft_itoa ft_memchr \
ft_memcmp ft_memcpy ft_memmove ft_memset \
ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd \
ft_strchr ft_split ft_strdup ft_striteri ft_strjoin \
ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp \
ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper

BONUS_FILES := ft_lstadd_front ft_lstnew ft_lstsize ft_lstlast \
ft_lstadd_back ft_lstiter ft_lstclear ft_lstdelone ft_lstmap

HEADER := libft.h

SRC := $(FILES:=.c)

SRC_BONUS := $(BONUS_FILES:=.c)

OBJS := $(SRC:.c=.o)

OBJS_BONUS := $(SRC_BONUS:.c=.o)

all : $(NAME) $(HEADER)

bonus : $(OBJS_BONUS)
	ar cr $(NAME) $(OBJS_BONUS)

$(NAME) : $(OBJS)
	ar cr $(NAME) $(OBJS)

%.o : %.c $(HEADER) 
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	rm -f $(NAME)

re: fclean all