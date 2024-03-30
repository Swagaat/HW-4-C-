#include <iostream>
#include <map>

class Polynomial {
public:
    Polynomial() {}

    void setTerm(int exponent, int coefficient) {
        terms[exponent] = coefficient;
    }

    int getTerm(int exponent) const {
        if (terms.count(exponent)) {
            return terms.at(exponent);
        }
        return 0;
    }

    Polynomial operator+(const Polynomial& other) const {
        Polynomial result = *this;
        for (const auto& term : other.terms) {
            result.terms[term.first] += term.second;
        }
        return result;
    }

    Polynomial operator-(const Polynomial& other) const {
        Polynomial result = *this;
        for (const auto& term : other.terms) {
            result.terms[term.first] -= term.second;
        }
        return result;
    }

    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            terms = other.terms;
        }
        return *this;
    }

    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;
        for (const auto& term1 : terms) {
            for (const auto& term2 : other.terms) {
                int exponent = term1.first + term2.first;
                int coefficient = term1.second * term2.second;
                result.terms[exponent] += coefficient;
            }
        }
        return result;
    }

    Polynomial& operator+=(const Polynomial& other) {
        *this = *this + other;
        return *this;
    }

    Polynomial& operator-=(const Polynomial& other) {
        *this = *this - other;
        return *this;
    }

    Polynomial& operator*=(const Polynomial& other) {
        *this = *this * other;
        return *this;
    }

    void print() const {
        for (const auto& term : terms) {
            std::cout << term.second << "x^" << term.first << " + ";
        }
        std::cout << "\b\b " << std::endl;  // Erase the last " +"
    }

private:
    std::map<int, int> terms;
};

int main() {
    Polynomial p1, p2, p3, p4;

    // Set terms for p1
    p1.setTerm(4, 3);  
    p1.setTerm(1, 2);  
    
    // Set terms for p2
    p2.setTerm(1, 4);  
    p2.setTerm(0, 5); 
    p2.setTerm(1, 2);

    // Print p1, p2 and p4
    std::cout << "Polynomial p1: ";
    p1.print();
    std::cout << "Polynomial p2: ";
    p2.print();
    

    // Test addition
    p3 = p1 + p2;
    std::cout << "p1 + p2: ";
    p3.print();

    // Test subtraction
    p3 = p1 - p2;
    std::cout << "p1 - p2: ";
    p3.print();

    // Test multiplication
    p3 = p1 * p2;
    std::cout << "p1 * p2: ";
    p3.print();

    return 0;
}
