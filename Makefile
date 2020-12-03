SRC =			main.c \
				key/handle_key.c \
				image/bmp.c \
				mlx/create_window.c \
				mlx/pixel_put.c \
				maths/vector_utils.c \
				maths/vector_operations.c \
				maths/vector_product.c \
				maths/vector_norme.c \
				maths/color.c \
				maths/matrix.c \
				maths/ray.c \
				objects/camera.c \
				raytracing/trace_ray.c \
				raytracing/display.c \
				raytracing/lighting/lighting.c \
				raytracing/intersections/ray_sphere.c \
				raytracing/intersections/ray_triangle.c \
				raytracing/intersections/ray_square.c \
				raytracing/intersections/ray_cylinder.c \
				raytracing/intersections/ray_plane.c \
				utils/comparison.c  \
				utils/ft_calloc.c		\
				utils/ft_strcmp.c		\
				utils/get_next_line.c	\
				utils/get_next_line_utils.c	\
				free/free_scene.c		\
				free/exit_rt.c		\
				parsing/parsing.c	\
				parsing/parsing_args.c	\
				parsing/parsing_utils.c \
				parsing/is_functions.c \
				parsing/parsing_scene.c \
				parsing/parsing_objects.c \
				parsing/parsing_elem.c \
				error/error.c \
				error/error_utils.c	
NAME =			miniRT

CC =			clang
	
FLAGS =			-Wall -Werror -Wextra			

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

OBJS =			$(SRCS:.c=.o)

RM =			rm -rf

HEADERS =	-I $(DIR_HEADERS)	\
			-I $(DIR_LIBFT)/include	\

DIR_HEADERS = 		./include/

DIR_SRCS =		./src/

DIR_LIBFT =	./libs/libft
	

LIBS = 			-L /usr/local/lib -lXext -lX11 -lm -lbsd -lmlx \
				-L$(DIR_LIBFT) -lft	\

all:			$(NAME)

$(NAME) :		$(OBJS)
			@echo "Compiling Libft..."
			make -C $(DIR_LIBFT)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBS)

%.o: %.c
				@$(CC) $(FLAGS) $(HEADERS) -c $< -o $@
				@echo "Compiled "$<" successfully!"

bonus:

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
			make clean -C $(DIR_LIBFT)
			$(RM) $(OBJS)

fclean:			clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:			all, clean, fclean, re, bonus
