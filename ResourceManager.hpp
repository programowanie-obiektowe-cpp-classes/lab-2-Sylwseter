#pragma once

#include "Resource.hpp"
#include <memory> // dla std::shared_ptr

class ResourceManager
{
private:
    std::shared_ptr< Resource > resource_; // Zarz�dzany zas�b

public:
    // Konstruktor domy�lny: inicjalizuje Resource
    ResourceManager() : resource_(std::make_shared< Resource >()) {}

    // Konstruktor kopiuj�cy
    ResourceManager(const ResourceManager& other) : resource_(other.resource_) {}

    // Operator przypisania kopiuj�cego
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resource_ = other.resource_;
        }
        return *this;
    }

    // Usuni�cie konstruktora przenosz�cego i operatora przenosz�cego przypisania
    ResourceManager(ResourceManager&&)            = delete;
    ResourceManager& operator=(ResourceManager&&) = delete;

    // Destruktor
    ~ResourceManager() = default;

    // Metoda get() zwracaj�ca wynik get() z Resource
    double get() const { return resource_->get(); }
};
