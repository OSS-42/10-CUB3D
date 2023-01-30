#------------------------------------------------------------------------------#
#								   GENERAL									   #
#------------------------------------------------------------------------------#
NAME = libart.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar rcs

#------------------------------------------------------------------------------#
#									SOURCES									   #
#------------------------------------------------------------------------------#
HEADER = includes/libart.h
D_SRC = src/
D_OBJ = obj/
OBJS = $(patsubst $(D_SRC)%.c,$(D_OBJ)%.o,$(SRCS))
SRCS = \
		src/art_colors.c \
		src/art_colors2.c \
		src/art_intro_mini.c \
		src/art_exit_mini.c

#------------------------------------------------------------------------------#
#									 RULES									   #
#------------------------------------------------------------------------------#
all:	$(NAME)

$(NAME): $(OBJS)
	@$(call archiving, $(AR) $@ $(OBJS))
	@echo "$(LGREEN)LIBART completed !$(NC)"

$(OBJS) : $(D_OBJ)%.o : $(D_SRC)%.c $(HEADER)
	@mkdir -p $(D_OBJ)
	@$(call run_and_test, $(CC) $(CFLAGS) -c $< -o $@)

intro_daftpunk:
	@printf "\n \
			${LGRAY}             ▄▄▄▄${DGRAY}▄▄▄▄▄\n \
			${LGRAY}         ▄███████${DGRAY}████████▄\n \
			${LGRAY}       ▄█████████${DGRAY}██████████▄\n \
			${LGRAY}     ▄███████████${DGRAY}████████████${LYELLOW}▄${NC}\n \
			${LGRAY}    █████████████${DGRAY}████████████${LYELLOW}██${NC}\n \
			${LGRAY}   ██████████████${DGRAY}████████████${LYELLOW}████${NC}\n \
			${LGRAY} ███             ${DGRAY}████████████${LYELLOW}████${NC}\n \
			${LGRAY} ███             ${DGRAY}████████████${LYELLOW}████${NC}\n \
			${LGRAY}   ██████████████${DGRAY}████████████${LYELLOW}██▀${NC}\n \
			${LGRAY}      ███████████${DGRAY}████████████${LYELLOW}██${NC}\n \
			${LGRAY}       ██████████${DGRAY}███████████${LYELLOW}██${NC}\n \
			${LGRAY}        ████     ${LYELLOW}████████████▀${NC}\n \
			${LGRAY}          ███████${LYELLOW}██████████▀${NC}\n \
			${LGRAY}             ▀▀▀▀${LYELLOW}▀▀▀▀▀▀▀${NC}\n \
			__________________________________\n \
			\n";

intro_deadpool:
	@printf " \n \
			${RED}             ▄▄▄▄▄▄▄\n \
			${RED}       ▄▄███████████████▄▄\n \
			${RED}     ▄██▀▀     ███     ▀▀██▄\n \
			${RED}   ▄██▀        ███        ▀██▄\n \
			${RED} ▄██▀          ███          ▀██▄\n \
			${RED}▄█▀            ███            ▀█▄\n \
			██  ${NC}▄█▄${RED}        ███        ${NC}▄█▄${RED}  ██\n \
		       ██  ${NC}▄████▄     ${RED} ███ ${NC}     ▄████▄${RED}  ██\n \
		       ██  ${NC}▀██████▄   ${RED} ███ ${NC}   ▄██████▀${RED}  ██\n \
			██   ${NC}▀▀█████▄  ${RED}███ ${NC} ▄█████▀▀${RED}   ██\n \
			${RED}▀█▄       ${NC} ▀▀▀ ${RED}███ ${NC}▀▀▀        ${RED}▄█▀\n \
			${RED} ▀██▄          ███          ▄██▀\n \
			${RED}   ▀██▄        ███        ▄██▀\n \
			${RED}     ▀██▄▄     ███     ▄▄██▀\n \
			${RED}       ▀▀███████████████▀▀\n \
			${RED}             ▀▀▀▀▀▀▀${NC}\n${NC} \
			${NC}_________________________________\n \
			\n"

bonus: all
	@printf " \n \
		    ${NC} ╔══  $(LCYAN)  ══  $(LRED) ╔   ╦ $(LYELLOW) ╦  ╦ $(LMAGENTA) ╔══╗ \n \
		    ${NC} ║  ║ $(LCYAN) ║  ║ $(LRED) ║\  ║ $(LYELLOW) ║  ║ $(LMAGENTA) ║   \n \
		    ${NC} ╠══  $(LCYAN) ║  ║ $(LRED) ║ \ ║ $(LYELLOW) ║  ║ $(LMAGENTA) ╚══╗\n \
		    ${NC} ║  ║ $(LCYAN) ║  ║ $(LRED) ║  \║ $(LYELLOW) ║  ║ $(LMAGENTA)    ║\n \
		    ${NC} ╚══  $(LCYAN)  ══  $(LRED) ╩   ╝ $(LYELLOW)  ══  $(LMAGENTA) ╚══╝\n \
		    ${NC}_______________________________\n \
		\n"

clean:
	@$(call cleaning, $(RM) $(D_OBJ));

fclean: clean
	@$(call fcleaning, $(RM) $(NAME))

re: fclean all

.PHONY: all clean fclean re

#------------------------------------------------------------------------------#
#								  MAKEUP RULES								   #
#------------------------------------------------------------------------------#

#----------------------------------- SOURCE -----------------------------------#

#----------------------------------- INTROS -----------------------------------#

#----------------------------------- COLORS -----------------------------------#
LRED= \033[91m
RED= \033[31m
LGREEN= \033[92m
YELLOW= \033[33m
LYELLOW= \033[93m
LMAGENTA= \033[95m
LCYAN= \033[96m
LGRAY= \033[37m
DGRAY= \033[90m
BLACK= \033[30m
NC= \033[0;39m

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
printf "%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBART Objects Files & Directories$(NC)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBART Objects Files & Directories" "💥$(NC)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBART Objects Files & Directories" "⚠️$(NC)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBART Objects Files & Directories" "✅$(NC)\n"; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

define fcleaning
printf "%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBART Executable Files$(NC)\r"; \
$(1) 2> $@.log; \
RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBART Executable Files" "💥$(NC)\n"; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBART Executable Filess" "⚠️$(NC)\n"; \
	else \
		printf "%-60b%b" "$(LCYAN)$(CLEAN_STRING)$(LMAGENTA) LIBART Executable Files" "✅$(NC)\n"; \
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


.PHONY: all