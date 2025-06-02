#include "stack.h"
#include <iostream>
#include <fstream>
#include <string>

void processFromFile(Stack& stack, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    int wagonType;
    while (file >> wagonType) {
        stack.push(wagonType);
    }
    file.close();
}

void processFromKeyboard(Stack& stack) {
    std::cout << "Enter wagon types (1 or 2), end with -1:" << std::endl;
    int wagonType;
    while (true) {
        std::cin >> wagonType;
        if (wagonType == -1) break;
        if (wagonType != 1 && wagonType != 2) {
            std::cerr << "Invalid wagon type! Use 1 or 2." << std::endl;
            continue;
        }
        stack.push(wagonType);
    }
}

void splitStack(Stack& stack, Stack& track1, Stack& track2) {
    while (!stack.isEmpty()) {
        int wagonType = stack.pop();
        if (wagonType == 1) {
            track1.push(wagonType);
        }
        else if (wagonType == 2) {
            track2.push(wagonType);
        }
    }
}

void printStack(const std::string& name, Stack& stack) {
    std::cout << name << ": ";
    Stack temp;
    while (!stack.isEmpty()) {
        int value = stack.pop();
        std::cout << value << " ";
        temp.push(value);
    }
    // Восстанавливаем исходный стек
    while (!temp.isEmpty()) {
        stack.push(temp.pop());
    }
    std::cout << std::endl;
}

int main() {
    Stack mainStack, track1, track2;
    int choice;

    std::cout << "Choose input method:\n1. From file\n2. From keyboard\n";
    std::cin >> choice;

    if (choice == 1) {
        std::string filename;
        std::cout << "Enter filename: ";
        std::cin >> filename;
        processFromFile(mainStack, filename);
    }
    else if (choice == 2) {
        processFromKeyboard(mainStack);
    }
    else {
        std::cerr << "Invalid choice!" << std::endl;
        return 1;
    }

    splitStack(mainStack, track1, track2);

    printStack("Track 1 (Type 1): ", track1);
    printStack("Track 2 (Type 2): ", track2);

    return 0;
}