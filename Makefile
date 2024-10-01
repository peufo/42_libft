NAME = libft.a
DIR_SRC = src
DIR_BUILD = build
DIR_TEST = .test
FLAGS = -Wall -Wextra -Werror -include libft.h

SOURCES = $(wildcard $(DIR_SRC)/*.c)
FUNCTIONS = $(subst .c,,$(notdir $(SOURCES)))
OBJECTS = $(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS)))
TESTS = $(addprefix $(DIR_TEST)/$(DIR_BUILD)/, $(FUNCTIONS))

all: $(NAME)
	@./norm.sh $(SOURCES)

$(NAME): $(OBJECTS)
	@ar -cr $@ $^
	@ranlib $@

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@cc $(FLAGS) -c $^ -o $@

$(DIR_BUILD):
	mkdir $(DIR_BUILD)

test: $(NAME) $(TESTS) $(OBJECTS)
	@./test.sh

$(TESTS): $(DIR_TEST)/$(DIR_BUILD)/%: $(DIR_TEST)/%.c $(DIR_BUILD)/%.o | $(DIR_TEST)/$(DIR_BUILD)
	@cc -fsanitize=address $(FLAGS) $< -L. -lft -o $@

$(DIR_TEST)/$(DIR_BUILD):
	mkdir $(DIR_TEST)/$(DIR_BUILD)

clean:
	rm -rf $(DIR_BUILD)
	rm -rf $(DIR_TEST)/$(DIR_BUILD)

fclean: clean
	rm -f $(NAME).a

# Les sources nécessaires à la compilation de mon programme sont 🥁🥁🥁 : src/ft_atoi.c src/ft_bzero.c src/ft_calloc.c src/ft_isalnum.c src/ft_isalpha.c src/ft_isascii.c src/ft_isdigit.c src/ft_isprint.c src/ft_itoa.c src/ft_memchr.c src/ft_memcmp.c src/ft_memcpy.c src/ft_memmove.c src/ft_memset.c src/ft_putstr.c src/ft_split.c src/ft_strchr.c src/ft_strdup.c src/ft_strjoin.c src/ft_strlcat.c src/ft_strlcpy.c src/ft_strlen.c src/ft_strnstr.c src/ft_strrchr.c src/ft_strtrim.c src/ft_substr.c src/ft_tolower.c src/ft_toupper.c $
