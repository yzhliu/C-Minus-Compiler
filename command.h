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
#define ADD "add"
#define SUB "sub"
#define IMUL "imul"
#define IDIV "idiv"
#define LEA "lea"
#define LEAVE "leave"
#define RET "ret"
#define SAR "sar"
#define CMP "cmp"
#define SETE "sete"
#define SETNE "setne"
#define SETG "setg"
#define SETL "setl"
#define SETGE "setge"
#define SETLE "setle"
#define MOVZX "movzx"
#define CALLF "call"

#define EAX "eax"
#define EBX "ebx"
#define ECX "ecx"
#define EDX "edx"
#define EBP "ebp"
#define ESP "esp"
#define AL "al"

#define VARSIZE "dword"
#define GLOBAL_VAR_LENGTH 2
#define GLOBAL_VAR_DEFINE "resw"
#define VARSTR_LENGTH 20	/* for [ebp-4] ... */
#define REGSTR_LENGTH 4

#define MAX_STR_LENGTH 300

#define FUNC_PRE "F_"
#define GDATA_PRE "D_"

char strbucket[MAX_STR_LENGTH];

void output(const char *str);
static int func_is_main(int funcname);
static void getvarstr(char *varstr, int offset);
static int getregstr(char *regstr, int reg);
int creat_label();
void code_label(int labelno);
void code_jmp(int labelno);
void code_pop(int reg);
void code_lea_global(int target, int addr, int offset);
void code_lea_local(int target, int var);
void code_move_reg(int target, int source);
void code_push_mem(int addr, int offset);
void code_push_reg(int reg, int mem);
void code_push_ind(int idx);
void code_push_cons(int constant);
void code_push_global_var(int var, int offset);
void code_push_global_array(int var);
void code_call_func(int funcname);
void code_start_bss();
void code_start_text();
void code_declare_global_var(int varname, int size);
void code_start_func(int funcname);
void code_clean_stack(int height);
void code_end_func(int funcname);
void code_sub_esp(int size);
void code_test_condition(int reg, int test, int labelno);
void code_op_assign(int target, int source);
int code_get_array_offset(int baseoff, int idxreg, int varlength, int global);
int code_op_binary(int v1, int v2, char *op);

int code_data_section();
void code_func_output();
void code_func_input();
static void code_end_main();

#endif
