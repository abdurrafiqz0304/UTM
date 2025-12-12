// Initialize Stack and Output
create(S);              // S is the operator stack
push(S, '#');           // Push a bottom-of-stack marker

// --- Main Loop: Process Infix Expression ---
while (not end of infix input) {
    ch = getch();       // Get the next input character

    if (ch is an OPERAND) {
        // Operands are output immediately
        add ch to POSTFIX_OUTPUT;

    } else if (ch is '(') {
        // Left parenthesis has high priority and is pushed
        push(S, ch);

    } else if (ch is ')') {
        // Pop and output operators until '(' is found
        pop_ch = pop(S);
        while (pop_ch != '(') {
            add pop_ch to POSTFIX_OUTPUT;
            pop_ch = pop(S);
        }

    } else if (ch is an OPERATOR) { // e.g., +, -, *, /
        // Pop and output operators with higher or equal precedence
        while (stacktop(S) != '#' && stacktop(S) != '(' && (precedence(stacktop(S)) >= precedence(ch))) {
            pop_ch = pop(S);
            add pop_ch to POSTFIX_OUTPUT;
        }
        // Push the current operator
        push(S, ch);
    }
}

// --- Cleanup: Pop Remaining Operators ---
// After the input ends, pop all remaining operators from the stack
while (stacktop(S) != '#') {
    pop_ch = pop(S);
    add pop_ch to POSTFIX_OUTPUT;
}

// Result is stored in POSTFIX_OUTPUT