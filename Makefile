valgrind:
	clang -Wall -Werror -Wextra -g get_next_line.c get_next_line_utils.c
	valgrind --leak-check=full  --show-leak-kinds=all ./a.out

clang:
	clang -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c
	./a.out

bonus:
	clang -Wall -Werror -Wextra get_next_line_BONUS.c get_next_line_utils.c
	./a.out

sanitize:
	clang -Wall -Werror -Wextra -g -fsanitize=address get_next_line.c get_next_line_utils.c
	./a.out

push:
	git add .
	git commit -m "update"
	git push

bonus:
	clang -Wall -Werror -Wextra -g get_next_line_bonus.c get_next_line_utils_bonus.c
	valgrind --leak-check=full  --show-leak-kinds=all ./a.out