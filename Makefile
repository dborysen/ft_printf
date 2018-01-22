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

LIBFT = libft

SRCS = ft_output_pack2.c ft_output_pack1.c ft_flags_job.c ft_type_search.c ft_print_unicode.c right_alignment_x.c left_alignment_x.c ft_output_x.c ft_output_u.c right_alignment_u.c left_alignment_u.c right_alignment_d.c left_alignment_d.c ft_printf.c ft_output_d.c ft_output_s.c

OBJECT = ft_output_pack2.o ft_output_pack1.o ft_flags_job.o ft_type_search.o ft_print_unicode.o right_alignment_x.o left_alignment_x.o ft_output_x.o ft_output_u.o right_alignment_u.o left_alignment_u.o right_alignment_d.o left_alignment_d.o ft_printf.o ft_output_d.o ft_output_s.o

INCLUDES = ft_printf.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@gcc -I $(INCLUDES) -Wall -Wextra -Werror -c $(SRCS)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

comp:
	@gcc main.c $(SRCS) libft/libft.a && ./a.out 

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)

clean:
	@rm -f $(OBJECT)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all