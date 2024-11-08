#pragma once

#include "Resource.hpp"
#include <memory> // dla std::shared_ptr

class ResourceManager
{
private:
    std::shared_ptr< Resource > resource_; // Zarządzany zasób

public:
    // Konstruktor domyślny: inicjalizuje Resource
    ResourceManager() : resource_(std::make_shared< Resource >()) {}

    // Konstruktor kopiujący
    ResourceManager(const ResourceManager& other) : resource_(other.resource_) {}

    // Operator przypisania kopiującego
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource_ = other.resource_;
        }
        return *this;
    }

    // Usunięcie konstruktora przenoszącego i operatora przenoszącego przypisania
    ResourceManager(ResourceManager&&)            = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;

    // Destruktor
    ~ResourceManager() = default;

    // Metoda get() zwracająca wynik get() z Resource
    double get() const { return resource_->get(); }
};
