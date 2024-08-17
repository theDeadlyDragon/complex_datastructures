#ifndef COMPLEX_DATASTRUCTURES_LIBRARY_H
#define COMPLEX_DATASTRUCTURES_LIBRARY_H

#include <iostream>
#include <utility>

namespace Datastructures {

    template <typename T>
    struct TreiInputItem {
        std::string key;
        T item;
    };

    template <typename T>
    struct TreiItem {
        std::string key ="";
        T item;
        bool itemFilled = false;
        TreiItem<T> **childs = nullptr;
        int childAmount = 0;

        TreiItem(char key)
        {
            this->key = key;
        }

        TreiItem(){}

        int addChild(TreiItem<T>* item){
            int index = this->checkIfEntryExists(item);

            if(childs == nullptr){
                index = 0;
                this->childs = new TreiItem<T>*[1]();
                this->childs[index] = new TreiItem<T>(item->key[0]);
                childAmount +=1;
            }
            else if(index == -1){
                auto newArray = new TreiItem<T>*[childAmount + 1];
                memcpy(newArray, childs, childAmount * sizeof(TreiItem<T>*));
                index = childAmount;
                newArray[index] = new TreiItem<T>(item->key[0]);
                childAmount +=1;

                delete childs;
                childs = newArray;
            }


            if(item->key.size() > 1){
                item->key = item->key.substr(1, item->key.size()-1);
                childs[index]->addChild(item);
            }
            else {
                childs[index]->item = item->item;
                childs[index]->itemFilled = true;
            }

        }

        void printKeys(std::string keyName){
            if(this->itemFilled == true )
                std::cout << keyName << this->key<< std::endl;

            if(childAmount > 0){
                keyName.append(this->key);
                for(int i =0; i< childAmount; i++){
                    childs[i]->printKeys(keyName);
                }

            }

        }

        int checkIfEntryExists(TreiItem<T>* item){
            if(this->childs == nullptr)
                return -1;

            for(int i = 0; i< childAmount; i++){
                if(childs[i]->key[0] == item->key[0])
                    return i;
            }
            return -1;
        }
        T getItem(std::string keyName) {
            if(this->itemFilled == true && keyName.empty())
                return this->item;

            if (this->childs == nullptr)
                return 0;

            for (int i = 0; i < childAmount; i++) {
                if (childs[i]->key[0] == keyName[0]) {
                    keyName = keyName.substr(1, keyName.size() - 1);
                    return childs[i]->getItem(keyName);
                }
            }
            return 0;
        }
    };


    template <typename T>
    class Trie {

    public:
        Trie(){}
        Trie(TreiInputItem<T> input[],int amount);

        void insert(TreiInputItem<T> input,int amount){

                auto child = new TreiItem<T>();
                child->key = input.key;
                child->item = input.item;

                head->addChild(child);
        }
//        void parseTrei(TreiInputItem<T> input[]);
        void printKeys();
        T findItem(std::string key);
    private:
       TreiItem<T> *head;

    };

    template <typename T>
    Trie<T>::Trie(TreiInputItem<T> input[],int amount) {
        head = new TreiItem<T>();

        for (int i =0; i< amount; i++ ) {
            insert(input[i], amount);
        }

        for(int i =0; i< head->childAmount; i++){
            std::cout << head->childs[i]->key << std::endl;
        }
    }

    template <typename T>
    void Trie<T>::printKeys()
    {
        std::cout << "print keys:" << std::endl;
        this->head->printKeys("");
    }

    template <typename T>
    T Trie<T>::findItem(std::string key) {
        return head->getItem(key);
    }
}


#endif //COMPLEX_DATASTRUCTURES_LIBRARY_H
