#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

struct CELL {   // Declare CELL bit field
    unsigned short character  : 8;  // 00000000 ????????
    unsigned short foreground : 3;  // 00000??? 00000000
    unsigned short intensity  : 1;  // 0000?000 00000000
    unsigned short background : 3;  // 0???0000 00000000
    unsigned short blink      : 1;  // ?0000000 00000000
} ;

int main(void){
    CELL orange;
    orange.character = 'g';
    orange.foreground = 6;
    orange.intensity = false;
    orange.background = 3;
    orange.blink = true; 
    
    // Вывод исходных значений
    cout << "Исходные значения структуры:" << endl;
    cout << "orange.character = "  <<  orange.character << endl;
    cout << "orange.foreground = " << orange.foreground << endl;
    cout << "orange.intensity = "  << orange.intensity  << endl;
    cout << "orange.background = " << orange.background << endl;
    cout << "orange.blink = "      << orange.blink      << endl; 
    
    CELL *pointer = (&orange);

    // Метод 1: Преобразование через reinterpret_cast
    cout << "\nМетод 1 - Преобразование через reinterpret_cast:" << endl;
    unsigned short rawValue = *reinterpret_cast<unsigned short*>(pointer);
    cout << "Hex значение: 0x" << std::hex << std::uppercase << rawValue << std::dec << endl;

    // Метод 2: Использование stringstream для точного форматирования
    cout << "\nМетод 2 - Преобразование через stringstream:" << endl;
    std::stringstream ss;
    ss << std::hex << std::setw(4) << std::setfill('0') << rawValue;
    std::string formattedHex = ss.str();
    cout << "Форматированное hex значение: 0x" << formattedHex << endl;

    // Метод 3: Побайтовое представление
    cout << "\nМетод 3 - Побайтовое hex представление:" << endl;
    unsigned char* bytes = reinterpret_cast<unsigned char*>(pointer);
    cout << "Байт 1 (мл.): 0x" << std::hex << static_cast<int>(bytes[0]) << endl;
    cout << "Байт 2 (ст.): 0x" << std::hex << static_cast<int>(bytes[1]) << std::dec << endl;

    return 0;
}