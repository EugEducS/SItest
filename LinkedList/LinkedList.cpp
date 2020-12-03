#include "LList.h"

int main()
{
    List* list = new List();
    list->Add("Will Rock (2003)");
    list->Add("TimeShift (2007)");
    list->Add("Inversion (2011)");
    list->Add("World War Z (2019)");
   
    std::cout << "PrintAllData...\n";
    list->PrintAllData();

    std::cout << "\nSerialize...\n";

    FILE* file = fopen("./test.json", "wb");
    list->Serialize(file);
    fclose(file);

    std::cout << "\nDeserialize...\n";
    file = fopen("./test.json", "rb");
    list->Deserialize(file);
    fclose(file);

    std::cout << "\nPrintAllData...\n";

    list->PrintAllData([](std::string data) {
        std::cout << data << "\n";
    });

    return 0;
}
