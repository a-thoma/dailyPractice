#include <stdio.h>
#include <stdlib.h>

/* struct Stack */
typedef struct Stack {

	/* elements of a stack */
	int head; /* the current index of our stack accessible */
	int items[]; /* all the items in our stack */
} Stack;

/* our global stack */
Stack stack = {.head = 0}; /* initial values */

/* now the stack operations... */

/* push function */
void push(int value) {

	/* put an item in the stack */
	stack.items[stack.head] = value;

	/* open the next spot in the stack */
	stack.head++;
}

/* pop function */
int pop() {

	/* remove the top item */
	int popped = stack.items[stack.head - 1];

	/* decrement the head to indicate we removed something */
	stack.head--;

	/* return the item popped */
	return popped;
}

/* print the current stack */
void print_stack() {

	int i;

	if(stack.head > 0) {

		for(i = stack.head - 1; i >= 0; i--) {

			printf("Item %d: %d\n", i, stack.items[i]);
		}
	} else {

		printf("Stack is empty.\n");
	}
}

/* struct Queue */
typedef struct Queue {

	/* elements of a Queue */
	int first; /* next in line */
	int last;  /* last in line */
	int items[]; /* the line */
} Queue;

/* our global Queue */
Queue queue = {.first = 0, .last = 0};

/* now the Queue operations... */

void enqueue(int value) {


}

int dequeue() {

}

/* function to interleave the stack with it's second half
 * may use one other queue, created in this function
 * 
 */
void interleave() {

}

/* abstracted procedure to re-enqueue until the desired
 * value is in front of the queue */
void requeue() {

}

/* main driver function */
int main(int argc, char *argv[]) {

	/* test push and pop functionality */

	printf("Testing push\n");
	push(10);
	push(20);
	push(30);
	push(43);
	push(69);
	print_stack();
	printf("Testing pop\n");
	int x = pop();
	printf("Item popped: %d\n", x);
	print_stack();

	return EXIT_SUCCESS;
}