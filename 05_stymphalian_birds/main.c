#include <ctype.h>
#include <fcntl.h>
#include <pwd.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

struct proj {
	char *name;
	char *type;
	bool libft;
};

const char *mkfile_fmt = ""
	"CFLAGS=-Werror -Wextra -Wall -g -Ilibft/\n"
	"LIBFLAGS=-L libft/ -lft\n"
	"NAME=%s\n"
	"SRC=$(wildcard src/*)\n"
	"OBJ=$(SRC:src/%%.c=%%.o)\n"
	"SHELL := /bin/bash\n"
	"\n"
	".PHONY: clean fclean all re norm norme debug test norman\n"
	"\n"
	"VPATH = src obj libft/includes include\n"
	"\n"
	"$(NAME): update $(OBJ)\n"
	"	@make -C libft\n"
	"	@$(CC) -o $(NAME) obj/* $(LIBFLAGS)\n"
	"\n"
	"all: $(NAME)\n"
	"\n"
	"%%.o: %%.c\n"
	"	@mkdir -p obj\n"
	"	@$(CC) $(CFLAGS) -o obj/$@ -c $<\n"
	"\n"
	"clean:\n"
	"	@make -C libft/ clean\n"
	"	@rm -rf obj/\n"
	"\n"
	"fclean: clean\n"
	"	@make -C libft/ fclean\n"
	"	@rm -f $(NAME)\n"
	"\n"
	"re: fclean all\n"
	"\n"
	"norm:\n"
	"	norminette src/. includes/.\n"
	"\n"
	"update:\n"
	"	@./update.sh\n"
	"\n"
	"norme: norm\n"
	"\n"
	"norman:\n"
	"	-norminette * | grep -iv warning\n";

void
usage(void)
{
	puts("usage: ./new_project [-t type] [-l libft] project_name");
	exit(1);
}

void
help(void)
{
	puts("usage: ./new_project [-t type] [-l libft] project_name");
	puts("\t-t: create different type of project (only c is supported)");
	puts("\t-l: don't clone libft into project");
	exit(0);
}

void
handle_args(struct proj *p, int argc, char *argv[])
{
	int ch, i;
	while ((ch = getopt(argc, argv, "hlt:")) != -1) {
		switch (ch) {
		case 'h':
			help();
			break;
		case 'l':
			p->libft = false;
			break;
		case 't':
			p->type = strdup(optarg);
			for (i = 0; p->type[i]; i++)
				p->type[i] = tolower(p->type[i]);
			break;
		default:
			usage();
		}
	}
}

void
mk_proj_dir(char *dirname)
{
	int err;

	err = mkdir(dirname, 0755);
	if (err < 0) {
		perror("could not create project directory");
		exit(1);
	}
}

void
git_init(void)
{
	int err = system("git init");

	if (err != 0) {
		perror("could not initialize git repository");
		exit(1);
	}
}

void
creat_mkfile(char *name)
{
	int bytes;
	FILE *fp;

	fp = fopen("makefile", "w");
	if (fp == NULL) {
		perror("could not open makefile");
	}
	bytes = fprintf(fp, mkfile_fmt, name);
	if (bytes < 0) {
		perror("could not write to makefile");
		exit(1);
	}
	fclose(fp);
}

void
clone_libft(void)
{
	int err;

	err = system("git clone https://github.com/arwn/libft");
	if (err != 0) {
		perror("could not libft");
		exit(1);
	}
}

void
mk_src(void)
{
	int err;

	err = mkdir("src", 0755);
	if (err < 0) {
		perror("could not create src/");
	}
	creat("src/main.c", 0744);
}

void
populate_proj_dir(struct proj p)
{
	git_init();
	creat_mkfile(p.name);
	if (p.libft) {
		clone_libft();
	}
	mk_src();
}

int
main(int argc, char *argv[])
{
	struct proj p;
	p.type = 0;
	p.name = 0;
	p.libft = true;
	
	handle_args(&p, argc, argv);
	argc -= optind;
	argv += optind;
	if (argc != 1) {
		usage();
	}
	p.name = strdup(argv[0]);

	mk_proj_dir(p.name);
	int err = chdir(p.name);
	if (err < 0) {
		perror("could not create project directory");
		exit(1);
	}

	populate_proj_dir(p);
	puts("done");

	return (0);
}
