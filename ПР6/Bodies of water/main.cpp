#include "Bay.h"

using namespace std;

int main(){
    Sea Red("Mediterranian", "Red Sea");
    cout << Red;

    point l(39.123, 124.2331);
    Bay WC("Pacific", "Yellow Sea", "West-Corean Bay", l, 50, 12000);
    cout << WC;
}
