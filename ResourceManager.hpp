#pragma once

#include "Resource.hpp"
#include <memory> // dla std::shared_ptr

class ResourceManager
{
private:
    std::shared_ptr< Resource > resource_; // Zarz¹dzany zasób

public:
    // Konstruktor domyœlny: inicjalizuje Resource
    ResourceManager() : resource_(std::make_shared< Resource >()) {}

    // Konstruktor kopiuj¹cy
    ResourceManager(const ResourceManager& other) : resource_(other.resource_) {}

    // Operator przypisania kopiuj¹cego
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource_ = other.resource_;
        }
        return *this;
    }

    // Usuniêcie konstruktora przenosz¹cego i operatora przenosz¹cego przypisania
    ResourceManager(ResourceManager&&)            = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;

    // Destruktor
    ~ResourceManager() = default;

    // Metoda get() zwracaj¹ca wynik get() z Resource
    double get() const { return resource_->get(); }
};
