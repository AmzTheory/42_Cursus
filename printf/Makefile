#
# 'make depend' uses makedepend to automatically generate dependencies
#               (dependencies are added to end of Makefile)
# 'make'        build executable file 'mycc'
# 'make clean'  removes all .o and executable files
#

# define the C compiler to use
CC			= gcc

# define any compile-time flags
CFLAGS		= -Wall -Wextra -Werror -g
# define any directories containing header files other than /usr/include
#
libft_DIR 		= libft/
LIBFT			= libft/libft.a


# define any directories containing header files other than /usr/include
#
INCS = -I.

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = -L$(libft_DIR)
#-lft

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname
#   option, something like (this will link in libmylib.so and libm.so:
LIB 			= ar -rcs
LIB1 			= ranlib
RM				= rm -f

# define the C source files
SRCS = ft_printf.c config.c utils.c ft_uitoa.c hex_conv.c char_conv.c int_conv.c str_conv.c unsigned_conv.c
# define the C object files
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

# define the executable file
# NAME = libftprintf.a
NAME = libftprintf.a

# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lft

#
# The following part of the makefile is generic; it can be used to
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
				 $(LIB) $(NAME) $(OBJS)
				 $(LIB1) $(NAME)
exe: $(OBJS) $(LIBFT)
					@echo  Simple compiler named libfprint has been compiled
					$(CC) $(CFLAGS) $(INCS) -o $(NAME) $(OBJS) $(LFLAGS) $(LIBS)

# debug: $(OBJS) $(LIBFT)
# 					@echo  Simple debuger named libfprint has been compiled
# 					$(CC) $(CFLAGS) $(INCS)  -o $(NAME) $(OBJS) $(LFLAGS) $(LIBS)
# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file)
# (see the gnu make manual section about automatic variables)
.c.o:
		$(CC) $(CFLAGS) $(INCS) -c $<  -o $@

$(LIBFT):
		@echo  libft make
		make -C $(libft_DIR)
		cp $(LIBFT) $(NAME)

clean:
		make clean -C $(libft_DIR)
		$(RM) $(OBJS)

fclean: clean
			make fclean -C $(libft_DIR)
			$(RM) $(NAME)


bonus:	all

re:		fclean all

.PHONY: all clean fclean re
