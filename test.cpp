#include "dynamic_array.h"
#include "rb_tree.h"
#include <random>
#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>
#include <filesystem>

void saveResults(const std::string& filename, const std::string& test_name, const std::vector<size_t>& sizes, const std::vector<long long>& times) {
    std::filesystem::create_directory("/Users/alexsiu/Documents/LR4/LR4/results");
    
    std::ofstream file("/Users/alexsiu/Documents/LR4/LR4/results/" + filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка: не удалось открыть файл /Users/alexsiu/Documents/LR4/LR4/results/" << filename << std::endl;
        return;
    }
    
    file << "Test,Size,Time_ns\n";
    for (size_t i = 0; i < sizes.size(); ++i) {
        file << test_name << "," << sizes[i] << "," << times[i] << "\n";
    }
    file.close();
}

DynamicArray<int> RandomData(size_t size, int min, int max) {
    DynamicArray<int> random_data(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    for (size_t i = 0; i < size; ++i) {
        random_data[i] = dis(gen);
    }
    return random_data;
}

void testInsert() {

    std::vector<size_t> sizes = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    std::vector<long long> times;

    try {
        Set<int> tree1;
        DynamicArray<int> data1 = RandomData(sizes[0], -100000000, 100000000);
        auto start_time1 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < data1.GetLenght(); ++i) {
            tree1.Insert(data1[i]);
        }
        auto end_time1 = std::chrono::high_resolution_clock::now();
        long long time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1).count();
        times.push_back(time1);

        Set<int> tree2;
        DynamicArray<int> data2 = RandomData(sizes[1],-100000000, 100000000);
        auto start_time2 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < data2.GetLenght(); ++i) {
            tree2.Insert(data2[i]);
        }
        auto end_time2 = std::chrono::high_resolution_clock::now();
        long long time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time2 - start_time2).count();
        times.push_back(time2);

        Set<int> tree3;
        DynamicArray<int> data3 = RandomData(sizes[2], -100000000, 100000000);
        auto start_time3 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < data3.GetLenght(); ++i) {
            tree3.Insert(data3[i]);
        }
        auto end_time3 = std::chrono::high_resolution_clock::now();
        long long time3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time3 - start_time3).count();
        times.push_back(time3);

        Set<int> tree4;
        DynamicArray<int> data4 = RandomData(sizes[3], -100000000, 100000000);
        auto start_time4 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < data4.GetLenght(); ++i) {
            tree4.Insert(data4[i]);
        }
        auto end_time4 = std::chrono::high_resolution_clock::now();
        long long time4 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time4 - start_time4).count();
        times.push_back(time4);

        Set<int> tree5;
        DynamicArray<int> data5 = RandomData(sizes[4], -100000000, 100000000);
        auto start_time5 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < data5.GetLenght(); ++i) {
            tree5.Insert(data5[i]);
        }
        auto end_time5 = std::chrono::high_resolution_clock::now();
        long long time5 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time5 - start_time5).count();
        times.push_back(time5);

        Set<int> tree6;
        DynamicArray<int> data6 = RandomData(sizes[5], -100000000, 100000000);
        auto start_time6 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < data6.GetLenght(); ++i) {
            tree6.Insert(data6[i]);
        }
        auto end_time6 = std::chrono::high_resolution_clock::now();
        long long time6 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time6 - start_time6).count();
        times.push_back(time6);

        Set<int> tree7;
        DynamicArray<int> data7 = RandomData(sizes[6], -100000000, 100000000);
        auto start_time7 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < data7.GetLenght(); ++i) {
            tree7.Insert(data7[i]);
        }
        auto end_time7 = std::chrono::high_resolution_clock::now();
        long long time7 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time7 - start_time7).count();
        times.push_back(time7);

        Set<int> tree8;
        DynamicArray<int> data8 = RandomData(sizes[7], -100000000, 100000000);
        auto start_time8 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < data8.GetLenght(); ++i) {
            tree8.Insert(data8[i]);
        }
        auto end_time8 = std::chrono::high_resolution_clock::now();
        long long time8 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time8 - start_time8).count();
        times.push_back(time8);

        Set<int> tree9;
        DynamicArray<int> data9 = RandomData(sizes[8], -100000000, 100000000);
        auto start_time9 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < data9.GetLenght(); ++i) {
            tree9.Insert(data9[i]);
        }
        auto end_time9 = std::chrono::high_resolution_clock::now();
        long long time9 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time9 - start_time9).count();
        times.push_back(time9);

        Set<int> tree10;
        DynamicArray<int> data10 = RandomData(sizes[9], -100000000, 100000000);
        auto start_time10 = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < data10.GetLenght(); ++i) {
            tree10.Insert(data10[i]);
        }
        auto end_time10 = std::chrono::high_resolution_clock::now();
        long long time10 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time10 - start_time10).count();
        times.push_back(time10);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка в testInsert: " << e.what() << std::endl;
    }
}

void testMap() {
    std::vector<size_t> sizes = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    std::vector<long long> times;
    auto map_func = [](int x) { return x + 2; };

    try {
        for (size_t size : sizes) {
            Set<int> tree;
            DynamicArray<int> data = RandomData(size, -100000000, 10000000);
            for (size_t i = 0; i < data.GetLenght(); ++i) {
                tree.Insert(data[i]);
            }
            auto start_time = std::chrono::high_resolution_clock::now();
            tree.Map(map_func);
            auto end_time = std::chrono::high_resolution_clock::now();
            long long time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
            times.push_back(time);
        }
        saveResults("map_results.csv", "Map", sizes, times);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка в testMap: " << e.what() << std::endl;
    }
}

