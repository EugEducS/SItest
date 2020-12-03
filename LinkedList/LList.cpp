#include "LList.h"

List::List() {
	this->head = NULL;
	this->tail = NULL;
	this->count = 0;
}

void List::Add(std::string data) {
    ListNode* node = new ListNode;
    node->data = data;
    if (this->head != NULL) {
        node->prev = this->tail;
        node->rand = this->tail->prev;
        this->tail->next = node;
    } else {
        this->head = node;
    }
    this->tail = node;
    this->count++;
}

void List::PrintAllData() {
    ListNode* node = this->head;
    while (node != NULL) {
        std::cout << node->data << std::endl;
        node = node->next;
    }
}

void List::PrintRandom() {
    ListNode* node = this->head;
    while (node != NULL) {
        if (node->rand != NULL) {
            std::cout << "Random data: " << node->rand->data << "\n";
        } else {
            std::cout << "Random is NULL\n";
        }
        node = node->next;
    }
}

void List::PrintAllData(void (*f) (std::string)) {
    ListNode* node = this->head;
    while (node != NULL) {
        f(node->data);
        node = node->next;
    }
}

void List::Serialize(FILE* file) {
    nlohmann::json json;
    std::vector<std::string> listData;
    ListNode* node = this->head;
    while (node != NULL) {
        listData.push_back(node->data);
        node = node->next;
    }
    json["data"] = listData;
    std::string jsonStr = json.dump();
    fprintf(file, jsonStr.c_str());
}

void List::Deserialize(FILE* file) {
    nlohmann::json json;
    fseek(file, 0, SEEK_END);
    size_t len = ftell(file);
    rewind(file);
    char* buffer = new char[len];
    fread(buffer, 1, len, file);
    std::string jsonStr(buffer, len);
    delete[] buffer;
    json = nlohmann::json::parse(jsonStr);
    for (std::string str : json["data"]) {
        this->Add(str);
    }
}