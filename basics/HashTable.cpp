#include "hashtable.h"
#include "texture.h"

HashTable::HashTable(int size) {
    init(size);
}

void* HashTable::find(std::string path) {
    uint32_t hash = hash_code(path);

    if (table->arr[hash] != nullptr) { // checks if the element is in the table
        return table->arr[hash]->asset;
    }

    return nullptr;
}

HashTable::~HashTable() {
    clean();
}

bool HashTable::insert(std::string path) {
    std::cout << "Inserting..." << std::endl;
    Texture* asset = new Texture();
    if (!asset->load_texture(path)) {  // loads the texture from the path
        SDL_Log("Error when loading texture\n");
        return false;
    }

    std::cout << "..." << std::endl;
    Table_Item* entry; // creates a new table entry
    entry = static_cast<Table_Item*>(malloc(sizeof(Table_Item))); // loads the new table entry into memory
    if (entry == nullptr) {
        SDL_Log("Error when allocating space for table entry\n");
        return false;
    }

    // populates entry
    entry->path = path.c_str();
    entry->asset = asset;

    uint32_t hash = hash_code(path); // calculates hash

    table->arr[hash] = entry;
    table->count += 1;
    std::cout << "Done!" << std::endl;
    return true;
}

void HashTable::remove(Table_Item* item) {

    // cleans up the texture
    Texture* T = static_cast<Texture*>(item->asset);
    Texture& t = *T; // dereferences the pointer to the texture
    t.clean();
    item->asset = nullptr;

    item->path = nullptr; // fress the path
    
    item = nullptr;
    free(item);
}

void HashTable::clean() {

    for (int i = 0; i < table->size; i++) { // frees all of the current table entries
        if (table->arr[i] != nullptr) {
            std::cout << "Removing index: " + i << std::endl;
            remove(table->arr[i]);
            table->arr[i] = nullptr;
        }
    }

    free(table);
}
