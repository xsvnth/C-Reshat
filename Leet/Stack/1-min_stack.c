🧠 Key idea (important)

A normal stack only remembers values.

But here we also need:

getMin() in O(1) time

So the trick is:

👉 Every time we push a value, we also store:

the value itself
the minimum value up to that point

So each stack element becomes a pair of integers.

🧱 What we store in C

We’ll use a struct like this:

typedef struct {
    int val;
    int currentMin;
} Node;

Each node knows:

its own value
the minimum value at the moment it was pushed
📦 Stack structure

We also need a stack:

#define MAX 10000

typedef struct {
    Node arr[MAX];
    int top;
} MinStack;
⚙️ Operations
1. Create stack
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->top = -1;
    return obj;
}
2. Push
void push(MinStack* obj, int val) {
    obj->top++;

    obj->arr[obj->top].val = val;

    if (obj->top == 0) {
        obj->arr[obj->top].currentMin = val;
    } else {
        int prevMin = obj->arr[obj->top - 1].currentMin;
        obj->arr[obj->top].currentMin = (val < prevMin) ? val : prevMin;
    }
}
3. Pop
void pop(MinStack* obj) {
    obj->top--;
}
4. Top
int top(MinStack* obj) {
    return obj->arr[obj->top].val;
}
5. Get Min
int getMin(MinStack* obj) {
    return obj->arr[obj->top].currentMin;
}
6. Free stack
void minStackFree(MinStack* obj) {
    free(obj);
}
💡 Why this works

At each step, we “remember the history of minimums”.

Example:

Push: 3 → 5 → 2 → 4

Stack becomes:

Value	Current Min
3	3
5	3
2	2
4	2

So getMin() is always just:

👉 top element’s currentMin

🚀 Even simpler mental model

Think of it like:

“Every element carries its own memory of the smallest value seen so far.”
======================================================================
🔧 What you are required to design

We need to create a class called MinStack that behaves like a stack but supports 4 operations, all in O(1) time:

1. push(val)

Put a value on top of the stack.

2. pop()

Remove the top element.

3. top()

Return the top element (like peek).

4. getMin()

Return the smallest element currently in the stack.

⚠️ The real challenge

A normal stack can easily do push/pop/top in O(1), BUT:

👉 The tricky part is:

How do you always know the minimum element in O(1), even after pops?

Because if you just scan the stack every time → that becomes O(n) ❌ (too slow).

💡 What they want you to think

We need to store extra information while pushing, so you don’t need to recompute the minimum later.

There are 2 common approaches:

✅ Approach 1 (most common): Two stacks
stack → stores all values
minStack → stores current minimums
Idea:

When We push a value:

push it to normal stack
also push it to minStack only if it’s <= current min

When We pop:

if popped value equals minStack top → pop minStack too

So minStack.top() is always the current minimum.

🧠 Why this works

Because We are basically tracking:

“what was the minimum at each stage of the stack”

✅ Approach 2 (clever trick): store pairs

Each stack element stores:

(value, current_min_at_that_time)

So every element “remembers” the minimum below it.

📌 In one sentence

👉 You are asked to design a stack that can always tell the minimum element instantly, without scanning the whole stack, using smart extra storage.
