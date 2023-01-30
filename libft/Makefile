#------------------------------------------------------------------------------#
#								   GENERAL									   #
#------------------------------------------------------------------------------#
NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra #-I -nostartfiles
RM = rm -rf
AR = ar rcs

#------------------------------------------------------------------------------#
#									SOURCES									   #
#------------------------------------------------------------------------------#
HEADER = includes/libft.h
D_SRC = src/
D_OBJ = obj/
OBJS = $(patsubst $(D_SRC)%.c,$(D_OBJ)%.o,$(SRCS))
SRCS = \
		src/ft_isalpha.c \
		src/ft_isdigit.c \
		src/ft_isalnum.c \
		src/ft_isascii.c \
		src/ft_isprint.c \
		src/ft_strlen.c \
		src/ft_memset.c \
		src/ft_bzero.c \
		src/ft_memcpy.c \
		src/ft_memmove.c \
		src/ft_strlcpy.c \
		src/ft_strcpy.c \
		src/ft_strlcat.c \
		src/ft_tolower.c \
		src/ft_toupper.c \
		src/ft_strchr.c \
		src/ft_strrchr.c \
		src/ft_strncmp.c \
		src/ft_strcmp.c \
		src/ft_memchr.c \
		src/ft_memcmp.c \
		src/ft_strnstr.c \
		src/ft_atoi.c \
		src/ft_calloc.c \
		src/ft_strdup.c \
		src/ft_substr.c \
		src/ft_str_env_var.c\
		src/ft_char_env_var.c\
		src/ft_strjoin.c \
		src/ft_strtrim.c \
		src/ft_split.c \
		src/ft_itoa.c \
		src/ft_strmapi.c \
		src/ft_striteri.c \
		src/ft_putchar_fd.c \
		src/ft_putstr_fd.c \
		src/ft_putendl_fd.c \
		src/ft_putnbr_fd.c \
		src/ft_lstnew.c \
		src/ft_lstadd_front.c \
		src/ft_lstsize.c \
		src/ft_lstlast.c \
		src/ft_lstadd_back.c \
		src/ft_lstdelone.c \
		src/ft_lstclear.c \
		src/ft_lstiter.c \
		src/ft_lstmap.c \
		src/get_next_line.c \
		src/get_next_line_utils.c \
		src/ft_dbl_ptr_free.c \
		src/ft_dbl_ptr_len.c\
		src/ft_dbl_ptr_realloc.c\
		src/ft_dbl_ptr_copy.c\
		src/ft_atolong.c\
		src/ft_free_n_null.c\
		src/ft_is_str_digit.c

#------------------------------------------------------------------------------#
#									 RULES									   #
#------------------------------------------------------------------------------#

all:	$(NAME)

$(NAME): $(OBJS)
	@$(call archiving, $(AR) $@ $(OBJS))
	@echo "$(LGREEN)LIBFT completed !$(NC)"

$(OBJS) : $(D_OBJ)%.o : $(D_SRC)%.c $(HEADER)
	@mkdir -p $(D_OBJ)
	@$(call run_and_test, $(CC) $(CFLAGS) -c $< -o $@)

clean:
	@$(call cleaning, $(RM) $(D_OBJ));

fclean: clean
	@$(call fcleaning, $(RM) $(NAME))

re: fclean all

.PHONY: all clean fclean re

#=================== DONE BUT NOT ASKED FOR ==================#
# ft_strmap.c ft_strstr.c ft_strcat.c
# ft_strncat.c ft_strncpy.c
# ft_putchar.c ft_putnbr.c ft_putstr.c
#======================== NOT ASK FOR ========================#
# ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c
# ft_striter.c ft_strequ.c ft_strnequ.c ft_putendl.c
#=============================================================#

#------------------------------------------------------------------------------#
#								  MAKEUP RULES								   #
#------------------------------------------------------------------------------#

#----------------------------------- SOURCE -----------------------------------#

#----------------------------------- INTROS -----------------------------------#

#----------------------------------- COLORS -----------------------------------#
LRED = \033[91m
LGREEN = \033[92m
LYELLOW = \033[93
LMAGENTA = \033[95m
LCYAN = \033[96m
NC = \033[0;39m

#----------------------------------- TEXTES -----------------------------------#
OK_STRING = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING = "[WARNING]"
COMP_STRING = "Generating"
CLEAN_STRING = "Cleaning"
ARCH_STRING = "Archiving"

#----------------------------------- DEFINE -----------------------------------#
define run_and_test
printf "$(LRED)■$(NC)"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $(@F)" "💥$(NC)\n"; \
	elif [ -s $@.log ]; then \
			printf "%-60b%b" "$(LCYAN)$(COMP_STRING)$(LMAGENTA) $(@F)" "⚠️$(NC)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

define cleaning
printf "%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBFT Objects Files & Directories$(NC)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBFT Objects Files & Directories" "💥$(NC)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBFT Objects Files & Directories" "⚠️$(NC)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBFT Objects Files & Directories" "✅$(NC)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

define fcleaning
printf "%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBFT Executable Files$(NC)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBFT Executable Files" "💥$(NC)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBFT Executable Filess" "⚠️$(NC)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBFT Executable Files" "✅$(NC)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

define archiving
printf "%b" "\n$(LCYAN)$(ARCH_STRING)$(LMAGENTA) $(@F)$(NC)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(ARCH_STRING)$(LMAGENTA) $(@F)" "💥$(NC)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(ARCH_STRING)$(LMAGENTA) $(@F)" "⚠️$(NC)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(ARCH_STRING)$(LMAGENTA) $(@F)" "✅$(NC)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef
