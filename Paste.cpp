#include "Paste.h"
void Paste::paste(const std::set<fs::path>& BufferList) {
    for (const auto& el : BufferList) {
        if (!fs::exists(el)) 
            continue;
        const auto new_path = path / el.filename();
        if (fs::is_directory(el)) {
            // Создаём папку, даже если она пустая
            fs::create_directories(new_path);
            // Если папка непустая, копируем рекурсивно
            if (!fs::is_empty(el)) 
                fs::copy(el, new_path, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
        }
        else if (fs::is_regular_file(el)) {
            fs::copy(el, new_path, fs::copy_options::overwrite_existing);
        }
    }
}