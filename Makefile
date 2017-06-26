#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/20 19:26:58 by vinvimo           #+#    #+#              #
#    Updated: 2017/06/22 23:26:50 by vinvimo          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

C_INCLUDE_PATH += include/ libft

CFLAGS += -Wall -Wextra -Werror

CFLAGS += $(foreach d, $(C_INCLUDE_PATH), -I$d)

SRCS = src/ft_printf.c src/analyse_specs.c \
src/choose_type.c src/choose_type_bis.c src/initialize.c \
src/get_c.c src/get_s.c src/get_upper_s.c src/get_d.c \
src/get_u.c src/get_o.c src/get_x.c src/get_b.c \
src/ft_itoa_base_u.c src/unicode_to_utf8.c

LIBFT_FUNS = strnew_w memset_w strlen_w putstr_w putchar_w atoi strnew strdup \
bzero memset strlen putstr putchar

CFLAGS += $(foreach fun,$(LIBFT_FUNS),-Dft_$(fun)=ft_printf_libft_$(fun))

OBJS = $(patsubst src/%.c,obj/%.o,$(SRCS))
OBJS += $(foreach fun,$(LIBFT_FUNS),obj/libft/ft_$(fun).o)

CP = cp

RM = rm -f

all: $(NAME)

$(OBJS): | obj

obj:
	@mkdir -p $@
	@mkdir -p $@/libft

obj/%.o: src/%.c
	clang -c $(CFLAGS) $< -o $@

obj/libft/%.o: libft/%.c
	clang -c $(CFLAGS) $< -o $@

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $^

clean:
	$(RM) $(OBJS)
	$(RM) libft/*.o

libfttest: $(NAME) obj/main.o
	$(CC) -o $@ obj/main.o -L. -lftprintf

fclean: clean
	$(RM) $(NAME)
	$(RM) libft/*.a
	$(RM) -rf obj

re: fclean all

.PHONY: all clean fclean re
