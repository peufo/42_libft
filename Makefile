NAME = libft
DIR_SRC = src
DIR_BUILD = build
DIR_TEST = .test
FLAGS = -Wall -Wextra -Werror -include libft.h
FUNCTIONS += ft_isalpha
FUNCTIONS += ft_isdigit
FUNCTIONS += ft_isalnum
FUNCTIONS += ft_isascii
FUNCTIONS += ft_isprint
FUNCTIONS += ft_strlen
FUNCTIONS += ft_strlcpy
FUNCTIONS += ft_strlcat
FUNCTIONS += ft_bzero
FUNCTIONS += ft_memset
FUNCTIONS += ft_memcpy
FUNCTIONS += ft_memmove
FUNCTIONS += ft_toupper
FUNCTIONS += ft_tolower
FUNCTIONS += ft_strchr
FUNCTIONS += ft_strrchr
FUNCTIONS += ft_memchr
FUNCTIONS += ft_memcmp
FUNCTIONS += ft_strnstr
FUNCTIONS += ft_atoi
FUNCTIONS += ft_calloc
FUNCTIONS += ft_strdup
FUNCTIONS += ft_substr
FUNCTIONS += ft_strjoin
FUNCTIONS += ft_strtrim
FUNCTIONS += ft_split

OBJECTS = $(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS)))
TESTS = $(addprefix $(DIR_TEST)/$(DIR_BUILD)/, $(FUNCTIONS))

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -cr $@.a $^
	@ranlib $@.a

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@./sync.sh $^
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

.PHONY: clean
