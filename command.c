#include <stdio.h>
#include <string.h>
#include "command.h"

void output(const char *str)
{
    //printf("%s\n", str);
    fputs(str, block_fp);
    fputs("\n", block_fp);
}

int putblock_l()
{
    int no = 0; 
    no = creatblockno();
    sprintf(strbucket, "\n%d {", no);
    output(strbucket);

    return no;
}

void putblock_r()
{
    output("}");
}

void creatlabel(char *str)
{
    sprintf(str, "%s%d", LABEL, ++labelno);
}

int creatblockno()
{
    return ++code_block_no;
}

int generate_varname_on_stack(char *retname, const char *name)
{
    int offset;
    offset = lookup_var_offset(name);

    if (offset > 0) { /* not found */
        strcpy(retname, name);
        return 0;
    }

    sprintf(retname, "[%s%d]", EBP, offset);
    return 1;
}

int generate_varsize_on_stack(const char *name)
{
    int hash, index;

    hash = ELFHash(name, strlen(name));
    index = hash_loopup(variable_bucket_hash, HASHSIZE, hash);

    if (index < 0) /* not found */
        return 0;
    
    return variable_bucket_size[index];
}

void code_pop(int reg)
{
    switch (reg) {
    case 1:
        sprintf(strbucket, "%s\t%s", POP, EAX);
        break;
    case 2:
        sprintf(strbucket, "%s\t%s", POP, EBX);
        break;
    case 3:
        sprintf(strbucket, "%s\t%s", POP, ECX);
        break;
    case 4:
        sprintf(strbucket, "%s\t%s", POP, EDX);
        break;
    }
        
    output(strbucket);
}

void code_push(const char *name)
{
    int hash, index, size;
    char var[MAX_STR_LENGHT];

    hash = ELFHash(name, strlen(name));
    index = hash_loopup(variable_bucket_hash, HASHSIZE, hash);

    if (index < 0) {/* not found */
        sprintf(strbucket, "%s\t%s", PUSH, name);
    } else {
        generate_varname_on_stack(var, name);
        size = generate_varsize_on_stack(name);
        sprintf(strbucket, "%s\t%s %s", PUSH, var_type_str[size], var);
    }

    output(strbucket);
}

/* put the result in eax */
void code_op_add(const char *v1, const char *v2, char *op)
{
    char var1[MAX_STR_LENGHT];
    char var2[MAX_STR_LENGHT];

    int size1, size2;
    int found1, found2;
    int sar = 31;

    found1 = generate_varname_on_stack(var1, v1);
    found2 = generate_varname_on_stack(var2, v2);

    size1 = generate_varsize_on_stack(v1);
    size2 = generate_varsize_on_stack(v2);
        

    if (!found2) {
        code_pop(2); 
    } else {
        sprintf(strbucket, "%s\t%s %s, %s", MOV, var_type_str[size2], EBX, var2);
        output(strbucket);
    }

    if (!found1) {
        code_pop(1); 
    } else {
        sprintf(strbucket, "%s\t%s %s, %s", MOV, var_type_str[size1], EAX, var1);
        output(strbucket);
    }


    strcpy(var1, EAX);
    strcpy(var2, EDX);
    
    if (strcmp(op, "+") == 0) {
        sprintf(strbucket, "%s\t%s, [%s+%s]", LEA, EAX, EAX, EBX);

    } else if (strcmp(op, "-") == 0) {
        sprintf(strbucket, "%s\t%s, %s", SUB, EAX, EBX);

    } else if (strcmp(op, "*") == 0) {
        sprintf(strbucket, "%s\t%s, %s", IMUL, EAX, EBX);
    
    } else if (strcmp(op, "/") == 0) {
        sprintf(strbucket, "%s\t%s, %s", MOV, EDX, EAX);
        output(strbucket);
        sprintf(strbucket, "%s\t%s, %d", SAR, EDX, sar);
        output(strbucket);
        sprintf(strbucket, "%s\t%s", IDIV, EBX);

    } else { /* relop */
        sprintf(strbucket, "%s\t%s, %s", CMP, EAX, EBX);
        output(strbucket);

        if (strcmp(op, "==") == 0) {
            sprintf(strbucket, "%s\t%s", SETE, AL);

        } else if (strcmp(op, "!=") == 0) {
            sprintf(strbucket, "%s\t%s", SETNE, AL);

        } else if (strcmp(op, ">") == 0) {
            sprintf(strbucket, "%s\t%s", SETG, AL);

        } else if (strcmp(op, "<") == 0) {
            sprintf(strbucket, "%s\t%s", SETL, AL);

        } else if (strcmp(op, ">=") == 0) {
            sprintf(strbucket, "%s\t%s", SETGE, AL);

        } else if (strcmp(op, "<=") == 0) {
            sprintf(strbucket, "%s\t%s", SETLE, AL);
        }

        output(strbucket);
        sprintf(strbucket, "%s\t%s, %s", MOVZX, EAX, AL);
    }

    output(strbucket);

    code_push(EAX);
}

//void code_if(

