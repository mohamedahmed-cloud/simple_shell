#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM    0
#define CMD_OR        1
#define CMD_AND        2
#define CMD_CHAIN    3

/* for numberConverting() */
#define CONVERT_LOWERCASE    1
#define CONVERT_UNSIGNED    2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE    ".simple_shell_history"
#define HIST_MAX    4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct passinfo - contains pseudo-ar
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline
 * @argv:an array of strings generated
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count t
 * @fname: the program filename
 * @env: linked list local co
 * @environ: custom modified co
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which tut
 * @histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;

	int (*func)(info_t *);
} builtin_table;


/* toem_shloop.c */
int shellLoop(info_t *info, char **argumentVector);

int findFunction(info_t *info);

void findCommand(info_t *info);

void forkCommand(info_t *information);

/* toem_parser.c */
int isCmd(info_t *info, char *full_path);

char *debugChar(char *, int, int);

char *pathFinder(info_t *info, char *full_path_str, char *command);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
void _ePut(char *);

int _ePutChar(char);

int printFd(char c, int fd);

int _printFd(char *str, int fd);

/* toem_string.c */
/* toem_vars.c */
int _strLen(char *);

int _strComp(char *, char *);

char *startsWith(const char *, const char *);

char *strConcat(char *, char *);

/* toem_string1.c */
/* toem_vars.c */
char *_strCopy(char *, char *);

char *_strdup(const char *);

void printStr(char *);

int _putcharacter(char);

/* toem_exits.c */
char *_strcpy(char *, char *, int);

char *_strCat(char *, char *, int);

char *searchStr(char *, char);

/* toem_tokenizer.c */
char **splitStr(char *, char *);

char **strtow2(const char *, char);

/* toem_realloc.c */
char *setMemory(char *, char, unsigned int);

void fS(char **);

void *myReallocate(void *, unsigned int, unsigned int);

/* toem_memory.c */
int freePtr(void **);

/* toem_atoi.c */
int inInteractive(info_t *Inf);

int isDelim(char, char *);

int _isalpha(int);

int _fsti(const char *);

/* toem_errors1.c */
int _errfsti(char *);

void printError(info_t *Inf, char *errorstr);

int printDecimal(int, int);

char *numberConverting(long int, int, int);

void removeComments(char *);

/* toem_builtin.c */
int myExit(info_t *Inf);

int _changeDirectory(info_t *Inf);

int myHelp(info_t *Inf);

/* toem_builtin1.c */
int myHistory(info_t *Inf);

int _myAlias(info_t *Inf);

/*toem_getline.c */
ssize_t getInput(info_t *Inf);

int _getLine(info_t *Inf, char **ptr, size_t *length);

void sigintHandler(int);

/* toem_getinfo.c */
/* toem_vars.c */
void clearInformation(info_t *Inf);

void setInformation(info_t *Inf, char **argumentv);

void freeInformation(info_t *Inf, int all);

/* toem_environ.c */
/* toem_vars.c */
char *_getEnvironment(info_t *Inf, const char *name);

int _printEnv(info_t *Inf);

int mySetEnv(info_t *Inf);

int myUnsetEnv(info_t *Inf);

int fillEnvList(info_t *Inf);

/* added*/
int setAlias(info_t *Inf, char *string);

int _myAlias(info_t *Inf);

int unsetAlias(info_t *Inf, char *string);

int printAlias(list_t *node);

ssize_t getInput(info_t *Inf);

ssize_t inputBuffer(info_t *Inf, char **buffer, size_t *len);

ssize_t readBuffer(info_t *Inf, char *buffer, size_t *i);

char **getEnvironment(info_t *Inf);

int unsetEnv(info_t *Inf, char *var);

int _mySetEnv(info_t *Inf, char *var, char *value);

/* toem_history.c */
char *getHistoryFile(info_t *info);

int writeHistory(info_t *Inf);

int readHistory(info_t *Inf);

int start_history_list(info_t *Inf, char *buf, int line_count);

int renumberHistory(info_t *Inf);

/* tom_lists.c */
/* tom_vars.c */
list_t *node_adding(list_t **head, const char *string, int number);

list_t *node_adding_end(list_t **head, const char *string, int number);

size_t printStringList(const list_t *head);

int deleteAtIndex(list_t **head, unsigned int index);

void freeList(list_t **head_ptr);

/* tom_lists1.c */
/* tom_vars.c */
size_t lengthOfList(const list_t *head);

char **listToStrings(list_t *headPointer);

size_t printList(const list_t *h);

list_t *getStartNode(list_t *nodePointer, char *prefixPointer, char ch);

ssize_t searchIndex(list_t *headPointer, list_t *nodePointer);

/* tom_vars.c *//* tom_vars.c */

int isChain(info_t *info, char *buffer, size_t *p);

void
chain_check(info_t *info, char *buffer, size_t *p, size_t i, size_t length);

int replaceAlias(info_t *info);

int replaceVariables(info_t *info);

int replaceString(char **, char *);
/*#define S_IFREG  0100000 */

#endif
