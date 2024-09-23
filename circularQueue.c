queue[front].item;
for (int i = front; i < rear; i++) {
queue[i] = queue[i + 1];
}
rear--;
if (rear < front) {
front = -1;
rear = -1;
}
return item;
}
// Function to display the priority queue
void display() {
if (isEmpty()) {
printf("Queue is empty\n");
return;
}
printf("Priority Queue: \n");
for (int i = front; i <= rear; i++) {
printf("Item: %d, Priority: %d\n", queue[i].item,
queue[i].priority);
}
}
int main() {
int choice, item, priority;
while (1) {
printf("\nPriority Queue Operations:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");
printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter item: ");
scanf("%d", &item);
printf("Enter priority: ");
scanf("%d", &priority);
enqueue(item, priority);
break;
case 2:
item = dequeue();
if (item != -1) {
printf("Dequeued item: %d\n", item);
}
break;
case 3:
display();
break;
case 4:
exit(0);
default:
printf("Invalid choice\n");
}
}
return 0;
}
