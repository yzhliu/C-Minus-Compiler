#ifndef VAR_H
#define VAR_H

#define VAR_LENGTH 4
#define HASHSIZE 19

#define SCALAR 1
#define ARRAY 2
#define GENERAL 1
#define PARAMETER 2

#define FUNC_OUTPUT_NAME "output"
#define FUNC_INPUT_NAME "input"

HashNode *var_local[HASHSIZE];
HashNode *var_local_SorA[HASHSIZE];	/* whether it is scalar or array */
HashNode *var_local_GorP[HASHSIZE];	/* general local or param */
HashNode *var_global_SorA[HASHSIZE];	/* general local or param */

#endif
