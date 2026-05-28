#include<stdio.h>
#include<stdlib.h>
#include<string.h>
​
#define MAX 10
​
int stackEmptySlots[MAX];
int top = -1;
​
char parking[MAX][20]; // vehicle numbers
​
void push(int slot) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stackEmptySlots[++top] = slot;
}
​
int pop() {
    if (top == -1) {
        return -1;
    }
    return stackEmptySlots[top--];
}
​
void initialize() {
    for (int i = MAX - 1; i >= 0; i--) {
        push(i); // all slots initially free
        strcpy(parking[i], "EMPTY");
    }
}
​
void parkVehicle(char vehicleNumber[]) {
    int slot = pop();
​
    if (slot == -1) {
        printf("Parking Full!\n");
        return;
    }
​
    strcpy(parking[slot], vehicleNumber);
    printf("Vehicle parked at slot %d\n", slot);
}
​
void removeVehicle(int slot) {
    if (slot < 0 || slot >= MAX || strcmp(parking[slot], "EMPTY") == 0) {
        printf("Invalid slot or already empty!\n");
        return;
    }
​
    printf("Vehicle %s removed from slot %d\n", parking[slot], slot);
​
    strcpy(parking[slot], "EMPTY");
    push(slot); // mark slot as free
}
​
void displayParking() {
    printf("\n--- Parking Status ---\n");
    for (int i = 0; i < MAX; i++) {
        printf("Slot %d: %s\n", i, parking[i]);
    }
    printf("----------------------\n");
}
​
void printMenu() {
    printf("\n1. Park Vehicle\n");
    printf("2. Remove Vehicle\n");
    printf("3. Display Parking Status\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}
​
int main() {
    initialize();
    int choice;
    char vehicleNumber[20];
    int slot;
​
    while (1) {
        printMenu();
        scanf("%d", &choice);
​
        switch (choice) {
            case 1:
                printf("Enter vehicle number: ");
                scanf("%s", vehicleNumber);
                parkVehicle(vehicleNumber);
                break;
            case 2:
                printf("Enter slot number to remove vehicle: ");
                scanf("%d", &slot);
                removeVehicle(slot);
                break;
            case 3:
                displayParking();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
​
    return 0;
}
</string.h></stdlib.h></stdio.h>
