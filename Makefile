#----- Colors -----
BLACK	= "\033[1;30m"
RED		= "\033[1;31m"
GREEN	= "\033[1;32m"
YELLOW	= "\033[1;33m"
BLUE	= "\033[1;34m"
MAGENTA	= "\033[1;35m"
CYAN	= "\033[1;35m"
PURPLE	= "\033[1;36m"
WHITE	= "\033[1;37m"
RESET	= "\x1b[0m"
#==================

LIBRARY = libft/libft.a

NAME	= fractol
FLAGS	= -Wall -Wextra -Werror


#------ path -------
FILES_PATH		= ./files
FRACTOLS_PATH	= ./files/fractols
OBJECTS_PATH	= ./objects


#------ mlx --------
# MLX				= ./miniLibX/
# MLX_LIB			= $(addprefix $(MLX),mlx.a)
# MLX_INC			= -I ./miniLibX
# MLX_LNK			= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

MFLAGS = -L/usr/local/lib/ -I/usr/local/include -lm -lmlx -framework OpenGL -framework AppKit
HEADER = -I./
LIBMLX = /usr/local/lib/libmlx.a



#------ files ------
FILES_FILES		= main init control colors
FILES_FRACTOLS	= mandelbrot julia newton


#------ other ------
FILES_OBJ 		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(FILES_FILES)))
FRACTOLS_OBJ 	= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(FILES_FRACTOLS)))


#------ make ------
all: $(MLX_LIB) $(NAME)

$(NAME): $(FILES_OBJ) $(FRACTOLS_OBJ)
	@echo "\n"
	@make -C ./libft/
	@echo $(CYAN) "\tCompiling $@"$(RESET)

	@# @gcc $(FLAGS) $(MLX_LNK) -o $@ $^ $(LIBRARY)
	@gcc -o $(NAME) -o $@ $^ $(HEADER) $(MFLAGS) $(LIBRARY) $(LIBMLX)
	@echo $(GREEN) "\tfractol\t\t- has been made\n"$(RESET)

$(MLX_LIB):
	make -C $(MLX)

$(OBJECTS_PATH)/%.o: $(FILES_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(MLX_INC) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(FRACTOLS_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	gcc $(FLAGS) $(MLX_INC) -o $@ -c $<


#------ make clean ------
cleanlib:
	@make clean -C ./libft
	@# @make clean -C $(MLX)

clean: cleanlib
	@echo $(YELLOW)"\t\t\t\tFRACTOL"$(RESET)
	@rm -f $(FILES_OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)

#------ make fclean ------
fcleanlib:
	@make fclean -C ./libft
	@# @make clean -C $(MLX)

fclean: fcleanlib
	@echo $(YELLOW)"\t\t\t\tFRACTOL"$(RESET)
	@rm -f $(FILES_OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tfractol have been cleaned.\n"$(RESET)

#------ make re ------
re: fclean all


