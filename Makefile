_RED = \x1b[31;i;01m

INC=/usr/include

INCLIB=$(INC)/../lib

CC =			clang

FLAGS =		

RM =			rm -rf

DIR_HEADERS =	include/

DIR_SRCS =		./src/

DIR_OBJS =		./

LIBMLX =		-L /usr/lib -lm -lbsd -lX11 -lXext

SAVE =			-fsanitize=address

SRC =			main.c \
				image/bmp.c \
				image/image.c \
				maths/vector.c \
				maths/vector_operations.c \
				maths/vector_operations2.c \
				maths/color.c \
				maths/vector_norme.c \
				maths/matrix.c \
				maths/ray.c \
				objects/plane.c\
				objects/triangle.c\
				objects/sphere.c\
				objects/cylinder.c \
				objects/square.c \
				objects/light.c \
				objects/camera.c \
				raytracing/raytracing.c \
				raytracing/sphere_color.c \
				raytracing/plane_color.c \
				raytracing/triangle_color.c \
				raytracing/cylinder_color.c \
				raytracing/square_color.c \
				raytracing/intersections.c \
				raytracing/lighting/lighting.c \
				utils/comparison.c  \
				utils/ft_atoi.c		\
				utils/ft_calloc.c		\
				utils/get_next_line.c	\
				utils/get_next_line_utils.c	\
				parsing/parsing.c	\
				parsing/parsing_args.c	\
				parsing/parsing_utils.c \
				parsing/parsing_utils2.c \
				parsing/parsing_scene.c \
				parsing/parsing_objects.c \
				error/error.c \
				error/error_utils.c	
SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

OBJS =			$(SRCS:.c=.o)

NAME =			miniRT

all:			$(NAME)

$(NAME) :		$(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L.. -lmlx -L$(INCLIB) -lXext -lX11 -lm -lbsd

%.o: %.c
				@cc $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@ $(LIBS)
				@echo "Compiled "$<" successfully!"

bonus:

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus
