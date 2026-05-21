#ifndef _POST_FIX_EVAL_H_
#define _POST_FIX_EVAL_H_

#include "list_queue.h"
#include "linked_stack.h"
#include "ShuntingYard.h"

using namespace std;

class PostFixEval {
    public:
        PostFixEval();
        ~PostFixEval();
        double evaluatePostFix(ListQueue<char> postfix);
};

#endif