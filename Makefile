_RED = \x1b[31;i;01m

CC =			cc

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf

DIR_HEADERS =	include/

DIR_SRCS =		./src/

DIR_OBJS =		./

LIBMLX =		./lib/libmlx.a -lX11 -lXext -lm

SAVE =			-fsanitize=address

SRC =			main.c \
				maths/vector.c \
				maths/vector_operations.c \
				maths/vector_operations2.c \
				maths/color.c \
				maths/vector_norme.c \
				objects/plane.c\
				objects/triangle.c\
				objects/sphere.c\
				objects/cylinder.c \
				raytracing/raytracing.c \
				raytracing/sphere_color.c \
				raytracing/plane_color.c \
				raytracing/triangle_color.c \
				raytracing/cylinder_color.c \
				raytracing/intersections.c \
				raytracing/lighting/lighting.c \
				utils/comparison.c  \
				utils/ft_atoi.c		\
				utils/get_next_line.c	\
				utils/get_next_line_utils.c	\
				parsing/parsing.c	\
				parsing/parsing_utils.c \
				parsing/parsing_scene.c \
				parsing/parsing_objects.c \
				error/error.c 
SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

COMPIL =		$(FLAGS)

OBJS =			$(SRCS:.c=.o)

NAME =			miniRT

all:			$(NAME)

$(NAME) :		$(OBJS)
			$(CC) $(COMPIL) -I $(DIR_HEADERS) $(OBJS) $(LIBMLX) -o $(NAME)

%.o: %.c
				@cc -I $(DIR_HEADERS) -c $< -o $@ $(LIBMLX)
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