// testWhere: единый предикат
void testWhere() {
    std::vector<size_t> sizes = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    std::vector<long long> times;
    auto where_func = [](int x) { return x % 2 == 0; }; // Фиксированный предикат

    try {
        for (size_t size : sizes) {
            Set<int> tree;
            DynamicArray<int> data = RandomData(size,  -100000000, 10000000);
            for (size_t i = 0; i < data.GetLenght(); ++i) {
                tree.Insert(data[i]);
            }
            auto start_time = std::chrono::high_resolution_clock::now();
            tree.Where(where_func);
            auto end_time = std::chrono::high_resolution_clock::now();
            long long time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
            times.push_back(time);
        }
        saveResults("where_results.csv", "Where", sizes, times);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка в testWhere: " << e.what() << std::endl;
    }
}

void testFind() {
    std::vector<size_t> sizes = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    std::vector<long long> times;

    try {
        for (size_t size : sizes) {
            Set<int> tree;
            DynamicArray<int> data = RandomData(size, -100000000, 10000000);
            for (size_t i = 0; i < data.GetLenght(); ++i) {
                tree.Insert(data[i]);
            }
            // Измерение времени поиска
            auto start_time = std::chrono::high_resolution_clock::now();
            for (size_t i = 0; i < data.GetLenght(); ++i) {
                if (tree.Find(data[i]) == tree.end()) {
                    std::cerr << "Элемент " << data[i] << " не найден в дереве для size=" << size << std::endl;
                }
            }
            auto end_time = std::chrono::high_resolution_clock::now();
            long long time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
            times.push_back(time); // Среднее время на один поиск
        }
        saveResults("find_results.csv", "Find", sizes, times);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка в testFind: " << e.what() << std::endl;
    }
}

void testIsSubTree() {
    std::vector<size_t> sizes = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    std::vector<long long> times;

    try {
        for (size_t size : sizes) {
            Set<int> tree;
            DynamicArray<int> data = RandomData(size, -1000000, 1000000);
            for (size_t i = 0; i < data.GetLenght(); ++i) {
                tree.Insert(data[i]);
            }
            if (data.GetLenght() == 0) continue;
            int key = data[0];
            Set<int> sub_tree = tree.GetSubTree(key);
            auto start_time = std::chrono::high_resolution_clock::now();
            bool result = tree.IsSubTree(sub_tree);
            auto end_time = std::chrono::high_resolution_clock::now();
            long long time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
            times.push_back(time);
            if (!result) {
                std::cerr << "Ошибка: поддерево не найдено (size=" << size << ")\n";
            }
        }
        saveResults("is_subtree_results.csv", "IsSubTree", sizes, times);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка в testIsSubTree: " << e.what() << std::endl;
    }
}

void testGetSubTree() {
    std::vector<size_t> sizes = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    std::vector<long long> times;

    try {
        for (size_t size : sizes) {
            Set<int> tree;
            DynamicArray<int> data = RandomData(size, -100000000, 10000000);
            for (size_t i = 0; i < data.GetLenght(); ++i) {
                tree.Insert(data[i]);
            }
            if (data.GetLenght() == 0) continue;
            int key = data[0];
            auto start_time = std::chrono::high_resolution_clock::now();
            Set<int> sub_tree = tree.GetSubTree(key);
            auto end_time = std::chrono::high_resolution_clock::now();
            long long time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
            times.push_back(time);
            // Проверка корректности: поддерево не должно быть пустым
            if (sub_tree.Size() == 0) {
                std::cerr << "Ошибка: поддерево пусто для size=" << size << std::endl;
            }
        }
        saveResults("get_subtree_results.csv", "GetSubTree", sizes, times);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка в testGetSubTree: " << e.what() << std::endl;
    }
}
void testReduce() {
    std::vector<size_t> sizes = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    std::vector<long long> times;
    auto reduce_func = [](int a, int b) { return a + b; }; // Функция суммирования

    try {
        for (size_t size : sizes) {
            Set<int> tree;
            DynamicArray<int> data = RandomData(size, -1000000, 1000000);
            for (size_t i = 0; i < data.GetLenght(); ++i) {
                tree.Insert(data[i]);
            }
            auto start_time = std::chrono::high_resolution_clock::now();
            int result = tree.Reduce(reduce_func, 0);
            auto end_time = std::chrono::high_resolution_clock::now();
            long long time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
            times.push_back(time);
        }
        saveResults("reduce_results.csv", "Reduce", sizes, times);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка в testReduce: " << e.what() << std::endl;
    }
}

void testGoForward() {
    std::vector<size_t> sizes = {100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000, 1000000};
    std::vector<long long> times;

    try {
        for (size_t size : sizes) {
            Set<int> tree;
            DynamicArray<int> data = RandomData(size, -100000000, 100000000);
            for (size_t i = 0; i < data.GetLenght(); ++i) {
                tree.Insert(data[i]);
            }
            auto start_time = std::chrono::high_resolution_clock::now();
            DynamicArray<int> result = tree.GoForward();
            auto end_time = std::chrono::high_resolution_clock::now();
            long long time = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
            times.push_back(time);
            if (result.GetLenght() != tree.Size()) {
                std::cerr << "Ошибка: Размер массива не совпадает с размером дерева для size=" << size << "\n";
            }
        }
        saveResults("go_forward_results.csv", "GoForward", sizes, times);
    } catch (const std::exception& e) {
        std::cerr << "Ошибка в testGoForward: " << e.what() << std::endl;
    }
}

