#include <iostream>
#include <string>
#include <functional>
#include "rb_tree.h"
#include "test.h"

class TreeUI {
public:
    void Start() {
        Set<int> tree;
        Set<int> temp_tree;
        bool running = true;

        while (running) {
            PrintMainMenu();
            int choice = GetNumberInput(1, 10);

            switch (choice) {
                case 1:  AddElement(tree); break;
                case 2:  FindElement(tree); break;
                case 3:  PrintSize(tree); break;
                case 4:  PrintAllElements(tree); break;
                case 5:  CheckSubtree(tree); break;
                case 6:  CreateSubtree(tree, temp_tree); break;
                case 7:  ProcessMap(tree); break;
                case 8:  ProcessWhere(tree); break;
                case 9:  ProcessReduce(tree); break;
                case 10: running = false; break;
            }
        }
    }

private:
    void PrintMainMenu() {
        std::cout << "\n=== Red-Black Tree Manager ===\n";
        std::cout << "1. Add element\n";
        std::cout << "2. Find element\n";
        std::cout << "3. Get tree size\n";
        std::cout << "4. List all elements\n";
        std::cout << "5. Check subtree existence\n";
        std::cout << "6. Create subtree\n";
        std::cout << "7. Apply Map function\n";
        std::cout << "8. Apply Where filter\n";
        std::cout << "9. Calculate Reduce\n";
        std::cout << "10. Exit\n";
        std::cout << "Select option: ";
    }

    int GetNumberInput(int min, int max) {
        int value;
        while (!(std::cin >> value) || value < min || value > max) {
            std::cin.clear();
            std::cin.ignore(1024, '\n');
            std::cout << "Invalid input. Enter number " << min << "-" << max << ": ";
        }
        std::cin.ignore();
        return value;
    }

    void AddElement(Set<int>& tree) {
        std::cout << "Enter integer value: ";
        int val = GetNumberInput(INT_MIN, INT_MAX);
        tree.Insert(val);
        std::cout << "Element " << val << " added\n";
    }

    void FindElement(const Set<int>& tree) {
        std::cout << "Enter value to find: ";
        int val = GetNumberInput(INT_MIN, INT_MAX);
        auto it = tree.Find(val);
        std::cout << (it != tree.end() ? "Element exists" : "Element not found") << "\n";
    }

    void PrintSize(const Set<int>& tree) {
        std::cout << "Tree contains " << tree.Size() << " elements\n";
    }

    void PrintAllElements(const Set<int>& tree) {
        std::cout << "Elements: ";
        for (const auto& elem : tree) std::cout << elem << " ";
        std::cout << "\n";
    }

    void CheckSubtree(const Set<int>& tree) {
        std::cout << "Enter root value of subtree: ";
        int val = GetNumberInput(INT_MIN, INT_MAX);
        Set<int> subtree = tree.GetSubTree(val);
        std::cout << (tree.IsSubTree(subtree) ? "Subtree exists" : "Subtree not found") << "\n";
    }

    void CreateSubtree(Set<int>& src, Set<int>& dest) {
        std::cout << "Enter subtree root value: ";
        int val = GetNumberInput(INT_MIN, INT_MAX);
        dest = src.GetSubTree(val);
        std::cout << "Subtree created with " << dest.Size() << " elements\n";
    }

    void ProcessMap(Set<int>& tree) {
        std::cout << "Enter multiplier: ";
        int mult = GetNumberInput(INT_MIN, INT_MAX);
        auto new_set = tree.Map([mult](int x) { return x * mult; });
        std::cout << "Mapped elements: ";
        for (const auto& elem : new_set) std::cout << elem << " ";
        std::cout << "\n";
    }

    void ProcessWhere(const Set<int>& tree) {
        auto new_set = tree.Where([](int x) { return x % 2 == 0; });
        std::cout << "Even elements: ";
        for (const auto& elem : new_set) std::cout << elem << " ";
        std::cout << "\n";
    }

    void ProcessReduce(const Set<int>& tree) {
        int sum = tree.Reduce([](int a, int b) { return a + b; }, 0);
        std::cout << "Sum of all elements: " << sum << "\n";
    }
};

int main() {
    testInsert();
    
    testMap();
    
    testFind();
    
    testWhere();
    
    testReduce();
    
    testGoForward();
    
    testIsSubTree();
    
    testGetSubTree();
    
    std::cout<<"Hello, World"<<std::endl;
    
    TreeUI interface;
    interface.Start();
    
    
    return 0;
}



