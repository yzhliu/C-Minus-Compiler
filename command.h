#ifndef COMMAND_H
#define COMMAND_H

#define LABEL "L"
#define CMP "cmp"
#define JNE "jne"
#define JE "je"
#define MOV "mov"
#define JMP "jmp"
#define PUSH "push"
#define POP "pop"
#define SUB "sub"
#define IMUL "imul"
#define IDIV "idiv"
#define LEA "lea"
#define LEAVE "leave"
#define SAR "sar"
#define CMP "cmp"
#define SETE "sete"
#define SETNE "setne"
#define SETG "setg"
#define SETL "setl"
#define SETGE "setge"
#define SETLE "setle"
#define MOVZX "movzx"

#define EAX "eax"
#define EBX "ebx"
#define ECX "ecx"
#define EDX "edx"
#define EBP "ebp"
#define ESP "esp"
#define AL "al"

#define MAX_STR_LENGHT 200

#define HASHSIZE 100
#define HASHEMPTY -1

#define STACKSIZE 100

#define MARK_NONE -1
#define MARK_FUNC 0
#define MARK_IF 1
#define MARK_ELSE 2
#define MARK_WHILE 3
#define MARK_VAR_DEC 4

typedef struct treenode
{
    char *text;
    int mark;
    struct treenode *next;
    struct treenode *child;
} yytree;

/* 定义树结点的权举类型 */
typedef enum { TYPE_CONTENT, TYPE_INDEX, TYPE_OP } NodeEnum;
/* 操作符 */
typedef struct {
    int name; /* 操作符名称 */
    int num; /* 操作元个数 */
    struct NodeTag * node[1]; /* 操作元地址 可扩展 */
} OpNode;

typedef struct NodeTag {
    NodeEnum type; /* 树结点类型 */
    /* Union 必须是最后一个成员 */
    union {
        int content; /* 内容 */
        int index; /* 索引 */
        OpNode op; /* 操作符对象 */
    };
} Node;
extern int Var[26];

FILE *block_fp;
int labelno;
int code_block_no;
char strbucket[MAX_STR_LENGHT];
//char var_type_str[5][5] = { "", "byte", "word", "", "dword" };
char var_type_str[5][5];

int variable_bucket_hash[HASHSIZE];
int variable_bucket_offset[HASHSIZE];
int variable_bucket_size[HASHSIZE];
int last_v_hash_offset;
int var_no_in_list;

int stack_comp[STACKSIZE];
int stack_tail;

void stack_comp_init();
int pop_comp();
int push_comp(int value);

void output(const char *str);
void creatlabel();
void generate_var_offset(char *type);
void insert_variable_into_hash(char *var);
int lookup_var_offset(const char *var);
int generate_varname_on_stack(char *retname, const char *name);
int generate_varsize_on_stack(const char *name);

void code_op_assign(const char *target, const char *source);
void code_op_or(const char *v1, const char *v2);
void code_start_func();
void code_end_func();
void code_start_all();
void code_end_all();
void code_output();

unsigned int ELFHash(const char* str, unsigned int len);
int hash_loopup(int *hashtable, int hashsize, int hash);
void hash_init(int *hashtable, int hashsize);
void hash_insert(int *hashtable, int *last, int hash);

void addnext(yytree *source, yytree *node);
void addchild(yytree *parent, yytree *child);

#endif
