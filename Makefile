NAME = libft.a
NAME_SO = libft.so
DIR_SRC = src
DIR_BUILD = build
DIR_TEST = .test
FLAGS = -Wall -Wextra -Werror -include libft.h 

SOURCES		=	$(wildcard $(DIR_SRC)/*.c)
FUNCTIONS	=	$(subst .c,,$(notdir $(SOURCES)))
OBJECTS 	=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS)))
TESTS		=	$(addprefix $(DIR_TEST)/$(DIR_BUILD)/, $(FUNCTIONS))
OS			=	$(shell uname -s)
LIBS = -L. -lft
ifeq ($(OS),Linux)
	LIBS += -lbsd -ldl -lpthread -lm
endif

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -cr $@ $^

so: $(OBJECTS)
	@gcc -nostartfiles -shared -o libft.so $(OBJECTS)

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@gcc $(FLAGS) -c $^ -o $@

$(DIR_BUILD):
	mkdir $(DIR_BUILD)

test: $(NAME) $(TESTS) $(OBJECTS)
	@./test.sh

$(TESTS): $(DIR_TEST)/$(DIR_BUILD)/%: $(DIR_TEST)/%.c $(DIR_BUILD)/%.o | $(DIR_TEST)/$(DIR_BUILD)
	@gcc $(FLAGS) -include $(DIR_TEST)/test.h $< -o $@ $(LIBS)

$(DIR_TEST)/$(DIR_BUILD):
	mkdir $(DIR_TEST)/$(DIR_BUILD)

clean:
	rm -rf $(DIR_BUILD)
	rm -rf $(DIR_TEST)/$(DIR_BUILD)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_SO)

re: fclean all

