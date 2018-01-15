#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborysen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 16:40:13 by dborysen          #+#    #+#              #
#    Updated: 2018/01/11 16:40:16 by dborysen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

LSRCS = libft/ft_putllu.c libft/ft_putlonglong.c libft/ft_print_unicode.c libft/ft_lowstr.c libft/ft_itoa_base.c libft/ft_reverse_bits.c libft/ft_ispower.c libft/ft_isvalid.c libft/ft_atoi.c libft/ft_lstmap.c libft/ft_putendl.c libft/ft_strdel.c libft/ft_strncpy.c libft/ft_bzero.c libft/ft_lstnew.c libft/ft_putendl_fd.c libft/ft_strdup.c libft/ft_strnequ.c libft/ft_isalnum.c libft/ft_memalloc.c libft/ft_putnbr.c libft/ft_strequ.c	libft/ft_strnew.c libft/ft_isalpha.c libft/ft_memccpy.c libft/ft_putnbr_fd.c libft/ft_striter.c libft/ft_strnstr.c libft/ft_isascii.c libft/ft_memchr.c libft/ft_putstr.c libft/ft_striteri.c	libft/ft_strrchr.c libft/ft_isdigit.c	libft/ft_memcmp.c libft/ft_putstr_fd.c libft/ft_strjoin.c libft/ft_strsplit.c libft/ft_isprint.c libft/ft_memcpy.c libft/ft_shwlst.c	libft/ft_strlcat.c	libft/ft_strstr.c libft/ft_itoa.c	libft/ft_memdel.c libft/ft_strcat.c libft/ft_strlen.c libft/ft_strsub.c libft/ft_lstadd.c libft/ft_memmove.c libft/ft_strchr.c libft/ft_strmap.c libft/ft_strtrim.c libft/ft_lstdel.c	libft/ft_memset.c libft/ft_strclr.c libft/ft_strmapi.c libft/ft_tolower.c libft/ft_lstdelone.c libft/ft_putchar.c libft/ft_strcmp.c libft/ft_strncat.c  libft/ft_toupper.c libft/ft_lstiter.c libft/ft_putchar_fd.c libft/ft_strcpy.c libft/ft_strncmp.c libft/ft_reverse.c libft/ft_countw.c

PSRCS = ft_printf.c ft_output_d.c

LOBJECT = ft_putllu.o ft_putlonglong.o ft_print_unicode.o ft_lowstr.o ft_itoa_base.o ft_reverse_bits.o ft_ispower.o ft_isvalid.o ft_atoi.o ft_lstmap.o	ft_putendl.o ft_strdel.o ft_strncpy.o ft_bzero.o ft_lstnew.o ft_putendl_fd.o ft_strdup.o ft_strnequ.o ft_isalnum.o ft_memalloc.o ft_putnbr.o ft_strequ.o ft_strnew.o ft_isalpha.o ft_memccpy.o ft_putnbr_fd.o ft_striter.o ft_strnstr.o ft_isascii.o ft_memchr.o ft_putstr.o ft_striteri.o ft_strrchr.o ft_isdigit.o ft_memcmp.o ft_putstr_fd.o	ft_strjoin.o ft_strsplit.o ft_isprint.o	ft_memcpy.o	ft_shwlst.o	ft_strlcat.o ft_strstr.o ft_itoa.o ft_memdel.o ft_strcat.o ft_strlen.o ft_strsub.o ft_lstadd.o ft_memmove.o	ft_strchr.o	ft_strmap.o	ft_strtrim.o ft_lstdel.o ft_memset.o ft_strclr.o ft_strmapi.o ft_tolower.o ft_lstdelone.o ft_putchar.o ft_strcmp.o ft_strncat.o	ft_toupper.o ft_lstiter.o ft_putchar_fd.o ft_strcpy.o ft_strncmp.o ft_reverse.o	ft_countw.o

POBJECT = ft_printf.o ft_output_d.o

INCLUDES = libft/includes

all: $(NAME)

$(NAME):
	gcc -I $(INCLUDES) -Wall -Wextra -Werror -c $(LSRCS) $(PSRCS)
	ar rc $(NAME) $(LOBJECT) $(POBJECT)
	ranlib $(NAME)

clean:
	rm -f $(LOBJECT) $(POBJECT)

fclean: clean
	rm -f $(NAME)

re: fclean all