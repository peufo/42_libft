NAME = libft
DIR_SRC = src
DIR_BUILD = build
DIR_TEST = .test
FUNCTIONS =	ft_isalpha\
			ft_isdigit\
			ft_isalnum\
			ft_isascii\
			ft_isprint\
			ft_strlen\
			ft_memset\

OBJECTS = $(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS)))
TESTS = $(addprefix $(DIR_TEST)/$(DIR_BUILD)/, $(FUNCTIONS))

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -cr $@.a $^
	@ranlib $@.a

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@./sync.sh $^
	@cc -Wall -Wextra -Werror -c $^ -o $@

$(DIR_BUILD):
	mkdir $(DIR_BUILD)

test: $(NAME) $(TESTS) $(OBJECTS)
	@./test.sh

$(TESTS): $(DIR_TEST)/$(DIR_BUILD)/%: $(DIR_TEST)/%.c $(DIR_BUILD)/%.o | $(DIR_TEST)/$(DIR_BUILD)
	@cc -fsanitize=address -Wall -Wextra -Werror $< -L. -lft -o $@

$(DIR_TEST)/$(DIR_BUILD):
	mkdir $(DIR_TEST)/$(DIR_BUILD)

clean:
	rm -rf $(DIR_BUILD)
	rm -rf $(DIR_TEST)/$(DIR_BUILD)

fclean: clean
	rm -f $(NAME).a

.PHONY: clean
