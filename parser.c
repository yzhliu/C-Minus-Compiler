#include <stdio.h>
#include <string.h>
#include "node.h"
#include "y.tab.h"
#include "hash.h"
#include "var.h"

int offset_local;
int offset_param;
/*int param_count;*/
int current_func;
int in_func_declaration;

int exeNode(Node *p, int signal) 
{
    HashNode *node, *s_or_a, *g_or_p;
    char binary_op_str[3];
    int label[2];

    int retvalue;
    int count;

	if (!p) return 0;

	switch(p->type) {
    case TYPE_CONTENT: 
        if (signal) {
            code_push_cons(p->content);
        }
        //printf("load %d\n", p->content);
        return 1;
    case TYPE_INDEX:   
        node = hash_lookup(var_local, HASHSIZE, p->index);
        if (node == NULL) {
            /* it should be the global var */
            if (signal) { /* as right operand */
                s_or_a = hash_lookup(var_global_SorA, HASHSIZE, p->index);
                if (s_or_a->data == SCALAR) {
                    code_push_global_var(p->index, 0);
                } else { /* array */
                    code_push_global_array(p->index);
                }
            } else { /* as left operand */
                code_lea_global(2, p->index, 0);
            }
            //printf("load(index) %d\n", p->index); 
        } else {  /* local */
            if (signal) { /* as right operand */ 
                s_or_a = hash_lookup(var_local_SorA, HASHSIZE, p->index);
                if (s_or_a->data == SCALAR) {
                    code_push_ind(node->data);
                } else { /* array */
                    /* store the addr of the array in eax and then push */
                    code_lea_local(1, node->data);
                    code_push_reg(1, 0); 
                }
            } else { /* as left operand */
                code_lea_local(2, node->data);
            }
        }
        return 1;
    case TYPE_OP:
		switch(p->op.name) {
        case GLOBAL_VAR:
            code_start_bss();
            count = exeNode(p->op.node[0], 1);
            return count;
        case VAR:
            if (signal) {/* global var declaration */
                if (p->op.num == 2) { /* not array */
                    code_declare_global_var(p->op.node[1]->index, 1);
                    s_or_a = hash_insert(var_global_SorA, HASHSIZE, 
                                            p->op.node[1]->index, SCALAR);
                } else if (p->op.num == 3) { /* array */
                    code_declare_global_var(p->op.node[1]->index, 
                                            p->op.node[2]->content);
                    s_or_a = hash_insert(var_global_SorA, HASHSIZE, 
                                            p->op.node[1]->index, ARRAY);
                }
            } else {
                if (p->op.num == 2) { /* not array */
                    /* FIXME:var_count thing, esp */
                    /*var_count = 0;*/
                    /*++var_count;*/
                    //printf("var:%d\n", var_count);
                    offset_local -= VAR_LENGTH;
                    code_sub_esp(VAR_LENGTH);
                    node = hash_insert(var_local, HASHSIZE, 
                                        p->op.node[1]->index, offset_local);
                    s_or_a = hash_insert(var_local_SorA, HASHSIZE, 
                                            p->op.node[1]->index, SCALAR);
                    g_or_p = hash_insert(var_local_GorP, HASHSIZE, 
                                            p->op.node[1]->index, GENERAL);
                } else if (p->op.num == 3) {
                    /* FIXME:var_count thing, esp */
                    /*var_count = 0;*/
                    /*var_count += VAR_LENGTH * p->op.node[2]->content;*/
                    offset_local -= VAR_LENGTH * p->op.node[2]->content;
                    code_sub_esp(VAR_LENGTH * p->op.node[2]->content);
                    node = hash_insert(var_local, HASHSIZE, 
                                        p->op.node[1]->index, offset_local);
                    s_or_a = hash_insert(var_local_SorA, HASHSIZE, 
                                            p->op.node[1]->index, ARRAY);
                    g_or_p = hash_insert(var_local_GorP, HASHSIZE, 
                                            p->op.node[1]->index, GENERAL);
                }
                //printf("VAR(index) %d(esp)\n", node->data);
            }
            return 0;
        case FUNC:
            retvalue = code_data_section();
            if (!retvalue) { /* start text section */
                code_start_text();
                current_func = ELFHash(FUNC_OUTPUT_NAME, strlen(FUNC_OUTPUT_NAME));
                code_start_func(current_func);
                code_func_output();
                code_end_func(current_func);
            }

            if (p->op.num == 1) { /* compound */
                in_func_declaration = 0;
                count = exeNode(p->op.node[0], 0);
                code_end_func(current_func);
            } else { /* declaration */
                hash_init(var_local, HASHSIZE);
                hash_init(var_local_SorA, HASHSIZE);
                hash_init(var_local_GorP, HASHSIZE);
                offset_local = 0;
                in_func_declaration = 1;
                /* in callee, [ebp] is the old ebp, [ebp+4] is the caller's addr
                 * so the param start at [ebp+8] */
                offset_param = VAR_LENGTH;
                /*param_count = 0;*/

                current_func = p->op.node[1]->index;
                code_start_func(p->op.node[1]->index);
                //printf("\nFUNC-D(index) %d\n", p->op.node[1]->index);
                /* the local variables */
                count = exeNode(p->op.node[2], 0);
                /*
                if (param_count > 0) 
                    code_sub_esp(VAR_LENGTH*param_count);
                    */
            }
            return count;
        case PARAM:
            /*++param_count;*/
            offset_param += VAR_LENGTH;
            node = hash_insert(var_local, HASHSIZE, p->op.node[1]->index, offset_param);
            g_or_p = hash_insert(var_local_GorP, HASHSIZE, p->op.node[1]->index, PARAMETER);
            if (p->op.num == 2) { /* no [ ] */
                s_or_a = hash_insert(var_local_SorA, HASHSIZE, p->op.node[1]->index, SCALAR);
                //printf("PARAM(index) %d(esp)\n", node->data);
            } else { /* [ ] pointer */
                s_or_a = hash_insert(var_local_SorA, HASHSIZE, p->op.node[1]->index, ARRAY);
                //printf("PARAM(index) %d[]\n", p->op.node[1]->index);
            }
            return 0;
		case '=':	
            /* 1 means need push when means need push */
            count = exeNode(p->op.node[1], 1); 
            //node = hash_lookup(var_local, HASHSIZE, p->op.node[0]->index);
            count += exeNode(p->op.node[0], 0);
            code_pop(1);
            code_op_assign(2, 1);

            if (signal) { /* as right operand */
                code_push_ind(p->op.node[0]->index);
            }
            /*
            if (p->op.node[0]->type == TYPE_INDEX) {
                printf("Assign last result to VAR(index) %d\n", p->op.node[0]->index);
            } else {  
                printf("Assign last result to VAR(index) %d[]\n", 
                    p->op.node[0]->op.node[0]->index);
            } */
            return count;
        case '<':
            strcpy(binary_op_str, "<");
            goto op_binary;
        case '>':
            strcpy(binary_op_str, ">");
            goto op_binary;
        case LE_OP:
            strcpy(binary_op_str, "<=");
            goto op_binary;
        case GE_OP:
            strcpy(binary_op_str, ">=");
            goto op_binary;
        case EQ_OP:
            strcpy(binary_op_str, "==");
            goto op_binary;
        case NE_OP:
            strcpy(binary_op_str, "!=");
            goto op_binary;
        case '+':
            strcpy(binary_op_str, "+");
            goto op_binary;
        case '-':
            strcpy(binary_op_str, "-");
            goto op_binary;
        case '*':
            strcpy(binary_op_str, "*");
            goto op_binary;
        case '/':
            strcpy(binary_op_str, "/");
op_binary:
            count = exeNode(p->op.node[0], 1);
            count += exeNode(p->op.node[1], 1);
            code_pop(2); code_pop(1);

            retvalue = code_op_binary(1, 2, binary_op_str);
            if (signal) 
                code_push_reg(retvalue, 0);

            //printf("< last two result\n");
            return count;
        case '[': /* array */
            count = exeNode(p->op.node[1], 1);
            /* pop the idx into eax */
            code_pop(1);

            /* get the array base offset */
            node = hash_lookup(var_local, HASHSIZE, p->op.node[0]->index);
            if (node == NULL) {
                /* global */
                retvalue = code_get_array_offset(0, 1, VAR_LENGTH, 1);
                if (signal) { /* use as right operand */
                    code_push_mem(p->op.node[0]->index, retvalue);
                } else { /* use as left oprand */
                    /* put the addr into ebx */
                    code_lea_global(2, p->op.node[0]->index, retvalue);
                } 
                //printf("load(index) %d\n", p->index); 
            } else { 
                g_or_p = hash_lookup(var_local_GorP, HASHSIZE, p->op.node[0]->index);
                if (g_or_p->data == GENERAL) {
                    retvalue = code_get_array_offset(node->data, 1, VAR_LENGTH, 0);
                } else if (g_or_p->data == PARAMETER) {
                    retvalue = code_get_array_offset(node->data, 1, VAR_LENGTH, -1);
                }
                if (signal) { /* use as left oprand */
                    code_push_reg(retvalue, 1);
                } else { /* use as right oprand */
                    code_move_reg(2, retvalue);
                }
            }
            //printf("load(index) %d + last\n", p->op.node[0]->index);
            return count;
        case CALL:
            /*printf("call params:\n");*/
            count = exeNode(p->op.node[1], 1);
            //printf("ready to fetch call name\n");
            code_call_func(p->op.node[0]->index);
            code_clean_stack(count*VAR_LENGTH);
            if (signal)
                code_push_reg(1, 0); /* function save the ret in eax */
            //printf("call last\n");
            return count;
        case '{':
		case ';':    
			count = exeNode(p->op.node[0], 0);
			return (exeNode(p->op.node[1], 0) + count); 
        case ',':
            if (in_func_declaration) {
                /* from right to left */
                count = exeNode(p->op.node[1], signal);
                return (exeNode(p->op.node[0], signal) + count); 
            } else {
                /* from left to right */
                count = exeNode(p->op.node[0], signal);
                return (exeNode(p->op.node[1], signal) + count); 
            }
		case WHILE: 
            //printf("start while\n");
            label[0] = creat_label();
            label[1] = creat_label();
            /* the main proc */
            code_jmp(label[0]);
            code_label(label[1]);
            count = exeNode(p->op.node[1], 0); 
            /* condition */
            code_label(label[0]);
            count += exeNode(p->op.node[0], 1); 
            code_pop(1);
            code_test_condition(1, 1, label[1]);
            //printf("end while\n");
			return count;
		case IF:     
            /*printf("start if\n");*/
            label[0] = creat_label();
            /* condition */
            exeNode(p->op.node[0], 1);
            code_pop(1);
            code_test_condition(1, 0, label[0]);
            //printf("test last\n");
            /* the main proc */
            count += exeNode(p->op.node[1], 0);
            if (p->op.num > 2) { /* else label */
                label[1] = creat_label();
                code_jmp(label[1]);
            }
            code_label(label[0]);
            /* else proc */
            if (p->op.num > 2) {
                count += exeNode(p->op.node[2], 0);
                code_label(label[1]);
            }
			return count;
        case RETURN:
            if (p->op.num > 0)
                count = exeNode(p->op.node[0], 1);
            code_pop(1); /* ret value */
            /* FIXME: there may be two "leave & ret" 
             * since it is also called when function ends */
            code_end_func(current_func);
            //printf("now return last value\n");
            return count;
		}
    }
   
    return 0;
}
