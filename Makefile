NAME = libftprintf.a

SRCS = ft_lstdelone.c ft_putchar_fd.c ft_strdup.c ft_strnew.c ft_lstiter.c ft_putendl.c \
	   ft_strequ.c ft_strnstr.c ft_lstmap.c ft_putendl_fd.c ft_striter.c ft_strrchr.c \
	   ft_atoi.c	ft_lstnew.c	ft_putnbr.c	ft_striteri.c	ft_strsplit.c \
	   ft_bzero.c	ft_memalloc.c	ft_putnbr_fd.c	ft_strjoin.c	ft_strstr.c \
	   ft_isalnum.c	ft_memccpy.c	ft_putstr.c	ft_strlcat.c	ft_strsub.c \
	   ft_isalpha.c	ft_memchr.c	ft_putstr_fd.c	ft_strlen.c	ft_strtrim.c \
	   ft_isascii.c	ft_memcmp.c	ft_strcat.c	ft_strmap.c \
	   ft_isdigit.c	ft_memcpy.c	ft_strchr.c	ft_strmapi.c \
	   ft_isprint.c	ft_memdel.c	ft_strclr.c	ft_strncat.c \
	   ft_itoa.c	ft_memmove.c	ft_strcmp.c	ft_strncmp.c \
	   ft_lstadd.c	ft_memset.c	ft_strcpy.c	ft_strncpy.c \
	   ft_lstdel.c	ft_putchar.c	ft_strdel.c	ft_strnequ.c \
	   ft_toupper.c ft_tolower.c ft_abs.c ft_exp.c ft_iswspace.c \
	   ft_lstlen.c	ft_lstat.c get_next_line.c ft_itoa_base.c  ft_utoa_base.c \
	   heap.c heap_help.c heap_help_two.c random.c \
	   printf/printf.c printf/process.c printf/import.c printf/wide.c
OBJS = ft_lstdelone.o ft_putchar_fd.o ft_strdup.o ft_strnew.o ft_lstiter.o ft_putendl.o \
	   ft_strequ.o ft_strnstr.o ft_lstmap.o ft_putendl_fd.o ft_striter.o ft_strrchr.o \
	   ft_atoi.o	ft_lstnew.o	ft_putnbr.o	ft_striteri.o	ft_strsplit.o \
	   ft_bzero.o	ft_memalloc.o	ft_putnbr_fd.o	ft_strjoin.o	ft_strstr.o \
	   ft_isalnum.o	ft_memccpy.o	ft_putstr.o	ft_strlcat.o	ft_strsub.o \
	   ft_isalpha.o	ft_memchr.o	ft_putstr_fd.o	ft_strlen.o	ft_strtrim.o \
	   ft_isascii.o	ft_memcmp.o	ft_strcat.o	ft_strmap.o \
	   ft_isdigit.o	ft_memcpy.o	ft_strchr.o	ft_strmapi.o \
	   ft_isprint.o	ft_memdel.o	ft_strclr.o	ft_strncat.o \
	   ft_itoa.o	ft_memmove.o	ft_strcmp.o	ft_strncmp.o \
	   ft_lstadd.o	ft_memset.o	ft_strcpy.o	ft_strncpy.o \
	   ft_lstdel.o	ft_putchar.o	ft_strdel.o	ft_strnequ.o \
	   ft_toupper.o ft_tolower.o ft_abs.o ft_exp.o ft_iswspace.o \
	   ft_lstlen.o	ft_lstat.o get_next_line.o ft_itoa_base.o ft_utoa_base.o \
	   heap.o heap_help.o heap_help_two.o random.o \
	   printf/printf.o printf/process.o printf/import.o printf/wide.o
all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)
%.o: %.c
	gcc -c -o $@ $< -I includes
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re:	fclean all
