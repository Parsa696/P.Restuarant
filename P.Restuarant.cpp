#include <iostream>
#include <string>

using namespace std;

const double VAT_PERCENTAGE = 9.0; // درصد ارزش افزوده

struct Item {
    int code;
    string name;
    double price;
};

// تعریف منوی غذاها
Item foods[] = {
    {1, "پیتزا", 200000},
    {2, "پاستا", 150000},
    {3, "برگر", 100000}
};

// تعریف منوی نوشیدنی‌ها
Item drinks[] = {
    {1, "نوشابه", 30000},
    {2, "آبمیوه", 40000},
    {3, "چای", 20000}
};

// تعریف منوی پیش‌غذاها
Item appetizers[] = {
    {1, "سالاد", 50000},
    {2, "سوپ", 60000},
    {3, "نان سیر", 40000}
};

double calculateFinalPrice(double price) {
    return price + (price * VAT_PERCENTAGE / 100);
}

Item findItemByCode(Item items[], int size, int code) {
    for (int i = 0; i < size; i++) {
        if (items[i].code == code) {
            return items[i];
        }
    }
    return {0, "نامعلوم", 0.0}; // در صورتی که آیتم پیدا نشود
}

int main() {
    int foodCode, drinkCode, appetizerCode;

    cout << "کد غذا را وارد کنید: ";
    cin >> foodCode;
    cout << "کد نوشیدنی را وارد کنید: ";
    cin >> drinkCode;
    cout << "کد پیش‌غذا را وارد کنید: ";
    cin >> appetizerCode;

    Item selectedFood = findItemByCode(foods, sizeof(foods)/sizeof(foods[0]), foodCode);
    Item selectedDrink = findItemByCode(drinks, sizeof(drinks)/sizeof(drinks[0]), drinkCode);
    Item selectedAppetizer = findItemByCode(appetizers, sizeof(appetizers)/sizeof(appetizers[0]), appetizerCode);

    double totalPrice = selectedFood.price + selectedDrink.price + selectedAppetizer.price;
    double finalPrice = calculateFinalPrice(totalPrice);

    cout << "\nفاکتور نهایی:\n";
    cout << "غذا: " << selectedFood.name << " - قیمت: " << selectedFood.price << " تومان\n";
    cout << "نوشیدنی: " << selectedDrink.name << " - قیمت: " << selectedDrink.price << " تومان\n";
    cout << "پیش‌غذا: " << selectedAppetizer.name << " - قیمت: " << selectedAppetizer.price << " تومان\n";
    cout << "قیمت کل با ارزش افزوده: " << finalPrice << " تومان\n";

    return 0;
}
