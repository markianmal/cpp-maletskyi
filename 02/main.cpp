#include "geometry.h"
#include <iostream>
#include <limits>
#include <string>

#include <windows.h>

using namespace std;

void fixCin() {
    cin.clear();
    cin.ignore((numeric_limits<streamsize>::max)(), '\n');
    cout << "  [!] Помилка: введіть число. Спробуйте ще раз.\n";
}

double readCoord(const string& prompt) {
    double val;
    while (true) {
        cout << prompt;
        if (cin >> val) return val;
        fixCin();
    }
}

Point readPoint(const string& name) {
    cout << "Введіть координати для " << name << ":\n";
    double x = readCoord("  -> X: ");
    double y = readCoord("  -> Y: ");
    return {x, y}; 
}

void processPoints(const Triangle& t) {
    int count;
    while (true) {
        count = readCoord("\nСкільки точок хочете перевірити? ");
        if (count > 0) break;
        cout << "  [!] Кількість має бути більшою за 0.\n";
    }

    for (int i = 0; i < count; ++i) {
        cout << "\n";
        Point p = readPoint("Точки " + to_string(i + 1));
        
        string ruleVec = "", ruleHeron = ""; 
        int resVec = t.checkPointVector(p, ruleVec);
        int resHeron = t.checkPointHeron(p, ruleHeron);
        
        cout << "  --- Результати ---\n";
        
        cout << "  Векторний метод: ";
        if (resVec == 1) cout << "ВСЕРЕДИНІ\n";
        else if (resVec == 0) cout << "НА МЕЖІ\n";
        else cout << "ЗОВНІ\n";
        
        cout << "  Метод Герона:    ";
        if (resHeron == 1) cout << "ВСЕРЕДИНІ\n";
        else if (resHeron == 0) cout << "НА МЕЖІ\n";
        else cout << "ЗОВНІ\n";
        
        cout << "  ------------------\n";
    }
}

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    cout << "=== Програма перевірки точок ===\n\n";
    
    Point a = readPoint("Вершини A");
    Point b = readPoint("Вершини B");
    Point c = readPoint("Вершини C");
    
    Triangle t = {a, b, c}; 
    
    if (t.isDegenerate()) {
        cout << "\n[!] Увага: Трикутник вироджений (точки на одній прямій)!\n"; 
        cout << "Координати вершин виродженого трикутника:\n";
        t.showPoints(); 
    }

    processPoints(t);
    return 0;
}