/* put the result in eax */
void code_op_or(const char *v1, const char *v2)
{
    char l1[MAX_STR_LENGHT];
    char l2[MAX_STR_LENGHT];
    char l3[MAX_STR_LENGHT];

    char var1[MAX_STR_LENGHT];
    char var2[MAX_STR_LENGHT];

    int size1, size2;
    int found1, found2;

    found1 = generate_varname_on_stack(var1, v1);
    found2 = generate_varname_on_stack(var2, v2);

    size1 = generate_varsize_on_stack(v1);
    size2 = generate_varsize_on_stack(v2);

    if (!found1) {
       code_pop(2); 
       strcpy(var1, EBX);
    }
    if (!found2) {
       code_pop(4); 
       strcpy(var2, EDX);
    }
    
    creatlabel(l1);
    creatlabel(l2);
    creatlabel(l3);

    sprintf(strbucket, "%s\t%s %s, 0", CMP, var_type_str[size1], var1);
    output(strbucket);
    sprintf(strbucket, "%s %s", JNE, l1);
    output(strbucket);
    sprintf(strbucket, "%s\t%s %s, 0", CMP, var_type_str[size2], var2);
    output(strbucket);
    sprintf(strbucket, "%s %s", JE, l2);
    output(strbucket);
    sprintf(strbucket, "%s:", l1);
    output(strbucket);
    sprintf(strbucket, "%s\t%s, 1", MOV, EAX);
    output(strbucket);
    sprintf(strbucket, "%s %s", JMP, l3);
    output(strbucket);
    sprintf(strbucket, "%s:", l2);
    output(strbucket);
    sprintf(strbucket, "%s\t%s, 0", MOV, EAX);
    output(strbucket);
    sprintf(strbucket, "%s:", l3);
    output(strbucket);

    code_push(EAX);
}

void code_op_assign(const char *target, const char *source)
{
    char target_var[MAX_STR_LENGHT];
    char source_var[MAX_STR_LENGHT];
    int found, size;

    generate_varname_on_stack(target_var, target);
    found = generate_varname_on_stack(source_var, source);

    size = generate_varsize_on_stack(target);

    if (found) {
        sprintf(strbucket, "%s\t%s, %s", MOV, EAX, source_var);
        output(strbucket);
        strcpy(source_var, EAX);
    } else {
       code_pop(2); 
       strcpy(source_var, EBX);
    }

    sprintf(strbucket, "%s\t%s %s, %s", MOV, var_type_str[size], target_var, source_var);
    output(strbucket);

    code_push(target);
}


void code_start_func()
{
    sprintf(strbucket, "%s\t%s", PUSH, EBP);
    output(strbucket);
    sprintf(strbucket, "%s\t%s, %s", MOV, EBP, ESP);
    output(strbucket);
}

void code_end_func()
{
    code_output();
    sprintf(strbucket, "%s", LEAVE);
    output(strbucket);
}

void code_sub_esp(int size)
{
    sprintf(strbucket, "%s\t%s, %d", SUB, ESP, size);
    output(strbucket);
}

void code_start_all()
{
    sprintf(strbucket, "section .text\nglobal _start");
    output(strbucket);
    sprintf(strbucket, "_start:");
    output(strbucket);
}

void code_end_all()
{
    sprintf(strbucket, "mov eax,1\nmov ebx,0\nint 80h");
    output(strbucket);
}

void code_output()
{
    sprintf(strbucket, "\npush dword [ebp-12]\npop eax\nadd eax, 48\nmov [ebp-12], eax\n" \
                "MOV eax, 4\nMOV ebx, 1\n" \ 
                "lea ecx, [ebp-12]\nMOV edx, 1\nINT 80h\n");
    output(strbucket);
}

void generate_var_offset(char *type)
{
    int index;
    int size;

    size = 0;
    if (var_no_in_list <= 0 || last_v_hash_offset < 0) 
        return;

    for (; var_no_in_list>0; --var_no_in_list) {
        index = last_v_hash_offset - var_no_in_list + 1;
        variable_bucket_size[index] = 4;
        size += variable_bucket_size[index];
        if (index == 0) {
            variable_bucket_offset[index] = -4;
        } else {
            variable_bucket_offset[index] = 
                variable_bucket_offset[index-1] - variable_bucket_size[index-1];
        }
    }

    code_sub_esp(size);

}

void insert_variable_into_hash(char *var)
{
    int hash;
    hash = ELFHash(var, strlen(var));
    hash_insert(variable_bucket_hash, &last_v_hash_offset, hash);
}

int lookup_var_offset(const char *var)
{
    int index, hash;

    hash = ELFHash(var, strlen(var));
    index = hash_loopup(variable_bucket_hash, HASHSIZE, hash);

    if (index < 0)
        return 1;
    
    return variable_bucket_offset[index];
}

unsigned int ELFHash(const char* str, unsigned int len)
{  
    unsigned int hash = 0;  
    unsigned int x    = 0;  
    unsigned int i    = 0;  
    for(i = 0; i < len; str++, i++)  
    {  
        hash = (hash << 4) + (*str);  
        if((x = hash & 0xF0000000L) != 0)  
        {  
            hash ^= (x >> 24);  
        }  
        hash &= ~x;  
    }  
    return hash;
}

int hash_loopup(int *hashtable, int hashsize, int hash)
{
    int i;

    for (i = 0; i < hashsize; ++i) {
        if (hashtable[i] == hash)
            return i;
    }

    return -1;
}

void hash_init(int *hashtable, int hashsize)
{
    int i;

    last_v_hash_offset = -1;
    for (i = 0; i < hashsize; ++i)
        hashtable[i] = HASHEMPTY;
}

void hash_insert(int *hashtable, int *last, int hash)
{
    (*last)++;
    hashtable[*last] = hash;
}

void stack_comp_init()
{
    stack_tail = -1;
}

int pop_comp()
{
    if (stack_tail < 0)
        return  -1;

    return stack_comp[stack_tail--];
}

int push_comp(int value)
{
    if (stack_tail == STACKSIZE)
        return -1;

    stack_comp[++stack_tail] = value;

    return 0;
}

void addnext(yytree *source, yytree *node)
{
    yytree *tmp = source;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = node;
}

void addchild(yytree *parent, yytree *child)
{
    parent->child = child;
}
    
