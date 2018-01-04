#include <stdio.h>
#include <stdlib.h>

/* preprocessor constants */
#define N_ITEMS (100) /* arbitrary, for purposes of practice */

/* struct Stack */
typedef struct Stack {

	/* elements of a stack */
	int head; /* the current index of our stack accessible */
	int items[N_ITEMS]; /* all the items in our stack */
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

		printf("Printing stack:\n");

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
	int items[N_ITEMS]; /* the line */
} Queue;

/* our global Queue */
Queue queue = {.first = 0, .last = 0};

/* now the Queue operations... */

void enqueue(int value) {

	/* put our value in the Queue */
	queue.items[queue.last] = value;

	/* next spot in the Queue */
	queue.last++;
}

int dequeue() {

	/* grab the next item in the Queue */
	int dequeued = queue.items[queue.first];

	/* next! */
	queue.first++;

	/* if our first is back to our last, it's time to reset the queue */
	if(queue.first == queue.last) {

		queue.first = 0;
		queue.last = queue.first;
	}

	/* return the dequeued item */
	return dequeued;
}

void print_queue() {

	int i;

	if(queue.last > 0) {

		printf("Printing queue:\n");

		for(i = queue.first; i < queue.last; i++) {

			printf("Item %d: %d\n", i, queue.items[i]);
		}
	} else {

		printf("Queue empty.\n");
	}
}

/* abstracted procedure to re-enqueue until the desired
 * value is in front of the queue */
void requeue(int index) {

	/* adjust the queue so that the index specified is now first */

	/* !!! let the user know we're adjusting the queue !!! */
	printf("Requeue!\n");
	/* initial variables */
	int end = queue.first + index - 1; /* how many to end at */
	int i; /* iterator */

	/* shift the queue */
	for(i = queue.first; i <= end; i++) {

		enqueue(dequeue());
	}
}
/* function to interleave the stack with it's second half
 * may use one other Queue, created above
 * 
 */
void interleave() {

	/* initial variables */
	int i; /* iterator, used to store indices later */

	/* !!! test print the current stack !!! */
	print_stack();

	/* pop everything off into the queue */
	for(i = stack.head; i > 0; i--) {

		enqueue(pop());
	}

	/* !!! test that the above code worked !!! */
	print_stack();
	print_queue();

	/* now to grab the middle element */
	i = ((queue.last - queue.first) / 2);
	printf("requeues to middle index: %d\n", i);

	/* requeue call to fix our queue to have the middle item first */
	requeue(i);

	/* !!! print the stack and the queue for checking !!! */
	print_stack();
	print_queue();

	/* if the initial stack was an odd number of items,
	 * we want to now dequeue two items at a time to
	 * put back into the stack, requeue, and loop the
	 * last two instructions until there are no more
	 * elements
	 *
	 * otherwise, if the initial stack was an even number
	 * of items, we want to dequeue one item to push, 
	 * requeue, dequeue two items to push, and continue
	 * the last two instructions until there are no more
	 * elements
	 *
	 * both cases include the initial middle push
	 */
	printf("%d\n", queue.last - queue.first);

	/* IMPORTANT: this for loop handles the odd case */
	for(i = queue.last - queue.first; i > 0; i -= 2) {

		if(i == 1) {

			push(dequeue());
			return;
		}

		/* dequeue 2 elements */
		push(dequeue());
		push(dequeue());

		/* requeue */
		requeue(2);

		/* !!! print the stack and queue after every iteration */
		print_stack();
		print_queue();
	}
}

/* main driver function */
int main(int argc, char *argv[]) {

	/* !!! test Stack functionality !!! */

	/*
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
	*/

	/* !!! test Queue functionality !!! */

	/*
	printf("Testing enqueue\n");
	enqueue(10);
	enqueue(20);
	enqueue(30);
	enqueue(40);
	enqueue(69);
	print_queue();
	printf("Testing dequeue\n");
	x = dequeue();
	printf("Item dequeued: %d\n", x);
	print_queue();
	*/

	/* set up the stack for testing of interleaving */
	int i; /* iterator */
	for(i = 7; i > 0; i--) push(i); /* push 1-5 onto the stack */

	/* queue is empty, as it should be initially */

	/* interleaving call */
	interleave();

	/* print the finished product */
	printf("Final results:\n");
	print_stack();
	print_queue();

	return EXIT_SUCCESS;
}