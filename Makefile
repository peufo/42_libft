NAME = libft.a
NAME_SO = libft.so
DIR_SRC = src
DIR_BUILD = build
DIR_TEST = .test
FLAGS = -Wall -Wextra -Werror -include libft.h

SOURCES		=	src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c src/ft_isalnum.c src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c src/ft_itoa.c src/ft_memchr.c src/ft_memcmp.c src/ft_memcpy.c src/ft_memmove.c src/ft_memset.c src/ft_putchar_fd.c src/ft_putendl_fd.c src/ft_putnbr_fd.c src/ft_putstr.c src/ft_putstr_fd.c src/ft_split.c src/ft_strchr.c src/ft_strdup.c src/ft_striteri.c src/ft_strjoin.c src/ft_strlcat.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strmapi.c src/ft_strncmp.c src/ft_strnstr.c src/ft_strrchr.c src/ft_strtrim.c src/ft_substr.c src/ft_tolower.c src/ft_toupper.c 
FUNCTIONS	=	$(subst .c,,$(notdir $(SOURCES)))
OBJECTS		=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS)))
TESTS		=	$(addprefix $(DIR_TEST)/$(DIR_BUILD)/, $(FUNCTIONS))

SOURCES_BNS	=		src/ft_lstadd_front.c src/ft_lstnew.c 
FUNCTIONS_BNS	=	$(subst .c,,$(notdir $(SOURCES_BNS)))
OBJECTS_BNS		=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS_BNS)))
TESTS_BNS		=	$(addprefix $(DIR_TEST)/$(DIR_BUILD)/, $(FUNCTIONS_BNS))

OS			=	$(shell uname -s)
LIBS = -L. -lft
ifeq ($(OS),Linux)
	LIBS += -lbsd -ldl -lpthread -lm
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -cr $@ $^

bonus: $(NAME) $(OBJECTS_BNS)
	@ar -cr $(NAME) $(OBJECTS_BNS)

so: $(OBJECTS)
	@gcc -nostartfiles -shared -o libft.so $(OBJECTS)

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@gcc $(FLAGS) -c $^ -o $@

$(DIR_BUILD):
	@mkdir $(DIR_BUILD)

test: bonus $(TESTS) $(TESTS_BNS)
	@./test.sh

test-v: bonus $(TESTS) $(TESTS_BNS)
	@./test.sh -v

$(DIR_TEST)/$(DIR_BUILD)/%: $(DIR_TEST)/%.c $(DIR_BUILD)/%.o | $(DIR_TEST)/$(DIR_BUILD)
	@gcc $(FLAGS) -include $(DIR_TEST)/test.h $< -o $@ $(LIBS)

$(DIR_TEST)/$(DIR_BUILD):
	@mkdir $(DIR_TEST)/$(DIR_BUILD)

clean:
	rm -rf $(DIR_BUILD)
	rm -rf $(DIR_TEST)/$(DIR_BUILD)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_SO)

re: fclean all
