#include <iostream>
#include <vector>


// Exercice1 TP02
/*template <typename T>
T multiply(T val, int n) {
  return val * n;
}


int main() 
{
	std :: cout << multiply(2 , 3) << '\n';
	std :: cout << multiply(1.2 , 3) << '\n';
	
	return 0;
}
	
// Exercice 2 TP02

template <typename T>
T powiter(T a, int n) {
    T result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = result * a;
        }
        a = a * a;
        n /= 2;
    }
    return result;
}

template <typename T>
T powrec(T a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        T b = powrec(a, n/2);
        return b * b;
    } else {
        return a * powrec(a, n-1);
    }
}

int main()
{
	std :: cout << powiter(2 , 3) << '\n';
	std :: cout << powiter(1.2 , 3) << '\n';
	
	std :: cout << powrec(2 , 3) << '\n';
	std :: cout << powrec(1.2 , 3) << '\n';
	return 0;

}*/
//Exercice 3

template <typename T>
std::vector<std::vector<T>> matpow(std::vector<std::vector<T>> a, int k) {
    int n = a.size();
    std::vector<std::vector<T>> result(n, std::vector<T>(n));
    // Initialize the result matrix as the identity matrix
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    while (k > 0) {
        if (k & 1) {
            result = result * a;
        }
        a = a * a;
        k >>= 1;
    }
    return result;
}

template <typename T>
void matprint(std::vector<std::vector<T>> a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
template <typename T>
std::vector<std::vector<T>> matpownaive(std::vector<std::vector<T>> a, int k) {
    int n = a.size();
    std::vector<std::vector<T>> result(n, std::vector<T>(n));
    // Initialize the result matrix as the identity matrix
    for (int i = 0; i < n; i++) {
        result[i][i] = 1;
    }
    for (int i = 0; i < k; i++) {
        result = result * a;
    }
    return result;
}



int main(int argc , char *argv[])
{
	std::vector<std::vector<int> > a { {1 , 1 , 1} , {2 , 2 , 2} };
	std::vector<std::vector<double> > b { {1.0 , 1.23 , 1.22} , {2.22 , 2.33 , 2.33} };
	matprint(matpow(a , 12));
	matprint(matpow(b , 15));
	
}
