#include "menu.h"
#include "figure_factory.h"
#include "shape_manager.h"
#include <limits>
#include <algorithm>
#include <iomanip>
#include <iostream>


void Menu::displayMenu() const {
    cout << "\nМЕНЮ:\n"
         << "1. Добавить фигуру (круг / прямоугольник / треугольник)\n"
         << "2. Показать список фигур с параметрами\n"
         << "3. Показать список фигур с площадями\n"
         << "4. Показать сумму всех площадей\n"
         << "5. Отсортировать по возрастанию площади\n"
         << "6. Удалить фигуру по номеру\n"
         << "7. Удалить фигуры с площадью больше введённой\n"
         << "8. Выход\n"
         << "Ваш выбор: ";
}

void Menu::addCircle() {
    figures.push_back(FigureFactory::createCircle());
}

void Menu::addRectangle() {
    figures.push_back(FigureFactory::createRectangle());
}

void Menu::addTriangle() {
    figures.push_back(FigureFactory::createTriangle());
}

void Menu::initializeFigure() {
    figureMap = {
        {CIRCLE, [this]() { addCircle(); }},
        {RECTANGLE, [this]() { addRectangle(); }},
        {TRIANGLE, [this]() { addTriangle(); }}
    };

    int type;
    cout << "Выберите тип фигуры:\n"
         << "1. Круг\n"
         << "2. Прямоугольник\n"
         << "3. Треугольник\n"
         << "Ваш выбор: ";
    cin >> type;

    auto it = figureMap.find(type);
    if (it != figureMap.end()) {
        it->second();
    } else {
        cout << "Неверный тип фигуры.\n";
    }
}

void Menu::handleShowFullInfo() const {
    if (figures.empty()) {
        cout << "Коллекция пуста.\n";
        return;
    }

    for (size_t i = 0; i < figures.size(); ++i) {
        cout << i + 1 << ". " << figures[i]->getName()
        << " — " << figures[i]->getDescription() << "\n";
    }
}

void Menu::handleShowAreas() const {
    if (figures.empty()) {
        cout << "Коллекция пуста.\n";
        return;
    }

    for (size_t i = 0; i < figures.size(); ++i) {
        cout << i + 1 << ". " << figures[i]->getName()
        << " — Площадь: " << fixed << setprecision(2)
        << figures[i]->getArea() << "\n";
    }
}

void Menu::handleTotalArea() const {
    double totalArea = ShapeManager::calculateTotalArea(figures);
    cout << "Сумма площадей всех фигур: " << fixed << setprecision(2)
         << totalArea << "\n";
}

void Menu::handleSortByArea() {
    ShapeManager::sortByArea(figures);
    cout << "Фигуры отсортированы по возрастанию площади.\n";
}

void Menu::handleDeleteFigure() {
    if (figures.empty()) {
        cout << "Список пуст.\n";
        return;
    }

    int index;
    cout << "Введите номер фигуры для удаления: ";
    if (!(cin >> index)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода.\n";
        return;
    }

    if (ShapeManager::deleteByIndex(figures, index)) {
        cout << "Фигура удалена.\n";
    } else {
        cout << "Неверный номер.\n";
    }
}

void Menu::handleDeleteFiguresAboveThreshold() {
    double threshold;
    cout << "Введите значение площади: ";
    if (!(cin >> threshold)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода значения.\n";
        return;
    }

    int removed = ShapeManager::deleteFiguresAboveArea(figures, threshold);
    cout << "Удалено фигур: " << removed << "\n";
}

void Menu::initializeCommands() {
    commandMap = {
        {ADD_FIGURE, [this]() { initializeFigure(); }},
        {OUTPUT_INFO, [this]() { handleShowFullInfo(); }},
        {OUTPUT_AREAS, [this]() { handleShowAreas(); }},
        {PRINT_AREAS_SUM, [this]() { handleTotalArea(); }},
        {SORT_AREAS, [this]() { handleSortByArea(); }},
        {DELETE_BY_NUM, [this]() { handleDeleteFigure(); }},
        {DELETE_LARGER_AREAS, [this]() { handleDeleteFiguresAboveThreshold(); }},
        {EXIT, []() { cout << "Выход из программы.\n"; }}
    };
}

void Menu::run() {
    initializeCommands();
    bool running = true;

    while (running) {
        displayMenu();

        int choice;
        bool validInput = static_cast<bool>(cin >> choice);

        if (!validInput) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Некорректный ввод.\n";
        } else if (choice == EXIT) {
            running = false;
        } else {
            auto cmd = commandMap.find(choice);
            if (cmd != commandMap.end()) {
                cmd->second();
            } else {
                cout << "Некорректный выбор.\n";
            }
        }
    }
}
